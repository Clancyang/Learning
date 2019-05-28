#include<stdio.h>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#define MaxSize 100005
#define Null -1
using namespace std;
struct Node {
	int data;
	int left;
	int right;
}T1[10],T2[10];
typedef int Tree;
vector<int> ans;
int readTree(struct Node T[]); 
void levelOrderTraverse(Tree T);
int main() {
	int root = readTree(T1); 
	levelOrderTraverse(root);
	for (int i = 0; i < ans.size()-1; i++)
	{
		cout << ans[i] << " ";
	}
	cout << ans[ans.size() - 1] << endl;
	system("pause");
	return 0;
} 

int readTree(struct Node T[]) {
	int m;
	char left, right;
	cin >> m;
	vector<int> isChild(m, 0);
	 
	for (int i = 0; i < m; i++)
	{
		T[i].data = i;
		cin >> left>> right;
		if (left == '-') {
			T[i].left = Null;
		}
		else {
			T[i].left = left - '0';
			isChild[T[i].left] = 1;
		}

		if (right == '-') {
			T[i].right = Null;
		}else {
			T[i].right = right - '0';
			isChild[T[i].right] = 1;
		}
	}
 
	for (int i = 0; i < m; i++)
	{
		if (isChild[i] == 0) {
			return i;
		}
	}
	
	return Null;
}

void levelOrderTraverse(Tree T) {
	if (T == Null) return;
	queue<Node> q;
	q.push(T1[T]);
	while (!q.empty())
	{
		Node tmp = q.front();
		q.pop();
		if (tmp.left != Null) q.push(T1[tmp.left]);
		if (tmp.right != Null) q.push(T1[tmp.right]);
		if (tmp.left == Null && tmp.right == Null) {
			ans.push_back(tmp.data);
		}
	}
}
 