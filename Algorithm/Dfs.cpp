//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//struct Vertex
//{
//	// int data;
//};
//
//vector<Vertex> vertices;	// 정점 목록
//vector<vector<int>> adjacent;	// 인접 목록
//vector<bool> visited; // 방문한 목록
//
//void CreateGraph()
//{
//	vertices.resize(6);
//	adjacent = vector<vector<int>>(6);
//
//
//	// 인접 리스트
//	/*adjacent[0].push_back(1);
//	adjacent[0].push_back(3);
//	adjacent[1].push_back(0);
//	adjacent[1].push_back(2);
//	adjacent[1].push_back(3);
//	adjacent[3].push_back(4);
//	adjacent[5].push_back(4);*/
//
//	// 인접 행렬
//	adjacent = vector<vector<int>>
//	{
//		{0,1,0,1,0,0},
//		{1,0,1,1,0,0},
//		{0,0,0,0,0,0},
//		{0,0,0,0,1,0},
//		{0,0,0,0,0,0},
//		{0,0,0,0,1,0},
//	};
//
//
//}
//
//// DFS(Depth First Search) 깊이 우선 탐색	--> 길이 있으면 일단 들어가고 본다.
//void Dfs(int here)
//{
//	// 방문체크!
//	visited[here] = true;
//	cout << "Visited : " << here << endl;
//	
//	// 인접 리스트 version
//	// 모든 인접 정점을 순회한다.
//	/*for (int i = 0; i < adjacent[here].size(); i++)
//	{
//		int there = adjacent[here][i];
//
//		// 방문한 적이 없다면
//		if (visited[there] == false)	
//			Dfs(there);		// 방문한다.
//	}*/
//
//	// 인접 행렬 version
//	// 모든 인접 정점을 순회한다.
//	for (int there = 0; there < 6; there++)
//	{
//		if (adjacent[here][there] == 0)
//			continue;
//
//		// 아직 방문하지 않는 곳이 있으면 방문한다.
//		if (visited[there] == false)
//			Dfs(there);
//	}
//
//}
//
//// 연결이 끊긴 부분도 탐색
//void DfsAll()
//{
//	visited = vector<bool>(6, false);
//
//	for (int i = 0; i < 6; i++)
//	{
//		if (visited[i] == false)
//		{
//			Dfs(i);
//		}
//	}
//}
//
////
////int main()
////{
////	CreateGraph();
////
////	//visited = vector<bool>(6, false);
////	//Dfs(0);
////
////	DfsAll();
////}