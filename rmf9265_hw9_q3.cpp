#include <iostream>
using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);

int main () {

    int arrSize = 5, outPosArrSize = 0;
    int originalArray[arrSize] = {3, -1, 0, 6, 4};
    int* newArrayPointer;
    int* outPosArrSizePtr, **outPosArrPtr;
    outPosArrSizePtr = &outPosArrSize;
    outPosArrPtr = &newArrayPointer;

    //newArrayPointer = getPosNums2(originalArray, arrSize, outPosArrSizePtr);
    //getPosNums3(originalArray, arrSize, newArrayPointer, outPosArrSize);

    //p2
    /*for (int index = 0; index < *outPosArrSizePtr; index++)
    {
        cout << newArrayPointer[index] << "\t";
    }*/

    //p3
    /*for (int index = 0; index < outPosArrSize; index++)
    {
        cout << newArrayPointer[index] << "\t";
    }
    return 0;*/

    getPosNums4(originalArray, arrSize, outPosArrPtr, outPosArrSizePtr);

    for (int index = 0; index < outPosArrSize; index++)
    {
        cout << newArrayPointer[index] << "\t";
    }
    return 0;
    

}


int* getPosNums1(int* arr, int arrSize, int& outPosArrSize)
{
    int* newArray;
    int newIndex = 0;
    outPosArrSize = 0;

    for (int index = 0; index < arrSize; index++)
    {
        if (arr[index] > 0)
        { 
            outPosArrSize++;
        }
    }

    newArray = new int[outPosArrSize];
    
    for (int index = 0; index < arrSize; index++)
    {
        if (arr[index] > 0)
        { 
            *(newArray + newIndex) = arr[index];
            newIndex++;
        }
    }

    return newArray;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr)
{
    int* newArray;
    int newIndex = 0;
    int outPosArrSize = 0;

    for (int index = 0; index < arrSize; index++)
    {
        if (arr[index] > 0)
        { 
            outPosArrSize++;
        }
    }

    newArray = new int[outPosArrSize];
    
    for (int index = 0; index < arrSize; index++)
    {
        if (arr[index] > 0)
        { 
            *(newArray + newIndex) = arr[index];
            newIndex++;
        }
    }

    *outPosArrSizePtr = newIndex;

    return newArray; 
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize)
{
    int* newArray;
    int newIndex = 0;
    outPosArrSize = 0;

    for (int index = 0; index < arrSize; index++)
    {
        if (arr[index] > 0)
        { 
            outPosArrSize++;
        }
    }

    newArray = new int[outPosArrSize];
    
    for (int index = 0; index < arrSize; index++)
    {
        if (arr[index] > 0)
        { 
            *(newArray + newIndex) = arr[index];
            newIndex++;
        }
    }

    outPosArr = newArray;
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr)
{
    int* newArray;
    int newIndex = 0;
    int outPosArrSize = 0;

    for (int index = 0; index < arrSize; index++)
    {
        if (arr[index] > 0)
        { 
            outPosArrSize++;
        }
    }

    newArray = new int[outPosArrSize];
    
    for (int index = 0; index < arrSize; index++)
    {
        if (arr[index] > 0)
        { 
            *(newArray + newIndex) = arr[index];
            newIndex++;
        }
    }

    *outPosArrSizePtr = newIndex;
    *outPosArrPtr = newArray;
}