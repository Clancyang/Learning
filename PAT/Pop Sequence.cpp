#include<stdio.h>
#include<iostream>
#include<stack>
#include<vector>
#define MaxSize 100005
using namespace std;
int main() {
	int m, n,times;
	cin >> m >> n >> times;
	// m 为栈的大小
	// n 压栈的最大值  例如 1 2 3 4 5 6 7， n=7
	// times 为几组数据
	for (int i = 0; i < times; i++)
	{
		stack<int> sta;
		vector<int> ans(n + 1, 0);
		for (int j = 1; j <= n; j++)
		{
			cin >> ans[j];
		}
	
		int maxNum = m;     // 栈内最大值
		bool result = true;
		for (int k = 1,j=1; k <= n; k++)
		{
			if (ans[k] > maxNum) {
				result = false;
				break;
			}
			while ((sta.empty() || !sta.empty() && sta.top() != ans[k]) && j <= n && sta.size() <= m)
				// 两种情况 ： 栈为空 || 栈不为空，但是 栈首 ！= ans[k]
				// j<= n压栈的值不能超过最大值  
				// 限制栈的大小
			{
				sta.push(j++);
			}
			if (sta.top() != ans[k]) {
				result = false;
				break;
			}
			sta.pop(); 
			maxNum++;
		}
		if (result) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		} 
	}
	system("pause");
	return 0;
} 

// 参考博客 ： https://www.cnblogs.com/siukwan/p/5003137.html