#include<iostream>
#include<vector>
#include<boost/multiprecision/cpp_int.hpp>
#include<boost/numeric/ublas/matrix.hpp>
#include<boost/numeric/ublas/io.hpp>
#include<boost/multiprecision/gmp.hpp>
#include<boost/math/special_functions/gamma.hpp>

using namespace std;
using namespace boost::multiprecision;
using namespace boost::numeric::ublas;

cpp_int b1(unsigned n)
{
   cpp_int r(1);
   return (r << n) - 1;
}

int main()
{
   //std::cout << std::hex << std::showbase << b1(16) << "\n";
   // Calculate the largest number that will fit inside 128 bits, we could
   // also have used numeric_limits<int128_t>::max() for this value:
   //cout << cpp_int(1) << "\n";
   //cpp_int limit = (cpp_int(1) << 16) - 1;
   //cout << limit << "\n";

    matrix<double> m (3, 3);
    for (unsigned i = 0; i < m.size1 (); ++ i)
        for (unsigned j = 0; j < m.size2 (); ++ j)
            m (i, j) = 3 * i + j;
    std::cout << m << "\n";

    mpf_float a = 2;
    std::cout << std::setprecision(8) <<sqrt(a) << "\n";

    // Operations at fixed precision and full standard library support:
    mpf_float_50 b = 2;
    std::cout << std::setprecision(10) << log10(b) << "\n"; // print log(2)
    std::cout << boost::math::tgamma(b*b) << "\n";
    cout << std::setprecision(10) << M_PI << "\n";

   return 0;
}
