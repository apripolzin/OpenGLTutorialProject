#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
#include <GL/glew.h>

class Vertex
{
public:
    Vertex(const glm::vec3 &pos, const glm::vec2 texCoord)
    {
        this->pos = pos;
        this->texCoord = texCoord;
    }

    glm::vec3 *getPos() { return &pos; }
    glm::vec2 *getTexCoord() { return &texCoord; }

private:
    glm::vec3 pos;
    glm::vec2 texCoord;
};

class Mesh
{
public:
    Mesh(Vertex *vertices, unsigned int numVerticies);
    virtual ~Mesh();

    void draw();

private:
    Mesh(const Mesh &) = delete;
    Mesh& operator=(const Mesh &) = delete;

    enum {
        POSITION_VB,
        TEXCOORD_VB,
        NUM_BUFFERS
    };
    GLuint m_vertexArrayObject;
    GLuint m_vertexArrayBuffers[NUM_BUFFERS];
    unsigned int m_drawCount;

};

#endif // MESH_H
