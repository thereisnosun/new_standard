#include "string_view_test.h"
#include <string_view>
#include <string>
#include <chrono>
#include <random>
#include <fstream>
#include <sstream>

//void* operator new(size_t size)
//{
//    std::cout << "Allocated " << size << std::endl;
//    return malloc(size);
//}
size_t constexpr MAX_LEN = 65536;

string_view_test::string_view_test()
{

}
template<class Type>
void string_view_test::testPerformance(Type& testStr, std::string&& testName)
{
     const auto start = std::chrono::steady_clock::now();

     const int maxLen = std::min(MAX_LEN, testStr.size());
     for(size_t i = 0; i < maxLen; ++i)
     {
          Type subStr = testStr.substr(0, i);
     }

     const std::chrono::duration<double> durString = std::chrono::steady_clock::now() - start;
     std::cout << testName << "::substr: " << durString.count() << " seconds" << std::endl;
}

void string_view_test::test(const std::string& fileName)
{
    std::string allocString = "1234567890111111111111111111111111111111111111111";
    std::string moveStr = std::move(allocString);
    std::string_view stringView = moveStr;

    std::ifstream inFile{fileName};
    std::stringstream strStream;
    strStream <<  inFile.rdbuf();
    std::string textChunk  = strStream.str();

    testPerformance(textChunk, "std::string");

    std::string_view textChunkView = textChunk;
    testPerformance(textChunkView, "std::string_view");


}
