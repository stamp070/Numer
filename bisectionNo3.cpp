#include <iostream>
#include <cmath>
using namespace std;
double equation(double xm, double expo, double num);
int main()
{
    int x, count = 1;
    double n, xl, xr, xm;
    cin >> x >> n >> xl >> xr;
    double error = 0.000001, ans = pow(x, 1 / n);
    for (double i = xl; i <= xr; i += 0.01)
    {
        xm = (xl + xr) / 2;

        if (equation(xm, n, x) * equation(xr, n, x) > 0)
        {
            xr = xm;
        }
        else
        {
            xl = xm;
        }

        // check
        if (xm < ans + error && xm > ans - error)
        {
            break;
        }
        cout << "Iteration " << count++ << " = " << fixed << xm << endl;
    }

    cout << "Actual Ans: " << ans << endl;
    cout << "Iteration " << count++ << " (ans) = " << fixed << xm << endl;

    return 0;
}
double equation(double xm, double expo, double num)
{
    return pow(xm, expo) - num;
}