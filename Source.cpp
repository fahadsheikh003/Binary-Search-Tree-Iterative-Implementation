#include"BinarySearchTree.h"

int main()
{
	BST<int, string> bst;

	bst.Insert(5, "D");
	
	bst.Insert(3, "B");
	bst.Insert(7, "F");
	
	bst.Insert(2, "A");
	bst.Insert(4, "C");
	
	bst.Insert(6, "E");
	bst.Insert(8, "G");

	bst.Remove(7);

	bst.Display();
}