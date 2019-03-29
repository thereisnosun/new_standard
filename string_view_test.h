#ifndef STRING_VIEW_TEST_H
#define STRING_VIEW_TEST_H
#include <iostream>
#include <string_view>


class string_view_test
{
public:
    string_view_test();
    void test(const std::string&);
private:
    template<class Type>
    void testPerformance(Type& fileName, std::string&& testName);
};


#endif // STRING_VIEW_TEST_H
