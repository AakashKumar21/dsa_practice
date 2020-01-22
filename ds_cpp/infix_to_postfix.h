#include "stack.h"
#include <iostream>

using namespace std;

int prec(const char &a);

bool isoperator(const char &a);

void to_postfix(const char *exp) {
    static std::vector<char> postfix_exp;
    static std::stack<char> temp; // temp stack

    for (int i = 0; i < strlen(exp); i++) {
        char c = exp[i]; // For Debugging
        //1. If its left bracket push it to stack
        if (c == '(')
            temp.push(c);

            //2. IF its a operand push to postfix exp
        else if (isalnum(c))
            postfix_exp.push_back(c);

            //3. If its operator
        else if (isoperator(c)) {
            //3.1 and stack is empty OR has top element '('
            // Push it to stack
            if (temp.empty())
                temp.push(c);
            else if (temp.top() == '(')
                temp.push(c);

                //3.2 IF top element of stack is operator
                // and precedence of char is lower
                // Pop all the operators from the stack
                // which are greater than or equal to in
                // precedence than that of the scanned operator
            else if (isoperator(temp.top())) {
                    while(prec(c) <= prec(temp.top()))
                    {
                        postfix_exp.push_back(temp.top());
                        temp.pop();
                        if(temp.empty()) break;
                        if(temp.top() == '(') break;
                    }
                    temp.push(c);

                 if (prec(c) > prec(temp.top()))
                    temp.push(c);
            }
        }
        else if (c == ')') { // when ')'
            while (temp.top() != '(') {
                char t = temp.top();
                if (isoperator(t))
                    postfix_exp.push_back(temp.top());
                temp.pop();
            }
            temp.pop();
        }
    }
    if (!temp.empty())
        while (!temp.empty()) {
            char c;
            c = temp.top();
            temp.pop();
            postfix_exp.push_back(c);
        }
    for (char &x: postfix_exp) cout << x << ' ';
    cout << *postfix_exp.end();
}

// To compare precedence of scanned char and char in top of stack
// 0: scanned char has precedence <= than char in top of stack
// 1: scanned char has precedence > than char in top of stack
int prec(const char &a) {
    static const char ops[5] {'+', '-', '*', '/', '^'}; //operators
    static const int prec[5] { 1,   1,   2,   2,   3 };// Precedences
    // Find precedence of a and b
    int i = 0, j = 0;
    for (; i < 5; i++) if (a == ops[i]) break;
    return prec[i];
}

bool isoperator(const char &a) {
    static char ops[5]{'*', '/', '+', '-', '^'};
    for (char op : ops)
        if (a == op) return true;
    return false;
}

