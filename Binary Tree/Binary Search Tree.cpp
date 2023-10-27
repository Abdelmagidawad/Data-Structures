#include <iostream>
#include<queue>
using namespace std;

//Binary Tree (Binary Search Tree=BST)

template<class t>

class BST {

	struct node {
		t data;
		node* left, * right;

		node(t val) {
			data = val;
			left = right = NULL;
		}
	};
	

public:
	node* root = NULL;
	
	//implementation BST without recursion
	//add elemnt to binary search tree

	void add(t val) {
		node* new_node = new node(val);    

		if (root == NULL) {
			root = new_node;
		}
		else {
			node* temp = root;
			node* ptr = NULL;
			
			while (temp != NULL) {
				ptr = temp;
				if (val <= temp->data)  temp = temp->left;
				else  temp = temp->right;
			}
			if (val <= ptr->data)  ptr->left = new_node;
			else  ptr->right = new_node;
		}	
	}


	//*************
	//implementation BST using recursion
	//add elemnt to binary search tree

	node* insert(node* r, t val) {
		if (r == NULL) {
			node* new_node = new node(val);
			r = new_node;
		}
		else if (val <= r->data)
			r->left = insert(r->left, val);
		else
			r->right=insert(r->right, val);
		return r;
	}
	
	//****************
	//to Update in the last root in tree
	void insert(t val) {
		root=insert(root, val);
	}


	//In Two Way To Display all Element in the Binary Tree
	//1-DFT(PreOrder,InOrder,PostOrder)
	//2-BST(levelOrder)

	//1-Depth_first traversal
	///preorder (root-left-right)
	void preorder(node* r) {
		if (r != NULL) {
			cout << r->data << "\t";
			preorder(r->left);
			preorder(r->right);
		}
	}

	///inorder (left-root-right)
	void inorder(node* r) {
		if (r != NULL) {
			inorder(r->left);
			cout << r->data << "\t";
			inorder(r->right);
		}
	}

	///postorder (left-right-root)
	void postorder(node* r) {
		if (r != NULL) {
			postorder(r->left);
			postorder(r->right);
			cout << r->data << "\t";
		}
	}

	//***********
	//2-Breadth_first traversal
	///level_order (queue)
	void levelorder(node* r) {
		if (r == NULL)
			return;

			queue<node*>q;
			q.push(r);

			while (!q.empty()) {
				node* cur = q.front();
				cout << cur->data << " ";
				if (cur->left != NULL)
					q.push(cur->left);
				if (cur->right != NULL)
					q.push(cur->right);
				q.pop();
			}
			cout << endl;
	}

	
	
int main()
{
	BST<int> b;

	b.add(20);
	b.add(30);
	b.insert(10);
	b.insert(7);
	b.insert(11);
	
	cout << "pre_order = "; //20 10 7 11 30
	b.preorder(b.root);     
	cout << endl;

	cout << "in_order = "; //7 10 11 20 30
	b.inorder(b.root);
	cout << endl;
	
	cout << "post_order = "; // 7 11 10 30 20
	b.postorder(b.root);
	cout << endl;
	
	cout << "Level_order = "; //20 10 30 7 11
	b.levelorder(b.root);
	

	
	return 0;
}