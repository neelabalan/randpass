#define SODIUM_STATIC
#include "sodium.h"
#include <iostream>
#include <utility>
#include <vector>

inline unsigned short generateRandNumber(unsigned short lower, unsigned short upper)
{
    return (lower + randombytes_uniform(upper) % ((upper + 1) - lower));
}

namespace randpass
{
auto lowerBoundary = std::make_pair(97, 122);
auto upperBounday = std::make_pair(65, 90);
auto numberBoundary = std::make_pair(48, 57);

auto sym1 = std::make_pair(33, 47);
auto sym2 = std::make_pair(58, 64);
auto sym3 = std::make_pair(91, 96);
auto sym4 = std::make_pair(123, 126);

auto generatePass(
    short length, short pass, bool lower, bool upper, bool symbol, bool number
)
{

    std::vector<std::string> password;
    std::vector<std::pair<unsigned short, unsigned short>> constraints{};
    if (upper)
    {
        constraints.push_back(upperBounday);
    }
    if (lower)
    {
        constraints.push_back(lowerBoundary);
    }
    if (number)
    {
        constraints.push_back(numberBoundary);
    }
    if (symbol)
    {
        constraints.push_back(sym1);
        constraints.push_back(sym2);
        constraints.push_back(sym3);
        constraints.push_back(sym4);
    }

    short len = constraints.size();
    for (int i = 0; i < pass; i++)
    {
        std::string temp_pass = "";
        for (int j = 0; j < length; j++)
        {
            short random_at = generateRandNumber(0, len);
            auto vi = constraints.at(random_at);
            char letter = generateRandNumber(
                static_cast<unsigned short>(vi.first),
                static_cast<unsigned short>(vi.second)
            );
            temp_pass = temp_pass + letter;
        }
        password.push_back(temp_pass);
    }
    return password;
}
} // namespace randpass