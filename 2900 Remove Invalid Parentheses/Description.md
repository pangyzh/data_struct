# Remove Invalid Parentheses

Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).
#### 中文大意：除去最小数量的圆括号来确保输入的合法性。你应该找到所有可能的结果。输入的字符串可能还会有字母。
### Sample Input0
```
()())()
```
### Sample Output0
```
(())()
()()()
```
### Sample Input1
```
(a))(a))(())a
```
### Sample Output1
```
(a(a))(())a
(a)(a)(())a
```
### Sample Input2
```
)(
```
### Sample Output2
```
```
### Hint: set在这里仅需要用到insert方法，e.g.: set<string> s; s.insert("aaa");使用set的原因是帮助你去重以及排序，确保与答案输出一致。所以在这里你可以把set仅作为一个特殊的容器看待而不需要了解其更多的方法。