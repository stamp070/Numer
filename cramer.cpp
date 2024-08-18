#include <iostream>
using namespace std;

double det(int matrix[3][3]);
int main()
{
    int arry[3][3] = {{-2, 3, 1},
                      {3, 4, -5},
                      {1, -2, 1}};
    int b[3] = {9, 0, -4};
    int ans[3];

    for (int i = 0; i < 3; i++)
    {
        int temparry[3][3] = {{-2, 3, 1},
                              {3, 4, -5},
                              {1, -2, 1}};

        for (int j = 0; j < 3; j++)
        {
            temparry[j][i] = b[j];
        }
        for (int j = 0; j < 3; j++)
        {
            cout << "\t";
            for (int k = 0; k < 3; k++)
            {
                cout << temparry[j][k] << " ";
            }
            cout << endl;
        }
        ans[i] = det(temparry) / det(arry);
        cout << "x" << i << " : " << ans[i] << endl;
    }

    return 0;
}
double det(int matrix[3][3])
{
    double det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
    return det;
}