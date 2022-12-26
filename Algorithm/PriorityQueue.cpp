//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//// --- 힙 트리 ---
//// [부모 노드]가 가진 값은 항상 [자식 노드]가 가진 값보다 크다.
//// 마지막 레벨을 제외한 모든 레벨에 노드가 꽉 차 있다. (완전 이진 트리)
//// 마지막 레벨에 노드가 있을 때는, 항상 왼쪽부터 순서대로 채워야 한다.
//// 노드의 개수를 알면, 트리 구조는 무조건 확정할 수 있다. => vector로 표현 가능
//// -> i번 노드의 왼쪽 자식은 [(2 * 1) + 1]번
//// -> i번 노드의 오른쪽 자식은[(2 * 1) + 2]번
//// -> i번 노드의 부모는 [(i - 1) / 2]번
//
//// 우선순위큐는 힙 트리구조 이다.
//// 제일 작은 값 혹은 제일 큰 값을 추출해야하는 경우가 있을 경우 우선적으로 떠올리면 좋다.
//// predicate : 어떤 조건에 의해서 판별할지를 결정한다.
//template<typename T, typename Container = vector<T>, typename Predicate = less<T>>
//class PriorityQueue
//{
//public:
//	void push(const T& data)
//	{
//		// 우선 힙 구조부터 맞춰춘다.
//		_heap.push_back(data);
//
//		// 도장깨기 시작
//		int now = static_cast<int>(_heap.size()) - 1;
//
//		// 루트 노드까지 시도한다.
//		while (now > 0)
//		{
//			// 부모 노드의 데이터와 비교해서 더 작으면 패배
//			int next = (now - 1) / 2;
//			/*if (_heap[now] < _heap[next])
//				break;*/
//			if (_predicate(_heap[now], _heap[next]))
//				break;
//
//			// 데이터 교체
//			::swap(_heap[now], _heap[next]);
//			now = next;
//		}
//	}
//	void pop()
//	{
//		_heap[0] = _heap.back();
//		_heap.pop_back();
//
//		int now = 0;
//
//		while (true)
//		{
//			int left = 2 * now + 1;
//			int right = 2 * now + 2;
//
//			// 리프에 도달한 경우
//			if (left >= (int)_heap.size())
//				break;
//
//			int next = now;
//
//			// 왼쪽과 비교
//			/*if (_heap[next] < _heap[left])
//				next = left;*/
//			if (_predicate(_heap[next], _heap[left]))
//				next = left;
//
//			// 둘 중 승자를 오른쪽과 비교
//			// right가 항상 유효하다는 보장이 없음. 따라서 사이즈 체크를 해야 함.
//			/*if (right < (int)_heap.size() && _heap[next] < _heap[right])
//				next = right;*/
//			if (right < (int)_heap.size() && _predicate(_heap[next], _heap[right]))
//				next = right;
//
//			// 왼쪽/오른쪽 둘 다 현재 값보다 작으면 종료
//			if (next == now)
//				break;
//
//			::swap(_heap[now], _heap[next]);
//
//			now = next;
//		}
//	}
//	T& top()
//	{
//		return _heap[0];
//	}
//	bool empty()
//	{
//		return _heap.empty();
//	}
//
//private:
//	Container _heap = {};
//	Predicate _predicate = {};
//};
//
//
//
//int main()
//{
//	PriorityQueue<int, vector<int>, greater<int>> pq;
//
//	pq.push(100);
//	pq.push(200);
//	pq.push(300);
//	pq.push(500);
//	pq.push(400);
//
//	while (pq.empty() == false)
//	{
//		int value = pq.top();
//		pq.pop();
//
//		cout << value << endl;
//	}
//}