#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//判断变量类型的方法
// typeid(i)==typeid(int)
typedef long long ll; 
int main() {  
	string str;
	cin >> str;
	int len = str.size();
	vector<int> arr(len, 0);
	vector<int> vis1(10, 0); 
	vector<int> vis2(10, 0);
	for (int i = 0; i < str.size(); i++)
	{
		arr[i] = str[i]-0x30;   
		vis1[arr[i]]++;
	} 
	int cf = 0;
	for (int i = len-1; i>=0 ; i--)
	{ 
		int tmp = 2 * arr[i] + cf;   
		if(tmp >= 10) {
			arr[i] = tmp-10;
			cf = 1;
		}
		else {
			arr[i] = tmp ;
			cf = 0;
		}  
		vis2[arr[i]]++;
	}
	if (cf == 1) {
		cout << "No" << endl;
		cout << 1;
		for (int i = 0; i < len; i++)
		{
			cout << arr[i];
		}
		cout << endl;
	}
	else {
		bool flag = true;
		for (int i = 0; i < 10; i++)
		{
			if (vis1[i] != vis2[i]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "Yes" << endl;
			for (int i = 0; i < len; i++)
			{
				cout << arr[i];
			}
			cout << endl;
		}
		else {
			cout << "No" << endl;
			for (int i = 0; i < len; i++)
			{
				cout << arr[i];
			}
			cout << endl;
		}
	}

	system("pause");
	return 0;
}

 
