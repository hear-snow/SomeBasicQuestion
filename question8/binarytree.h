struct BinaryTreeNode;
typedef BinaryTreeNode * Position;

struct BinaryTreeNode
{
	int m_nValue;
	Position m_pParent;
	Position m_pLeft;
	Position m_pRight;
};

void PreorderFindProcess( Position TreeNode, Position * FindNode, int Target );
Position FindTree( const Position TreeRoot, int Target );
void DeleteTree( Position TreeRoot );
