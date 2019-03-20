#include <iostream>
#include "obj.h"
#include "objcontainer.h"
using namespace std;
 
int main(int argc, const char * argv[]) {
    string str;
    cin >> str;
    obj o(str);
    objcontainer objc1(o);
    objc1->print();
    cin >> str;
    objcontainer objc2(str);
    objc2->print();
    return 0;
}
