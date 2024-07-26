#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
double cal(double x);
int main()
{
    cout << setprecision(6);
    double xNew;
    double xOld = cal(1);
    double err;
    int count = 1;
    for (int i = 2; i <= 4; i += 0.1)
    {
        xNew = cal(xOld);
        err = abs(xNew - xOld);

        cout << "i " << count++ << " : " << fixed << xNew << endl;
        if (err < 0.000001)
        {
            break;
        }
        xOld = xNew;
    }
}
double cal(double x)
{

    double y = 1.0 / 2 * (7.0 / x + x);
    return y;
}
