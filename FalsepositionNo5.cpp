#include <iostream>
#include <cmath>
using namespace std;
double cal(double x, double expo, double num);
int main()
{
    int x, count = 1;
    double n, xm, xl, xr;
    cin >> x >> n >> xl >> xr;
    double error = 0.000001, ans = pow(x, 1 / n);
    for (double i = xl; i <= xr; i += 0.1)
    {
        xm = (xl * cal(xr, n, x) - xr * cal(xl, n, x)) / (cal(xr, n, x) - cal(xl, n, x));
        if (cal(xm, n, x) * cal(xr, n, x) > 0)
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
    cout << "Actual Ans : " << ans << endl;
    cout << "Iteration " << count++ << "(ans) = " << fixed << xm << endl;
}
double cal(double x, double expo, double num)
{
    return pow(x, expo) - num;
}