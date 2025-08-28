#include <iostream>
#include <vector>
using namespace std;

long long atMostKDistinct(const string& s, int k) {
    if(k<0) 
    return 0;
    int n=(int)s.size();
    vector<int>freq(26, 0);        
    int distinct=0, left = 0;
    long long ans=0;

    for(int right=0; right<n; ++right) {
        if (freq[s[right]-'a']++==0) distinct++;     
        while(distinct>k) {                          
            if(--freq[s[left]-'a']==0) distinct--;
            left++;
        }
        ans+=(right-left+1);                      
    }
    return ans;
}
long long exactlyKDistinct(const string& s, int k) {
    return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
}
int main() {
    string s = "pqpqs";
    int k = 2;
    cout<< exactlyKDistinct(s, k)<<"\n";  
    return 0;
}
