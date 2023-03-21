//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//// (N-1) + (N-2) + ... + 2 + 1
//// 시간복잡도 O(N^2)
//void BubbleSort(vector<int>& v)
//{
//	int i = v.size() - 1;
//	int j;
//	int temp;
//	
//	while (i > 0)
//	{
//		j = 0;
//		while (j < i)
//		{
//			if (v[j] > v[j + 1])
//			{
//				temp = v[j];
//				v[j] = v[j + 1];
//				v[j + 1] = temp;
//			}
//			j++;
//		}
//		i--;
//	}
//}
//
//// 시간복잡도 O(N^2)
//void SelectionSort(vector<int>& v)
//{
//	int i = 0;
//	int j;
//	int index;
//	int temp;
//
//	while (i < v.size() - 1)
//	{
//		index = i;
//		j = i + 1;
//		while (j < v.size())
//		{
//			if (v[j] < v[index])
//			{
//				index = j;
//			}
//			j++;
//		}
//		temp = v[i];
//		v[i] = v[index];
//		v[index] = temp;
//
//		i++;
//	}
//}
//
//// 시간복잡도 O(N^2)
//void InsertionSort(vector<int>& v)
//{
//	const int size = v.size();
//
//	int temp;
//	int j;
//	int i{ 1 };
//	while (i < size)
//	{
//		temp = v[i];
//		
//		j = i - 1;
//		while (j >= 0 && v[j] > temp)
//		{
//			v[j + 1] = v[j];
//			j--;
//		}
//		v[j + 1] = temp;
//		
//		i++;
//	}
//}
//
//// 힙 정렬
//void HeapSort(vector<int>& v)
//{
//	priority_queue<int, vector<int>, greater<int>> pq;
//
//	//O(NlogN)
//	for (int num : v)
//		pq.push(num);
//
//	v.clear();
//
//	//O(NlogN)
//	while (pq.empty() == false)
//	{
//		v.push_back(pq.top());
//		pq.pop();
//	}
//}
//
//
//// 병함 정렬
//// 분할 정복 (Divede and Conquer)
//// - 분할 (Divide)	문제를 더 단순하게 분할한다.
//// - 정복 (Conquer) 분할된 문제를 해결
//// - 결합 (Combine)	결과를 취합하여 마무리
//
//// [3][k][7][2][j][4][8][9]				8개 * 1
//// [3][k][7][2]	[j][4][8][9]			4개 * 2
//// [3][k]	[7][2]	[j][4]	[8][9]		2개 * 4
//// [3]	[k]	[7]	[2]	[j]	[4]	[8]	[9]		1개 * 8
//// [3][k]	[2][7]	[4][j]	[8][9]		2개 * 4
//// [2][3][7][k]	[4][8][9][j]			4개 * 2
//// [2][3][4][7][8][9][j][k]				8개 * 1
//
//void MergeResult(vector<int>& v, int left, int mid, int right)
//{
//
//	int leftIndex = left;
//	int rightIndex = mid + 1;
//
//	vector<int> temp;
//
//	while (leftIndex <= mid && rightIndex <= right)
//	{
//		if (v[leftIndex] <= v[rightIndex])
//		{
//			temp.push_back(v[leftIndex]);
//			leftIndex++;
//		}
//		else
//		{
//			temp.push_back(v[rightIndex]);
//			rightIndex++;
//		}
//	}
//
//	while (leftIndex <= mid)
//	{
//		temp.push_back(v[leftIndex]);
//		leftIndex++;
//	}
//	while (rightIndex <= right)
//	{
//		temp.push_back(v[rightIndex]);
//		rightIndex++;
//	}
//
//	for (int i = 0; i < temp.size(); i++)
//	{
//		v[left + i] = temp[i];
//	}
//
//}
//
//// O(NlogN)
//void MergeSort(vector<int>& v, int left, int right)
//{
//	if (left >= right)
//		return;
//
//	int mid = (left + right) / 2;
//	MergeSort(v,left,mid); 
//	MergeSort(v,mid+1,right);
//
//	MergeResult(v, left, mid, right);
//}
//
//int Partition(vector<int>&v, int left, int right)
//{
//	int pivot = v[left];
//	int low = left + 1;
//	int high = right;
//
//	while (low <= high)
//	{
//		while (low <= right && pivot >= v[low])
//			low++;
//
//		while (high >= left + 1 && pivot <= v[high])
//			high--;
//
//		if (low < high)
//			swap(v[low], v[high]);
//	}
//
//	swap(v[left], v[high]);
//	return high;
//}
//
//// O(N^2) 최악
//// O(NlogN) 평균
//void QuickSort(vector<int>&v, int left, int right)
//{
//	if (left > right)
//		return;
//
//	int pivot = Partition(v, left, right);
//	QuickSort(v, left, pivot - 1);
//	QuickSort(v, pivot+1, right);
//
//}
//
//
//int main()
//{
//	vector<int> v;
//
//	srand(time(0));
//
//	for (int i = 0; i < 50; i++)
//	{
//		int randValue = rand() % 100;
//		v.push_back(randValue);
//	}
//
//	//BubbleSort(v);
//	//SelectionSort(v);
//	//InsertionSort(v);
//
//	//HeapSort(v);
//
//	//MergeSort(v, 0, v.size() - 1);
//	QuickSort(v, 0, v.size() - 1);
//
//	for (int number : v)
//	{
//		cout << number << endl;
//	}
//}