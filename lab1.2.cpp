#include<iostream>
using namespace std;

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
    for (int i = 0; i < size; i++)
    {
    genRandArray(size, maxValue);
    }

};
void printMatrix(int** matrix)
{
    
};


int main()
{
    int size=rand()%10;
    int maxValue = 100;
    int** matrix = genRandMatrix(size, maxValue);
    printMatrix(matrix);
//очистка памяти
}