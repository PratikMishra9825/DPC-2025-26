#include <iostream>
#include<vector>
#include <string>
using namespace std;

void helper(string &s, vector<bool> &used, string &current, vector<string> &result) {
    if(current.size()==s.size()) {
        result.push_back(current);
        return;
    }
    for(int i=0; i<s.size(); i++) {
        if(used[i]) continue;
        if(i>0 && s[i]==s[i-1] && !used[i-1]) 
        continue;
        used[i] = true;
        current.push_back(s[i]);
        helper(s, used, current, result);
        current.pop_back();
        used[i]=false;
    }
}
vector<string> permutation(string s) {
    vector<string>result;
    sort(s.begin(), s.end()); 
    vector<bool>used(s.size(), false);
    string current;
    helper(s, used, current, result);
    return result;
}

int main() {
    string s="abc";
    vector<string>permutations=permutation(s);
    cout << "All unique permutations are:\n";
    for (auto &p : permutations) {
        cout<<p<<"\n";
    }
    return 0;
}
