#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void insertAtBottom(stack<int>& st, int x) {
    if(st.empty()) {
        st.push(x);
        return;
    }
    int topElem=st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(topElem);
}
void reverseStack(stack<int>& st) {
    if(st.empty()) 
    return;
    int topElem=st.top();
    st.pop();
    reverseStack(st);        
    insertAtBottom(st, topElem); 
    }

int main() {
    stack<int> st;
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);
    cout << "Original Stack: ";
    stack<int> temp=st;
    while(!temp.empty()) {
        cout<<temp.top()<<" ";
        temp.pop();
    }
    cout << endl;
    reverseStack(st);
    cout<<"Reversed Stack :";
    while(!st.empty()) {
        cout<<st.top()<< " ";
        st.pop();
    }
    cout<<endl;
    return 0;
}
