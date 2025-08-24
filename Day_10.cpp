#include <iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& str) {
    unordered_map<string, vector<string>>mp;
    
    for(string s : str) {
        string key = s;
        sort(key.begin(), key.end()); 
        mp[key].push_back(s);
    }
    vector<vector<string>> result;
    for (auto &entry : mp) {
        result.push_back(entry.second);
    }
    return result;
}
int main() {
    vector<string> str = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = groupAnagrams(str);
    for(auto &group : ans) {
        cout<<"[ ";
        for(auto &word : group) {
            cout<<word<<" ";
        }
        cout<<"]\n";
    }
    return 0;
}
