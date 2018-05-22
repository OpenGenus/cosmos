#include <cmath>

template <typename T>
typename T::value_type mean(const T& container)
{
    typename T::value_type result;
    for (const auto& value : container)
        result += value;
    if (container.size() > 0)
        result /= container.size();
    return result;
}

template <typename T>
typename T::value_type var(const T& container)
{
    auto mu = mean(container);

    typename T::value_type result;
    for (const auto& value : container)
    {
        auto res = value - mu;
        result += res * res;
    }
    if (container.size() > 1)
        result /= container.size() - 1;
    return result;
}

template <typename T>
typename T::value_type stdDev(const T& container)
{
    return std::sqrt(var(container));
}
