#include<stdio.h>
#include<iostream>
#include<stack>
#include<vector>
#define MaxSize 100005
#define Null -1
using namespace std;
struct Node {
	char data;
	int left;
	int right;
}T1[10],T2[10];
typedef int Tree;
int readTree(struct Node T[]);
bool isomorphic(Tree r1, Tree r2);
int main() {
	int root1 = readTree(T1);
	int root2 = readTree(T2);
	bool ans = isomorphic(root1, root2);
	if (ans) cout << "Yes" << endl;
	else cout << "No" << endl;

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
		cin >> T[i].data >> left>> right;
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
bool isomorphic(Tree r1, Tree r2) {
	if ((r1 == Null) && (r2 == Null)) {  //T1、T2均为空
		return true;
	}
	if ((r1 == Null && r2 != Null) || (r1 != Null) && (r2 == Null)) {  // T1 || T2有一个不为空 
		return false;
	}
	if (T1[r1].data != T2[r2].data) {       // 根节点数据不同
		return false;
	}
	if (T1[r1].left == Null && T2[r2].left == Null) {     // 两棵树的左子树均为空
		isomorphic(T1[r1].right, T2[r2].right);
	}
	if ((T1[r1].left != Null && T2[r2].left != Null) && T1[T1[r1].left].data == T2[T2[r2].left].data) {
		return isomorphic(T1[r1].left, T2[r2].left) && isomorphic(T1[r1].right, T2[r2].right);
	}
	else {
		return isomorphic(T1[r1].left, T2[r2].right) && isomorphic(T1[r1].right, T2[r2].left);
	}
}