#include "outputBMP.hpp"

// Outputs the rendered fractal on a window
outputBMP::outputBMP(int w, int h, std::shared_ptr<uint32_t[]> pixels): w(w), h(h), pixels(pixels)
{

    // Opens the window
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Polar Mandelbrot Set Renderer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
    surface = SDL_GetWindowSurface(window);

    // Outputs the fractal on the opened window
    SDL_Surface* BMPSurface = SDL_CreateRGBSurfaceWithFormatFrom(pixels.get(), w, h, 8, w * sizeof(uint32_t), SDL_PIXELFORMAT_RGBA8888);
    SDL_BlitSurface(BMPSurface, NULL, surface, NULL);
    SDL_UpdateWindowSurface(window);
    SDL_FreeSurface(BMPSurface);
}

// Closes the window
outputBMP::~outputBMP()
{
    SDL_FreeSurface(surface);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
