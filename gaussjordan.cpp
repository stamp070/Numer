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

    for (int i = 2; i >= 0; i--)
    {
        for (int check = i - 1; check >= 0; check--)
        {
            double temp = arry[check][i];
            double tempnext = arry[i][i];
            cout << "temp: " << temp << " tempnext: " << tempnext << endl;
            for (int j = 3; j >= 0; j--)
            {
                arry[check][j] /= temp;
                arry[check][j] *= tempnext;

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
    for (int i = 0; i < size; i++)
    {
        double temp = arry[i][i];
        arry[i][i] /= temp;
        arry[i][size] /= temp;
    }
    for (int j = 0; j < size; j++)
    {
        for (int k = 0; k < size + 1; k++)
        {
            if (k == size)
            {
                cout << "ans : " << arry[j][k] << endl;
            }
            else
            {
                cout << arry[j][k] << " ";
            }
        }
    }
}