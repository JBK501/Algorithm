//#include "BinarySearchTree.h"
//#include <iostream>
//#include <vector>
//#include <Windows.h>
//
//using namespace std;
//
//void SetCursorPosition(int x, int y)
//{
//	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
//	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
//	::SetConsoleCursorPosition(output, pos);
//}
//
//void BinarySearchTree::Print(Node* node, int x, int y)
//{
//	if (node == nullptr)
//		return;
//
//	SetCursorPosition(x, y);
//	cout << node->key;
//	Print(node->left, x - (5 / (y + 1)), y+1);
//	Print(node->right, x + (5 / (y + 1)), y + 1);
//
//}
//
//void BinarySearchTree::Insert(int key)
//{
//	Node* newNode = new Node();
//	newNode->key = key;
//
//	if (_root == nullptr)
//	{
//		_root = newNode;
//		return;
//	}
//
//	Node* node = _root;
//	Node* parent = nullptr;
//
//	while (node)
//	{
//		parent = node;
//
//		if (key < node->key)
//			node = node->left;
//		else
//			node = node->right;
//	}
//
//	newNode->parent = parent;
//
//	if (key < parent->key)
//		parent->left = newNode;
//	else
//		parent->right = newNode;
//}
//
//Node* BinarySearchTree::Search(Node* node, int key)
//{
//	while (node != nullptr && node->key != key)
//	{
//		if (node->key > key)
//			node = node->left;
//		else
//			node = node->right;
//	}
//
//	return node;
//}
//
//Node* BinarySearchTree::Min(Node* node)
//{
//	while (node->left)
//		node = node->left;
//	return node;
//}
//
//Node* BinarySearchTree::Max(Node* node)
//{
//	while (node->right)
//		node = node->right;
//	return node;
//}
//
//Node* BinarySearchTree::Next(Node* node)
//{
//	if (node->right)
//		return Min(node->right);
//
//	Node* parent = node->parent;
//
//	while (parent && node == parent->right)
//	{
//		node = parent;
//		parent = parent->parent;
//	}
//
//
//	return parent;
//}
//
//void BinarySearchTree::Delete(int key)
//{
//	Node* deleteNode = Search(_root, key);
//	Delete(deleteNode);
//}
//
//void BinarySearchTree::Delete(Node* node)
//{
//	if (node == nullptr)
//		return;
//
//	if (node->left == nullptr)
//		Replace(node, node->right);
//	else if(node->right == nullptr)
//		Replace(node, node->left);
//	else
//	{
//		// 다음 데이터 찾기
//		Node* next = Next(node);
//		node->key = next->key;
//		Delete(next);
//	}
//
//
//}
//
//// u 서브트리를 v 서브트리로 교체한다.
//// 그리고 delete u
//void BinarySearchTree::Replace(Node* u, Node* v)
//{
//	if (u->parent == nullptr)
//		_root = v;
//	else if (u == u->parent->left)
//		u->parent->left = v;
//	else
//		u->parent->right = v;
//
//	if (v)
//		v->parent = u->parent;
//
//	delete u;
//}
//
//void BinarySearchTree::Print_Inorder(Node* node)
//{
//	if (node == nullptr)
//		return;
//
//	cout << node->key << endl;
//	Print_Inorder(node->left);
//	Print_Inorder(node->right);
//}
//
//int main()
//{
//	BinarySearchTree bst;
//
//	bst.Insert(20);
//	bst.Insert(10);
//	bst.Insert(30);
//	bst.Insert(25);
//	bst.Insert(26);
//	bst.Insert(40);
//	bst.Insert(50);
//
//	bst.Delete(20);
//	bst.Delete(26);
//
//	//bst.Print_Inorder();
//	bst.Print();
//}