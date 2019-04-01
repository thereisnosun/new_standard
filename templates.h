#pragma once
#include <utility>

template <typename... X>
constexpr auto make_storage(X... x)
{
    auto storage = [=](auto f) {return f (x...); };
}

template <typename... X>
struct tuple{
    explicit constexpr tuple(X... x):
        storage{make_srtorage(x...)} {}
    decltype(make_storage(std::declval<X>()...)) storage;
};


template <size_t N, typename... T>
constexpr decltype(auto) get(tuple<T...>& t)
{
    return t.storage([] (auto&&... x) {});
};
