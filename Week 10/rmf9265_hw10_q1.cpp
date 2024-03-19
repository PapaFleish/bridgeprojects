/* Implement the function:
string* createWordsArray(string sentence, int& outWordsArrSize)
This function gets a string sentence containing a sentence.
When called, it should create and return a new array (of strings), that contains all the
words in sentence. The function should also update the output parameter,
outWordsArrSize, with the logical size of the new array that was created. */

#include <iostream>
#include <string>
using namespace std;

string* createWordsArray (string inputSentence, int& outWordsArrSize);


int main () {
    string inputSentence, *transitoryPointer;
    int outWordsArrSize;

    cout << "Please enter your sentence: ";
    getline(cin, inputSentence);

    string* wordsArray = createWordsArray(inputSentence, outWordsArrSize); 

    for (int index; index < outWordsArrSize; index++)
    {
        cout << wordsArray[index] << "  ";
    }

    return 0;
}

string* createWordsArray (string inputSentence, int & outWordsArrSize)
{
    int sentenceLength = inputSentence.length();
    int leftMarker = 0, rightMarker = 1;
    outWordsArrSize = 1; // starting at 1 t account for first word my loop will not count for



    for (int index = 0; index < sentenceLength; index++)
    {   
        if (inputSentence.at(index == ' '))
        {
            outWordsArrSize++;
        }
        else
        {
            continue;
        }

    }

    string* wordArrayPtr = new string [outWordsArrSize];
    int wordArrayIndex = 0;

    while (rightMarker < sentenceLength)
    {
        if (inputSentence.at(rightMarker) == ' ' || rightMarker == (sentenceLength-1))
        {
            wordArrayPtr[wordArrayIndex] = inputSentence.substr(leftMarker, (rightMarker - leftMarker + 1));
            wordArrayIndex++;
            leftMarker = rightMarker + 1;
        }
        
        rightMarker++;
    }

    return (wordArrayPtr);
}