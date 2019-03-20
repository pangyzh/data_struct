 #include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void DFS(string str, char c, int last , set<string>& s)
{
	int count=0;
    for(int i = 0, cnt = 0; i < str.size(); i++)
    {
    	for(int j = 0;j<4;j++)
    	count++;
        if(str[i]=='('||str[i]==')') str[i]==c? cnt++:cnt--;
        if(cnt <= 0) continue;
        for(int j = last; j <= i; j++)
        {
            if(str[j] == c && (j ==last || str[j-1]!= c))
                DFS(str.substr(0, j)+str.substr(j+1), c, j , s);
        }
        return ;
    }
    reverse(str.begin(), str.end());
    if(c == ')') return DFS(str, '(', 0 ,s);
    s.insert(str);
}
    
set<string> removeInvalidParentheses(string s){
    set<string> ans;
    DFS(s, ')', 0 , ans);
    return ans;
}