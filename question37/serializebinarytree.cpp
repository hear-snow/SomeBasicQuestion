#include"binarytree.h"
#include<iostream>
#include<string>
using namespace std;

void SerializeBinaryTree( Position pTreeNode, string & serializeTreeNode )
{
	if( pTreeNode == nullptr )
	{
		serializeTreeNode += "$,";
		return; 
	}
	serializeTreeNode += to_string( pTreeNode->m_nValue );
	serializeTreeNode += ',';
	SerializeBinaryTree( pTreeNode->m_pLeft, serializeTreeNode );
	SerializeBinaryTree( pTreeNode->m_pRight, serializeTreeNode );
}

bool GetNumInString( const string & serializeTreeNode, int & currentNum, int & itemValue )
{
	if( serializeTreeNode[ currentNum ] != '$' )
	{
		while( serializeTreeNode[ currentNum ] != ',' )
		{
			itemValue = itemValue * 10 + serializeTreeNode[ currentNum ] - '0';
			currentNum++;
		}
		currentNum++;
		return true;
	}
	currentNum += 2;
	return false;
}

void DeSerializeProcess( Position * pNewTreeNode, const string & serializeTreeNode, int & currentNum )
{
	int itemValue = 0;
	if( GetNumInString( serializeTreeNode, currentNum, itemValue ) )
	{
		*pNewTreeNode = new BinaryTreeNode;
		( *pNewTreeNode )->m_nValue = itemValue;
		( *pNewTreeNode )->m_pLeft = nullptr;
		( *pNewTreeNode )->m_pRight = nullptr;
		DeSerializeProcess( &( ( *pNewTreeNode )->m_pLeft ), serializeTreeNode, currentNum );
		DeSerializeProcess( &( ( *pNewTreeNode )->m_pRight ), serializeTreeNode, currentNum );
	}
}

Position DeSerializeBinaryTree( const string & serializeTreeNode )
{
	Position pNewTreeRoot = nullptr;
	int currentNum = 0;
	DeSerializeProcess( &pNewTreeRoot, serializeTreeNode, currentNum );
	return pNewTreeRoot;
}

void Test1()
{
	cout << "test1: 功能测试" << endl;
	Position pTreeNode_1 = CreateNewTreeNode( 1 );
	Position pTreeNode_2 = CreateNewTreeNode( 2 );
	Position pTreeNode_3 = CreateNewTreeNode( 3 );
	Position pTreeNode_4 = CreateNewTreeNode( 4 );
	Position pTreeNode_5 = CreateNewTreeNode( 5 );
	Position pTreeNode_6 = CreateNewTreeNode( 6 );
	ConnectTreeNode( pTreeNode_1, pTreeNode_2, pTreeNode_3 );
	ConnectTreeNode( pTreeNode_2, pTreeNode_4, nullptr );
	ConnectTreeNode( pTreeNode_3, pTreeNode_5, pTreeNode_6 );
	Position pTreeRoot = pTreeNode_1;
	cout << "正确的输出: ";
	PrintTreeNode( pTreeRoot );
	cout << endl;
	cout << "实际的输出: "; 
	string serializeTreeNode;
	SerializeBinaryTree( pTreeRoot, serializeTreeNode );
	Position pNewTreeRoot = DeSerializeBinaryTree( serializeTreeNode );
	PrintTreeNode( pNewTreeRoot );
	cout << endl;
	DeleteAll( pTreeRoot );
	DeleteAll( pNewTreeRoot );
}

void Test2()
{
	cout << "test2: 负面测试" << endl;
	Position pTreeRoot = nullptr;
	cout << "正确的输出: ";
	PrintTreeNode( pTreeRoot );
	cout << endl;
	cout << "实际的输出: ";
	string serializeTreeNode;
	SerializeBinaryTree( pTreeRoot, serializeTreeNode );
	Position pNewTreeRoot = DeSerializeBinaryTree( serializeTreeNode );
	PrintTreeNode( pNewTreeRoot );
	cout << endl;
	DeleteAll( pTreeRoot );
	DeleteAll( pNewTreeRoot );
}

int main()
{
	Test1();
	Test2();
	
	return 0;
}
