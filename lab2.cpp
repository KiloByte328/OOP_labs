#include<iostream>
#include <cstdlib>
using namespace std;

int **genRandomMatrix(int **matrix, int size)
{
        for(int i = 0;i <= size; i++)
    {
        matrix[i] = new int[size];

    }
    for (int i = 0; i <= size; i++)
    {
        for(int j = 0; j <= size; j++)
        {
            matrix[i][j] = rand();
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    return matrix;
};

void MatrixToArray(int **matrix, int *arr, int size, int type)
{
    int inner = size;
    int arr_counter = 0;
    switch (type)
    {
    case 0:
        for (int i = 0; i <= size; i++)
        {
            int f = i;
            for(int j = size; j >= 0; j--, i--)
            {
                if (i >= 0)
                {
                arr[arr_counter] = matrix[i][j];
                cout << arr[arr_counter] << " ";
                arr_counter++;
                }
            }
            i = f;
            cout << "\n";
        }
        cout <<"\n";
        break;
    case 1:
        for (int i = 0; i <= size; i++)
        {
            int v = i;
            for(int j = 0; j <= size; j++, i--)
            {
                if (i >= 0)
                {
                arr[arr_counter] = matrix[i][j];
                cout << arr[arr_counter] << " ";
                arr_counter++;
                }
            }
            i = v;
            cout << "\n";
        }
        cout <<"\n";
        break;
    case 2:
        int middle;
        middle = size/2;
        for(int i = size/2; i < size*size; i++)
        {
 //           arr[i] = ;
        }
        cout <<"\n";
        break;
    case 3:
        
        for(int i = 0; i <=size; i++)
        {

        }
        cout <<"\n";
        break;
    }

};

int main()
{
    int n;
    cout<<"Print matrix range: ";
    cin>>n;
    if (n <= 0)
    {
        cout << "Matrix cant be that range, try again";
        cin>>n;
    }
    n=n--;
    int **new_matrix = new int*[n]{};
    int *mass = new int[n]{};
    genRandomMatrix(new_matrix, n);
    cout <<"\n";
    for(int i = 0; i <= 3; i++)
    {
        MatrixToArray(new_matrix, mass, n, i);
    }
    for (int i = 0; i <= n; i++)
    {
        delete[] new_matrix[i];
    }
    delete[] new_matrix;
}