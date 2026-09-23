#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(char c : s) {
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);  // Opening bracket → push
            } else {
                // Closing bracket → check if it matches
                if(st.empty()) return false;  // No opening bracket
                
                char top = st.top();
                if((c == ')' && top == '(') || 
                   (c == '}' && top == '{') || 
                   (c == ']' && top == '[')) {
                    st.pop();  // Match found
                } else {
                    return false;  // Mismatch
                }
            }
        }
        
        return st.empty();  // Valid only if stack is empty
    }
};

int main(){
    char st;
    Solution s1 ;
    s1.isValid(());


    return 0;
}