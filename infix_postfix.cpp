#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:

    // Function to define precedence
    int precedence(char op) {
        if (op == '^') return 3;
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return -1;
    }

    string infixToPostfix(string s) {
        stack<char> st;
        string output = "";

        for (char ch : s) {

            // If operand → add to output
            if (isalnum(ch)) {
                output += ch;
            }

            // If '(' → push
            else if (ch == '(') {
                st.push(ch);
            }

            // If ')' → pop until '('
            else if (ch == ')') {
                while (!st.empty() && st.top() != '(') {
                    output += st.top();
                    st.pop();
                }
                st.pop(); // remove '('
            }

            // If operator
            else {
                while (!st.empty() &&
                       st.top() != '(' &&
                       (precedence(st.top()) > precedence(ch) ||
                        (precedence(st.top()) == precedence(ch) && ch != '^'))) {
                    
                    output += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }

        // Pop remaining operators
        while (!st.empty()) {
            output += st.top();
            st.pop();
        }

        return output;
    }
};

int main() {
    string s;
    cout << "Enter infix expression: ";
    cin >> s;

    Solution obj;
    cout << "Postfix expression: " << obj.infixToPostfix(s);

    return 0;
}