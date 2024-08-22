#include <iostream>
using namespace std;
#define size 3
void printArray(double arry[size][size]);
int main()
{
    double arry[size][size] = {{-2, 3, 1},
                               {3, 4, -5},
                               {1, -2, 1}};

    double identityMattrix[size][size] = {{1, 0, 0},
                                          {0, 1, 0},
                                          {0, 0, 1}};
    double arry2[size] = {9, 0, -4};

    for (int i = 0; i < size; i++)
    {
        double temp = arry[i][i];
        for (int j = 0; j < size; j++)
        {
            arry[i][j] /= temp;
            identityMattrix[i][j] /= temp;
        }

        for (int check = i + 1; check < size; check++)
        {
            double tempnext = arry[check][i];
            for (int j = 0; j < size; j++)
            {
                arry[check][j] -= arry[i][j] * tempnext;
                identityMattrix[check][j] -= identityMattrix[i][j] * tempnext;
            }
        }
        cout << "First Mattrix : \n";
        printArray(arry);
        cout << "Mattrix Inversion : \n";
        printArray(identityMattrix);
    }

    for (int i = size - 1; i >= 0; i--)
    {
        for (int check = i - 1; check >= 0; check--)
        {
            double tempnext = arry[check][i];
            for (int j = 0; j < size; j++)
            {
                arry[check][j] -= arry[i][j] * tempnext;
                identityMattrix[check][j] -= identityMattrix[i][j] * tempnext;
            }
            cout << "First Mattrix : \n";
            printArray(arry);
            cout << "Mattrix Inversion : \n";
            printArray(identityMattrix);
        }
    }
    cout << "First Mattrix (Last) : \n";
    printArray(arry);
    cout << "Mattrix Inversion (Last) : \n";
    printArray(identityMattrix);

    double ans[size];
    for (int i = 0; i < size; i++)
    {
        ans[i] = 0;
        for (int j = 0; j < size; j++)
        {
            ans[i] += arry2[j] * identityMattrix[i][j];
        }
        cout << "ans : " << ans[i] << endl;
    }
}

void printArray(double arry[size][size])
{
    for (int j = 0; j < size; j++)
    {
        for (int k = 0; k < size; k++)
        {
            cout << arry[j][k] << " ";
        }
        cout << endl;
    }
}