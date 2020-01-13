/************ NAMING CONVENTIONS ***********/
// starting with _ -> private member func or var
// Starting with m_ public



#include <iostream>
#include <vector>
#include "array_adt.h"
using namespace std;

int main() {
    int x[10] = {34,34,26,18,1,1,54,67,657,2};
    vector <int> z;
    auto arr = array<int>(x,10);
    arr.sort_insertion();
    for(int y: arr) cout << y << " ";

}