#include <iostream>
#include <vector>
#include <variant>
#include <tuple>
#include <map>

auto make_tuple(int a, std::string&& str)
{
    return std::tuple(a, str);
}

void structBinding();

int main(int argc, char* argv[])
{
    std::cout << "Experiments with C++17\n";
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
