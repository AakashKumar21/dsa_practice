#include "stack.h"
#include <iostream>

using namespace std;

template <typename type>

bool p_match(stack<type> &exp)
{
    if (exp.get_data() == '(' ||
        exp.get_data() == '{' ||
        exp.get_data() == '{')
    {
        cout << "Wrong Exp";
        return 0;
    }

    int i = 0;
    auto expCheck = stack<char>();


    while (!exp.is_empty())
    {

        if (exp.get_data() == ')' ||
            exp.get_data() == ']' ||
            exp.get_data() == '}')
        {
            expCheck.push(exp.pop());
        }
        else
        {
            switch (expCheck.get_data())
            {
            case ')':
                if (exp.get_data() == '('){
                    exp.pop();
                    expCheck.pop();
                    break;
                }

            case ']':
                if (exp.get_data() == '['){
                    exp.pop();
                    expCheck.pop();
                    break;
                }

            case '}':
                if (exp.get_data() == '{'){
                    exp.pop();
                    expCheck.pop();
                    break;
                }
            }
        if (exp.is_empty())
            if (expCheck.is_empty())
                return true;
            else 
                return false;
        }
        i++;
    };
};
