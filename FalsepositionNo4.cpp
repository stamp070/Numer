#include <iostream>
#include <cmath>
using namespace std;
double cal(double num);
int main()
{
    double xl = 1.5, xr = 2.0, x;
    double error = 0.000001, ans = pow(13, 1 / 4.0);
    int count = 1;
    for (double i = xl; i <= xr; i += 0.1)
    {
        x = (xl * cal(xr) - xr * cal(xl)) / (cal(xr) - cal(xl));
        if (cal(x) * cal(xr) > 0)
        {
            xr = x;
        }
        else
        {
            xl = x;
        }

        // check
        if (x > ans - error && x < ans + error)
        {
            break;
        }
        cout << "Iteration " << count++ << " = " << fixed << x << endl;
    }
    cout << "Actual Ans : " << fixed << ans << endl;
    cout << "Iteration " << count++ << " (ans) = " << fixed << x << endl;
}
double cal(double num)
{
    return pow(num, 4) - 13;
}