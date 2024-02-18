#include <iostream>
using namespace std;

void printShiftedTriangle (int n, int m, char symbol);
void printPineTree (int n, char symbol);

int main () {
 int triangles;
 char symbol;
 cout << "Enter the number of triangles in the tree. Then, enter the character.";
 cin >> triangles;
 cin >> symbol;
 printPineTree(triangles, symbol);

 return 0;
}

void printShiftedTriangle (int n, int m, char symbol)
{
    for(int k;k < n; k++)
    {
        for (int i = 0; i < (n - (k+1))+ m; i++)
        {
            cout << ' ';
        }
        
        for (int l = 0; l < (2*k)+1; l++)
        {
            cout << symbol;
        }
        
        cout << endl;
    }
    return;
}

void printPineTree(int n, char symbol)
{
    for (int k = 1; k <= n; k++)
    {   
        cout << "this loop only works if I type a sentence here";
        printShiftedTriangle((k+1), (n-k), symbol);   
    }
    return;
}