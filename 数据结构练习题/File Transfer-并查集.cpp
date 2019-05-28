#include<stdio.h>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<math.h>
#define MaxSize 10001
#define INF -0x3f3f3f3f
#define Null -1
using namespace std; 
//vector<int> ans(MaxSize,0),number;
 
int H[MaxSize];
int n,len=0;
void init();
int find(int x);
bool isSame(int x, int y);
void unit(int x, int y);
void Input_Connection();
void Check_Conection();
void check_Network();
int main() {
	int m; 
	cin >> n ;
	init(); 
	char ch;
	do{
		 cin >> ch;
		 switch (ch)
		 {
		 case 'I':Input_Connection(); break;
		 case 'C':Check_Conection();  break;
		 case 'S':check_Network(); break;
		 default:
			 break;
		 }
		 
	} while (ch != 'S');
	system("pause");
	return 0;
} 
void Input_Connection() {
	int x, y;
	cin >> x >> y;
	unit(x - 1, y - 1);
}
void Check_Conection() {
	int x, y;
	cin >> x >> y;
	if (isSame(x - 1, y - 1)) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
}
void check_Network() {
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (H[i] < 0) cnt++;
	}
	if (cnt == 1) {
		cout << "The network is connected." << endl;
	}
	else
		cout << "There are " << cnt << " components." << endl;
}
void init() {
	for (int i = 0; i < n; i++)
	{
		H[i] = -1;
	}
}
// 路径压缩
int find(int x) {
	if (H[x] < 0)
		return x;
	else
		return H[x] = find(H[x]);
}
bool isSame(int x,int y) {
	return find(x) == find(y);
 }
void unit(int x, int y) {
	int rootx, rooty;
	rootx = find(x);
	rooty = find(y);
	if (rootx == rooty) {
		return;
	}
	if (H[rootx] < H[rooty]) {
		H[rooty] = rootx; 
	}
	else {
		if (H[rootx] == H[rooty]) H[rootx]--;
		H[rooty] = rootx;
	}
}