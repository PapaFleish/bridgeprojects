#include<iostream>
#include<string>
using namespace std;

const int ALPHABET = 26;
typedef char* charPointer;
typedef int* intPointer;

void unifySentence (string &str, int &startCount);
void lowerCase (string &str);
void letterCount (string str, char letArr[], int uniqueNumArr[], int startCount);
bool newLetter(string str, int currentSpot);
bool anagram(int uniqueNumArr[], int uniqueNumArrDos[]);

int main (){

    string inputOne, inputTwo;
    char letArr[26];
    int startPointOne, startPointTwo, numArrOne[26] = {0}, numArrTwo[26] = {0};

    cout << "please enter your first text:\n";
    getline(cin, inputOne);
    unifySentence(inputOne, startPointOne);
    lowerCase(inputOne);
    letterCount(inputOne, letArr, numArrOne, startPointOne);

    cout << "please enter your second text\n";  
    getline(cin, inputTwo);
    unifySentence(inputTwo, startPointTwo);
    lowerCase(inputTwo);  
    letterCount(inputTwo, letArr, numArrTwo, startPointTwo);

    if (anagram(numArrOne, numArrTwo) == true)
        cout << "yeah they palindromes";
    else
        cout << "nah they not anagram or whatever";

    return 0;
}


void unifySentence (string &str, int &startCount)
{
    int garbageCount = 0, temp;
    
    for (int index = 0; index < str.length(); index++)
    {
        if (str.at(index) >= 'A' && str.at(index) <= 'z')
        {
            continue;
        }
        else
        {
            temp = str.at(index);
            str.at(index) = str.at(garbageCount);
            str.at(garbageCount) = temp;
            garbageCount++;
        }
    } 

    startCount = garbageCount;

    return;
}

void lowerCase (string &str)
{
    for (int index = 0; index < str.length(); index++)
    {
        if (str.at(index) >= 'A' && str.at(index) <= 'Z')
        {
            str.at(index) = str.at(index) + 32;
        }
    }

    return;
}

bool newLetter(string str, int currentSpot)
{
    for (int i; i < currentSpot; i++)
    {
        if (str.at(i) == str.at(currentSpot))
            return false;
        else    
            continue;
    }

    return true;
}

void letterCount(string str, char letArr[], int uniqueNumArr[], int startCount)
{
    int index = startCount;
    int charIndex = 0, intIndex = 0;
    intPointer numArr = uniqueNumArr;
   
    for (index; index < str.length(); index++)
    {
        if (str.at(index) >= 'A' && str.at(index) <= 'z')
        {
            if (newLetter(str, index) == true)
            {
                letArr[charIndex] = str.at(index);
                numArr[intIndex] = 1;
                charIndex++;
                intIndex++;
            }
            else
            {
                for(int j = 0; j < charIndex; j++)
                {
                    if (str.at(index) == letArr[j])
                    {
                        numArr[j]++;
                    }
                    else
                        continue;
                }
            }
        }
        else
            continue;
    }

     numArr[intIndex] = 80085; //needed later down the line

}

bool anagram(int uniqueNumArr[], int uniqueNumArrDos[])
{
    for(int index = 0; index < 26; index++)
    {
        if (uniqueNumArr[index] == uniqueNumArrDos[index])
            continue;
        else
            return false;
    }

    return true;
}