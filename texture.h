#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <GL/glew.h>

class Texture
{
public:
    Texture(const std::string &fileName);
    virtual ~Texture();

    void bind(unsigned int unit);

private:
    Texture(const Texture &) = delete;
    Texture& operator=(const Texture &) = delete;

    GLuint m_texture;
};

#endif // TEXTURE_H
