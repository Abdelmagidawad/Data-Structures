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

	
	
	//*********
	//search item in BST

	node* search(node* r, t key) {

		if (r == NULL) return NULL;
		else if (r->data == key)
			return r;
		else if (key < r->data)
			return search(r->left, key);
		else
			return search(r->right, key);
	}

	void search(t key) {

		node* result = search(root, key);
		if (result == NULL)
			cout << "Sorry ,Im not found" << endl;
		else
			cout << "Yes ,Im found" << endl;
	}

	//***********
	//Find Minimum number in BST

	node* findmin(node* r) {
		
		if (r == NULL)  return NULL;
		else if (r->left == NULL)
			return r;
		else
			return findmin(r->left);
 	}

	void findmin() {
		node* res = findmin(root);
		if (res == NULL)
			cout << "NO items exist" << endl;
		else
			cout << "Min_item = "<<res->data << endl;
	}


	//***********
	//Find Maxmum number in BST

	node* findmax(node* r) {

		if (r == NULL)  return NULL;
		else if (r->right == NULL)
			return r;
		else
			return findmax(r->right);
	}

	void findmax() {
		node* res = findmax(root);
		if (res == NULL)
			cout << "No items exist" << endl;
		else
			cout << "Max_item = " << res->data << endl;
	}


	//************
	//Delete item in BST

	node* Delete(node* r, t key) {
		
		if (r == NULL)   return NULL;
		if (key < r->data)
			r->left = Delete(r->left, key);
		else if (key > r->data)
			r->right = Delete(r->right, key);
		else {
			if (r->left == NULL && r->right == NULL)  //leaf node
				r = NULL;
			else if (r->left != NULL && r->right == NULL) {    //one chiled on the left node
				r->data = r->left->data;
				delete r->left;
				r->left = NULL;
			}
			else if (r->left == NULL && r->right != NULL)   //one chiled on the right node
			{
				r->data = r->right->data;
				delete r->right;
				r->right = NULL;
			}
			else //node have a tow chiled
			{
				node* max = findmax(r->left);
				r->data = max->data;
				r->left=Delete(r->left, max->data);
			}
		}
		return r;
	}

	void Delete(t key) {
		node* res = Delete(root, key);
		cout << "tree after delete "<<endl;
		preorder(res);
	}


	//*************
	//Hight(BST)=> number of the last node in tree
	int gethight(node* r) {
		
		if (r == NULL) return 0;
		else
			return 1 + max(gethight(r->left), gethight(r->right));
	}

};

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
	
	//*********************************
	int key;  cin >> key;

	b.search(key);

	b.findmin();
	b.findmax();
	
	b.Delete(11);
	
	cout <<endl<< "hight= " << b.gethight(b.root)<<endl;
	
	return 0;
}