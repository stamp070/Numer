#include <iostream>
#include <math.h>
using namespace std;
#define size 3
void printArray2d(double arry[size][size]);
void printArray1d(double ans[size]);
int main()
{
    int arry1[size][size] =
        {{4, 2, 4},
         {2, 10, 5},
         {4, 5, 9}};
    double arry2[size] = {20, 37, 41};
    double L[size][size];
    double LT[size][size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            L[i][j] = 0;
            LT[i][j] = 0;
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            double sum = 0;

            if (j == i)
            {
                for (int k = 0; k < j; k++)
                {
                    sum += pow(L[j][k], 2);
                }
                L[j][j] = sqrt(arry1[j][j] - sum);
                LT[j][j] = sqrt(arry1[j][j] - sum);
            }
            else
            {
                for (int k = 0; k < j; k++)
                {
                    sum += (L[i][k] * L[j][k]);
                }
                L[i][j] = (arry1[i][j] - sum) / L[j][j];
                LT[j][i] = (arry1[i][j] - sum) / L[j][j];
            }
        }
    }

    cout << "Matrix L :" << endl;
    printArray2d(L);
    cout << "Matrix LT :" << endl;
    printArray2d(LT);

    double Y[size] = {0, 0, 0};
    for (int i = 0; i < size; i++)
    {
        double sum = 0;
        for (int j = 0; j < i; j++)
        {
            sum += L[i][j] * Y[j];
        }
        Y[i] = (arry2[i] - sum) / L[i][i];
    }
    cout << "Y : ";
    printArray1d(Y);

    double X[size] = {0, 0, 0};
    for (int i = size - 1; i >= 0; i--)
    {
        double sum = 0;
        for (int j = i; j < size; j++)
        {
            sum += LT[i][j] * X[j];
        }
        X[i] = (Y[i] - sum) / LT[i][i];
    }
    cout << "X : ";
    printArray1d(X);
}
void printArray2d(double arry[size][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << arry[i][j] << " ";
        }
        cout << endl;
    }
}

void printArray1d(double ans[size])
{
    for (int i = 0; i < size; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}