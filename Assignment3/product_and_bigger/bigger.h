#pragma

#include <string>
#include <cstring>


// TODO finish inline template function bigger
template<typename T>
inline T bigger(T x,  T y) {
    return y >= x ? y : x;
}

template<>
inline const char *bigger<const char *>(char const *x, char const *y) {
    return strlen(y) >= strlen(x) ? y : x;
}

template<>
inline std::string bigger<std::string>(const std::string x, const std::string y) {
    return y.length() >= x.length() ? y : x;
}