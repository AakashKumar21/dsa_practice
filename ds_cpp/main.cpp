/************ NAMING CONVENTIONS ***********/
// starting with _ -> private member func or var
// Starting with m_ public



#include <iostream>
#include <vector>
#include "array_adt.h"
using namespace std;

int main() {
    int x[10] = {34,32,26,600,2};
    vector <int> z;
    auto arr = array<int>(x,5);
    arr.sort_selection();
    for(int y: arr) cout << y << " ";
}