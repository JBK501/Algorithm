//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//// Q) map vs hash_map(C++11 표준 unordered_map)
//
//// C# dictionary == C++ map(X)
//// C# dictionary == C++ unordered_map
//
//// ------------------------------------------------------------------------------------------------------
//// <면접 질문>
//// map
//// Red-Black Tree구조로 만들어져 있어서 트리구조로 데이터를 관리한다.
//// 이진트리를 유지하지만 균형을 맞춰줘가지고 한쪽으로 쏠리는 것을 예방한다.
//// -추가/탐색/삭제 O(logN)시간 복잡도를 따른다.
//
//// hash_map (unordered_map)
//// 속도적인 측면에서 보면 해시맵이 훨씬 빠르다.
//// -추가/탐색/삭제 O(1)시간복잡도를 가진다.
//// 메모리를 내주고 속도를 취하는 방식이기 때문에 충돌이 일어나지 않는다면 해시맵이 훨씬 더 빠르다.
//// ------------------------------------------------------------------------------------------------------
//
//// '해시' '테이블'
//// 테이블로 데이터를 관리하되, 해시값을 추출해서 키 값을 어떻게 활용할지를 결정한다.
//// 사용하는 이유: 테이블을 사용해서 데이터에 빠르게 접근하기 위해서.
//// 충돌이 일어나지 않고 정상적으로 잘 동작만 한다면 레드블랙트리보다 훨씬 효과적으로 동작한다.
//// O(1)
//void TestTable()
//{
//	struct User
//	{
//		int userId = 0; // 1-999
//		string username;
//	};
//
//	vector<User> users;
//	users.resize(1000);
//
//	// 777번 유저 정보 세팅
//	users[777] = User{ 777,"Rookiss" };
//
//	// 777번 유저 이름은?
//	string name = users[777].username;
//	cout << name << endl;
//
//	// 테이블
//	// 키를 알면, 데이터를 단번에 찾을 수 있다.
//
//	// 문제의 상황
//	// int32_max (3억~)
//	// 메모리도 무한은 아니다..
//
//}
//
//// 보안
//// id : rookiss + pw : qwer1234	<과거>
//// id : rookiss + pw : hash(qwer1234) -> fqekfnf13f1vnekjn  hash함수를 이용해 변환하여 DB에 저장한다. <현재>
//
//// DB [rookiss][qwer1234] <과거>
//// DB [rookiss][fqekfnf13f1vnekjn] <현재>
//
//// 홈페이지 쪽에서도 비밀번호를 알 수가 없음.
//// 비밀번호의 해시값만 알고있을 뿐임.
//// 비밀번호를 통해 해시값은 알 수 있지만 해시값을 통해 비밀번호를 알아낼 수는 없음.
//// 따라서 비밀번호를 잃어버렸을 경우 보통 아래의 과정을 거치는 것임.
//// 비밀번호 찾기 -> 아이디 입력 / 폰 인증 -> 새 비밀번호를 입력하세요..
//
//void TestHash()
//{
//	struct User
//	{
//		int userId = 0; // 1-int32_max
//		string username;
//	};
//
//	vector<User> users;
//	users.resize(1000);
//
//
//	// 해시 : 고유키값을 이용해서 어떤 칸(버킷)을 사용할 지 결정하는 개념.
//	const int userid = 123456789;
//	int key = (userid % 1000); // hash < 고유번호 추출
//
//
//	// 123456789번 유저 정보 세팅
//	users[key] = User{ userid,"Rookiss" };
//
//	// 123456789번 유저 이름은?
//	User& user = users[key];
//	if (user.userId == userid)
//	{
//		string name = user.username;
//		cout << name << endl;
//	}
//
//	// 충돌 문제!
//	// 이 알고리즘의 경우
//	// 123456789와 789가 충돌함!
//
//	// 아이디는 엄청나게 크지만 실제로 사용하는 데이터가 적을 경우..
//	// 충돌이 발생한 자리를 대신해서 다른 빈자리를 찾아나서면 된다.
//	// - 선형 조사법 (linear probing)
//	// hash(key) + 1 -> hash(key) + 2...
//	// - 이차 조사법 (quardratic probing)
//	// hash(key) + 1^2 -> hash(key) + 2^2...
//
//
//
//}
//
//// 체이닝 (충돌 문제 해결)
//void TestHashTableChaining()
//{
//	struct User
//	{
//		int userId = 0; // 1-int32_max
//		string username;
//	};
//
//	// 메모리는 엄청나게 손해를 볼지언정 데이터는 굉장히 빠르게 접근할 수 있다.
//	vector<vector<User>> users;
//	users.resize(1000);
//
//	const int userid = 123456789;
//	int key = (userid % 1000); // hash < 고유번호 추출
//
//	users[key].push_back(User{ userid,"Rookiss" });
//	users[789].push_back(User{ 789,"Faker" });
//
//	// 123456789번 유저 이름은?
//	vector<User>& bucket = users[key];
//	for (User& user : bucket)
//	{
//		if (user.userId == userid)
//		{
//			string name = user.username;
//			cout << name << endl;
//		}
//	}
//}
//
//int main()
//{
//	//TestTable();
//	//TestHash();
//	TestHashTableChaining();
//}