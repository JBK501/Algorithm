#include "RedBlackTree.h"
#include <iostream>
#include <vector>
#include <Windows.h>
#include <thread>

using namespace std;

enum class ConsoleColor
{
	BLACK = 0,
	RED = FOREGROUND_RED,
	GREEN = FOREGROUND_GREEN,
	BLUE = FOREGROUND_BLUE,
	YELLOW = RED | GREEN,
	WHITE = RED | GREEN | BLUE,
};

void SetCursorColor(ConsoleColor color)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::SetConsoleTextAttribute(output, static_cast<SHORT>(color));
}

void SetCursorPosition(int x, int y)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	::SetConsoleCursorPosition(output, pos);
}

void ShowConsoleCursor(bool flag)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	::GetConsoleCursorInfo(output, &cursorInfo);
	cursorInfo.bVisible = flag;
	::SetConsoleCursorInfo(output, &cursorInfo);
}

RedBlackTree::RedBlackTree()
{
	_nil = new Node(); // Black
	_root = _nil;
}

RedBlackTree::~RedBlackTree()
{
	delete _nil;
}

void RedBlackTree::Print()
{
	::system("cls");
	ShowConsoleCursor(false);
	{Print(_root, 10, 0); }
}

void RedBlackTree::Print(Node* node, int x, int y)
{
	if (node == _nil)
		return;

	SetCursorPosition(x, y);
	
	if (node->color == Color::Black)
		SetCursorColor(ConsoleColor::BLUE);
	else
		SetCursorColor(ConsoleColor::RED);

	cout << node->key;
	Print(node->left, x - (5 / (y + 1)), y+1);
	Print(node->right, x + (5 / (y + 1)), y + 1);

	SetCursorColor(ConsoleColor::WHITE);
}

Node* RedBlackTree::Min(Node* node)
{
	while (node->left != _nil)
		node = node->left;
	
	return node;	
}

Node* RedBlackTree::Max(Node* node)
{
	while (node->right != _nil)
		node = node->right;

	return node;
}

Node* RedBlackTree::Next(Node* node)
{
	if (node->right != _nil)
		return Min(node->right);
		
	Node* parent = node->parent;
		
	while (parent != _nil && node == parent->right)
	{
		node = parent;
		parent = parent->parent;
	}
		
	return parent;
}

void RedBlackTree::Insert(int key)
{
		Node* newNode = new Node();
		newNode->key = key;
	
		Node* node = _root;
		Node* parent = _nil;
	
		while (node != _nil)
		{
			parent = node;
	
			if (key < node->key)
				node = node->left;
			else
				node = node->right;
		}
	
		newNode->parent = parent;
	
		if (parent == _nil)
			_root = newNode;

		if (key < parent->key)
			parent->left = newNode;
		else
			parent->right = newNode;

		// 검사
		newNode->left = _nil;
		newNode->right = _nil;
		newNode->color = Color::Red;

		InsertFixup(newNode);
}

void RedBlackTree::InsertFixup(Node* node)
{
	// 1) p == red, uncle == red
	// -> p = black, uncle = black, pp = red로 바꾼다.
	// 2) p == red, uncle == black (triangle case)
	// -> 회전을 통해서 case3으로 바꾼다.
	// 3) p == red, uncle == black (list case)
	// -> 색상 변경 + 회전한다.


	while (node->parent->color == Color::Red)
	{
		if (node->parent == node->parent->parent->left)
		{
			//			[pp(B)]
			//		[p(R)]	  [u(?)]
			//		   [n(R)]
			Node* uncle = node->parent->parent->right;
			
			if (uncle->color == Color::Red)
			{
				//			[pp(B)]
				//		[p(R)]	  [u(R)]
				//		   [n(R)]			일때
				node->parent->color = Color::Black;
				uncle->color = Color::Black;
				node->parent->parent->color = Color::Red;

				node = node->parent->parent; // ppp가 R이면 조건을 위반하므로 pp에서 다시 실행한다.
			}
			else
			{
				// Trianle 타입
				
				//			[pp(B)]
				//		[p(R)]	  [u(B)]
				//		   [n(R)]			일때(triangle case)

				// Lotate를 사용하여 List 타입을 만든다.
				//			[pp(B)]
				//		[p(R)]  [u(B)]
				//	[n(R)]

				if (node == node->parent->right)
				{
					node = node->parent;
					LeftRotate(node);
				}

				// List 타입

				//			[pp(B)]
				//		[p(R)]	  [u(R)]
				//	[n(R)]					

				//			[p(B)]
				//		[n(R)]	 [pp(R)]
				//					 [u(B)]
				node->parent->color = Color::Black;
				node->parent->parent->color = Color::Red;
				RightRotate(node->parent->parent);
			}
		}
		else
		{
			//			[pp(B)]
			//		[u(?)]	[p(R)]	  
			//					[n(R)]
			Node* uncle = node->parent->parent->left;

			if (uncle->color == Color::Red)
			{
				//			[pp(B)]
				//		[u(R)]	[p(R)]	  
				//					[n(R)]
				node->parent->color = Color::Black;
				uncle->color = Color::Black;
				node->parent->parent->color = Color::Red;

				node = node->parent->parent; // ppp가 R이면 조건을 위반하므로 pp에서 다시 실행한다.
			}
			else
			{
				if (node == node->parent->left)
				{
					node = node->parent;
					RightRotate(node);
				}

				node->parent->color = Color::Black;
				node->parent->parent->color = Color::Red;
				LeftRotate(node->parent->parent);
			}
		}
	}
	_root->color = Color::Black;
}

Node* RedBlackTree::Search(Node* node, int key)
{
	if (node == _nil || key == node->key)
		return node;

	if (key < node->key)
		return Search(node->left, key);
	else
		return Search(node->right, key);
}

void RedBlackTree::Delete(int key)
{
	Node* deleteNode = Search(_root, key);
	Delete(deleteNode);
}

// 먼저 BST 삭제 실행

void RedBlackTree::Delete(Node* node)
{
	if (node == _nil)
		return;

	if (node->left == _nil)
	{
		Color color = node->color;
		Node* right = node->right;
		Replace(node, node->right);

		if (color == Color::Black)
			DeleteFixup(right);
	}
	else if (node->right == _nil)
	{
		Color color = node->color;
		Node* left = node->left;
		Replace(node, node->left);

		if (color == Color::Black)
			DeleteFixup(left);
		
	}
	else
	{
		// 다음 데이터 찾기
		Node* next = Next(node);
		node->key = next->key;
		Delete(next);
	}
}

void RedBlackTree::DeleteFixup(Node* node)
{
	Node* x = node;

	while (x != _root && x->color == Color::Black)
	{
		if (x == x->parent->left)
		{
			Node* s = x->parent->right;
			
			if (s->color == Color::Red)
			{
				s->color = Color::Black;
				x->parent->color = Color::Red;

				LeftRotate(x->parent);
				s = x->parent->right; 
			}

			if (s->left->color == Color::Black && s->right->color == Color::Black)
			{
				s->color = Color::Red;
				x = x->parent;
			}
			else
			{
				if (s->right->color == Color::Black)
				{
					s->left->color = Color::Black;
					s->color = Color::Red;
					RightRotate(s);
					s = x->parent->right;
				}

				s->color = x->parent->color;
				x->parent->color = Color::Black;
				x->right->color = Color::Black;
				LeftRotate(x->parent);
				x = _root;
			}
		}
		else
		{
			Node* s = x->parent->left;

			if (s->color == Color::Red)
			{
				s->color = Color::Black;
				x->parent->color = Color::Red;

				RightRotate(x->parent);
				s = x->parent->left;
			}

			if (s->right->color == Color::Black && s->left->color == Color::Black)
			{
				s->color = Color::Red;
				x = x->parent;
			}
			else
			{
				if (s->left->color == Color::Black)
				{
					s->right->color = Color::Black;
					s->color = Color::Red;
					LeftRotate(s);
					s = x->parent->left;
				}

				s->color = x->parent->color;
				x->parent->color = Color::Black;
				x->left->color = Color::Black;
				RightRotate(x->parent);
				x = _root;
			}
		}
	}


	x->color = Color::Black;


}

void RedBlackTree::Replace(Node* u, Node* v)
{
	if (u->parent == _nil)
		_root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;

	v->parent = u->parent;

	delete u;
}




void RedBlackTree::LeftRotate(Node* x)
{

	//		[x]
	//	[1]		[y]
	// 		  [2] [3]
	 

	//		[y]
	//	[x]		[3]
	//[1] [2]

	Node* y = x->right;

	x->right = y->left;	//[2]

	if(y->left != _nil)
		y->left->parent = x;

	y->parent = x->parent;

	if (x->parent == _nil)
		_root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;

	y->left = x;
	x->parent = y;
}

void RedBlackTree::RightRotate(Node* y)
{
	//		[y]
	//	[x]		[3]
	//[1] [2]
	

	//		[x]
	//	[1]		[y]
	// 		  [2] [3]

	Node* x = y->left;

	y->left = x->right;	//[2]

	if (x->right != _nil)
		x->right->parent = y;

	x->parent = y->parent;

	if (y->parent == _nil)
		_root = x;
	else if (y == y->parent->left)
		y->parent->left = x;
	else
		y->parent->right = x;

	x->right = y;
	y->parent = x;
}

int main()
{
	RedBlackTree rbt;

	rbt.Insert(30);
	rbt.Print();
	this_thread::sleep_for(1s);

	rbt.Insert(10);
	rbt.Print();
	this_thread::sleep_for(1s);

	rbt.Insert(20);
	rbt.Print();
	this_thread::sleep_for(1s);

	rbt.Insert(25);
	rbt.Print();
	this_thread::sleep_for(1s);

	rbt.Insert(40);
	rbt.Print();
	this_thread::sleep_for(1s);

	rbt.Insert(50);
	rbt.Print();
	this_thread::sleep_for(1s);

	rbt.Delete(20);
	rbt.Print();
	this_thread::sleep_for(1s);

	rbt.Delete(10);
	rbt.Print();
	this_thread::sleep_for(1s);
}