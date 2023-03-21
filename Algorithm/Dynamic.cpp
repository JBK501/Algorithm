//#include <iostream>
//#include <Windows.h>
//#include <vector>
//
//using namespace std;
//
//// ���� ��ȹ��(DP) -- �ζ�
//
////// �޸������̼� (memoization)
////int cache[50][50];
////
////int Combination(int n, int r)
////{
////	// ���� ���
////	if (r == 0 || n == r)
////		return 1;
////
////	// �̹� ���� ���� �� ������ �ٷ� ��ȯ
////	int& ret = cache[n][r];
////	if (ret != -1)
////		return ret;
////
////	// ���� ���� ���ؼ� ĳ�ÿ� ����
////	
////	ret = Combination(n - 1, r - 1) + Combination(n - 1, r);
////	return ret;
////}
//
//
//// Lis (Longest Increasing Sequence)
//
//// Seq : 1 9 2 5 7
//// �κ� ���� : �Ϻ�(0�� �̻�) ���ڸ� ����� ���� ����
//// ex) 1 2 5
//// ex) 1 9 5 7
//// �� ���� �κ� ����
//// ex) 1 2 5 
//
//// Lis : ���� �� [�� ���� �κ� ����]�� ����
//// 1 2 5 7 = ���� 4
//
//
//int cache[100];
//vector<int> seq;
//
//int LIS(int pos)
//{
//	// ���� ����
//	/*if (pos == seq.size() - 1)
//		return 1;*/
//
//	// ĳ�� Ȯ��
//	int& ret = cache[pos];
//	if (ret != -1)
//		return ret;
//
//	// ���ϱ�
//	
//	// Seq : 1 9 2 5 7
//	// 1 9 = 2
//	// 1 2 5 7 = 4
//	// 1 5 7 = 3	ex) LIS(0) -> 1 + LIS(3) -> 1 + LIS(4)<�ݺ�>
//	// 1 7 = 2			LIS(0) -> 1 + LIS(4)<�ݺ�>.. ĳ��
//
//	// �ּ� seq[pos]�� ������ 1���� ����
//	ret = 1;
//
//	for (int next = pos + 1; next < seq.size(); next++)
//		if (seq[pos] < seq[next])
//			ret = max(ret, 1 + LIS(next));
//
//	return ret;
//}
//
//int main()
//{
//	// �ζ�
//	/*::memset(cache, -1, sizeof(cache));
//	__int64 start = GetTickCount64();
//	int lotto = Combination(45, 6);
//	__int64 end = GetTickCount64();
//	cout << "number : " << lotto << ", time : " << end - start << "ms" << endl;*/
//
//	// LIS
//	::memset(cache, -1, sizeof(cache));
//	seq = vector<int>{ 10, 1, 9, 2, 5, 7 };
//	
//	int ret = 0;
//	for (int pos = 0; pos < seq.size(); pos++)
//		ret = max(ret, LIS(pos));
//
//}