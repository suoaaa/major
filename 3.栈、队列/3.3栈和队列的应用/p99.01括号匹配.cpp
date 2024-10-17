//假设一个算术表达式中包含圆括号，方括号和花括号三种类型的括号，编写一个算法来判别表达式中的括号是否配对，以字符"\0"作为算术表达式的结束符
#include <iostream>
#include <stack>
using namespace std;

void Bracket_Pairing(string s){
    stack<char> bracket;
    char Parentheses;
    for(int i=0;i<s.size();i++){
        if (s[i] == '(' || s[i] == '{' || (s[i] == '[')) {
			bracket.push(s[i]);
		}
		if (s[i] == ')' || s[i] == '}' || (s[i] == ']')) {
            if(bracket.empty()){
                cout << "匹配失败!" << endl;
					return;
            }else Parentheses = bracket.top();
			switch (Parentheses)
			{
				case '(': {
					if (s[i] == ')') {
						bracket.pop();
						break;
					}
				}
				case '[': {
					if (s[i] == ']') {
						bracket.pop();
						break;
					}
				}
				case '{': {
					if (s[i] == '}') {
						bracket.pop();
						break;
					}
				}
				default: {
					cout << "匹配失败!" << endl;
					return;
				}
			}
		}
    }
    if (bracket.empty()) {
		cout << "匹配成功！" << endl;
	}
	return;
}   
int main()
{
	Bracket_Pairing("[(){}]");
	return 0;
}

