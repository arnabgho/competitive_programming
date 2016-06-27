

#include <iomanip>
#include <iostream>

int main()
{
    double num1 = 3.12345678;
    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(2);
    std::cout << num1 << endl;
    return 0;

}

