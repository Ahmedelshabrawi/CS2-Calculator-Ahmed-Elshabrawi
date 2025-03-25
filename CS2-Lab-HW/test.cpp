#include <iostream>
 #include "calculator.h"
 #include <string>
 using namespace std;
 int main () {
     double x, y, a=0;
     int main() {
         double x, y;
         int z;
         char ans;
         
         while (true) {
             cout << "Enter the desired operation: +, -, *, /, !, G (for GDC), L (for LCM), R (for random number generation), E (to exit)" << endl;
             cin >> ans;
 
             if (ans == 'E' || ans == 'e') {
                 cout << "Exiting program. Goodbye!" << endl;
                 break;
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
                 case 'G': case 'g'
                     cout << "GCD(" << x << ", " << y << ") = " << gcd(static_cast<int>(x), static_cast<int>(y)) << endl;
                     break;
                 case 'L': case 'l'
                     cout << "LCM(" << x << ", " << y << ") = " << lcm(static_cast<int>(x), static_cast<int>(y)) << endl;
                     break;
                 case 'R': case 'r'
                     cout << "Random number between " << x << " and " << y << ": " << random(static_cast<int>(x), static_cast<int>(y)) << endl;
                     break;
                 default:
                     cout << "Invalid operation. Please try again." << endl;
             }
         }
 
         return 0;
     }
