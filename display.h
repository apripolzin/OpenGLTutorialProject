#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL.h>
#include <string>


class Display
{
public:
    Display(int width, int height, const std::string &title);
    virtual ~Display();

    void clear(float r, float g, float b, float a);
    void update();
    bool isClosed() const;

private:
    Display(const Display &) = delete;
    Display& operator=(const Display &) = delete;

    SDL_Window *m_window;
    SDL_GLContext m_glContext;
    bool m_isClosed;

};

#endif // DISPLAY_H
