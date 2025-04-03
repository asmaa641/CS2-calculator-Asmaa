// calculator.cpp
#include "calculator.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int substract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

double divide(int a, int b) {
    if (b == 0) {
	cout<< "Error, cannot divide by zero" << endl;
	return INFINITY;
}
else{
    return a / b;
}
}

int factorial(int n) {
    if (n <= 1) return 1;
    return n*factorial(n-1);
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int randomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}
      
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

double applyOperation(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b != 0) return a / b;
            else {
                cout << "Error: Division by zero!" << endl;
                return 0;
            }
        default: return 0;
    }
}

bool isNumber(char c) {
    return (c >= '0' && c <= '9') || c == '.'; 
}

vector<string> infixToPostfix(const string& infix) {
    stack<char> ops;              
    vector<string> output;        
    string numBuffer;

    for (size_t i = 0; i < infix.size(); i++) {
        char token = infix[i];

        if (isNumber(token)) {
           
            numBuffer.clear();
            while (i < infix.size() && isNumber(infix[i])) {
                numBuffer.push_back(infix[i]);
                i++;
            }
            output.push_back(numBuffer);
            i--;  
        } else if (token == '(') {
            ops.push(token);
        } else if (token == ')') {
            while (!ops.empty() && ops.top() != '(') {
                output.push_back(string(1, ops.top()));
                ops.pop();
            }
            ops.pop(); // Pop '('
        } else if (token == '+' || token == '-' || token == '*' || token == '/') {
            while (!ops.empty() && precedence(ops.top()) >= precedence(token)) {
                output.push_back(string(1, ops.top()));
                ops.pop();
            }
            ops.push(token);
        }
    }

   
    while (!ops.empty()) {
        output.push_back(string(1, ops.top()));
        ops.pop();
    }

    return output;
}

double evaluatePostfix(const vector<string>& postfix) {
    stack<double> stack;

   for (vector<string>::const_iterator it = postfix.begin(); it != postfix.end(); ++it) {
        string token = *it;

        if (isNumber(token[0])) {
            stack.push(stod(token.c_str()));  // Use stod() or atof() depending on your compiler
        } else {
            double b = stack.top();
            stack.pop();
            double a = stack.top();
            stack.pop();
            stack.push(applyOperation(a, b, token[0]));
        }       
    }
   

    return stack.top();
}


double bonusParsing(const string& expression) {
   
    vector<string> postfix = infixToPostfix(expression);

   
    return evaluatePostfix(postfix);
}
