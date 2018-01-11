#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;

	map<int,int> mp;
	rep(i,m){
		int a, b;
		cin >> a >> b;
		mp[a]++;
		mp[b]++;
	}

	for(auto i : mp){
		if(i.second % 2 == 1){
			cout << "NO" << endl;
			return  0;
		}
	}
	cout << "YES" << endl;
}
