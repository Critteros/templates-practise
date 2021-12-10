#pragma once
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <type_traits>
#include <exception>
#include <algorithm>
#include <utility>

template <class... Args>
class XVector
{
public:
    XVector() = default;
    XVector(Args... args);

    template <class... T>
    XVector<Args...> operator+(const XVector<T...> &other) const;

    XVector(const XVector<Args...> &) = default;

    template <class... T>
    friend std::ostream &operator<<(std::ostream &stream, XVector<T...> &);

    using commonType = typename std::common_type_t<Args...>;

    template <class... T>
    friend class XVector;

private:
    std::vector<commonType> _data;
};

template <class... Args>
template <class... T>
XVector<Args...> XVector<Args...>::operator+(const XVector<T...> &other) const
{
    const XVector<Args...> &first = *this;
    const XVector<T...> &second = other;

    //Sanity checks

    //Check vector sizes
    if (first._data.size() != second._data.size())
        throw std::runtime_error("Adding vectors with diffrent sizes!");

    //Check common type
    static_assert(
        std::is_same_v<
            typename XVector<Args...>::commonType,
            typename XVector<T...>::commonType>,
        "Common vector types are not equal!");

    XVector<Args...> out = first;
    //Summing
    std::transform(
        out._data.begin(), out._data.end(),
        second._data.begin(),
        out._data.begin(),
        std::plus<typename XVector<Args...>::commonType>());

    return out;
}

template <class... Args>
std::ostream &operator<<(std::ostream &stream, class XVector<Args...> &vec)
{
    std::stringstream out;
    out << std::fixed << std::setprecision(2);
    out << "[";
    for (const auto &el : vec._data)
    {
        out << el << ", ";
    }
    out << "]";
    std::string output = out.str();
    output.erase(output.end() - 3, output.end() - 1);
    stream << output << std::endl;
    return stream;
}

template <class... Args>
XVector<Args...>::XVector(Args... args)
    : _data{static_cast<commonType>(args)...}
{
}