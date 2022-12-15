#include <iostream>
#include <stack>
#include <vector>
#include <list>

using namespace std;

// Stack (LIFO Last-In-First-Out 후입선출)

// [1][2][3][4] << 밀어넣음
// 되돌리기 (Ctrl+Z)

#pragma region Stack구현
template<typename T, typename Container = vector<int>>	// 기본컨테이너를 벡터로 지정
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
	//list<T> _container; // list도 동일하게 작동한다. list도 vector와 동일한 함수들이 사용되기 때문(다른 것도 있음).
	Container _container;

};
#pragma endregion

//int main()
//{
//	Stack<int, list<int>> s;	// 컨테이너를 리스트로 지정해서 사용
//
//	// 삽입
//	s.push(1);
//	s.push(2);
//	s.push(3);
//
//	// 비었나?
//	while (s.empty() == false)
//	{
//		// 최상위 원소 가져오기
//		int data = s.top();
//
//		// 최상위 원소 삭제
//		s.pop();
//		
//		cout << data << endl;
//	}
//
//	int size = s.size();
//}

