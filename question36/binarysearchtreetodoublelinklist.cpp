#include"binarysearchtree.h"
#include<iostream>
using namespace std;

void ChangeTreeNode( Position pTreeNode, Position* pListLastNode )
{
	if( pTreeNode == nullptr )
		return;
		
	ChangeTreeNode( pTreeNode->m_pLeft, pListLastNode );			   //中序遍历 
	
	pTreeNode->m_pLeft = *pListLastNode;
	if( *pListLastNode != nullptr )							   		   //需要注意*pListLastNode为空的特殊情况 
		( *pListLastNode )->m_pRight = pTreeNode;
	*pListLastNode = pTreeNode;										   //更新*pListLastNode
	
	ChangeTreeNode( pTreeNode->m_pRight, pListLastNode );
}

Position BinarySearchTreeToDoubleLinkList( Position pTreeRoot )
{
	if( pTreeRoot == nullptr )
		return nullptr;
	Position pListLastNode = nullptr;
	ChangeTreeNode( pTreeRoot, &pListLastNode );						//调整树节点指针顺序，构建双向链表 
	Position pListHead = pListLastNode;
	while( pListHead != nullptr && pListHead->m_pLeft != nullptr )		//通过链表尾节点得到头结点并返回 
		pListHead = pListHead->m_pLeft; 
	return pListHead;
}

void PrintDoubleLinkList( Position pListHead )
{
	if( pListHead == nullptr )
		return;
	Position pListNode = pListHead;
	while( pListNode->m_pRight != nullptr )
	{
		cout << pListNode->m_nValue << ' ';
		pListNode = pListNode->m_pRight;
	}
	cout << pListNode->m_nValue << ' ';
	cout << endl;
	while( pListNode != nullptr )
	{
		cout << pListNode->m_nValue << ' ';
		pListNode = pListNode->m_pLeft;
	}
	cout << endl;
}

void DeleteAll( Position pListNode )
{
	if( pListNode != nullptr )
	{
		DeleteAll( pListNode->m_pLeft );
		delete pListNode;
	}
}

void Test1()
{
	cout << "test1: 功能测试" << endl;
	Position pTreeNode_10 = CreateNewTreeNode( 10 );
	Position pTreeNode_6 = CreateNewTreeNode( 6 );
	Position pTreeNode_14 = CreateNewTreeNode( 14 );
	Position pTreeNode_4 = CreateNewTreeNode( 4 );
	Position pTreeNode_8 = CreateNewTreeNode( 8 );
	Position pTreeNode_12 = CreateNewTreeNode( 12 );
	Position pTreeNode_16 = CreateNewTreeNode( 16 );
	ConnectTreeNode( pTreeNode_10, pTreeNode_6, pTreeNode_14 );
	ConnectTreeNode( pTreeNode_6, pTreeNode_4, pTreeNode_8 );
	ConnectTreeNode( pTreeNode_14, pTreeNode_12, pTreeNode_16 );
	Position pTreeRoot = pTreeNode_10;
	cout << "正确的输出: " << endl;
	cout << "4 6 8 10 12 14 16" << endl;
	cout << "16 14 12 10 8 6 4" << endl;
	cout << "实际的输出: " << endl;
	Position pDoubleLinkList = BinarySearchTreeToDoubleLinkList( pTreeRoot );
	PrintDoubleLinkList( pDoubleLinkList );
	DeleteAll( pDoubleLinkList );
}

void Test2()
{
	cout << "test2: 负面测试" << endl;
	Position pTreeRoot = nullptr;
	cout << "正确的输出: " << endl;
	cout << "实际的输出: " << endl;
	Position pDoubleLinkList = BinarySearchTreeToDoubleLinkList( pTreeRoot );
	PrintDoubleLinkList( pDoubleLinkList );
	DeleteAll( pDoubleLinkList );
}

int main()
{
	Test1();
	Test2();
	
	return 0;
}
