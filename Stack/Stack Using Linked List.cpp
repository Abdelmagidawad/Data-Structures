 #include <iostream>
using namespace std;

//Implementaion Stack Using Linked List

template<class t>

class stack_ln {

	struct node {
		t data;
		node* next;
	};
	node* top; //head
public:
	//Constractor
	stack_ln():top(NULL)
	{    }

	//push fun insert element at begining (Stack)
	void push(t val) {
		node* new_node = new node;
		new_node->data = val;
		if (top == NULL) {
			top = new_node;
			new_node->next = NULL;
		}
		else {
			new_node->next = top;
			top = new_node;
		}
	}
	
	//*************
	//pop fun delete element at begining (Stack)
	t pop() {

		t value;
		if (top == NULL) {
			cout << "stack underflow " << endl;
			return -1;
		}
		else {
			node* ptr = top;
			top = ptr->next;
			value = ptr->data;
			delete(ptr);
			return value;
		}
	}
	
	//**********
	//peek fun Return value to top refer it 
	t peek() {
		if (top == NULL) {
			cout << "stack underflow" << endl;
			return -1;
		}
		else {
			return top->data;
		}
	}

	//*******
	//display all element from stack
	void display() {
		if (top == NULL)
			cout << "stack underflow" << endl;
		else {
			node* curr = top;
			while (curr != NULL) {
				cout << curr->data << endl;
				curr = curr->next;
			}
			cout << endl;
		}
	}
};




int main()
{
	stack_ln<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.display();  //50 40 30 20 10
	s.pop();//50
	s.display();   //40 30 20 10
	cout << "peek= " << s.peek() << endl;//40
 
	return 0;
}
 