#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int>A={16, 17, 4, 3, 5, 2};
    vector<int>ans;
    int n=A.size();

    int maxRight=A[n-1];
    ans.push_back(maxRight); 

    for(int i = n-2; i >= 0; i--) {
        if (maxRight<=A[i]) {
            ans.push_back(A[i]);
            maxRight= A[i];
        }
    }

    for(int i=ans.size()-1; i>=0; i--) {
        cout<<ans[i]<< " ";
    }
    cout<<endl;
    return 0;
}
