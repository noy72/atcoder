#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

#define int long long

bool canUse(bitset<31> b, int lim){
	rep(i,lim){
		if(b[i]) return false;
	}
	if(not b[lim]) return false;
	return true;
}

signed main(){
	int n;
	cin >> n;

	vector<bitset<31>> a(n);
	vector<bool> used(n,0);
	bitset<31> b(0);
	rep(i,n){
		int in;
		cin >> in;
		a[i] = bitset<31>(in);
		b ^= a[i];
	}

	int ans = 0;
	for(int i = 30; i >= 0; i--){
		if(b[i]){
			int tmp = (1 << (i + 1)) - 1;

			rep(j,n){
				if(used[j]) continue;
				if(not canUse(a[j], i)) continue;
				b ^= tmp;
				ans++;
				break;
			}
		}
	}

	cout << (b == 0 ? ans : -1) << endl;
}
