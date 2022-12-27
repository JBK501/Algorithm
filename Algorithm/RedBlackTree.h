#pragma once


enum class Color
{
	Red = 0,
	Black = 1
};

struct Node
{
	Node* parent = nullptr;
	Node* left = nullptr;
	Node* right = nullptr;
	int			key = {};
	Color color = Color::Black;
};


// Red-Black Tree
// 1) 모든 노드는 Red or Black이다.
// 2) Root노드는 Black이다.
// 3) Leaf(NIL)노드는 Black이다.
// 4) Red 노드의 자식은 Black이다. (연속해서 Red-Red 는 불가능)
// 5) 각 노드로부터 - 리프까지 가는 경로들은 모두 같은 수의 Black노드를 만난다.	

class RedBlackTree
{
public:

	RedBlackTree();
	~RedBlackTree();

	void		Print();
	void		Print(Node* node, int x, int y);

	Node*		Min(Node* node);
	Node*		Max(Node* node);
	Node*		Next(Node* node);

	void		Insert(int key);
	void		InsertFixup(Node* node);
	Node*		Search(Node* node, int key);
	void		Delete(int key);
	void		Delete(Node* node);
	void		DeleteFixup(Node* node);
	void		Replace(Node* u, Node* v);

	void		LeftRotate(Node* node);
	void		RightRotate(Node* node);

private:
	Node*		_root = nullptr;
	Node*		_nil = nullptr;
};

