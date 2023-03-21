//#include <iostream>
//#include <Windows.h>
//#include <vector>
//
//using namespace std;
//
//// 동적 계획법(DP) -- 로또
//
////// 메모이제이션 (memoization)
////int cache[50][50];
////
////int Combination(int n, int r)
////{
////	// 기저 사례
////	if (r == 0 || n == r)
////		return 1;
////
////	// 이미 답을 구한 적 있으면 바로 반환
////	int& ret = cache[n][r];
////	if (ret != -1)
////		return ret;
////
////	// 새로 답을 구해서 캐시에 저장
////	
////	ret = Combination(n - 1, r - 1) + Combination(n - 1, r);
////	return ret;
////}
//
//
//// Lis (Longest Increasing Sequence)
//
//// Seq : 1 9 2 5 7
//// 부분 수열 : 일부(0개 이상) 숫자를 지우고 남은 수열
//// ex) 1 2 5
//// ex) 1 9 5 7
//// 순 증가 부분 수열
//// ex) 1 2 5 
//
//// Lis : 제일 긴 [순 증가 부분 수열]의 길이
//// 1 2 5 7 = 길이 4
//
//
//int cache[100];
//vector<int> seq;
//
//int LIS(int pos)
//{
//	// 기저 사항
//	/*if (pos == seq.size() - 1)
//		return 1;*/
//
//	// 캐시 확인
//	int& ret = cache[pos];
//	if (ret != -1)
//		return ret;
//
//	// 구하기
//	
//	// Seq : 1 9 2 5 7
//	// 1 9 = 2
//	// 1 2 5 7 = 4
//	// 1 5 7 = 3	ex) LIS(0) -> 1 + LIS(3) -> 1 + LIS(4)<반복>
//	// 1 7 = 2			LIS(0) -> 1 + LIS(4)<반복>.. 캐싱
//
//	// 최소 seq[pos]는 있으니 1부터 시작
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
//	// 로또
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