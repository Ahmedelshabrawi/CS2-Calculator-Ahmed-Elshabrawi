
#include <string>

double addition(double num1, double num2);
double subtraction(double num1,double num2);
double multiplication(double num1, double num2 );
double division(double num1 ,double num2);
int factorial (int num);
int gcd(int num1,int num2);
int lcm (int num1,int num2);
int random(int num1, int num2);
//BONUS PART
double evaluateExpression(const std::string& expression);
double addsub(const std::string& expression, size_t& index);
double multdiv(const std::string& expression, size_t& index);
double numpar(const std::string& expression, size_t& index);
