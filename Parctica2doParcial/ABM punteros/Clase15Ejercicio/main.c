#include <stdio.h>
#include <stdlib.h>

void printArray1(int array[], int len);
void printArray2(int array[], int len);
void printArray3(int* array, int len);
void printArray4(int* array, int len);


int main()
{
    int vector[10]={11,22,33,44,55,66,77,88,99,00};
    printArray1(vector, 10);
    printArray2(vector, 10);
    printArray3(vector, 10);
    printArray4(vector, 10);

    return 0;
}

void printArray1(int array[], int len)
{
    for(int i=0; i<len; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n\n");
}

void printArray2(int array[], int len)
{
    for(int i=0; i<len; i++)
    {
        printf("%d ", *(array+i) );
    }
    printf("\n\n");
}

void printArray3(int* array, int len)
{
    for(int i=0; i<len; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n\n");
}

void printArray4(int* array, int len)
{
    for(int i=0; i<len; i++)
    {
        printf("%d ", *(array+i));
    }
    printf("\n\n");
}

