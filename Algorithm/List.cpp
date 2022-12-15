//#include <iostream>
//#include <vector>
//#include <list>
//
//using namespace std;
//
//int main()
//{
//	list<int> li;
//
//	list<int>::iterator eraseIt;
//	for (int i = 0; i < 10; i++)
//	{
//		if (i == 5)
//		{
//			eraseIt = li.insert(li.end(), i);
//		}
//		else
//		{
//			li.push_back(i);
//		}
//	}
//
//	li.pop_back();
//	li.erase(eraseIt);
//
//	for (list<int>::iterator it = li.begin(); it != li.end(); it++)
//	{
//		cout << (*it) << endl;
//	}
//}