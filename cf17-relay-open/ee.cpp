#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

#define int double

signed main(){
	int n, p;
	cin >> n >> p;

	vector<int> w(n), b(n);
	rep(i,n){
		cin >> w[i] >> b[i];
	}

	int sum_b = accumulate(all(b), 0);
	vector<pair<int, pair<int,int>>> in;
	rep(i,n){
		in.emplace_back(w[i] / sum_b - b[i] + w[i], make_pair(w[i],b[i]));
	}
	sort(all(in), greater<pair<int, pair<int,int>>>());

	int sum_w = 0;
	rep(i,n){
		sum_w += in[i].second.first;
		sum_b -= in[i].second.second;
		if(sum_w * 100 >= p * (sum_w + sum_b)){
			cout << i + 1 << endl;
			return 0;
		}
	}
}
