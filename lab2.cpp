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
    int diagonal = 0;
    int arr_count = 0;
    switch (type)
    {
    case 0:
    for(int i = 0; i <= size*size; i++)
    {
        
    }
/*    for (int i = 0; i <= size*size; i++)
    {
        arr[i] = matrix[i][size-i];
    }*/
/*    for (int i = 0; i <= size; i++)
        {
            for (int j = size; (diagonal+i) >= size; j = j--)
            {  
                arr[arr_count] = matrix[i][j];
                cout << arr[arr_count] << " ";
                if (arr_count <= size)
                arr_count = arr_count + 1;
            }
            arr_count = 0;
            cout << "\n";
        }*/
        cout <<"\n";
        break;
    case 1:
    for (int i = 0; i <= size; i++)
        {
            for (int j = 0; j <= i; j++)
            {  
                arr[j] = matrix[i][j];
                cout << arr[j] << " ";
            }
            cout << "\n";
        }
        cout <<"\n";
        break;
    case 2:
        for(int i = size/2; i < size*size; i++)
        {
 //           arr[i] = ;
        }
        cout <<"\n";
        break;
    case 3:

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