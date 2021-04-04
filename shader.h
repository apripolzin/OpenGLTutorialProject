#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/glew.h>

#include "transform.h"

class Shader
{
public:
    Shader(const std::string &filename);
    virtual ~Shader();

    void bind();
    void update(const Transform &transform);
private:
    Shader(const Shader &) = delete;
    Shader& operator=(const Shader &) = delete;

    static constexpr int NUM_SHADERS = 2;

    enum {
        TRANSFORM_U,
        NUM_UNIFORMS
    };

    GLuint m_program;
    GLuint m_shaders[NUM_SHADERS];
    GLuint m_uniforms[NUM_UNIFORMS];
};

#endif // SHADER_H
