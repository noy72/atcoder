#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	long long w, h;
	cin >> w >> h;

	vector<pair<long long, long long>> p(w + h);
	rep(i,w){
		cin >> p[i].first;
		p[i].second = 0;
	}
	rep(i,h){
		cin >> p[i].first;
		p[i].second = 1;
	}

	sort(all(p));

	w++;
	h++;
	long long ans = 0;
	int i = 0;
	while(w > 0 or h > 0){
		if(p[i].second){
			ans += h * p[i].first;
			w--;
		}else{
			ans += w * p[i].first;
			h--;
		}
	}
	cout << ans << endl;
}
