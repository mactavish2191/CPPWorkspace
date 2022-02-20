#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

int main()
{
    using namespace boost::multiprecision;
    
    int128_t v = 1;
    
    for(unsigned i = 1; i <= 20; ++i)
        v *= i;
    
    std::cout << v << "\n";
    
    cpp_int u = 1;
    for(unsigned i = 1; i <= 100; ++i)
        u *= i;
    
    std::cout << u << "\n";
    
    return 0;
}
