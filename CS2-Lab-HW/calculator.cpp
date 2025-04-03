#include <cstdlib>  // For rand()
#include <ctime>    // For srand()
#include <cctype>  // For isdigit()
#include <stdexcept> // For exceptions
double addition(double num1, double num2) {
    return num1 + num2;
}

double subtraction(double num1, double num2) {
    return num1 - num2;
}

double multiplication(double num1, double num2) {
    return num1 * num2;
}

double division(double num1, double num2) {
    if (num2 == 0) {
        throw "Error: Division by zero.";
    }
    return num1 / num2;
}

int factorial(int num) {
    if (num <= 1) return 1;
    return num * factorial(num - 1);
}

int gcd(int num1, int num2) {
    if (num2 == 0) return num1;
    return gcd(num2, num1 % num2);
}

int lcm(int x, int y) {
    return (x / gcd(x, y)) * y;
}

int random(int min, int max) {
    return min + rand() % (max - min + 1);
}
// BONUS PART: Recursive function to evaluate the expression
double evaluateExpression(const string& expression) {
    size_t index = 0;
    return addsub(expression, index);  //start evaluating with addition/subtraction
}

// addsub() to handle addition and subtraction
double addsub(const string& expression, size_t& index) {
    double result = multdiv(expression, index);  //start with multiplication/division (multdiv)

    while (index < expression.length()) {
        if (expression[index] == '+') {
            index++;
            result = addition(result, multdiv(expression, index));  //perform addition
        } 
        else if (expression[index] == '-') {
            index++;
            result = subtraction(result, multdiv(expression, index));  //perform subtraction
        } 
        else {
            break;  //end if no more + or - operators
        }
    }

    return result;
}

// multdiv() to handle multiplication and division
double multdiv(const string& expression, size_t& index) {
    double result = numpar(expression, index);  //start with factor (numbers or parentheses)

    while (index < expression.length()) {
        if (expression[index] == '*') {
            index++;
            result = multiplication(result, numpar(expression, index));  //perform multiplication
        } 
        else if (expression[index] == '/') {
            index++;
            result = division(result, numpar(expression, index));  //perform division
        } 
        else {
            break;  //end if no more * or / operators
        }
    }

    return result;
}

// numpar() to handle numbers and parentheses
double numpar(const string& expression, size_t& index) {
    double result = 0;

    //skip spaces
    while (index < expression.length() && isspace(expression[index])) index++;

    if (expression[index] == '(') {  //if it's a left parenthesis
        index++;  //consume '('
        result = addsub(expression, index);  //recurse for the inner expression
        if (expression[index] == ')') {
            index++;  //consume ')'
        } else {
            throw runtime_error("Error: Mismatched parentheses.");
        }
    }
    else if (isdigit(expression[index])) {  //if it's a number
        size_t start = index;
        while (index < expression.length() && (isdigit(expression[index]) || expression[index] == '.')) {
            index++;
        }
        result = stod(expression.substr(start, index - start));  //convert string to double
    } 
    else {
        throw runtime_error("Error: Invalid character in expression.");
    }

    return result;
}
