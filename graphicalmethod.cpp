#include <iostream>
#include <bits/stdc++.h>
using namespace std;
double equation(double x);
int main()
{
    double y, z;
    for (int i = 0; i <= 10; i++)
    {
        double f = equation(i);
        if (f * equation(i + 1) < 0)
        {
            y = i;
            z = i + 1;
        }
    }
    for (double i = y; i <= z; i += 0.000001)
    {
        double f = equation(i);
        if (f * equation(i + 0.000001) < 0)
        {
            y = i;
            z = i + 0.000001;
        }
    }

    cout << fixed << setprecision(6) << "x: " << (y + z) / 2;
    return 0;
}
double equation(double x)
{
    return 43 * x - 180;
}