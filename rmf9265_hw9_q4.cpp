#include <iostream>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);
void findMin(int arr[], int start, int length);

int main () {
    int arrayOfIntegers[14] = {55, 22, 99, 11, 53, 20, 91, 132, 929, 24, 1, 5, 6, 16};
    int logicalSize = 14;

    oddsKeepEvensFlip(arrayOfIntegers, logicalSize);

    for (int index = 0; index < logicalSize; index++)
    {
        cout << arrayOfIntegers[index] << " ";
    }

    return 0;
}


//if the minimum comes later, it's always setting to that

void findMin(int arr[], int start, int length)
{
    int temp;
    for(int index = start; index < length; index++)
    {
        if (arr[index] < arr[start])
        {
            temp = arr[start];
            arr[start] = arr[index];
            arr[index] = temp;
        }
        else
        {
            continue;
        }
    }
}


void oddsKeepEvensFlip(int arr[], int arrSize)
{
    int *arrayPtr = arr, oddIndex = 0, evenindex = 0, minEven = 80085, minIndex = 0;
    int *evenPointer = new int [arrSize];

    for(int index = 0; index < arrSize; index++)
    {
        if (arr[index] % 2 != 0)
        {
            arrayPtr[oddIndex] = arr[index];
            oddIndex++;
        }
        else
        {
            evenPointer[evenindex] = arr[index];
            evenindex++;
        }
    }


    for (int index = 0; index < evenindex; index++)
    {
        findMin(evenPointer, index, evenindex);
    }

    for (int index = 0; index < evenindex; index++)
    {
        *(arrayPtr + oddIndex + index) = evenPointer[index];
    }
}
