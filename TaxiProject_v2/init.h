#include <ctime>

template<typename T>
std::string StringUtils::toString(const T &t) {
    std::ostringstream oss;
    oss << t;
    return oss.str();
}

template<typename T>
T StringUtils::fromString( const std::string& s ) {
    std::istringstream stream( s );
    T t;
    stream >> t;
    return t;
}
