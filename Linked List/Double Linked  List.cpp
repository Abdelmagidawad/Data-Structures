#include <iostream>
using namespace std;

class doublelinkedlist {

    struct node {
        int data;
        node* next;
        node* prev;
   };
    node* head, * last = NULL;
    int count = 0;

public:

    //insert Node at first Double Linked List  
    void insertfirst(int val) {
        node* new_node = new node;
        new_node->data = val;
         
        if (head == NULL) {
            head = new_node;
            last = head;
            new_node->next = new_node->prev = NULL;
        }
        else
        {
            new_node->next = head;
            new_node->prev = NULL;
            head->prev = new_node;
            head = new_node;
        }
    }

    //**********
    //insert Node at last Double Linked List 
    void insertlast(int val) {
        node* new_node = new node;
        new_node->data = val;

        if (head == NULL) {
            head = new_node;
            last = head;
            new_node->next = new_node->prev = NULL;
        }
        else{
            last->next = new_node;
            new_node->next = NULL;
            new_node->prev = last;
            last = new_node;
        }
    }

    //**********
    //insert Node at position in Double Linked List 
    void inserAtpos(int pos,int val) {
        if (pos < 0) cout << "Out of rang" << endl;
        else {
            node* new_node = new node;
            new_node->data = val;
            if (pos == 0)
                insertfirst(val);
            else if (pos == count)
                insertlast(val);
            else {
                node* curr=head;
                for (int i = 1; i < pos; i++) {
                    curr = curr->next;
                }
                new_node->next = curr->next;
                new_node->prev = curr;
                curr->next = new_node;
                curr->next->prev = new_node;
            }
            count++;
        }
    }

    //********
    //delete node at first double linked list 
    void deletefirst() {
        if (head == NULL) cout << "Empty linked list" << endl;
        else if (head == last) {
            delete(last);
            head = last = NULL;
        }
        else
        {
            node* curr = head;
            head = curr->next;
            head->prev = NULL;
            free(curr); //this method to delete node
        }
    }

    
    //***********
    //delete node at last double linked list 
    void deletend() {
        if (head == NULL)  cout << "Empty linked list" << endl;

        else if (head == last) {
            delete(head);
            head = last = NULL;
        }
        else
        {
            node* curr = last;
            last = last->prev;
            last->next = NULL;
            delete(curr);
        }
    }

    //***********
    //delete any Node in Double Linked List 
    void deletitem(int it) {

        if (head == NULL) cout << "Empty linked list" << endl;
        else if (head->data == it)
            deletefirst();
        else{
            node* ptr = head->next;
            while (ptr != NULL) {
                if (ptr->data == it)
                    break;
                ptr = ptr->next;
            }

            if (ptr == NULL) cout << "item no there" << endl;
            else if (ptr->next == NULL)
                deletend();
            else {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
                free(ptr); //this method to delete node
            }
        }
    }

    //***************
    //display all node data in double linked list 
    void display() {

        cout << " Element Linked list" << endl;
        
        if (head == NULL) cout << "linked list Empty" << endl;
        else {
            node* ptr = head;
            while (ptr != NULL) {
                cout << ptr->data << "\t";
                ptr = ptr->next;
            }
            cout << endl;
        }
    }

    //**************
      //display all node data in double linked list from end to first (reverse)
    void reverse() {
        
        cout << "Reverse Element Linked list" << endl;

        if (last == NULL) cout << "linked list is Empty" << endl;
        else
        {
            while (last != NULL) {
                cout << last->data <<"\t";
                last = last->prev;
            }
            cout << endl;
        }
    }

    //Deconstractor used to destroy Double linked list
    ~doublelinkedlist() {

        node* curr, * prev;
        curr = head;
        while (curr != NULL) {
            prev = curr;
            curr = curr->next;
            delete(prev);
        }
        last = NULL;
    }
};


int main()
{
    doublelinkedlist dln;
    dln.insertfirst(10);
    dln.insertlast(20);
    dln.insertlast(30);
    dln.insertlast(40);
    dln.insertlast(50);
    dln.display();       //10 20 30 40 50
    dln.deletend();
    dln.display();       //10 20 30 40
    dln.inserAtpos(1, 15);
    dln.display();       //10 15 20 30 40
    dln.reverse();       //40 30 20 10
    dln.deletitem(20);  
    dln.display();       //10 30 40
    dln.deletefirst();   
    dln.display();      //30 40
  
    return 0;
}

