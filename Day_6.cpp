#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    vector<int> arr = {1, 2, -3, 3, -1, 2};
    int n = arr.size();
    unordered_map<int, vector<int>> m;
    vector<pair<int,int>>ans;

    int prefixSum = 0;
    for(int i=0; i<n; i++) {
        prefixSum+=arr[i];
        
        if(prefixSum==0) {
            ans.push_back({0, i});
        }

        if(m.find(prefixSum)!=m.end()) {
            for (int start : m[prefixSum]) {
                ans.push_back({start + 1, i});
            }
        }

        m[prefixSum].push_back(i);
    }

    for (auto &p : ans) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    return 0;
}
