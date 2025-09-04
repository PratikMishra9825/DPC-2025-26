#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void insertAtBottom(stack<int>& st, int x) {
    if(st.empty()) {
        st.push(x);
        return;
    }
    int top=st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(top);
}
void reverseStack(stack<int>& st) {
    if(st.empty())
     return;

    int top=st.top();
    st.pop();
    reverseStack(st);   
    insertAtBottom(st, top);
}
int main() {
    stack<int> st;
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);
    reverseStack(st);
    cout<<"Reversed Stack: ";
    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}
