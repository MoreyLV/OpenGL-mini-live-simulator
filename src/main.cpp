#include <chrono>

#include <glad/glad.h>
#include <SFML/Window.hpp>

#include <iostream>
#include <string>
#include <vector>
#include <thread>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../include/Camera.h"
#include "../include/Events.h"
#include "../include/Mesh.h"
#include "../include/Rendering.h"
#include "../include/Shader.h"
#include "../include/Utility.h"
#include "../include/Vertices.h"
#include "../include/Map.h"
#include "../include/Simulation.h"

// ================== MAIN ==================
int main() {
    sf::ContextSettings settings;
    settings.depthBits         = 24;
    settings.stencilBits       = 8;
    settings.antialiasingLevel = 0;
    settings.majorVersion      = 3;
    settings.minorVersion      = 3;
    settings.attributeFlags    = sf::ContextSettings::Core;

    sf::VideoMode mode(1280, 720);
    sf::Window window(
        mode,
        "OpenGL Template",
        sf::Style::Default,
        settings
    );

    window.setVerticalSyncEnabled(true);
    if (!window.setActive(true)) {
        std::cerr << "Failed to activate OpenGL context" << std::endl;
        return -1;
    }

    if (!gladLoadGL()) {
        std::cerr << "Failed to initialize GLAD\n";
        return -1;
    }

    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
    glViewport(0, 0, mode.width, mode.height);

    const char* vsSrc = R"(
         #version 330 core
         layout (location = 0) in vec3 TriaPos;
         layout (location = 1) in vec3 TriaColor;

         uniform mat4 uProj;
         uniform vec2 uOffset;
         uniform vec4 uColor;
         out vec4 VertexColor;

         void main() {
            vec2 pos = TriaPos.xy + uOffset;
            gl_Position = uProj * vec4(pos, TriaPos.z, 1.0);
            VertexColor = uColor;
         }
     )";
    const char* fsSrc = R"(
         #version 330 core
         in vec4 VertexColor;

         out vec4 FragColor;

         void main() {
            FragColor = vec4(VertexColor);
         }
     )";

    Shader shader(vsSrc, fsSrc);
    shader.use();
    Camera camera;
    Mesh mesh(vertices);

    float map_width, map_height;
    map_width = 20.0f;//map width in tiles
    map_height = 20.0f;//map height in tiles

    Map map(map_width, map_height, 2, 50); //3 and 4 variables are species number (defines amount of coloured cells spawned on start) and food number that defines amount of random spawned food

    float scale = 0.9f;

    float scaleW = map_width*scale;
    float scaleH = map_height*scale;

    glm::mat4 proj = glm::ortho(
        -map_width * 2.5f+scaleW*1.5f, map_width * 2.5f-scaleW*1.5f,
        -map_height * 1.5f+scaleH, map_height * 1.5f-scaleH,
        -1.0f, 1.0f
    );
    shader.setMat4("uProj", glm::value_ptr(proj));

    mesh.draw();




    bool running = true;
    sf::Clock clock;
    Utility utility;
    Events events;
    Rendering render;
    Simulation simulation;

    while (running) {
        float dt = clock.restart().asSeconds();

        sf::Event event{};
        while (window.pollEvent(event)) {

            running = events.CheckClosingEvent(event);
            if (event.type == sf::Event::Resized) {
                glViewport(0, 0, event.size.width, event.size.height);
                mode.width  = event.size.width;
                mode.height = event.size.height;
            }

        }

        utility.ClearWindow(1.0f, 1.0, 1.0, 1.0f); //background color  r g b a
        shader.use();
        mesh.bindVAO();


        for (const SquareObject& tile : map.tiles) {

            shader.setVec2("uOffset", tile.x, tile.y);
            shader.setVec4("uColor", tile.r, tile.g, tile.b, tile.a);

            glDrawArrays(GL_TRIANGLES, 0, 6);
        }

        glBindVertexArray(0);
        simulation.live(map.tiles, map_width, map_height);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));//time between 1 move for every cell in milliseconds

        window.display();
    }

    window.close();
    return 0;
}
