#include <iostream>
#include <math.h>
using namespace std;

double cal(double num)
{
    return num * num - 7;
}
int main()
{
    double x0 = 2, x1 = 2.75, x2;
    double err = 1;
    int count = 1;
    while (err > 0.000001)
    {
        x2 = x1 - (cal(x1) * (x1 - x0)) / (cal(x1) - cal(x0));
        err = abs(x2 - x1);
        x0 = x1;
        x1 = x2;
        cout << "Iteration " << fixed << count++ << " : " << x2 << endl;
    }
}