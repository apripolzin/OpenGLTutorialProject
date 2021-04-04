#include <iostream>

#include "mesh.h"
#include "display.h"
#include "shader.h"
#include "texture.h"
#include "transform.h"

int main()
{
    Display display(800, 600, "Hello world");

    Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0.0), glm::vec2(0.0, 0.0)),
                          Vertex(glm::vec3( 0.0,  0.5, 0.0), glm::vec2(0.5, 1.0)),
                          Vertex(glm::vec3( 0.5, -0.5, 0.0), glm::vec2(1.0, 0.0)) };

    Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));
    Shader shader("./res/basicShader");
    Texture texture("./res/bricks.jpg");
    Transform transform;

    float counter = 0.0f;

    while (!display.isClosed())
    {
        display.clear(0.0f, 0.15f, 0.3f, 1.0f);

        float sinCounter = sinf(counter);
        float cosCounter = cosf(counter);

        transform.getPos().x = sinCounter;
        transform.getRot().z = counter;
        transform.setScale(glm::vec3(cosCounter, cosCounter, cosCounter));

        shader.bind();
        texture.bind(0);
        shader.update(transform);
        mesh.draw();

        display.update();

        counter += 0.01f;
    }

    return 0;
}
