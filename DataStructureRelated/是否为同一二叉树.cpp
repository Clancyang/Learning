#include<stdio.h>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<string>
#define MaxSize 30
#define Null -1
using namespace std;
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
vector<int> sample;
bool judge(vector<int>& sample, vector<int>& test);
int main() {
	int n, m;  // n为一个序列的元素个数 m为序列个数
	cin >> n;
	while (n) 
	{
		cin >> m;
		sample.clear();
		for (int j = 0; j < n; j++)
		{
			int tmp; cin >> tmp; sample.push_back(tmp);
		}
		vector<vector<int>> test(m);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int tmp; cin >> tmp; test[i].push_back(tmp); 
			}
			if (judge(sample, test[i])) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
		cin >> n;
	} 
	system("pause");
	return 0;
} 

bool judge(vector<int>& sample, vector<int>& test) {
	if (sample.size() != test.size()) return false;
	if (sample.size() == 0) return true;
	if (sample[0] != test[0]) return false;
	vector<int> s_left, s_right;
	vector<int> t_left, t_right;
	for (int i = 1; i < sample.size(); i++)
	{
		if (sample[i] > sample[0]) s_right.push_back(sample[i]);
		else s_left.push_back(sample[i]);
	}
	for (int i = 1; i < test.size(); i++)
	{
		if (test[i] > test[0]) t_right.push_back(test[i]);
		else t_left.push_back(test[i]);
	}
	bool res1=judge(s_left, t_left);
	bool res2=judge(s_right, t_right); 
	if (res1 == false || res2 == false) return false;
	return true;
}


//-----------------------------------方法二 ------------------------------------
 #include<stdio.h>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<string>
#define MaxSize 30
#define Null -1
using namespace std; 
struct node { 
	int data;
	node* left;
	node* right;
	node() {
		this->data = 0; this->left = this->right = NULL;
	}
};
 
typedef int Tree;
vector<int> ans;
vector<int> sample;

node* insert(int tmp, node* root);
node*  buildTree(int n);
bool judge(node* r1, node* r2);
int main() {
	int n, m;
	cin >> n;
	while (n)
	{
		cin >> m;
		node* sample = buildTree(n);
		for (int i = 0; i < m; i++)
		{
			node* test = buildTree(n);
			if (judge(sample, test)) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
		cin >> n;
	}
	
	system("pause");
	return 0;
} 
node*  buildTree(int n) {
	int tmp;
	node* root = new node();
	cin >> tmp; 
	root->data = tmp;
	for (int i = 1; i < n; i++)
	{
		cin >> tmp;
		insert(tmp, root);
	}
	return root;
}
node* insert(int tmp,node* root) {
	if (!root) {
		root = new node();
		root->data = tmp;
	}
	else {
		if (tmp < root->data) {
			root->left = insert(tmp, root->left);
		} else if (tmp > root->data) {
			root->right = insert(tmp, root->right);
		}
	}
	return root;
}
bool judge(node* r1,node* r2) {
	if ((r1 == NULL && r2 != NULL) || (r1 != NULL && r2 == NULL)) return false;
	if (r1 == NULL && r2 == NULL) return true;
	if (r1->data == r2->data) {
		bool res1 = judge(r1->left, r2->left);
		bool res2 = judge(r1->right, r2->right);
		if (res1 == false || res2 == false) return false;
		return true;
	}
	else {
		return false;
	}
}
//void free(node* root) {
//	
//}
 