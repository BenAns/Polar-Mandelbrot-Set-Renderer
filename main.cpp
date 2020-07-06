#include "renderer.hpp"
#include "outputBMP.hpp"

int main(int argc, char* argv[])
{
    // Constants to render the fractal
    const int width = 640;
    const int height = 480;
    const double leftTheta = -2 * M_PI;
    const double rightTheta = 2 * M_PI;
    const double topR = 2;
    const double bottomR = 0;
    const uint64_t maxIterations = 1000;
    std::vector<SDL_Color> palette = {{0x00, 0x00, 0x00}, {0x00, 0xff, 0x00}, {0x00, 0x88, 0x88}, {0x00, 0x00, 0xff}};

    // Renders the fractal
    renderer fractalRenderer;
    fractalRenderer.generateFractal(width, height, leftTheta, rightTheta, topR, bottomR, maxIterations);
    std::shared_ptr<uint32_t[]> pixels = fractalRenderer.renderBitmap(width, height, maxIterations, palette);

    // Outputs the fractal
    outputBMP window(width, height, pixels);
    SDL_Delay(5000);

    return 0;
}
