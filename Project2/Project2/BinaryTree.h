struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* leftNode;
	BinaryTreeNode* rightNode;
};

class CBinaryTree
{
public:
	CBinaryTree();
	~CBinaryTree();
	bool IsBST(BinaryTreeNode* node);
	int SearchValueFromSortedArray(int sortedArray[], int value, int minIndex, int maxIndex);
private:
	bool IsBST(BinaryTreeNode* node, int min, int max);

};