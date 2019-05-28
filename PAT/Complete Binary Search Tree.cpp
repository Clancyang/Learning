#include<stdio.h>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<math.h>
#define MaxSize 1000
#define Null -1
using namespace std; 
vector<int> ans(MaxSize,0),number;
int n, index = 0;
// 利用完全二叉树的特性，进行中序建树
void build(int root) {
	if (root > n) return;
	build(root * 2);
	ans[root] = number[index++];
	build(root * 2 + 1);
}
 
int main() {
	cin >> n; 
	number.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> number[i];
	}
	sort(number.begin(), number.end());
	build(1);
	for (int i = 1; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	cout <<ans[n]<< endl;
	system("pause");
	return 0;
} 
 