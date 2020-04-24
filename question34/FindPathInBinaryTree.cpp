#include"binarytree.h"
#include<iostream>
#include<vector>
using namespace std;

void FindPathProcess( Position treeRoot, int targetNum, vector<int> & BinaryTreeNodeData, int pathDataSum )
{
	pathDataSum += treeRoot->m_nValue;
	BinaryTreeNodeData.push_back( treeRoot->m_nValue );
	
	bool isLeef = ( treeRoot->m_pLeft == nullptr ) && ( treeRoot->m_pRight == nullptr );
	if( pathDataSum == targetNum && isLeef )
	{
		for( auto i = BinaryTreeNodeData.begin(); i != BinaryTreeNodeData.end(); i++ )
			cout << *i << ' ';
		cout << endl;
	}
	if( treeRoot->m_pLeft != nullptr )
		FindPathProcess( treeRoot->m_pLeft, targetNum, BinaryTreeNodeData, pathDataSum );
	if( treeRoot->m_pRight != nullptr )
		FindPathProcess( treeRoot->m_pRight, targetNum, BinaryTreeNodeData, pathDataSum );
	BinaryTreeNodeData.pop_back();
}

void FindPathInBinaryTree( Position treeRoot, int targetNum )
{
	if( treeRoot == nullptr || targetNum <= 0 )
		return;
	vector<int> BinaryTreeNodeData;
	int pathDataSum = 0;
	FindPathProcess( treeRoot, targetNum, BinaryTreeNodeData, pathDataSum );
}

void Test1()
{
	cout << "test1: 功能测试" << endl;
	Position binaryTreeNode_10 = NewBinaryTreeNode( 10 );
	Position binaryTreeNode_5 = NewBinaryTreeNode( 5 );
	Position binaryTreeNode_12 = NewBinaryTreeNode( 12 );
	Position binaryTreeNode_4 = NewBinaryTreeNode( 4 );
	Position binaryTreeNode_7 = NewBinaryTreeNode( 7 );
	ConnectBinaryTreeNode( binaryTreeNode_10, binaryTreeNode_5, binaryTreeNode_12 );
	ConnectBinaryTreeNode( binaryTreeNode_5, binaryTreeNode_4, binaryTreeNode_7 );
	Position treeRoot = binaryTreeNode_10;
	int targetNum = 22;
	cout << "正确的输出: " << endl;
	cout << "10 5 7" << endl;
	cout << "10 12" << endl;
	cout << "实际的输出: " << endl;
	FindPathInBinaryTree( treeRoot, targetNum );
	DeleteAll( treeRoot );
}

void Test2()
{
	cout << "test2: 功能测试" << endl;
	Position binaryTreeNode_10 = NewBinaryTreeNode( 10 );
	Position binaryTreeNode_12 = NewBinaryTreeNode( 12 );
	Position binaryTreeNode_8 = NewBinaryTreeNode( 8 );
	Position binaryTreeNode_4 = NewBinaryTreeNode( 4 );
	Position binaryTreeNode_7 = NewBinaryTreeNode( 7 );
	ConnectBinaryTreeNode( binaryTreeNode_10, binaryTreeNode_12, binaryTreeNode_8 );
	ConnectBinaryTreeNode( binaryTreeNode_12, binaryTreeNode_4, binaryTreeNode_7 );
	Position treeRoot = binaryTreeNode_10;
	int targetNum = 22;
	cout << "正确的输出: " << endl;
	cout << "实际的输出: " << endl;
	FindPathInBinaryTree( treeRoot, targetNum );
	DeleteAll( treeRoot );
}

void Test3()
{
	cout << "test3: 负面测试" << endl;
	Position treeRoot = nullptr;
	int targetNum = 22;
	cout << "正确的输出: " << endl;
	cout << "实际的输出: " << endl;
	FindPathInBinaryTree( treeRoot, targetNum );
	DeleteAll( treeRoot );
}

int main()
{
	Test1();
	Test2();
	Test3();
	
	return 0;
}
