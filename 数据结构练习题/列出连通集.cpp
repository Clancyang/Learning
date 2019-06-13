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
#define N 10
using namespace std; 
//vector<int> ans(MaxSize,0),number;
 
int H[MaxSize];
int n,len=0;
bool visited[N] = {0};
int G[N][N];
vector<int> ans;
void DFS(int v);
void BFS(int s);
void ListComponent(bool);
int main() {
	int m; 
	cin >> n >> m ;  // n为等点数，m为边数
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			G[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int v, w; cin >> v >> w;
		G[v][w] = G[w][v] = 1;
	}
	ListComponent(true);
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;	
	}
	ListComponent(false);
	system("pause");
	return 0;
} 
void DFS(int v) {
	visited[v] = true;
	ans.push_back(v);
	for (int i = 0; i < n; i++)
	{
		if (G[v][i] == 1 && !visited[i]) {
			DFS(i);
		}
	}
 }
void BFS(int s) {
	queue<int> q; int v, w;
	q.push(s);
	visited[s] = true;
	ans.push_back(s);
	while (!q.empty()) {
		v = q.front(); q.pop();
		for (w = 0; w < n; w++)
		{
			if (G[v][w] == 1 && !visited[w]) {
				q.push(w);
				visited[w] = true;
				ans.push_back(w);
			}
		}
	}
}

void ListComponent(bool isDFS) {
	for (int i = 0; i < n; i++)
	{
		ans.clear();
		if (!visited[i]) {
			if(isDFS)
				DFS(i);
			else BFS(i);
			cout << "{ ";
			int j = 0;
			for (; j < ans.size() - 1; j++)
			{
				cout << ans[j] << " ";
			}
			cout << ans[j] << " }" << endl;
		}
		
	}
}