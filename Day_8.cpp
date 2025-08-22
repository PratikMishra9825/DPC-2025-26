#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    string s="the sky is blue";
    int n=s.size();
        string ans="";
        reverse(s.begin(), s.end());
        for(int i=0; i<n; i++){
            string word="";
            while(i<n && s[i]!=' '){
                word+=s[i++];
            }
        reverse(word.begin(), word.end());
        if(word.size()>0){
            ans+=' '+word;
        }
        }
        cout<<ans.substr(1)<<endl;
        return 0;
}
