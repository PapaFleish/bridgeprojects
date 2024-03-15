#include<iostream>
#include<string>
using namespace std;

const int ALPHABET = 26;
typedef char* charPointer;
typedef int* intPointer;

int wordCount (string str);
void lowerCase (string &str);
void letterCount (string str);
bool newLetter(string str, int currentSpot);

int main (){

    string inputSentence;

    cout << "please enter a line of text:\n";

    getline(cin, inputSentence);
    lowerCase(inputSentence);    
    cout << wordCount(inputSentence) << "\t" << "words\n";
    letterCount(inputSentence);

    return 0;
}


int wordCount (string str)
{
    int index = 0, wordCount = 1;

    //might expand section to skip white spaces at start
    for (index; index < str.length(); index++)
    {
        if (str.at(index) == '\n' || str.at(index) == ' ')
        {
            wordCount++;
        }
        else
        {
            continue;
        }
    } 

    return (wordCount);
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

void letterCount(string str)
{
    int index = 0;
    int charIndex = 0, intIndex = 0;
    charPointer letArr;
    intPointer numArr;
    letArr = new char [26];
    numArr = new int [26];

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

    for (int l = 0; l < charIndex; l++)
    {
        cout << numArr[l] << "\t" << letArr[l] << endl; 
    }
}
