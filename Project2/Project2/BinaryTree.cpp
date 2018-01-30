#include "BinaryTree.h"
#include <iostream>
CBinaryTree::CBinaryTree()
{

}
CBinaryTree::~CBinaryTree()
{

}

int CBinaryTree::SearchValueFromSortedArray(int sortedArray[], int value, int minIndex, int maxIndex)
{
	if (sortedArray == NULL) return;
	if (minIndex <= maxIndex)
	{
		int currentIndex = (minIndex + maxIndex) / 2;

		if (sortedArray[currentIndex] == value) 
			return currentIndex;
		if (value < sortedArray[currentIndex])
		{
			return SearchValueFromSortedArray(sortedArray, value, minIndex, currentIndex -1);
		}
		else
		{
			return SearchValueFromSortedArray(sortedArray, value, currentIndex + 1, maxIndex);
		}
	}
	return -1;
}
bool CBinaryTree::IsBST(BinaryTreeNode* node)
{
	return IsBST(node, INT_MIN, INT_MAX);
}
bool CBinaryTree::IsBST(BinaryTreeNode* node, int min, int max)
{
	if (node == NULL) return true;
	//if ((node->value < min) && (node->value > max)) return false;

	bool leftBST = IsBST(node->leftNode, min, node->value);
	bool rightBST = IsBST(node->rightNode, node->value + 1, max);
	if ((node->value >= min) && (node->value <= max))
	{
		return leftBST && rightBST;
	}
	else
	{
		return  false;
	}
}