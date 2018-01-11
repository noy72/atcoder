#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

#define int long long

signed main(){
	int n, l;
	cin >> n >> l;

	vector<pair<int, char>> p(n + 2);
	p[0] = make_pair(0,'L');
	rep(i,n){
		int a;
		char b;
		cin >> a >> b;
		p[i + 1] = make_pair(a,b);
	}
	p[n + 1] = make_pair(l + 1,'R');

	long long ans = 0;
	rep(i,n + 2){
		if(p[i].second == 'L' && p[i + 1].second == 'L'){
			ans += p[i + 1].first - p[i].first - 1;
			p[i + 1].first = p[i].first + 1;
		}
	}
	for(int i = n + 1; i > 0; i--){
		if(p[i].second == 'R' && p[i - 1].second == 'R'){
			ans += p[i].first - p[i - 1].first - 1;
			p[i - 1].first = p[i].first - 1;
		}
	}
	//for(auto i : p){ cout << i.first << ' ' ; } cout << endl;

	vector<int> v(n + 2,0);
	int cnt = 0;
	range(i,1,n + 2){
		if(p[i].second == 'R' && i != n + 1){
			cnt++;
		}else{
			v[i - 1] = cnt;
			cnt = 0;
		}
	}
	cnt = 0;
	for(int i = n + 1; i > 0; i--){
		if(p[i].second == 'L' && i != 0){
			cnt++;
		}else{
			if(v[i + 1] != 0) continue;
			v[i + 1] = cnt;
			cnt = 0;
		}
	}
	//for(auto i : v){ cout << i << ' '; } cout << endl;
	
	//show(ans)
	rep(i,n + 1){
		if(p[i].second == 'R' &&  p[i + 1].second == 'L'){
			//show(i)
			ans += max(v[i], v[i + 1]) * (p[i + 1].first - p[i].first - 1);
		}
	}
	cout << ans << endl;

