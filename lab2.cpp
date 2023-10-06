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
    {
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
    }
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
    {
        int center = size/2;
        if (size % 2 == 1)
        {
            center++;
        }
        if(size == 1)
        {
            center = 1;
        }
        int cycles_count = center;
        arr[arr_counter] = matrix[center][center];
        cout <<"center:" <<  arr[arr_counter] << "\n";
        arr_counter++;
            int bottom = 1, top = 1, right = 1, left = 1;  
            for(int g = 1; g <= cycles_count+1; g++)
            {
                cout << "Top:\n";
                for(int top_count = 0; top_count < g*3-1; top_count++)
                {
                    arr[arr_counter] = matrix[center-top][center-g+top_count];
                    cout << arr[arr_counter] << " ";
                    arr_counter++;
                    if (top_count == size)
                        top_count = g*3+1;
                }
                top++;
                cout << "\nright:\n";
                 for(int right_count = 0; right_count < g*3-1; right_count++)
                {
                    arr[arr_counter] = matrix[center-g+right_count][center+right];
                    cout << arr[arr_counter] << " ";
                    arr_counter++;
                    if (right_count == size)
                        right_count = g*3+1;
                }
                right++;
                cout << "\nbottom:\n";
                for(int bottom_count = 0; bottom_count < g*3-1; bottom_count++)
                {
                    arr[arr_counter] = matrix[center+bottom][center+g-bottom_count];
                    cout << arr[arr_counter] << " ";
                    arr_counter++;
                    if (bottom_count == size)
                        bottom_count = g*3;
                }
                bottom++;
                cout << "\nleft:\n";
                 for(int left_count = 0; left_count < g*3-1; left_count++)
                {
                    arr[arr_counter] = matrix[center+g-left_count][center-left];
                    cout << arr[arr_counter] << " ";
                    arr_counter++;
                    if (left_count == size)
                        left_count = g*3;
                }
                left++;
                cout << "\n\n";
        }
        cout <<"\n";
        break;
    }
    case 3:
        {
        for(int i = 0; i <=size; i++)
        {
            int temp;
            for (int j = 0; j <= i; j++)
            {
                arr[arr_counter] = matrix[i][j];
                cout << arr[arr_counter] << " ";
                arr_counter++;
                temp = j;
            }
            for (int f = temp; f >0;f--)
            {
                arr[arr_counter] = matrix[i-f][i];
                cout << arr[arr_counter] << " ";
            }
            cout << "\n";
        }
        cout <<"\n";
        break;
    }
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
    delete[] mass;
}