#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

#define int long long

signed main(){
	int n, q, s, t;
	cin >> n >> q >> s >> t;

	vector<int> a(n + 1, 0);
	rep(i,n + 1){
		cin >> a[i];
	}

	vector<int> d(n, 0);
	rep(i,n){
		d[i] = a[i + 1] - a[i];
	}

	int plus = 0, minus = 0;
	rep(i,n){
		if(d[i] > 0) plus+=d[i];
		else minus+=d[i];
	}

	while(q--){
		int l, r, x;
		cin >> l >> r >> x;
		l--;

		if(d[l] > 0) plus -= d[l];
		else minus -= d[l];
		d[l] += x;
		if(d[l] > 0) plus += d[l];
		else minus += d[l];

		if(r != n){
			if(d[r] > 0) plus -= d[r];
			else minus -= d[r];
			d[r] -= x;
			if(d[r] > 0) plus += d[r];
			else minus += d[r];
		}

		cout << plus * -s + minus * -t << endl;
	}
}
