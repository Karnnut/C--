#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

bool isBalanced(string s) {
    char new_char;
    stack<char> st;
    
    for (int i = 0; i < s.size(); i ++) {
        new_char = s[i];     
        if (new_char == '[' || new_char == '(' || new_char == '{') {
            st.push(new_char);
        }else {
            if (new_char == ')' || new_char ==  ']' || new_char == '}') {
                if (st.empty()){
                    st.push(new_char);                
                } 
            }
            if (((new_char == ')') && (st.top() == '(')) || ((new_char == '}') && (st.top() == '{')) || ((new_char == ']') && (st.top() == '['))){
                st.pop();
            }else {
                st.push(new_char);
            }
        }   
    }
    if (st.empty()){
        return true;         
    } 
    return false;
}

int main() {
    string s;
    cin >> s;
    while (s != "-1") {
    if(isBalanced(s)) {
        cout << "Parentheses are balanced" << endl;
    } else {
        cout << "Parentheses are not balanced" << endl;
    }
    cin >> s;
    }
    
}