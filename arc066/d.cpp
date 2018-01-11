#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

const long long M = 1000000007;
map<pair<long long,long long>,long long> m;

long long solve(long long s, long long x){
	if(s == 0) return 1;
	if(m.count(make_pair(s,x))) return m[make_pair(s,x)] % M;

	long long res = solve(s / 2, x / 2) % M;
	(res += solve((s - 1) / 2, (x - 1) / 2)) %= M;
	if(s >= 2) (res += solve((s - 2) / 2, x / 2)) %= M;
	return m[make_pair(s,x)] = res;
}

int main(){
    long long n;
    cin >> n;
	cout << solve(n,n) << endl;
}
