#include<stdio.h>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<string>
#define MaxSize 30
#define Null -1
using namespace std;
// 参考文档： https://blog.csdn.net/tdscdma123/article/details/52618669
// 另一种解法：https://blog.csdn.net/tjj1998/article/details/80215607
/*
解法一：
 1.每次push都指向一个新的节点。 
 2.每次pop都指向一个被抛出的节点。 
 3.连续的pop-pop或push-push流的方向都相同。 
 4.连续的push-pop指向同一个叶节点，同时执行方向转弯。（节点3） 
 5.连续的pop-push经过一个父节点，同时执行方向转弯。（节点2） 
 6.每个节点只能pop指向一次，push指向一次。（节点4到2直接跳到1）
解法二：
	题目中实际给出了前序和中序遍历
 */
struct Node { 
	int data;
	int left;
	int right;
	Node() {
		this->data = 0; this->left = this->right = -1;
	}
}T1[MaxSize],T2[MaxSize];
typedef int Tree;
vector<int> ans;
vector<string> operate;
void postOrder();
int main() {
	int n; cin >> n;
	string str; int data;
	stack<int> s; 
	int tmp; string last="";  
	for (int i = 0; i < n; ) 
	{ 
		cin >> str;
		if (str == "Push") {
			cin >> data;
			T1[i].data = data;
			if (last== "Push") {
				T1[tmp].left = i; 
			}
			else if(last=="Pop") {   
				T1[tmp].right = i;   
			} 
			s.push(i);
			tmp = i;
			last = "Push";
			i++; 
		}
		if (str == "Pop") {
			tmp = s.top();
			s.pop(); 
			if (last == "Push") {
				last = "Pop";
			}
			 
		}
	}
	postOrder();
	for (int i = 0; i < ans.size()-1; i++)
	{
		cout << ans[i] << " ";
	}
	cout << ans[ans.size()-1] <<endl;
	system("pause");
	return 0;
} 

void postOrder() {
	int T = 0,tmp=-1;
	stack<int> s;
	while (T != -1 || !s.empty())
	{
		while (T != -1) {
			s.push(T);
			T = T1[T].left;
		}
		T = s.top();
		s.pop();
		if(T1[T].right == -1 || T1[T].right == tmp)
		{
			ans.push_back(T1[T].data);
			tmp = T;
			T = -1;
		}
		else {
			s.push(T);
			T = T1[T].right;
		}
	}
}
 
 