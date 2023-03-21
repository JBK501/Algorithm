//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//// Q) map vs hash_map(C++11 ǥ�� unordered_map)
//
//// C# dictionary == C++ map(X)
//// C# dictionary == C++ unordered_map
//
//// ------------------------------------------------------------------------------------------------------
//// <���� ����>
//// map
//// Red-Black Tree������ ������� �־ Ʈ�������� �����͸� �����Ѵ�.
//// ����Ʈ���� ���������� ������ �����డ���� �������� �򸮴� ���� �����Ѵ�.
//// -�߰�/Ž��/���� O(logN)�ð� ���⵵�� ������.
//
//// hash_map (unordered_map)
//// �ӵ����� ���鿡�� ���� �ؽø��� �ξ� ������.
//// -�߰�/Ž��/���� O(1)�ð����⵵�� ������.
//// �޸𸮸� ���ְ� �ӵ��� ���ϴ� ����̱� ������ �浹�� �Ͼ�� �ʴ´ٸ� �ؽø��� �ξ� �� ������.
//// ------------------------------------------------------------------------------------------------------
//
//// '�ؽ�' '���̺�'
//// ���̺�� �����͸� �����ϵ�, �ؽð��� �����ؼ� Ű ���� ��� Ȱ�������� �����Ѵ�.
//// ����ϴ� ����: ���̺��� ����ؼ� �����Ϳ� ������ �����ϱ� ���ؼ�.
//// �浹�� �Ͼ�� �ʰ� ���������� �� ���۸� �Ѵٸ� �����Ʈ������ �ξ� ȿ�������� �����Ѵ�.
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
//	// 777�� ���� ���� ����
//	users[777] = User{ 777,"Rookiss" };
//
//	// 777�� ���� �̸���?
//	string name = users[777].username;
//	cout << name << endl;
//
//	// ���̺�
//	// Ű�� �˸�, �����͸� �ܹ��� ã�� �� �ִ�.
//
//	// ������ ��Ȳ
//	// int32_max (3��~)
//	// �޸𸮵� ������ �ƴϴ�..
//
//}
//
//// ����
//// id : rookiss + pw : qwer1234	<����>
//// id : rookiss + pw : hash(qwer1234) -> fqekfnf13f1vnekjn  hash�Լ��� �̿��� ��ȯ�Ͽ� DB�� �����Ѵ�. <����>
//
//// DB [rookiss][qwer1234] <����>
//// DB [rookiss][fqekfnf13f1vnekjn] <����>
//
//// Ȩ������ �ʿ����� ��й�ȣ�� �� ���� ����.
//// ��й�ȣ�� �ؽð��� �˰����� ����.
//// ��й�ȣ�� ���� �ؽð��� �� �� ������ �ؽð��� ���� ��й�ȣ�� �˾Ƴ� ���� ����.
//// ���� ��й�ȣ�� �Ҿ������ ��� ���� �Ʒ��� ������ ��ġ�� ����.
//// ��й�ȣ ã�� -> ���̵� �Է� / �� ���� -> �� ��й�ȣ�� �Է��ϼ���..
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
//	// �ؽ� : ����Ű���� �̿��ؼ� � ĭ(��Ŷ)�� ����� �� �����ϴ� ����.
//	const int userid = 123456789;
//	int key = (userid % 1000); // hash < ������ȣ ����
//
//
//	// 123456789�� ���� ���� ����
//	users[key] = User{ userid,"Rookiss" };
//
//	// 123456789�� ���� �̸���?
//	User& user = users[key];
//	if (user.userId == userid)
//	{
//		string name = user.username;
//		cout << name << endl;
//	}
//
//	// �浹 ����!
//	// �� �˰����� ���
//	// 123456789�� 789�� �浹��!
//
//	// ���̵�� ��û���� ũ���� ������ ����ϴ� �����Ͱ� ���� ���..
//	// �浹�� �߻��� �ڸ��� ����ؼ� �ٸ� ���ڸ��� ã�Ƴ����� �ȴ�.
//	// - ���� ����� (linear probing)
//	// hash(key) + 1 -> hash(key) + 2...
//	// - ���� ����� (quardratic probing)
//	// hash(key) + 1^2 -> hash(key) + 2^2...
//
//
//
//}
//
//// ü�̴� (�浹 ���� �ذ�)
//void TestHashTableChaining()
//{
//	struct User
//	{
//		int userId = 0; // 1-int32_max
//		string username;
//	};
//
//	// �޸𸮴� ��û���� ���ظ� �������� �����ʹ� ������ ������ ������ �� �ִ�.
//	vector<vector<User>> users;
//	users.resize(1000);
//
//	const int userid = 123456789;
//	int key = (userid % 1000); // hash < ������ȣ ����
//
//	users[key].push_back(User{ userid,"Rookiss" });
//	users[789].push_back(User{ 789,"Faker" });
//
//	// 123456789�� ���� �̸���?
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