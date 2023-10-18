#include <iostream>
using namespace std;

class linkedlist {

	struct node {
		int data;
		node* next;
	};
	node* head = NULL;

public:

	//Insert Node in Linkedlist
	void insertnode(int val) {
		node* new_node = new node,*last;
		new_node->data = val;

		if (head == NULL) {
			head = new_node;
			new_node->next = NULL;
		}
		else {
			last = head;
			while (last->next != NULL) {
				last = last->next;
			}
			last->next = new_node;
			new_node->next = NULL;
		}
	}

	//**********
	//Delete Node from Linkedlist
	void deletnode(int val) {
		
		node* prev, * curr;
		prev = curr = head;
		
		if (curr->data == val) {
			head = curr->next;
			free(curr); //this method to delete current node
			return;
		}

		while (curr->data != val) {
			prev = curr;
			curr = curr->next;
		}
		prev->next = curr->next;
		free(curr);
	}

	//************
	//Insert Node in begining Linkedlist
	void inseratbeg(int val) {

		node* new_node = new node;
		new_node->data = val;
		new_node->next = head;
		head = new_node;
	}

	//***********
	//Delete Node from begining Linkedlist
	void deletatbeg() {
		node* first_node = head;
		if (head == NULL) cout << "Empty linked list" << endl;

		else {
			head = first_node->next;
			delete(first_node);
		}
	}

	//*******
	//Delete Node from End Linkedlist
	void deletatend() {
		
		if (head == NULL) cout << "Empty linked list" << endl;
		else if (head->next == NULL) {
			delete(head);
			head = NULL;
		}
		else
		{
			node* ptr = head;
			while (ptr->next->next != NULL) {
				ptr = ptr->next;
			}
			delete(ptr->next);
			ptr->next = NULL;
		}

	}

	//*******
	//Reverse Nodes in LinkedList
	void revers() {
		node* pre, * curr, * next;
		
		pre = NULL; curr = head; next = curr->next;

		while (next != NULL) //curr->next!=NULL 
		{
			next = curr->next;
			curr->next = pre;
			pre = curr;
			curr = next;
		}
		head = pre;
	}

	//*********
	//Search Node in LinkedList
	int search(int val) {
		node* ptr = head;
		int pos = 0;
		while (ptr != NULL) {
			if (ptr->data == val)
				return pos;
			ptr = ptr->next;
			pos++;
		}
		return -1;
	}

	//**********
	//Display Nodes Data inLinkedlist 
	void display() {

		if (head == NULL) cout << "Empty linked list" << endl;
		
		else {
			node* curr = head;
			while (curr != NULL) {
				cout << curr->data << "\t";
				curr = curr->next;
			}
			cout << endl;
		}
	}

};

int main()
{
	linkedlist ln;
	ln.insertnode(5);
	ln.insertnode(10);
	ln.insertnode(15);    //5 10 15
	ln.deletnode(10);     //5 15
	ln.inseratbeg(20);//20 5 15
	ln.display();     
	cout << "pos search item =" << ln.search(15) << endl;
	ln.revers();      //15 5 20
	ln.display();
	ln.deletatbeg();//5 15  
	ln.display();
    ln.deletatend();    //5
	ln.display();

	return 0;
}
