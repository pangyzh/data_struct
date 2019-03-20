#ifndef OBJ_CONTAINER_H
#define OBJ_CONTAINER_H
#include "obj.h"
class objcontainer {
  public:
    explicit objcontainer(string st):o(st) {
    }
    explicit objcontainer(obj ob): o(ob) {
    }
    obj* operator->() {
        return &o;
    }
  private:
    obj o;
};
#endif