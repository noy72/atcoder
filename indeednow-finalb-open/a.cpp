#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

const int M = 1000000007;

int main(){
	long long a, b;
	cin >> a >> b;

	vector<long long> v(1000005);
	iota(all(v),0);
	range(i,1,1000001){
		v[i] += v[i - 1];
		v[i] %= M;
	}

	long long ans = 0;
	range(i,a,b + 1){
		//cout << v[i] << ' ' << i << endl;
		ans += v[i] * i % M;
		ans %= M;
	}
	cout << ans << endl;
}
