#include <iostream>
#include "BinaryTree.h"
#include "CustomString.h"
int main()
{
	//BinaryTreeNode* rootNode = new BinaryTreeNode();
	//BinaryTreeNode* leftNode = new BinaryTreeNode();
	//BinaryTreeNode* rightNode = new BinaryTreeNode();
	//rootNode->value = 10;
	//rootNode->leftNode = leftNode;
	//rootNode->rightNode = rightNode;
	//leftNode->value = 9;
	//rightNode->value = 11;
	//CBinaryTree* BinaryTree = new CBinaryTree();
	//BinaryTree->IsBST(rootNode);

	CustomString* customStringObj = new CustomString();
	int original[] = { 1, 2, 3};
	int newArray[] = { -1, -1, -1};

	std::string prefix = "";
	std::string postFix = "Yash";
//	customStringObj->PrintAllPermutation(original, 5, 0);
	//customStringObj->PrintAllPermutation(prefix, postFix);
	//customStringObj->DiceRoll(4);
	customStringObj->PrintAllSubSet(original, newArray, 3, 3);
	return 0;
}