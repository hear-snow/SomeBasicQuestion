struct BinaryTreeNode;
typedef BinaryTreeNode * Position;

struct BinaryTreeNode
{
	int m_nValue;
	Position m_pLeft;
	Position m_pRight;
};

void PosorderShowProcess( Position TreeRoot );
void PosorderShowTree( const Position TreeRoot );
void DeleteTree( Position TreeRoot );
