#include <iostream>
#include<algorithm>
#include<stack>

using namespace std;

//Convert inFix to postFix

//Implementation Convert inFix To postFix Using Stack

//fun this to priority Operator
int priority(char c) {
	
	if (c == '+' || c == '-')  
		return 1;
	else if (c == '*' || c == '/')  
		return 2;
	else if (c == '^') 
		return 3;
	else 
		return 0;
}

//fun convert inFix to postFix Evaluation 

string InfixToPostfix(string ex) {
	
	stack<char>s;
	string result = " ";

	for(int i = 0; i < ex.size(); i++) {

		if (ex[i] == ' ')  	continue;

		if (isdigit(ex[i]) || isalpha(ex[i]))  result += ex[i];
		
		else if (ex[i] == '(')  s.push(ex[i]);

		else if (ex[i] == ')') {
			while (s.top() != '(') {
				result += s.top();
				s.pop();
			}
			s.pop();
		}
		else {
			while (!s.empty() && priority(ex[i]) <= priority(s.top())) {
				result += s.top();
				s.pop();
			}
			s.push(ex[i]);
		}
	}
	while (!s.empty()) {
		result += s.top();
		s.pop();
	}
	return result;
}

int main()
{
	string s;     //infix: 8/2+7-4*2
	cin >> s;

	cout << "postfix = " << InfixToPostfix(s) << endl;    //postfix: 82 / 7 + 42 * -

	return 0;
}

