 #include<string.h>
#include<iostream>
using namespace std;

template<typename T>
bool cmp( T a, T b ){
    return a==b;
}

template<typename T>
bool cmp(T* a,T* b){
    return *a==*b;
}

bool cmp(char* a,char* b){
 if(strcmp(a,b)==0)
    return 1;
return 0;
}
