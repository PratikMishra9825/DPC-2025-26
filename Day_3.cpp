#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
    map<int,int> m;
    vector<int>arr= {3,1,3,4,2};
    int result;
    for(int i=0; i<arr.size(); i++) {
        if(m.find(arr[i])!=m.end()) {
            result=arr[i];
            break;
        }
        m[arr[i]]=1;
    }
    cout<<"The Duplicate no is : "<<result<<endl;
    return 0;
}
