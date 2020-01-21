#include <iostream>
#include <vector>
#include<bits/stdc++.h>
#include "infix_to_postfix.h"

using namespace std;

int main() {
const char *x = "((A*B)+(C/D))^((A*B)+(C/D))-(A*(B+(C/D)))*(A+B)*C+(D-E)-F+G*T*(T^C)-(C*D)";
to_postfix(x);
}
