#include "renderer.hpp"
#include <iostream>

// Generates the iterations for each pixel of the fractal, given parameters
void renderer::generateFractal(int w, int h, double leftTheta, double rightTheta, double topR, double bottomR, uint64_t maxIterations)
{
    iterateResults.reserve(w * h);

    // Goes through each pixel, maps it to a complex number, iterates it, then stores the results
    for(int y = 0; y < h; y++)
    {
        for(int x = 0; x < w; x++)
        {
            std::complex<double> zStart = mapNum(x, y, w, h, leftTheta, rightTheta, topR, bottomR);
            iterateResults[y * w + x] = generateIterations(zStart, maxIterations);
        }
    }
}

// Exports a generated fractal as bitmap given a palette
std::shared_ptr<uint32_t[]> renderer::renderBitmap(int w, int h, uint64_t maxIterations)
{
    std::shared_ptr<uint32_t[]> bitmap(new uint32_t[w * h]);

    for(int i = 0; i < w * h; i++)
    {
        bitmap[i] = iterateResults[i].iterations == maxIterations ? 0x000000ff : 0xffffffff;
    }

    return bitmap;
}

// Maps a pixel onto a complex number given the rendering parameters
std::complex<double> renderer::mapNum(int x, int y, int w, int h, double leftTheta, double rightTheta, double topR, double bottomR)
{
    double theta = leftTheta + ((rightTheta - leftTheta) * x) / w;
    double r = topR + ((bottomR - topR) * y) / h;

    return std::complex<double>(r * std::cos(theta), r * std::sin(theta));
}

// Iterates a specific complex number
renderer::iterateState renderer::generateIterations(std::complex<double> c, uint64_t maxIterations)
{
    // Performs the iteration
    std::complex<double> z;
    uint64_t i;
    for(i = 0; i < maxIterations; i++)
    {
        // Advances the current iteration
        z = z*z + c;

        // Leaves iteration loop if the number diverges
        if(std::abs(z) > 2)
        {
            break;
        }
    }

    return {c, z, i};
}
