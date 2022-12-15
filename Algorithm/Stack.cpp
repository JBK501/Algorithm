#include <iostream>
#include <stack>
#include <vector>
#include <list>

using namespace std;

// Stack (LIFO Last-In-First-Out ���Լ���)

// [1][2][3][4] << �о����
// �ǵ����� (Ctrl+Z)

#pragma region Stack����
template<typename T, typename Container = vector<int>>	// �⺻�����̳ʸ� ���ͷ� ����
class Stack
{
public:
	void push(const T& value)
	{
		_container.push_back(value);
	}
	void pop()
	{
		_container.pop_back();
	}
	T& top()
	{
		return _container.back();
	}
	bool empty()
	{
		return _container.empty();
	}
	int size()
	{
		return _container.size();
	}

private:
	//vector<T> _container;
	//list<T> _container; // list�� �����ϰ� �۵��Ѵ�. list�� vector�� ������ �Լ����� ���Ǳ� ����(�ٸ� �͵� ����).
	Container _container;

};
#pragma endregion

//int main()
//{
//	Stack<int, list<int>> s;	// �����̳ʸ� ����Ʈ�� �����ؼ� ���
//
//	// ����
//	s.push(1);
//	s.push(2);
//	s.push(3);
//
//	// �����?
//	while (s.empty() == false)
//	{
//		// �ֻ��� ���� ��������
//		int data = s.top();
//
//		// �ֻ��� ���� ����
//		s.pop();
//		
//		cout << data << endl;
//	}
//
//	int size = s.size();
//}

