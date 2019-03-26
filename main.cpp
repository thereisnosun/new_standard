#include <iostream>
#include <vector>
#include <variant>
#include <tuple>
#include <map>
#include <memory>

auto make_tuple(int a, std::string&& str)
{
    return std::tuple(a, str);
}

void structBinding();

template<typename T>
auto getValue(T t)
{
    if constexpr (std::is_pointer_v<T>)
        return *t;
    else
        return t;
}

template<typename... Args>
auto sum(Args... args)
{
    return(args + ...);
}

template<typename... Args>
auto multiply(Args... args)
{
    return(args * ...);
}

int main(int argc, char* argv[])
{
    std::cout << "Experiments with C++17\n";

    std::cout << sum(1, 2, 3, 4, 5) << std::endl;
    std::cout << multiply(1, 2, 3, 4, 5) << std::endl;
    auto pointer = std::make_unique<int>(5);
    int value = 5;
    std::cout << getValue(pointer.get()) << std::endl;
    std::cout << getValue(value) << std::endl;


    structBinding();

    return 0;
}

void structBinding()
{
    auto [first, second] = make_tuple(5, "Rock");

    int vecInt[3] = {1, 3, 5};
    auto [a, b, c] = vecInt;

    auto [firstPair, secondPair] = std::make_pair(1, 3);

    std::map<int, std::string> testMap;
    testMap.emplace(std::make_pair(1, "Test"));
    for (const auto& [key, value] : testMap)
    {
        std::cout << key << "=" << value << std::endl;
    }

}
