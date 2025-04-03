#include <iostream>
#include "calculator.h"
#include <string>

using namespace std;
//new feature
int main() {
    double x, y;
    int z;
    char ans;

    while (true) {
        cout << "Enter the desired operation: +, -, *, /, !, G (for GCD), L (for LCM), R (for random number generation), V to evaluate an expression, E (to exit)" << endl;
        cin >> ans;

        if (ans == 'E' || ans == 'e') {
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }
  // BONUS PART: Check if the user wants to evaluate an expression
        if (ans == 'V' || ans == 'v') {  
            cout << "Enter an expression to evaluate (e.g., 3 + 4 * 2): ";
            cin.ignore(); //to clear the newline left by previous cin
            getline(cin, expression); //read the full expression as a string
            try {
                double result = evaluateExpression(expression);
                cout << "Result: " << result << endl;
            } catch (const runtime_error& e) {
                cout << "Error: " << e.what() << endl;
            }
            continue;
        }
        // For operations that require two numbers
        if (ans == '+' || ans == '-' || ans == '*' || ans == '/' || ans == 'G' || ans == 'L' || ans == 'R') {
            cout << "Enter two numbers: ";
            cin >> x >> y;
        }

        switch (ans) {
            case '+':
                cout << x << " + " << y << " = " << addition(x, y) << endl;
                break;
            case '-':
                cout << x << " - " << y << " = " << subtraction(x, y) << endl;
                break;
            case '*':
                cout << x << " * " << y << " = " << multiplication(x, y) << endl;
                break;
            case '/':
                if (y == 0) {
                    cout << "Error: Division by zero is not allowed." << endl;
                } else {
                    cout << x << " / " << y << " = " << division(x, y) << endl;
                }
                break;
            case '!':
                cout << "Enter a positive integer: ";
                cin >> z;
                if (z < 0) {
                    cout << "Error: Factorial is not defined for negative numbers." << endl;
                } else {
                    cout << z << "! = " << factorial(z) << endl;
                }
                break;
            case 'G': case 'g':
                cout << "GCD(" << x << ", " << y << ") = " << gcd(static_cast<int>(x), static_cast<int>(y)) << endl;
                break;
            case 'L': case 'l':
                cout << "LCM(" << x << ", " << y << ") = " << lcm(static_cast<int>(x), static_cast<int>(y)) << endl;
                break;
            case 'R': case 'r':
                cout << "Random number between " << x << " and " << y << ": " << random(static_cast<int>(x), static_cast<int>(y)) << endl;
                break;
            default:
                cout << "Invalid operation. Please try again." << endl;
        }
    }

    return 0;
}
