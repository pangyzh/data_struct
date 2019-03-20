#ifndef OBJCONTAINER_H
#define OBJCONTAINER_H
#include "obj.h"

class objcontainer {
public:
    
    objcontainer(string strC) : o(strC) {}
    
    objcontainer(obj obC) : o(obC) {}
    void print() {}
    //lack something that you should add.
    obj * operator->()  
    { return &o; }
private:
    
    obj o;
    
    };
#endif