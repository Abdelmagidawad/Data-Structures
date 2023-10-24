#include <iostream>
using namespace std;

//simple queue using array

template<class t>
#define size 5

class simple_queue {

    t queue[size];
    int front;
    int rear;

public:
    simple_queue():front(-1),rear(-1)
    {   }

    //this fun to insert element in queue
    void enqueue(t val) {

        if (rear== size - 1)
            cout << "queue is Full" << endl;
        else {
            if (front == -1 && rear == -1) {
                front++;   //rear++;
                queue[++rear] = val;
            }
            else {
                queue[++rear] = val;
            }
        }
    }

    //*************
    //this fun to check exist elements in queue or not
    void dequeue() {
        if (front == -1 && rear == -1 && front > rear)
            cout << "queue is empty" << endl;
        else {
            front++;
        }
    }

    //*************
    //this fun to return element to front refer it
    
    t peek() {
        if (front == -1 && rear == -1 && front > rear) {
            cout << "queue id empty" << endl;
            return -1;
        }
        else {
            return queue[front];
        }
    }

    //***************
    //this fun to display all elemnt from queue
    
    void display() {

        if (front == -1 && rear == -1 && front > rear) 
            cout << "queue id empty" << endl;
        else {
           cout << '['<<" ";
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " ";
            }
          cout << ']'<<endl;
        }
    }

    //***************
    //this fun clear queue from all elemnt
    void clear() {

        if (front == -1 && rear == -1 && front > rear)
            cout << "queue id empty" << endl;
        else {
            while (front != rear + 1) {
                front++;
            }
            cout << " queue is cleared " << endl;
        }
    }
    
};

int main()
{
    simple_queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();     //[ 10 20 30 40 50 ]

    q.enqueue(60);   //queue is full

    q.dequeue();
    q.dequeue();
    q.display();  //[ 30 40 50 ]

    cout << "front = " << q.peek() << endl;  //30
    
    q.clear();
    q.display(); //[ ]

    return 0;
}
