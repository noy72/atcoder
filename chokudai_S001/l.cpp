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

	vector<int> a(n), m(n);
	rep(i,n){
		cin >> a[i];
		a[i]--;
		m[a[i]] = i;
	}

	int cnt = 0;
	rep(i,n){
		if(i != a[i]){
			cnt++;
			
			int t = m[i];
			m[a[i]] = t;
			swap(a[i], a[t]);
		}
		//for(auto j : a){ cout << j << ' ' ; } cout << endl;
	}

	n -= cnt;
	bool f = n >= 0 and n % 2 == 0;
	cout << (f ? "YES" : "NO") << endl;
}
