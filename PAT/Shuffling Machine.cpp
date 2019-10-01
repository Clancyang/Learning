#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
using namespace std;
// map<key,value> key唯一，且自动按照key排序，且不可修改
// 实现 字符串+数字 的方法
//      ostringstream oss;
// 		oss<< "S" << i;
// 		cards[t++] = oss.str();
typedef long long ll; 
int main() {   
	int n; cin >> n;
	vector<int> order(54,0);
	vector<string> cards(55);
	vector<string> ans(55);
	for (int i = 0; i < 54; i++)
	{
		cin >> order[i];
	}
	int t = 1;
	for (int i = 1; i <= 13; i++)
	{ 
		ostringstream oss;
		oss<< "S" << i;
		cards[t++] = oss.str();
	}
	for (int i = 1; i <= 13; i++)
	{
		ostringstream oss;
		oss << "H" << i;
		cards[t++] = oss.str();
	}
	for (int i = 1; i <= 13; i++)
	{
		ostringstream oss;
		oss << "C" << i;
		cards[t++] = oss.str();
	}
	for (int i = 1; i <= 13; i++)
	{
		ostringstream oss;
		oss << "D" << i;
		cards[t++] = oss.str();
	}
	for (int i = 1; i <= 2; i++)
	{
		ostringstream oss;
		oss << "J" << i;
		cards[t++] = oss.str();
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < order.size(); j++)
		{
			ans[order[j]] = cards[j + 1];
		}
		swap(ans, cards);
	}
	 

	// 输出结果
	for (int i = 1; i < cards.size(); i++)
	{
		cout << cards[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
