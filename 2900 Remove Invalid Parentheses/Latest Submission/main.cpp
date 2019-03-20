#include "Solution.hpp"
using std::cin;
using std::cout;
using std::endl;
int main() {
    string s;
    cin >> s;
    set<string> res =  removeInvalidParentheses(s);
    for (auto i = res.begin(); i != res.end(); ++i)
        cout << *i << endl;
}