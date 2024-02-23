//Ryan Fleishman Tandon Bridge HW6 Q3
//approximates the value of e when using the sum of the first (input+1) addends of the infinite definition of e

#include <iostream>
using namespace std;

double eApprox(int n);
// input - an integer
// approximates the value of e when using the sum of the first (input+1) addends of the infinite definition of e

int main() {

    cout.precision(30);
    for (int n = 1; n <= 15; n++) {
    cout<<"n = "<<n<<'\t'<<eApprox(n)<<endl;
    }
    return 0;

}

double eApprox(int n)
{
    double nextAddend = 1, iterator = 1, totalsum = 1;

    while (n > 0)
    {
        totalsum = totalsum + nextAddend;
        nextAddend = nextAddend * (1 / ++iterator);
        n--;
    }
    
    return (totalsum);
}