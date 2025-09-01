#include <iostream>
#include <cmath>
using namespace std;
int countDiv(int n) {
    int count=0;
    for(int i=1; i<=sqrt(n); i++) {
        if(n%i==0) {
            if(i==n/i)
                count++;
            else
                count+=2;  
        }
    }
    return count;
}

int main() {
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Total divisors:"<<countDiv(n)<<endl;
    return 0;
}
