#include "renderer.hpp"
#include "outputBMP.hpp"

int main(int argc, char* argv[])
{
    // Constants to render the fractal
    const int width = 640;
    const int height = 480;
    const double leftTheta = -4 * M_PI;
    const double rightTheta = 4 * M_PI;
    const double topR = 3;
    const double bottomR = 0.1;
    const uint64_t maxIterations = 100;

    // Renders the fractal
    renderer fractalRenderer;
    fractalRenderer.generateFractal(width, height, leftTheta, rightTheta, topR, bottomR, maxIterations);
    std::shared_ptr<uint32_t[]> pixels = fractalRenderer.renderBitmap(width, height, maxIterations);

    // Outputs the fractal
    outputBMP window(width, height, pixels);
    SDL_Delay(5000);

    return 0;
}
