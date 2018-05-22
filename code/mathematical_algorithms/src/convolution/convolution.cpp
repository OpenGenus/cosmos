/* Part of Cosmos by OpenGenus Foundation */
#include <iostream>
#include <vector>

// This code requires you to enable the C++11 standard when compiling

/**
 * @breif convolve - compute the discrete time convolution of functions vectors f and g. Coded for clarity,
 * not performance.
 * @return f * g
 **/
template <typename T>
std::vector<T> convolve(const std::vector<T>& f, const std::vector<T>& g)
{

    if (f.size() < 1 || g.size() < 1)
        return {};

    const auto outputSize = static_cast<int>(f.size() + g.size() - 1);
    std::vector<float> fg(outputSize, 0.0);

    for (int n = 0; n < outputSize; n++)
        for (int m = 0; m < static_cast<int>(g.size()); m++)
            if (n - m >= 0 && n - m <= static_cast<int>(outputSize - g.size()))
                fg[n] += f[n - m] * g[m];

    return fg;
}

int main()
{
    // In this example the input is a vector of 1s and the filter is a weighted
    // average filter. The result is the sliding average of input using four points.
    const auto input = std::vector<float>(5, 1.0f);
    const auto filter = std::vector<float>(4, 0.25f);

    const auto fg = convolve<float>(input, filter);

    for (const auto& elem : fg)
        std::cout << elem << std::endl;

    return 0;
}
