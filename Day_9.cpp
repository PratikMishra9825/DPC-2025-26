#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& str) {
    if (str.empty()) 
    return "";

    for (int i = 0; i < str[0].size(); i++) {
        char c = str[0][i];  
        for (int j = 1; j < str.size(); j++) {
            if (i >= str[j].size() || str[j][i] != c) {
                return str[0].substr(0, i);
            }
        }
    }
    return str[0];  
}
int main() {
    vector<string>str={"flower", "flow", "flight"};
    cout<<"Longest Common Prefix: "<<longestCommonPrefix(str)<<endl;
    return 0;
}
