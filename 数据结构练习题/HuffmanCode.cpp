

// 未通过测试数据



#include<stdio.h>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<math.h>
#include<map>
#define MaxSize 10001
#define INF -0x3f3f3f3f
#define Null -1
using namespace std;
//vector<int> ans(MaxSize,0),number;

int H[MaxSize];
int n, len = 0;
typedef struct node* HuffmanTree;
struct node {
	char content;
	int weight;
	HuffmanTree left, right;
	node(char ch = ' ', int w = 0, HuffmanTree l = NULL, HuffmanTree r = NULL) :content(ch), weight(w), left(l), right(r) {}
	bool operator < (const node& n) const {
		return this->weight > n.weight;
	}
};
struct cmp_1
{
	bool operator()(HuffmanTree h1, HuffmanTree h2) {
		return h1->weight > h2->weight;
	}
};
struct cmp_2
{
	bool operator()(const pair<char, string>&p1, const pair<char, string>&p2) {
		return p1.second.length() > p2.second.length();
	}
};
string isPrefixCode(string s, string l);
int WPL(HuffmanTree T, int depth);
HuffmanTree buildHuffmanTree(priority_queue<node*, vector<node*>, cmp_1> p);
int main11() {
	int m;
	cin >> n;
	priority_queue<node*, vector<node*>, cmp_1> nodes;
	map<char, int> data;
	HuffmanTree root;
	char ch; int tmp; string str, last = "";
	vector<pair<char, string>> huffman;
	for (int i = 0; i < n; i++)
	{
		cin >> ch >> tmp;
		HuffmanTree ht = new node(ch, tmp);
		nodes.push(ht);
		data.insert(make_pair(ch, tmp));
	}
	root = buildHuffmanTree(nodes);
	int len = WPL(root, 0);
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int wpl = 0;
		for (int j = 0; j < n; j++)
		{
			cin >> ch >> str;
			huffman.push_back(make_pair(ch, str));
			wpl += data[ch] * str.size();
		}
		sort(huffman.begin(), huffman.end(), cmp_2());
		bool flag = true;
		last = huffman[0].second;
		for (int i = 1; i < huffman.size(); i++)
		{
			str = huffman[i].second;
			last = isPrefixCode(str, last);
			if (str == last) {
				flag = false;
				break;
			}
			if (last == "") {
				last = str;
			}
		}
		if (wpl > len) {
			flag = false;
		}
		if (flag) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}

	system("pause");
	return 0;
}
string isPrefixCode(string s, string l) {
	if (l == "") return l;
	string res;
	int len = min(s.size(), l.size());
	for (int i = 0; i < len; i++)
	{
		if (l[i] == s[i])
			res.push_back(l[i]);
	}
	return res;
}
HuffmanTree buildHuffmanTree(priority_queue<node*, vector<node*>, cmp_1> p) {
	HuffmanTree root;
	int len = p.size();
	for (int i = 1; i < len; i++)
	{
		HuffmanTree T = new node();
		T->left = p.top();
		p.pop();
		T->right = p.top();
		p.pop();
		T->weight = T->left->weight + T->right->weight;
		p.push(T);
	}
	root = p.top(); p.pop();
	return root;
}
int WPL(HuffmanTree T, int depth) {
	if (!T->left && !T->right) {
		return depth * T->weight;
	}
	else {
		return WPL(T->left, depth + 1) + WPL(T->right, depth + 1);
	}
}