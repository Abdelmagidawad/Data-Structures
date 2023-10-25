#include <iostream>
using namespace std;
 
//queue using linked list 

template<class t>

class linked_queue {

    struct node {
        t data;
        node* next;
    };
  
    node* front, * rear;

public:
    
    linked_queue():front(NULL),rear(NULL)
    {   }

    //this fun to insert element in queue
    void enqueue(t val) {
        node* new_node = new node;
        new_node->data = val;
        new_node->next = NULL;

        if (front == NULL) {
            front = rear = new_node;
        }
        else {
            rear->next = new_node;
            rear = new_node;
        }
    }

    //***************
    //this fun to delete element from queue
    void dequeue() {
        if (front == NULL)
            cout << "linked queue is Empty" << endl;
        else if(front==rear){
            front = rear = NULL;
            free(front);  //delete front
        }
        else {
            node* ptr = front;
            front = front->next;
            delete(ptr);
        }
    }

    //***************
    //this fun return element value to front refer it
    t peek() {

        if (front == NULL) {
            cout << "linked queue is Empty" << endl;
            return -1;
        }
        else {
            return front->data;
        }
    }


    //******************
    //this fun to display all element in queue
    void display() {
        if (front == NULL)
            cout << "linked queue is Empty" << endl;
        else {
            node* curr = front;
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
    linked_queue<int> lq;

    lq.enqueue(5);
    lq.enqueue(8);
    lq.enqueue(9);
    lq.enqueue(10);
    lq.enqueue(15);
    lq.display();     // 5 8 9 10 15

    lq.dequeue();
    lq.dequeue();
    lq.display();  //9 10 15

    cout << "Peek =" << lq.peek() << endl; //9
    
    return 0;
}
