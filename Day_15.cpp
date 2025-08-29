#include <iostream>
#include<vector>
#include<string>
using namespace std;

pair<int,string> longestUniqueSubstring(const string &s) {
    int n=s.size();
    if(n == 0) 
    return{0, ""};

    vector<int> lastIndex(256, -1); 
    int start = 0;                  
    int maxLen = 0;
    int maxStart = 0;

    for(int j=0; j<n; ++j) {
        unsigned char c = s[j];
        if(lastIndex[c] >= start) {
            start=lastIndex[c] + 1;
        }
        lastIndex[c]=j;
        int curLen = j - start + 1;
        if(curLen>maxLen) {
            maxLen=curLen;
            maxStart=start;
        }
    }
    return {maxLen, s.substr(maxStart, maxLen)};
}
int main() {
    string Str;
    Str= "abcabcbb";
    auto res = longestUniqueSubstring(Str);
    cout<<"Length: "<<res.first<<"\n";
    cout<<"Substring: \"" <<res.second<<"\"\n";
    return 0;
}
