#include <iostream>
using namespace std;

//Stack Impelmentation Using Array

template<class t>

#define size 5


class stack_arr{

	t stack[size];
	int	top ;

public:

	//Constractor 
	stack_arr():top(-1)
	{   }

	//Push Elemnt inside Stack
	void push(t val) {

		if (top == size - 1)
			cout << "stack overflow" << endl;
		else {
			top++;
			stack[top] = val;
		}
	}

	//******
	//Pop fun Return and delete Element From Stack 
	t pop() {
		if (top == -1)
			cout << "stack underflow" << endl;
		else {
			return stack[top--];
		}
	}

	//********
	//Peek fun Return and not delete Element to pop refer it From Stack 
   t peek() {
		if (top == -1)
			return 0 ;
		else {
			return stack[top];
		}
	}

   //**********
   //Display All Element From Stack 
	void display() {
		if (top == -1)
			cout << "stack underflow" << endl;
		else {
			cout << '['<<" ";
			for (int i = top; i >= 0; i--) {
				cout << stack[i] << " ";
			}
			cout << ']';
			cout << endl;
		}

	}

};

int main()
{
	stack_arr<int> s;

	s.push(5);
	s.push(10);
	s.push(15);
	s.push(20);
	s.push(25);
	
	s.display();  //25 20 15 10 5
 
	s.pop();
	s.display(); //20 15 10 5
	cout << "peek is " << s.peek() << endl;
	
	return 0;
}
