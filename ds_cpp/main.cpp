#include <iostream>
#include "linked_list.h"
#include "linked_list.cpp"
#include "p_match.h"
#include "queue.h"
//#include "queue.cpp"
#include "graph.h"
#include <vector>
//#include "graph.cpp"
#include "array_adt.h"

using namespace std;

int main()
{
//    char x;
//    cout << "Enter equation, finish it by \'!\'";
//    cin >> x;
//    auto exp = stack<char>(x);
//    while (true)
//    {
//        cin >> x;
//        if (x == '!')
//            break;
//        exp.push(x);
//        // cout<< "Count:" << exp.count() <<endl;
//    }
//    if(p_match(exp)) cout << "Valid Eqn";
//    auto x = queue<char>('A');
//    x.enq_front('B');
//    x.enq_front('C');
//    x.enq_rear('Z');
//    x.enq_rear('Y');
//    cout << x.get_front() << ' ' << x.get_rear() << endl;
//    x.deq_front();
//    x.deq_front();
//    x.deq_rear();
//    cout << x.get_front() << ' ' << x.get_rear();
    auto arr = array<int>(6);
    arr[0] = 2;
    arr[1] = 4;
    arr[2] = 5;
    arr[3] = 76;
    arr[4] = 87;
    arr[5] = 687;
    cout << arr.search_binary(76);
}