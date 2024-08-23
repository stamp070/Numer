#include <iostream>
using namespace std;
#define size 3
void printMatrix(double matrix[size][size]);
void printArray1d(double ans[size]);
int main()
{
    int A[size][size] = {
        {-2, 3, 1},
        {3, 4, -5},
        {1, -2, 1}};
    int arry2[size] = {9, 0, -4};
    double L[size][size];
    double U[size][size];
    // set 0
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            L[i][j] = 0;
            U[i][j] = 0;
        }
    }

    for (int i = 0; i < size; i++)
    {

        for (int k = i; k < size; k++)
        {
            double sum = 0;
            for (int j = 0; j < i; j++)
            {
                sum += (L[k][j] * U[j][i]);
            }
            L[k][i] = A[k][i] - sum;
        }

        for (int k = i; k < size; k++)
        {
            if (i == k)
                U[i][i] = 1; // matrix U ตรงกลางเป็น 1
            else
            {
                double sum = 0;
                for (int j = 0; j < i; j++)
                {
                    sum += (L[i][j] * U[j][k]);
                }
                U[i][k] = (A[i][k] - sum) / L[i][i];
            }
        }
    }
    cout << "Lower Triangular Matrix L:\n";
    printMatrix(L);
    cout << "\nUpper Triangular Matrix U:\n";
    printMatrix(U);

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
            sum += U[i][j] * X[j];
        }
        X[i] = (Y[i] - sum) / U[i][i];
    }
    cout << "X : ";
    printArray1d(X);
    return 0;
}
void printMatrix(double matrix[size][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << matrix[i][j] << " ";
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