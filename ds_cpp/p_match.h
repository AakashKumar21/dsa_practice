#include "stack.h"
#include <iostream>

using namespace std;

template <typename type>

bool p_match(stack<type> &exp)
{
//    for(char x ; !exp.is_empty(); ){
//        x = exp.get_data();
//        exp.pop();
//        cout << " "<< x << endl;
//    }
//    exit(0);
//    for(int i=0; i<3; i++)
//    {
//        cout<< exp.pop() << endl;
//    }
//    exit(0);
    if (exp.get_data() == '(' ||
        exp.get_data() == '{' ||
        exp.get_data() == '{')
    {
        cout << "Wrong Exp";
        return 0;
    }
//    cout << "stack elements: " << exp.count() << endl;
    int i = 0;
//    bool once = true; //workaround
    auto expCheck = stack<char>();


    while (!exp.is_empty())
    {

//        cout << "pass: " << i << ' ';
        if (exp.get_data() == ')' ||
            exp.get_data() == ']' ||
            exp.get_data() == '}')
        {
            expCheck.push(exp.pop());
//            cout << exp.get_data() << " Left Bracket "
//                 << "expC.count: "
//                 << expCheck.count()
//                 << " exp.count: "
//                 << exp.count() << endl;
        }
        else
        {
            switch (expCheck.get_data())
            {
            case ')':
                if (exp.get_data() == '('){
                    exp.pop();
                    expCheck.pop();
//                    cout << "Match () " << "expC.count: "
//                    << expCheck.count()
//                    << " exp.count: "
//                    << exp.count() << endl;
                    break;
                }

            case ']':
                if (exp.get_data() == '['){
                    exp.pop();
                    expCheck.pop();
//                    cout << "Match [] " << "expC.count: "
//                         << expCheck.count()
//                         << " exp.count: "
//                         << exp.count() << endl;
                    break;
                }

            case '}':
                if (exp.get_data() == '{'){
                    exp.pop();
                    expCheck.pop();
//                    cout << "Match {} " << "expC.count: "
//                         << expCheck.count()
//                        << " exp.count: "
//                        << exp.count() << endl;
                    break;
                }
            }
        if (exp.is_empty())
            if (expCheck.is_empty())
                return true;
            else 
                return false;
//        else cout << "Not empty\n";
        }
        i++;
    };
};
