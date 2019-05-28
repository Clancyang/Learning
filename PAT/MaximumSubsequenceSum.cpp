#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm> 
using namespace std;

typedef long long ll; 
ll maxSubSeqSum(vector<ll> arr, ll arr_len);
ll maxSubSeqSum02(vector<ll> arr,ll& first ,ll& last);
int main() {   
	ll n; 
	cin >> n;
	vector<ll> arr(n, 0);
	ll first, last;
	for (ll i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	// ll sum = maxSubSeqSum02(arr, first, last);
	// cout << sum<<" " << first<<" " << last <<" "<< endl;
	ll sum=maxSubSeqSum(arr,n);
	cout<<sum<<endl;
	system("pause");
	return 0;
}


// 最大子序列和
ll maxSubSeqSum(vector<ll> arr, ll arr_len) {
	ll curSum=0,maxSum = 0;
	for (ll i = 0; i < arr_len; i++)
	{
		curSum += arr[i];     // 向右累加
		if (curSum > maxSum) {       // 大于maxSum，更新返回值
			maxSum = curSum;      
		} else if (curSum  <  0) {     // 当前子序列和为负
			curSum = 0;       // 不可能使后面的子序列和变大，抛弃
		}
	}
	return maxSum;
}
ll maxSubSeqSum02(vector<ll> arr, ll &first, ll& last) {
	ll curSum = 0,maxSum ;    
	// maxSum初始化arr[0]  为了防止全是负数时，最大值为0
	// first,last 初始化 为防止只有一个正数时tmp无法赋值给first
	first = arr[0], last = arr[0],maxSum = arr[0];
	// tmp初始化 保证在arr[0]为正的情况下，成功赋值给first
	ll tmp = arr[0]; 
	for (ll i = 0; i < arr.size(); i++)
	{
		curSum += arr[i];     // 向右累加
		if (curSum > maxSum) {       // 大于maxSum，更新返回值 
			maxSum = curSum;
			last = arr[i];
			first = tmp;
		}
		else if (curSum < 0) {     // 当前子序列和为负
			curSum = 0;       // 不可能使后面的子序列和变大，抛弃
			if (i + 1 < arr.size())
				tmp = arr[i + 1];
		}
	}
	//有负数和0组成
	if (maxSum == 0) {
		first = last = 0;
	}
	// 全是负数
	if (maxSum < 0) {
		maxSum = 0;
		first = arr[0]; last = arr[arr.size() - 1];
	}

	return maxSum;
}