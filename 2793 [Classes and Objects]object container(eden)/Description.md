# [Classes and Objects]object container(eden)

# Description

There is a class obj, which has been given in obj.h.
```

class obj {

public:

    obj(string st):str(st){}

    void print() {

        cout << str << endl;

    }

private:

    string str;

};
```

A class named objcontainer which has a private member obj o, like:
```

class objcontainer {

public:

    objcontainer(string str);

    objcontainer(obj ob);

    //lack something that you should add. 

private:

    obj o;

};
```

You should overloading the class objcontainer's pointer so that I can use the code like objc->print() in main.cpp.

Author: 黄浩然
