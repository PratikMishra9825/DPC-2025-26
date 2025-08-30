#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while(b!=0) {
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
long long lcm(int a, int b) {
    return(1LL * a * b) / gcd(a, b);  
}
int main() {
    int n, m;
    cout<<"Enter two numbers:";
    cin>>n>>m;
    cout<<"LCM of "<<n<<" and "<<m<<" is "<<lcm(n, m)<<endl;
    return 0;
}
