#include<iostream>
#include <cstdlib>
using namespace std;

int **genRandomMatrix(int **matrix, int size)
{
    for(int i = 0;i <= size; i++)
    {
        matrix[i] = new int[size];

    }
    cout << "Сгенерированная матрица: " << "\n";
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
        cout << "Задание 1. по правым диагоналям"<< "\n";
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
        }
        cout <<"\n";
        break;
    }
    case 1:
    cout << "Задание 1. по левым диагоналям"<< "\n";
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
        }
        cout <<"\n";
        break;
    case 2:
    {
        cout << "Задание 3. по спирали с центрального элемента"<< "\n";
        int center = size/2;
        bool the_last_circle;
        if (size % 2 == 0)
        {
            center++;
            the_last_circle = false;
        }
        else   
            the_last_circle = true;
        if(size == 1)
        {
            center = 1;
        }
        int numbers = 3;
        int cycles_count = center;
        arr[arr_counter] = matrix[center][center];
        cout << arr[arr_counter] << "\n";
        arr_counter++;
            int bottom = 1, top = 1, right = 1, left = 1;  
            for(int g = 1; g <= cycles_count+1; g++)
            {
                for(int top_count = 0; top_count < numbers; top_count++)
                {
                    arr[arr_counter] = matrix[center-top][center-top+top_count];
                    cout << arr[arr_counter] << " ";
                    arr_counter++;
                    if (top_count == size)
                        top_count = numbers;
                }
                top++;
                 for(int right_count = 0; right_count < numbers; right_count++)
                {
                    arr[arr_counter] = matrix[center-right+right_count][center+right];
                    cout << arr[arr_counter] << " ";
                    arr_counter++;
                    if (right_count == size)
                        right_count = numbers;
                }
                right++;
                for(int bottom_count = 0; bottom_count < numbers; bottom_count++)
                {
                    arr[arr_counter] = matrix[center+bottom][center+bottom-bottom_count];
                    cout << arr[arr_counter] << " ";
                    arr_counter++;
                    if (bottom_count == size)
                        bottom_count = numbers;
                }
                bottom++;
                 for(int left_count = 0; left_count < numbers; left_count++)
                {
                    arr[arr_counter] = matrix[center+left-left_count][center-left];
                    cout << arr[arr_counter] << " ";
                    arr_counter++;
                    if (left_count == size)
                        left_count = numbers;
                }
                left++;
                numbers = numbers + 2;
                cout << "\n\n";
                if(numbers > size)
                {
                    switch (the_last_circle)
                    {
                        case true:
                 for(int right_count = 0; right_count < numbers; right_count++)
                {
                    arr[arr_counter] = matrix[center-right+right_count+1][center+right];
                    cout << arr[arr_counter] << " ";
                    arr_counter++;
                    if (right_count == size)
                        right_count = numbers;
                }
                right++;
                                for(int bottom_count = 0; bottom_count < numbers; bottom_count++)
                {
                    arr[arr_counter] = matrix[center+bottom][center+bottom-bottom_count];
                    cout << arr[arr_counter] << " ";
                    arr_counter++;
                    if (bottom_count == size)
                        bottom_count = numbers;
                }
                bottom++;
                        break;
                        case false:
                 for(int left_count = 0; left_count < numbers; left_count++)
                {
                    arr[arr_counter] = matrix[center+left-left_count-1][center-left];
                    cout << arr[arr_counter] << " ";
                    arr_counter++;
                    if (left_count == size)
                        left_count = numbers;
                }
                left++;
                for(int top_count = 0; top_count < numbers; top_count++)
                {
                    arr[arr_counter] = matrix[center-top][center-top+top_count+1];
                    cout << arr[arr_counter] << " ";
                    arr_counter++;
                    if (top_count+1 == size)
                        top_count = numbers;
                }
                top++;
                        break;
                    }
                    g = cycles_count+2;
                }
        }
        cout <<"\n";
        break;
    }
    case 3:
    cout << "Заданиt 4. по спирали с леовго верхнего элемента"<< "\n";
        {
        for(int i = 0; i <size; i++)
        {
            int temp;
            for (int j = 0; j <= i; j++)
            {
                arr[arr_counter] = matrix[i][j];
                cout << arr[arr_counter] << " ";
                arr_counter++;
                temp = j;
            }
            for (int f = temp-1; f >= 0;f--)
            {
                arr[arr_counter] = matrix[f][i];
                cout << arr[arr_counter] << " ";
            }
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
    return 0;
}