#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void insertSorted(stack<int> &st, int x) {
    if(st.empty() || st.top()<=x) {
        st.push(x);
        return;
    }
    int temp=st.top();
    st.pop();
    insertSorted(st, x);

    st.push(temp);
}
void sortStack(stack<int> &st) {
    if(st.empty()) 
    return;

    int temp = st.top();
    st.pop();

    sortStack(st);
    insertSorted(st, temp);
}
void printStack(stack<int> st) {
    vector<int> arr;
    while(!st.empty()) {
        arr.push_back(st.top());
        st.pop();
    }
    reverse(arr.begin(), arr.end());
    for(int x : arr) 
    cout<<x<<" ";
    cout<<endl;
}

int main() {
    stack<int> st;
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);
    cout<<"Original Stack: 2 4 1 3"<<endl;
    sortStack(st);
    cout<<"Sorted Stack :";
    printStack(st);
    return 0;
}
