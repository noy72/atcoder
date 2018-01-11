#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

#define int long long

signed main(){
	int n, m;
	cin >> n >> m;

	vector<long long> a(n);
	rep(i,n){
		cin >> a[i];
		a[i]--;
	}

	long long sum = 0;
	rep(i,n - 1){
		int dif = a[i + 1] - a[i];
		//show(dif)
		sum += dif < 0 ? dif + m : dif;
	}

	//show(sum)

	vector<int> cSum(m * 2,0);
	rep(i,n - 1){
		if(a[i + 1] - a[i] == 1) continue;
		int from = a[i];
		int to = a[i + 1];
		if(from > to) to += m;
		cSum[from + 2]--;
		cSum[to + 1]++;
		//cout << from + 2 << ' ' << to + 1 << endl;
	}

	//for(auto i : cSum){ cout << i << ' '; } cout << endl;

	rep(i,m * 2 - 1){
		cSum[i + 1] += cSum[i];
	}
	//for(auto i : cSum){ cout << i << ' '; } cout << endl;

	rep(i, n - 1){
		if(a[i + 1] - a[i] == 1) continue;
		int from = a[i];
		int to = a[i + 1];
		if(from > to) to += m;
		cSum[to + 1] += to - from - 1;
		//cout << to + 1 << ' ' << to - from - 1 << endl;
	}

	//for(auto i : cSum){ cout << i << ' '; } cout << endl;
	rep(i,m * 2 - 1){
		cSum[i + 1] += cSum[i];
	}
	//for(auto i : cSum){ cout << i << ' '; } cout << endl;

	rep(i, m){
		cSum[i] += cSum[i + m];
	}
	//for(auto i : cSum){ cout << i << ' '; } cout << endl;

	cout << sum + *min_element(all(cSum)) << endl;
}
