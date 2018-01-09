#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	int n;
	cin >> n;

	vector<vector<pair<int, int>>> m(100000);
	rep(i,n){
		int s, c;
		cin >> s >> c;
		m[c - 1].emplace_back(make_pair(s,i));
	}

	for(auto i : m){

	}

}
