#include <iostream>

using namespace std;

//Implementation AVL Tree (Height Balanced Tree)

template<class t>

class AVL_tree
{
	struct node
	{
		t data;
		node*left, *right;
		int height;

		node(t val) {
			data = val;
			left = right = NULL;
			height = 1;
		}
	};

public:
	node* root = NULL;

	//calculate height
	int height(node* r) {

		if (r == NULL)  return 0;
		return r->height;
	}

	//Right Rotation
	node* rightrotate(node *r) {
		node* x = r->left;
		node* t2 = x->right;
		
		//perform rotation
		x->right = r;
		r->left = t2;
		
		//update height
		r->height = max(height(r->left), height(r->right)) + 1;
		x->height = max(height(x->left), height(x->right)) + 1;
		
		//return new root 
		return x;
	}

	//************
	//Left Rotaion
	node* leftrotate(node* r) {
		node* x = r->right;
		node* t2 = x->left;
		
		//perform rotation
		x->left = r;
		r->right = t2;
		
		//update Height
		r->height = max(height(r->left), height(r->right)) + 1;
		x->height = max(height(x->left), height(x->right)) + 1;

		//return new root
		return x;
	}

	//**************
	//calculate Balance factor
	int balance_factor(node* r) {
		
		if (r == NULL)  return 0;
		return height(r->left) - height(r->right);
	}

	
	//***************
	//Insert node in AVl tree
	node* insert(node* r, t val) {

		if (r == NULL) {
			node* new_node = new node(val);
			r = new_node;
		}
		else if (val <= r->data)
			r->left = insert(r->left, val);
		else if(val > r->data)
			r->right = insert(r->right, val);
		else
		   return r;

		//update hieght root
		r->height = max(height(r->left), height(r->right)) + 1;

		int balance = balance_factor(r);

		//Left Left(LL) Rotation
		if (balance > 1 && val < r->left->data)
			return rightrotate(r);
		
		//Right Right(RR) Rotation
		if (balance<-1 && val > r->right->data)
			return leftrotate(r);
		
		//Left Right(LR) Rotation
		if (balance > 1 && val > r->left->data) {
			r->left = leftrotate(r->left);
			return rightrotate(r);
		}
	
		//Right Left(Rl) Rotation
		if (balance < -1 && val < r->right->data) {
			r->right = rightrotate(r->right);
			return leftrotate(r);
		}

		return r;
	}

	//Update root
	void insert(t val) {
		root=insert(root, val);
	}
	
	//***************
	// display all item in tree 
	//preorder travers
	void preorder(node *r) {
		if (r != NULL) {
			cout << r->data << "\t";
			preorder(r->left);
			preorder(r->right);
		}
	}
	

	//*****************
	//search item in AVL Tree
	node* search(node* r, int data) {

		if (r == NULL)  return NULL;

		if (r->data==data)
			return r;
		else if (data < r->data)
			return search(r->left, data);
		else
			return search(r->right, data);
	}
	
	void search(int data) {
		node* res = search(root, data);
		if (res == NULL)
			cout << "Sorry ,not found" << endl;
		else
			cout << "Yes , exist item= " << res->data << endl;
	}
};


int main()
{
	AVL_tree<int>t;
	
	t.insert(30);
	t.insert(10);
	t.insert(20);
	t.insert(15);
	
	t.preorder(t.root);   //20 10 15 30
	cout << endl;

	t.search(30);
	
    return 0;
}



