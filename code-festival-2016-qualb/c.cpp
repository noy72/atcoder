#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	int w, h;
	cin >> w >> h;

	vector<long long> x(w), y(h);
	rep(i, w){
		cin >> x[i];
	}
	rep(i, h){
		cin >> y[i];
	}

	sort(all(x));
	sort(all(y));

	vector<long long> sum(w + 1, 0);
	sum[0] = 0;
	rep(i,w){
		sum[i + 1] = sum[i] + x[i];
	}

	long long ans = 0;
	rep(i,h){
		int p = distance(x.begin(), lower_bound(all(x), y[i]));
		ans += sum[p] + (w - p) * y[i];
	}
	cout << ans + accumulate(all(x),0LL) + accumulate(all(y),0LL) << endl;
}
