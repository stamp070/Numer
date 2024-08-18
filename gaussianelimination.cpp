#include <iostream>
using namespace std;
#define size 3
int main()
{
    double arry[size][size + 1] = {{-2, 3, 1, 9},
                                   {3, 4, -5, 0},
                                   {1, -2, 1, -4}};

    for (int i = 0; i < size - 1; i++)
    {
        for (int check = i + 1; check < size; check++)
        {
            double temp = arry[i][i];
            double tempnext = arry[check][i];
            cout << "temp: " << temp << " tempnext: " << tempnext << endl;
            for (int j = 0; j < size + 1; j++)
            {
                arry[i][j] /= temp;
                arry[i][j] *= tempnext;

                arry[check][j] -= arry[i][j];
            }
            for (int j = 0; j < size; j++)
            {
                for (int k = 0; k < size + 1; k++)
                {
                    cout << arry[j][k] << " ";
                }
                cout << endl;
            }
        }
    }
    double ans[size];
    // for (int i = 2; i >= 0; i--)
    // {
    //     for (int j = 0; j < size; j++)
    //     {
    //         ans[i] += arry[i][j] * arry[i][size];
    //     }
    // }
    double x3 = arry[2][3] / arry[2][2];
    double x2 = (arry[1][3] - arry[1][2] * x3) / arry[1][1];
    double x1 = (arry[0][3] - arry[0][1] * x2 - arry[0][2] * x3) / arry[0][0];
    cout << "x1 : " << x1 << "\nx2 : " << x2 << "\nx3 : " << x3 << endl;
}