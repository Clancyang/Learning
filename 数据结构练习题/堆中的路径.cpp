#include<stdio.h>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<math.h>
#define MaxSize 1001
#define INF -0x3f3f3f3f
#define Null -1
using namespace std; 
vector<int> ans(MaxSize,0),number;
// 注意事项：该题为最小堆，所以H[0]应该设为无穷小

int H[MaxSize];
int n,len=0;
void push(int item);
int main() {
	int m; 
	 
	cin >> n >> m; 
	H[0] = INF;
	for (int i = 0; i < n; i++)
	{
		int tmp;  cin >>tmp;
		push(tmp);
	}
	for (int i = 0; i < m; i++)
	{
		int tmp; cin >> tmp;
		while (tmp != 1)
		{
			cout << H[tmp]<<" ";
			tmp /= 2;
		}
		cout << H[1] << endl;
	}
	system("pause");
	return 0;
} 
void push(int item) {
	int p = ++len;
	for (; H[p/2] > item;p=p/2) {
		H[p] = H[p/2];
	}
	H[p] = item;
}
