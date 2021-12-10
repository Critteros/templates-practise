#include <iostream>
#include "XVector.h"

int main()
{
    XVector vec1(1, 2, 3, 4, 5, 6, 7.3, 7, 8, 3, 4.3, 3, 1, 2, 3, 5, 7.339);
    XVector vec2(2, 4, 5, 9, 5, 6, 7.3, 7, 8, 3, 4.3, 3.8, 7, 2, 3, 5, 7.9);

    XVector result = vec1 + vec2;
    std::cout << "vec1:\n"
              << vec1 << std::endl;

    std::cout << "vec2:\n"
              << vec2 << std::endl;

    std::cout << "result:\n"
              << result << std::endl;

    return 0;
}