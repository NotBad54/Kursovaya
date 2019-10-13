#include "op.h"

long long int fact(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    return n * fact(n - 1);
}
double op_plus(stack<double>& s)
{
    double a, b;
    a = s.top();
    s.pop();
    b = s.top();
    s.pop();
    return a + b;
}
double op_minus(stack<double>& s)
{
    double a, b;
    a = s.top();
    s.pop();
    b = s.top();
    s.pop();
    return b - a;
}
double op_mul(stack<double>& s)
{
    double a, b;
    a = s.top();
    s.pop();
    b = s.top();
    s.pop();
    return a * b;
}
double op_div(stack<double>& s)
{
    double a, b;
    a = s.top();
    s.pop();
    b = s.top();
    s.pop();
    return b / a;
}
double op_deg(stack<double>& s)
{
    double a, b;
    a = s.top();
    s.pop();
    b = s.top();
    s.pop();
    return pow(b, a);
}
double op_opposite(stack<double>& s)
{
    double a;
    a = s.top();
    s.pop();
    return -a;
}
double op_factorial(stack<double>& s)
{
    double a;
    a = s.top();
    s.pop();
    return fact(a);
}
double op_odiv(stack<double>& s)
{
    long long a, b;
    a = s.top();
    s.pop();
    b = s.top();
    s.pop();
    return b % a;
}
double op_and(stack<double>& s)
{
    double a, b;
    a = s.top();
    s.pop();
    b = s.top();
    s.pop();
    return a && b;
}
double op_or(stack<double>& s)
{
    double a, b;
    a = s.top();
    s.pop();
    b = s.top();
    s.pop();
    return a || b;
}
double op_not(stack<double>& s)
{
    double a;
    a = s.top();
    s.pop();
    return !a;
}
double op_sin(stack<double>& s)
{
    double a;
    a = s.top();
    s.pop();
    return sin(a);
}
double op_cos(stack<double>& s)
{
    double a;
    a = s.top();
    s.pop();
    return cos(a);
}
double op_tan(stack<double>& s)
{
    double a;
    a = s.top();
    s.pop();
    return tan(a);
}
double op_asin(stack<double>& s)
{
    double a;
    a = s.top();
    s.pop();
    return asin(a);
}
double op_acos(stack<double>& s)
{
    double a;
    a = s.top();
    s.pop();
    return acos(a);
}
double op_atan(stack<double>& s)
{
    double a;
    a = s.top();
    s.pop();
    return atan(a);
}