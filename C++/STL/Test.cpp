#include<vector>
#include<algorithm>
#include<functional>
#include<iostream>
using namespace std;
int main(){
    int ia [ 6 ] = {27,210,12,47,109,83};
    vector<int,allocator<int>> vi(ia,ia+6);
    cout<< count_if(vi.begin(),vi.end(),
                        not1(bind2nd(less<int>(),40)))<<endl;
    vector<int> arr = {1,2,3,4,5,6};
    for (auto i : arr)
    {
        i *= 3;
        cout<< i <<" ";
    }
    cout<<endl;
    for (auto& i : arr)
    {
        i *= 3;
        cout<< i <<" ";
    }
    cout<<endl;
    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}