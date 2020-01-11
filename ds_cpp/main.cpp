#include <iostream>
#include "array_adt.h"
using namespace std;

int main() {
    int x[10] = {6,8,46,78,45,98,54,67,657,2};
    auto arr = array<int>(x,10);
    arr.sort_bubble(1);
    for(int y: arr) cout << y << " ";

}