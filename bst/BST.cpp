//#include "TNode.h"
#include "BST.h"
#include "Student.h"
#include <iostream>
using namespace std;

	template <class DT>
TNode<DT>::TNode(DT* d)
{
	parent = NULL;
	left = NULL;
	right = NULL;
	data = *d;
}
	template <class DT>
TNode<DT>::TNode(DT d)
{
	parent = NULL;
	left = NULL;
	right = NULL;
	data = d;
}
	template <class DT>
BST<DT>::BST()
{
	root = NULL;
}

	template <class DT>
BST<DT>::~BST()
{
	cleanNodes();
}

	template <class DT>
TNode<DT>* BST<DT>::createNode()
{
	DT* data = new DT();
	TNode<DT>* newNode = new TNode<DT>(data);
	return newNode;
}
	template <>
TNode<int>* BST<int>::createNode()
{
	int* data = new int();
	cout << "What would you like to insert?" << endl;
	cin >> *data;
	TNode<int>* newNode = new TNode<int>(data);
	return newNode;
}
	template <>
TNode<Student>* BST<Student>::createNode()
{
	Student* data = new Student();
	data->inputData();
	TNode<Student>* newNode = new TNode<Student>(data);
	return newNode;
}
	template <class DT>
bool BST<DT>::bstInsert()
{
	return bstInsert(createNode());
}
	template <class DT>
bool BST<DT>::bstInsert(DT data)
{
	TNode<DT>* node = new TNode<DT>(data);
	return bstInsert(node);
}
	template <class DT>
bool BST<DT>::bstInsert(TNode<DT>* newNode)
	//returns true if the node was added successfully, false if it couldn't add it
{
	if(root == NULL)
	{
		root = newNode;
		return true;
	}
	else
	{
		TNode<DT>* current = root;
		TNode<DT>* prev = root;
		while(current)
		{
			prev = current;
			if(newNode->data <= current->data)
				current = current->left;
			else if(newNode->data > current->data)
				current = current->right;
		}//end while
		if(newNode->data <= prev->data)
			prev->left = newNode;
		else if(newNode->data > prev->data)
			prev->right = newNode;
		newNode->parent = prev;
	}
	return false;//the function should never get to this statement, only if theres an error
}
	template <class DT>
void BST<DT>::bstDelete(DT data)
{
	bstDelete(bstSearch(data));
}
	template <class DT>
void BST<DT>::bstDelete(TNode<DT>* node)
{
	if(node == NULL)
		cout << "Couldn't delete" << endl;
	else
	{
		TNode<DT>* del = node;
		TNode<DT>* replace = node;
		if(node->left == NULL || node->right == NULL)
			del = node;
		else
			del = successor(node);
		if(del->left != NULL)
			replace = del->left;
		else
			replace = del->right;
		//TRANSPLANT
		if(replace != NULL)
			replace->parent = del->parent;
		if(del->parent == NULL)
			root = replace;
		else if(del == del->parent->left)
			del->parent->left = replace;
		else
			del->parent->right = replace; 
		//end TRANSPLANT

		//if the node to be deleted is a leaf del will = replace
		if( del != replace)
			node->data = del->data;
		delete del;
	}
}

	template <class DT>
TNode<DT>* BST<DT>::bstSearch(DT data)
{
	TNode<DT>* current = root;
	while(current != NULL)
	{
		if(current->data == data)
		{
			//cout << "found" <<endl;
			return current;
		}
		if(data <= current->data)// && current->left != NULL)
			current = current->left;
		else if(data > current->data)// && current->right != NULL)
			current = current->right;
	}
	cout << "node not found" << endl;
	return NULL;//if the loop exits without returning that means the data it's 	looking for isn't in the tree
}

	template <class DT>
void BST<DT>::cleanNodes()
{
	cleanNodes(root);
}

	template <class DT>
void BST<DT>::cleanNodes(TNode<DT>* x)
{
	if(x != NULL)
	{
		cleanNodes(x->left);
		cleanNodes(x->right);
		delete x;
	}
}

	template <class DT>
TNode<DT>* BST<DT>::max()
{
	max(root);
}

	template <class DT>
TNode<DT>* BST<DT>::max(TNode<DT>* max)
{
	if(max != NULL)
		while(max->right != NULL)
		{
			max = max->right;
		}
	return max;
}

	template <class DT>
TNode<DT>* BST<DT>::min()
{
	min(root);
}

	template <class DT>
TNode<DT>* BST<DT>::min(TNode<DT>* min)
{
	if(min != NULL)	
		while(min->left != NULL)
		{
			min = min->left;
		}
	return min;
}

	template <class DT>
TNode<DT>* BST<DT>::successor()
{
	successor(root);
}

	template <class DT>
TNode<DT>* BST<DT>::successor(TNode<DT>* current)
{
	return min(current->right);
}

	template <class DT>
TNode<DT>* BST<DT>::predecessor()
{
	predecessor(root);
}

	template <class DT>
TNode<DT>* BST<DT>::predecessor(TNode<DT>* current)
{
	return max(current->left);
}

	template <class DT>
void BST<DT>::inOrder()
{
	inOrder(root);
}

	template <class DT>
void BST<DT>::inOrder(TNode<DT>* current)
{
	if(current != NULL)
	{
		inOrder(current->left);
		cout << current->data << ", ";
		inOrder(current->right);
	}
}

	template <class DT>
void BST<DT>::preOrder()
{
	preOrder(root);
}

	template <class DT>
void BST<DT>::preOrder(TNode<DT>* current)
{
	if(current != NULL)
	{
		cout << current->data << ", ";
		preOrder(current->left);
		preOrder(current->right);
	}
}

	template <class DT>
void BST<DT>::postOrder()
{
	postOrder(root);
}

	template <class DT>
void BST<DT>::postOrder(TNode<DT>* current)
{
	if(current != NULL)
	{
		postOrder(current->left);
		postOrder(current->right);
		cout << current->data << ", ";
	}
}

	template <class DT>
DT* BST<DT>::bstToArray(DT* array, int index, TNode<DT>* current)
{

//	if(current != NULL)
//	{
//		array[index] = current;
//		bstToArray(array, index/2, current->left);
//		bstToArray(array, index + index/2, current->right);
//	}
}
