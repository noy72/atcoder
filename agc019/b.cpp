#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	string s;
	cin >> s;

	map<char,long long> m;
	for(auto c : s){
		m[c]++;
	}
	auto f = [](long long a){ return a * (a - 1) / 2; };

	long long ans = f(s.size());
	for(auto p : m){
		ans -= f(p.second);
	}
	cout << ans + 1 << endl;
}
