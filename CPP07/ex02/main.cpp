#include <iostream>
#include <stdexcept>
#include "Array.hpp"

int main(int, char**)
{
    bool ok = true;

    {
        Array<int> empty;
        Array<int> numbers(3);

        numbers[0] = 10;
        numbers[1] = 20;
        numbers[2] = 30;

        ok &= (empty.size() == 0);
        ok &= (numbers.size() == 3);
        ok &= (numbers[0] == 10 && numbers[2] == 30);
        std::cout << "[block 1] " << (ok ? "ok" : "fail") << std::endl;
    }

    {
        Array<int> numbers(3);

        numbers[0] = 1;
        numbers[1] = 2;
        numbers[2] = 3;

        Array<int> copy(numbers);
        numbers[1] = 99;

        ok &= (copy[1] == 2);
        ok &= (copy.size() == numbers.size());
        std::cout << "[block 2] " << ((copy[1] == 2) ? "ok" : "fail") << std::endl;
    }

    {
        Array<int> source(4);
        Array<int> target;

        for (unsigned int i = 0; i < source.size(); ++i)
            source[i] = static_cast<int>(i + 1);

        target = source;
        source[0] = 42;

        ok &= (target[0] == 1);

        try
        {
            target[4] = 0;
            ok = false;
        }
        catch (const std::out_of_range&)
        {
        }

        std::cout << "[block 3] " << ((target[0] == 1) ? "ok" : "fail") << std::endl;
    }

    return ok ? 0 : 1;
}
