#include <iostream>
#include <typeinfo>
#include <limits>

using namespace std;

auto main() -> int {
    auto i = 0x3fff;   // Hexadecimal literal

    cout << "Hexadecimal value: " << i << "\n";

    auto binary = 0b00011;
    cout << "Binary value: " << binary << "\n";

    unsigned val_1 = 328u;                  // Unsigned value
    long val_2 = 0x7FFFFFL;                 // Long value specified
                                            //  as hex literal
    cout << "Unsigned value: " << val_1 << "\n";
    cout << "Long hex value: " << val_2 << "\n";

    unsigned long val_3 = 0776745ul;        // Unsigned long value
    auto val_4 = 108LL;                           // signed long long
    auto val_5 = 0x8000000000000000ULL << 16;     // unsigned long long

    cout << "Unsigned long value: " << val_3 << "\n";
    cout << "Signed long long value: " << val_4 << "\n";
    cout << "Unsigned long long hex value: " << val_5 << "\n";


    double max = std::numeric_limits<double>::max();
    double inf = std::numeric_limits<double>::infinity();

    cout << "MAX FLOAT: "<< max << "\nINFINITY FLOAT: " << inf << "\n";

    if (inf > max) {
        cout << "infinity is larger\n";
    }

    return 0;
}