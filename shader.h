#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/glew.h>

class Shader
{
public:
    Shader(const std::string &filename);
    virtual ~Shader();

    void bind();
private:
    Shader(const Shader &) = delete;
    Shader& operator=(const Shader &) = delete;

    static constexpr int NUM_SHADERS = 2;

    GLuint m_program;
    GLuint m_shaders[NUM_SHADERS];
};

#endif // SHADER_H
