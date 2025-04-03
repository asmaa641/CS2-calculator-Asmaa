#include <iostream>
#include "calculator.h"
using namespace std;

int main() {
    cout << "Addition: " << add(3, 4) << endl;
    cout << "Subtraction: " << substract(10, 4) << endl;
    cout << "Multiplication: " << multiply(2, 3) << endl;
    cout << "Division: " << divide(10, 2) << endl;
    cout << "Factorial: " << factorial(5) << endl;
    cout << "GCD: " << gcd(24, 36) << endl;
    cout << "LCM: " << lcm(4, 5) << endl;
    srand(time(0));
    cout << "Random number: " << randomNumber(1, 100) << endl;
    string expression = "3 + 4 * (2 - 1) / 5";
    cout << "Result: " << bonusParsing(expression) << endl;
    return 0;
}
