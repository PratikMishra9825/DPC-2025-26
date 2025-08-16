#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int>arr= {1,2,4,5};
    int n=arr.size()+1;
    int currSum=0;

    for(int i=0; i<=arr.size()-1; i++) {
        currSum+=arr[i];
    }

    int actualSum=n*(n+1)/2;
    int missingNo=actualSum-currSum;
    cout<<"The Missing no is :"<<missingNo<<endl;
    return 0;
}
