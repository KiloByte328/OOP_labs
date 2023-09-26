#include<iostream>

int* genRandArray(int size, int maxValue)
{
    int *new_arr = new int[size+1];
    new_arr[0] = size;
    for(int i = 1; i <= size; i++)
    {
        int j = rand()%maxValue;
        new_arr[i] = j;
    }
    return new_arr;
};
void print(int* arr)
{
    std::cout << arr[0] <<":  ";
    for(int i = 1; i <= arr[0]; i++)
    {
        std::cout << arr[i] << " ";
    }
};

int** genRandMatrix(int size, int maxValue)
{
    int** new_matrix = new int*[size+1];
    for (int i = 0; i < size+1; i++)
    {
    new_matrix[i] = genRandArray(size, maxValue);
    }
    new_matrix[0][0] = size;   
    return new_matrix;
};
void printMatrix(int** matrix)
{
    std::cout << matrix[0][0]<<"\n";
    for(int i = 1; i <= matrix[0][0]; i++)
    {
        print(matrix[i]);
        std::cout<<"\n";
    }
};


int main()
{
    int size=rand()%10;
    int maxValue = 100;
    int** matrix = genRandMatrix(size, maxValue);
    printMatrix(matrix);
//очистка памяти
    for(int x = 0; x <= size; x++)
    {
        delete[] matrix[x];    
    }
    delete[] matrix;
    return 0;
}
