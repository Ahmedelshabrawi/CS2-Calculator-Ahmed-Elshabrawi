#include <cstdlib>  // For rand()
#include <ctime>    // For srand()

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
