#ifndef OUTPUTBMP_HPP_INCLUDED
#define OUTPUTBMP_HPP_INCLUDED

#include <memory>
#include <SDL.h>

// Class that outputs displaying a bitmap image given the resolution and array of pixels

class outputBMP
{
    public:
        outputBMP(int w, int h, std::shared_ptr<uint32_t[]> pixels);

        ~outputBMP();

    private:
        int w, h;
        std::shared_ptr<uint32_t[]> pixels;

        SDL_Window* window;
        SDL_Surface* surface;
};

#endif
