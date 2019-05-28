#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

typedef long long ll; 
int main() {
	int n,m;
	cin >> n >> m;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	} 
	m = m % n;
	int t = (n - m) % n;
	for (int i = 0; i < n-1; i++)
	{
		cout << arr[t]<<" ";
		t = (t + 1) % n;
	}
	cout << arr[t];
	system("pause");
	return 0;
}
