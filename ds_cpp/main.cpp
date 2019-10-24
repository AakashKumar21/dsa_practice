#include <iostream>
#include "linked_list.h"
#include "stack.h"

using namespace std;
int main()
{
//    auto list = linked_list<string> ("Aakash");
//    list.push("Kumar");
//    list.push("Boi");
//    list.push("One Tappy Boi");
//    auto head = list.get_head();
//    for(auto x = head; head; cout << head->get_data()<<endl, head = head->get_next());

//    auto s = stack<string> ("Aakash");
//    s.push("CSGO");
//    s.push("TF2");
//    s.push("PUBG");
//    cout << s.get_data()<<endl;
//    s.pop();
//    s.pop();
//    s.pop();
//    cout << s.get_data()<< endl;
//    s.pop();
//    cout << s.get_data();
    char x;
    cout << "Enter equation, finish it by \'!\'";
    cin>>x;
    auto exp = stack<char>(x);
    while(true)
    {
        cin>>x;
        if(x == '!') break;
        exp.push(x);
        cout<< "Count:" << exp.count() <<endl;
    }

//    for(auto y = exp; !y.is_empty(); cout << y.pop()<<endl);
//    for(auto y = exp.get_head_node(); !y->is_tail(); cout << y->get_data()<<endl, y = y->get_next());
    // Check if exp is correct
//    auto head = exp.get_head_node();
    if( exp.get_data() == '(' ||
        exp.get_data() == '{' ||
        exp.get_data() == '{') {
            cout << "Wrong Exp";
            exit(0);
    }
//    if( head->get_data() == '}' ||
//        head->get_data() == ')' ||
//        head->get_data() == ']') {
//        cout << "Wrong Exp";
//        exit(0);
//    }

    int i=0;
    auto expCheck = stack<char> (exp.pop());
    while(!exp.is_empty())
    {
        cout << "pass: " << i << endl;
        if (exp.get_data() == ')' ||
            exp.get_data() == ']' ||
            exp.get_data() == '}')
            {
                cout << "RB\n";
                expCheck.push(exp.pop());
            }
        else
            {
                switch (expCheck.get_data())
                {
                    case ')':   if( exp.get_data() == ')' ) cout << "Match ()\n";
                                expCheck.pop();
                                break;
                    case ']':   if( exp.get_data() == ']' ) cout << "Match []\n";
                                expCheck.pop();
                                break;
                    case '}':   if( exp.get_data() == '}' ) cout << "Match {}\n";
                                expCheck.pop();
                                break;
                }
            }
    if(expCheck.is_empty()) cout << "Valid";
    i++;
    };
}