#include<iostream>
#include<cmath>
using namespace std;

// 出错原因 ：n太小，改为long long 就好了
// 参考文章
// https://blog.csdn.net/huang_miao_xin/article/details/51331710
typedef long long ll;
bool isPrime(ll n);
int main() {
	ll n,ans=0;
	cin >> n;
	if (n<5)
	{
		cout << ans << endl;
		system("pause");
		return 0;
	}
	ans += 1;   // 3 5
	for (ll i = 5; i <= n; i+=6)
	{
		if ((i + 2) <= n && isPrime(i) && isPrime(i+2))
		{
			ans += 1;
		}
	}
	cout << ans << endl;
	system("pause");
	return 0;
}

bool isPrime(ll n) {
	// n小于6的情况
	if (n==2 || n==3)
	{
		return true;
	}
	// n为 6x,6x+2,6x+3.6x+4的情况
	if (n%6 !=1 && n%6!=5)
	{
		return false;
	}
	// 再循环 6x-1,6x,6x+1,6x+2,6x+3,6x+4,6x+5中
	// 除了 6x-1 和 6x+i 外，均不可能（该情况中 N 为奇数 ）
	ll tmp = sqrt(n);
	for (ll i = 5; i <= tmp; i+=6)
	{
		if (n%i == 0 || n % (i + 2) == 0) {
			return false;
		}
	}
	return true;
}


