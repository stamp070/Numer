#include <iostream>
using namespace std;
#include <math.h>
double cal(double num)
{
    return num * num - 7;
}
double caldif(double num)
{
    return 2 * num;
}
int main()
{
    double err = 1;
    double x0 = 2, x1;
    int count = 1;
    while (err > 0.000001)
    {
        x1 = x0 - (cal(x0) / caldif(x0));
        err = abs(x1 - x0);
        x0 = x1;
        cout << "Iteration " << fixed << count++ << " : " << x1 << endl;
    }
}