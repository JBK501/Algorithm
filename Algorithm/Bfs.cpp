#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct vertex
{
	// int data;
};

vector<vertex> vertices;	// 정점 목록
vector<vector<int>> adjacent;	// 인접 목록
vector<bool> discovered; // 발견한 목록

void creategraph()
{
	vertices.resize(6);
	adjacent = vector<vector<int>>(6);


	 //인접 리스트
	/*adjacent[0].push_back(1);
	adjacent[0].push_back(3);
	adjacent[1].push_back(0);
	adjacent[1].push_back(2);
	adjacent[1].push_back(3);
	adjacent[3].push_back(4);
	adjacent[5].push_back(4);*/

	// 인접 행렬
	adjacent = vector<vector<int>>
	{
		{0,1,0,1,0,0},
		{1,0,1,1,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,1,0},
		{0,0,0,0,0,0},
		{0,0,0,0,1,0},
	};
}


// 1. queue에 예약
// 2. 예약한 노드 가져오기
// 3. 가져온 노드의 인접노드 개수 만큼 반복하기
//	3.1. 해당 노드를 방문했으면 다음노드로 (큐에 추가하지 않는다.)
//	3.2. 방문하지 않았다면 큐에 추가 후 방문체크
//  3.3. 추가한 노드의 부모노드 저장
//  3.4. 추가한 노드의 거리 저장

// bfs(breadt first search) 너비 우선 탐색	--> 입구에서 가까운 정점을 기준으로 탐색한다.
void Bfs(int here)
{
	// 누구에 의해 발견 되었는지?
	vector<int> parent(6, -1);

	// 시작점에서 얼만큼 떨어져 있는지?
	vector<int> distance(6, -1);


	queue<int> q;	// 발견한 정점목록을 관리하는 큐 생성 (예약시스템)
	q.push(here);	// 발견한 정점 추가
	discovered[here] = true;	// 발견여부 표시

	parent[here] = here;
	distance[here] = 0;

	while (q.empty() == false)
	{
		here = q.front();
		q.pop();

		cout << "visited : " << here << endl;


		// 인접 리스트 version
		//for (int there : adjacent[here])
		//{
		//	if (discovered[there])
		//		continue;

		//	q.push(there);	// 발견한 정점 추가
		//	discovered[there] = true;	// 발견여부 표시

		//	parent[there] = here;
		//	distance[there] = distance[here] + 1;
		//}

		// 인접 행렬 version
		for (int there = 0 ; there < 6 ; there++)
		{
			if (adjacent[here][there] == 0)
				continue;

			if (discovered[there])
				continue;

			q.push(there);	// 발견한 정점 추가
			discovered[there] = true;	// 발견여부 표시

			parent[there] = here;
			distance[there] = distance[here] + 1;
		}
	}
}

void Bfsall()
{
	for (int i = 0; i < 6; i++ )
	{
		if (discovered[i] == false)
			Bfs(i);
	}
}

//int main()
//{
//	creategraph();
//
//	discovered = vector<bool>(6, false);
//
//	Bfs(0);
//	//Bfsall();
//}