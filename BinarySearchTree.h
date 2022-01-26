#pragma once
//Fahad Waheed

#include<iostream>
using namespace std;

template <typename K, typename V>
class BST
{
	struct Node
	{
		K key;
		V value;
		Node* left, * right;

		Node() : key(K()), value(V()), left(NULL), right(NULL) {};

		Node(K key, V value) : key(key), value(value), left(NULL), right(NULL) {};
	};

	Node* root;

	void inorder(Node* node)
	{
		if (node)
		{
			inorder(node->left);
			cout << node->key << "  " << node->value << endl;
			inorder(node->right);
		}
	}

public:
	BST() : root(NULL) {};

	bool isEmpty()
	{
		return root == NULL;
	}

	void Insert(K key, V value)
	{
		if (isEmpty())
			root = new Node(key, value);
		else
		{
			Node* currnode = root;

			while (currnode)
			{
				if (currnode->key > key)
				{
					if (currnode->left)
						currnode = currnode->left;
					else
					{
						currnode->left = new Node(key, value);
						break;
					}
				}
				if (currnode->key < key)
				{
					if (currnode->right)
						currnode = currnode->right;
					else
					{
						currnode->right = new Node(key, value);
						break;
					}
				}
			}
		}
	}

	void Remove(K key, V value = V())
	{
		Node* parent = NULL;
		Node* currnode = root;

		while (currnode)
		{
			if (currnode->key == key)
				break;
			else if (currnode->key < key)
			{
				parent = currnode;
				currnode = currnode->right;
			}
			else if (currnode->key > key)
			{
				parent = currnode;
				currnode = currnode->left;
			}
		}

		if (currnode == NULL)
			return;

		if (currnode->left == NULL)//right child & no child case
		{
			if (parent == NULL)
				root = currnode->right;
			else if (parent->left == currnode)
				parent->left = currnode->right;
			else if (parent->right == currnode)
				parent->right = currnode->right;

			delete currnode;
		}

		else if (currnode->right == NULL)//left child case
		{
			if (parent == NULL)
				root = currnode->left;
			else if (parent->left == currnode)
				parent->left = currnode->left;
			else if (parent->right == currnode)
				parent->right = currnode->left;

			delete currnode;
		}

		else//both child case
		{
			Node* tempParent = NULL;
			Node* temp = currnode->right;

			while (temp->left)
			{
				tempParent = temp;
				temp = temp->left;
			}

			if (tempParent)
				tempParent->left = temp->right;
			else
				currnode->right = temp->right; // currnode->right = currnode->right->right;
				
			currnode->key = temp->key;
			currnode->value = temp->value;

			delete temp;
		}
	}

	void Display()
	{
		inorder(root);
	}
};