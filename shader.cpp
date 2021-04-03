#include <fstream>
#include <iostream>
#include "shader.h"

static void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string &errorMessage);
static std::string loadShader(const std::string &filename);
static GLuint createShader(const std::string &text, GLenum shaderType);

Shader::Shader(const std::string &filename)
{
    m_program = glCreateProgram();
    m_shaders[0] = createShader(loadShader(filename + ".vs"), GL_VERTEX_SHADER);
    m_shaders[1] = createShader(loadShader(filename + ".fs"), GL_FRAGMENT_SHADER);

    for (unsigned int i = 0; i < NUM_SHADERS; ++i) {
        glAttachShader(m_program, m_shaders[i]);
    }
    glBindAttribLocation(m_program, 0, "position");
    glBindAttribLocation(m_program, 1, "texCoord");

    glLinkProgram(m_program);
    checkShaderError(m_program, GL_LINK_STATUS, true, "Error: Program linking failed ");

    glValidateProgram(m_program);
    checkShaderError(m_program, GL_VALIDATE_STATUS, true, "Error: Program is invalid ");
}

Shader::~Shader()
{
    for (unsigned int i = 0; i < NUM_SHADERS; ++i) {
        glDetachShader(m_program, m_shaders[i]);
        glDeleteShader(m_shaders[i]);
    }
    glDeleteProgram(m_program);
}

void Shader::bind()
{
    glUseProgram(m_program);
}

static void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string &errorMessage)
{
    GLint success = 0;
    GLchar error[1024] = { 0 };

    if (isProgram) {
        glGetProgramiv(shader, flag, &success);
    } else {
        glGetShaderiv(shader, flag, &success);
    }

    if (success == GL_FALSE) {
        if (isProgram) {
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        } else {
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);
        }

        std::cerr << errorMessage << ": '" << error << "'" << std::endl;
    }
}


std::string loadShader(const std::string &filename)
{
    std::ifstream file;

    file.open(filename.c_str());
    std::string line;
    std::string output;

    if (file.is_open()) {
        while (file.good()) {
            getline(file, line);
            output += line + "\n";
        }
    } else {
        std::cerr << "Unable to load shader: " << filename << std::endl;
    }

    return output;
}

static GLuint createShader(const std::string &text, GLenum shaderType)
{
    GLuint shader = glCreateShader(shaderType);
    if (shader == 0) {
        std::cerr << "Error: Shader creation failed" << std::endl;
    }

    const GLchar *shaderSourceStrings[1];
    GLint shaderSourceStringLengths[1];

    shaderSourceStrings[0] = text.c_str();
    shaderSourceStringLengths[0] = text.length();

    glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringLengths);
    glCompileShader(shader);

    checkShaderError(shader, GL_COMPILE_STATUS, false, "Error: Shader compilation failed ");

    return shader;
}
