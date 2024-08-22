#include <iostream>
using namespace std;
#define size 3
void printArray(double arry[size][size + 1]);
int main()
{
    double arry[size][size + 1] = {{-2, 3, 1, 9},
                                   {3, 4, -5, 0},
                                   {1, -2, 1, -4}};

    for (int i = 0; i < size; i++)
    {
        double temp = arry[i][i];
        for (int j = 0; j < size + 1; j++)
        {
            arry[i][j] /= temp;
        }

        for (int check = i + 1; check < size; check++)
        {
            double tempnext = arry[check][i];
            for (int j = 0; j < size + 1; j++)
            {
                arry[check][j] -= arry[i][j] * tempnext;
            }
            cout << "Mattrix : " << endl;
            printArray(arry);
        }
    }

    for (int i = size - 1; i >= 0; i--)
    {
        for (int check = i - 1; check >= 0; check--)
        {
            double tempnext = arry[check][i];
            for (int j = 0; j < size + 1; j++)
            {
                arry[check][j] -= arry[i][j] * tempnext;
            }
            cout << "Mattrix : " << endl;
            printArray(arry);
        }
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
void printArray(double arry[size][size + 1])
{
    for (int j = 0; j < size; j++)
    {
        for (int k = 0; k < size + 1; k++)
        {
            cout << arry[j][k] << " ";
        }
        cout << endl;
    }
}