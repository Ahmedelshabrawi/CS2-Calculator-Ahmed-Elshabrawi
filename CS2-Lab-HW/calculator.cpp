
double addition(double num1, double num2)
{
    return num1+num2;
}
double subtraction(double num1,double num2)
{
    return num1-num2;
}
double multiplication(double num1, double num2 )
{
    return num1*num2;
}
double division(double num1 ,double num2)
{
    return num1/num2;
}
int factorial (int num);
{
    if (num==1 )
        return 1
    else
        return num*factorial(num-1);
}
int gcd(int num1, int num2 )
{
    if (num2 !=0)
        return gcd(num1,num1 %num2 )
    else
        return num1;
}
int random(int min, int max )
{
    int r;
    int num;
    num=max-min+1;
    r=min+ rand()%num;
    return r;
}
int lcm(int x, int y)
{
        return (x / gcd(x, y)) * y;
}

