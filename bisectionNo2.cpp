#include <iostream>
#include <cmath>

using namespace std;
double equation(double num);
int main()
{
    double xl = 1.5, xr = 2.0, xm;
    double error = 0.000001, ans = pow(13, 1 / 4.0);
    int count = 1;
    for (int i = 0; i < 4; i += 0.1)
    {
        xm = (xl + xr) / 2;

        if (equation(xm) * equation(xr) > 0)
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
    // fixed คือไม่ปัดทศนิยม
    cout << "Actual Ans : " << fixed << ans << endl;
    cout << "Iteration " << count++ << " (ans) = " << fixed << xm << endl;

    return 0;
}
double equation(double num)
{
    return pow(num, 4) - 13;
}