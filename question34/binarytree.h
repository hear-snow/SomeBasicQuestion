struct BinaryTreeNode;
typedef BinaryTreeNode* Position;

struct BinaryTreeNode
{
	int m_nValue;
	Position m_pLeft;
	Position m_pRight;
};

Position NewBinaryTreeNode( int itemValue );
void ConnectBinaryTreeNode( Position treeRoot, Position treeLeft, Position treeRight );
void DeleteAll( Position treeRoot );
