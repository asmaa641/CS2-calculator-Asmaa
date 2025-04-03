#include <string>
#include <stack>
#include <vector>
using namespace std;


int add(int a, int b);
int substract(int a, int b);
int multiply(int a, int b);
double  divide(int a, int b);
int factorial(int a);
int gcd(int a, int b);
int lcm(int a, int b);
int randomNumber(int min, int max);
double bonusParsing (const string& input);
vector<string> infixToPostfix(const string& infix);
double evaluatePostfix(const vector<string>& postfix);
