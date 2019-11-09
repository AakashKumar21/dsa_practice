#include <iostream>
#include "linked_list.h"
#include "linked_list.cpp"
#include "p_match.h"

using namespace std;

int main()
{
//    auto list = linked_list<int >(2);
//    list.push(3);
//    list.push(4);
//    list.insert_as_head(1);
//    list.insert_as_head(0);
//
//    for(int x ; !list.is_empty(); ){
//        cout << "count:" << list.get_count();
//        x = list.delete_head();
//        cout << " "<< x << endl;
//    }
//
//    list.insert_as_head(5);
//    list.insert_as_head(-2);
//    list.push(8);
//    list.insert_as_head(-4);

//    cout<< list.delete_head();
//    for(auto x = list.delete_head(); !list.is_empty(); ){
//        x = list.delete_head();
//        cout << x << endl;
//    }

    char x;
    cout << "Enter equation, finish it by \'!\'";
    cin >> x;
    auto exp = stack<char>(x);
    while (true)
    {
        cin >> x;
        if (x == '!')
            break;
        exp.push(x);
        // cout<< "Count:" << exp.count() <<endl;
    }
    if(p_match(exp)) cout << "Valid Eqn";

}