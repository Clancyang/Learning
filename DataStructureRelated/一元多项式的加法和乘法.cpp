#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
using namespace std;

typedef long long ll;  
typedef struct poly {
	int exp;	//指数 
	int coef;   // 系数
	// 结果显示要求递减
	bool operator < (poly & p) {
		return this->exp > p.exp;
	}
	poly(int exp=0, int coef=0) {
		this->exp = exp;
		this->coef = coef;
	}

} ;
class Polyomial 
{
public:
	Polyomial ()=default;
	Polyomial(vector<poly>& p) {
		this->polys = p;
	}
	~Polyomial ()=default; 
	void poly_sort() {
		sort(polys.begin(),polys.end());
	}
	poly get(int i) {
		return polys[i];
	}
	void remove(int i) {
		polys.erase(polys.begin() + i);
	}
	// 默认指数都是递减的
	int size() {
		return this->polys.size();
	}
	Polyomial operator +(Polyomial p) {
		vector<poly> ans;
		int i = 0, j = 0;
		while(i<this->size()&&j<p.size())
		{
			if (polys[i].exp > p.get(j).exp) {
				ans.push_back(polys[i++]); 
			}
			else if (polys[i].exp == p.get(j).exp)
			{
				if (polys[i].coef+p.get(j).coef != 0)
				{ 
					poly tmp;
					tmp.exp = polys[i].exp;
					tmp.coef = polys[i].coef + p.get(j).coef;
					ans.push_back(tmp); 
				}
				i++; j++;
			}
			else {
				ans.push_back(p.get(j++));
			}
		}
		while (i<this->size())
		{
			ans.push_back(polys[i++]);
		}
		while (j<p.size())
		{
			ans.push_back(p.get(j++));
		}
		for (int i = 0; i < ans.size(); i++)
		{
			if (ans[i].coef == 0) {
				ans.erase(ans.begin()+i);
			}
		}
		// 如果最后结果为0 需要返回一个 0 0
		if(ans.size()==0){
			ans.push_back(poly(0,0));
		}
		Polyomial res(ans);
		return res;
	}
	Polyomial operator *(Polyomial p) {
		Polyomial ans;   
		for (int i = 0; i < p.size(); i++)
		{
			ans = ans + mult(p.get(i), polys);
		} 
		return  ans;
	}
	void show() {
		int i = 0;
		for (; i < polys.size()-1; i++)
		{
			cout << polys[i].coef << " " << polys[i].exp << " ";
		}
		cout << polys[i].coef << " " << polys[i].exp<<endl;
	}
	void input() {
		int n;
		cin >> n;
		if (n != 0) {
			for (int i = 0; i < n; i++)
			{
				poly p;
				cin >> p.coef >> p.exp;
				polys.push_back(p);
			} 
		}
		else {
			polys.push_back(poly(0, 0));
		}
		
	}
private:
	vector<poly> polys;
	Polyomial mult(poly p, vector<poly>& ps) {
		vector<poly> ans;
		for (int i = 0; i < ps.size(); i++)
		{
			ans.push_back(poly(p.exp + ps[i].exp, p.coef * ps[i].coef));
		}
		return Polyomial(ans);
	}
};

 
int main() {     
	Polyomial p1,p2;
	p1.input(); p2.input();
	Polyomial p4 = p1 * p2;
	p4.show();
	Polyomial p3 = p1 + p2;
	p3.show();
	system("pause");
	return 0;
}


 