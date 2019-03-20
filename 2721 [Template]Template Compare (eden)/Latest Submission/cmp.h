 #include<string.h>
template<typename T>
bool cmp(T s1,T s2)
{
    if(s1==s2)
        return 1;
    return 0;
}
template<typename T>
bool cmp(T* s1,T*s2){
  if(*s1==*s2)
    return 1;
  return 0;
}
bool cmp(char *s1,char *s2)
{
    if(strcmp(s1,s2)==0)
      return 1;
  return 0;
}