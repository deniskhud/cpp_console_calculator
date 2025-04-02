#include <stack>
#include <queue>
#include <iostream>
#include <string>
using namespace std;

int Priority(char op) {
    if (op == '+' || op == '-') return 1;   //low priority
    if (op == '*' || op == '/') return 2;    //high priority
    return 0;
}

double performOperation(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    default: return 0;
    }
}

//the function makes the expression look like Polish Notation
void RPN(string& line, queue<string>& q) {
    stack<char> st;

    for (int i = 0; i < line.length(); ++i) {
        char ch = line[i];

        if (ch == ' ') continue;    //if a space

        if (isdigit(ch)) {
            string number;
            //line[i] == '.' cause double numbers (ex: 2.5)
            while (i < line.length() && (isdigit(line[i]) || line[i] == '.')) {
                number += line[i++];
            }
            q.push(number);
            --i;  // roll back the index after inner while loop
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                q.push(string(1, st.top()));
                st.pop();       //pop ')'
            }
            st.pop();  // Don't forget to pop '('
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!st.empty() && Priority(st.top()) >= Priority(ch)) {
                q.push(string(1, st.top()));
                st.pop();
            }
            st.push(ch);
        }
    }

    // After processing the entire expression, pop all remaining operators in the stack
    while (!st.empty()) {
        q.push(string(1, st.top()));
        st.pop();
    }
}

//
double Result(queue<string>& q) {
    stack<double> st;

    while (!q.empty()) {
        string temp = q.front();
        q.pop();

        if (isdigit(temp[0])) {
            st.push(stod(temp));  // Convert string to double
        }
        else {
            double b = st.top();
            st.pop();
            double a = st.top();
            st.pop();
            st.push(performOperation(a, b, temp[0]));  // Apply the operation
        }
    }
    return st.top();
}

int main() {
    string line;
    cout << "Enter an expression: ";
    getline(cin, line);

    queue<string> q;
    RPN(line, q);

    double result = Result(q);

    cout << "result: " << result << endl;

    return 0;
}
