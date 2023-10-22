#include <iostream>
#include<algorithm>
#include<stack>
using namespace std;

//Expression Evaluation Using Stack

//Implementaion Using Stack

//this fun to Operation about element 
int operation(int op1, int op2, char ope) {
	int answer;
	switch (ope) {
	case'+':
		answer = op1 + op2;
		break;
	case'-':
		answer = op1 - op2;
		break;
	case'*':
		answer = op1 * op2;
		break;
	case'/':
		answer = op1 / op2;
		break;
	}
	return answer;
	
}

//this fun to implemented PostFix evaluation 
int postfix_evalu(string ex) {
	stack<int>s;
	
	for (int i = 0; i < ex.size(); i++) {
		if (isdigit(ex[i]))
			s.push(ex[i] - '0');
		else {
			int op2 = s.top();
			s.pop();
			int op1 = s.top();
			s.pop();

			int result = operation(op1, op2, ex[i]);
			s.push(result);
		}
	}
	return s.top();
}

//*********************
//this fun to implemented PreFix evaluation

int prefix_evalu(string ex) {
	stack<int>s;

	for (int i = ex.size()-1; i >=0; i--) {
		if (isdigit(ex[i]))
			s.push(ex[i] - '0');
		else {
			int op1 = s.top();
			s.pop();
			int op2 = s.top();
			s.pop();

			int result = operation(op1, op2, ex[i]);
			s.push(result);
		}
	}
	return s.top();
}

int main()
{
	string ex1,ex2;
	cin >> ex1 >> ex2;

	cout << " this result of operation =  " << postfix_evalu(ex1) << endl;
	
	cout << " this result of operation =  " << prefix_evalu(ex2) << endl;
	
	return 0;
}

