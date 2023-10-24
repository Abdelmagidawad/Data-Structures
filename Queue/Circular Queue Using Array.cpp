#include <iostream>
using namespace std;

//circular queue using array

template<class t>
#define size 5

class circular_queue {

	t queue[size];
	int front, rear;

public:
	circular_queue(): front(-1),rear(-1)
	{   }

	//to check queue is full or not
	bool isfull() {
		return ((front == 0 && rear == size - 1) || front == rear+1)? true :false;
	}
	//to check queue is empty or not
	bool isempty() {
		return(front == -1 && rear == -1) ?true :false;
	}
	 
	//***********
	//to insert elemnt in circular queue
	void enqueue(t val) {
		if (isfull())
			cout << "queue is Full" << endl;
		else {
			if (isempty()) {
				front = rear = 0;
					queue[rear] = val;
			}
			else if (rear == size - 1) {
				rear = 0;
				queue[rear] = val;
			}
			else
				queue[++rear] = val;

		}
	}

	//**************
	// to delete elemnt about circular queue
	void dequeue() {
		if (isempty())
			cout << "queue is Empty " << endl;
		else {
			if (front == size - 1)
				front = 0;
			else if (front == rear)
				front = rear = -1;
			else
				front++;
		}
	}

	//*****************
	//rturn elemnt to front refer it
	t peek() {
		if (isempty()) {
			cout << "queue is Empty" << endl;
			return -1;
		}
		else {
			return queue[front];
		}
	}


	//*************
	//display all elemnts in circular queue
	void display() {

		if (isempty())
			cout << "queue is Empty" << endl;
		else {
			if (front <= rear) {
				cout << '[' << " ";
				for (int i = front; i <= rear; i++)
					cout << queue[i] << " ";
				cout << ']';
			}
			else {
				cout << '[' << " ";
				for (int i = front; i <= size - 1; i++)
					cout << queue[i] << " ";
				for (int i = 0; i <= rear; i++)
					cout << queue[i] << " ";
				cout << ']';
			}
			cout << endl;
		}
	}

	//***************
	//to cleart all elemnt from circular queue
	void clear() {
		if (isempty())
			cout << "queue is Empty" << endl;
		else {
			while (!isempty()) {
				if (front == rear) front = rear = -1;
				else if (front == size - 1)  front = 0;
				else front++;
			}
			cout << "queue is cleared"<< endl;
		}
	}
};


int main()
{
	circular_queue<int> q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.display();   //10 20 30 40 50
	
	q.dequeue();
	q.dequeue();
	q.display();   // 30 40 50
	cout << "Peek = " << q.peek()<<endl; //30
	
	q.enqueue(60);
	q.enqueue(70);
	q.display();    //30 40 50 60 70

	q.clear();
	q.display(); 

	return 0;
}
