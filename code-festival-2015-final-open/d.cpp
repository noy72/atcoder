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

	int imos[200005] = {0};
	pair<int, int> p[100005];
	rep(i,n){
		int l, r;
		cin >> l >> r;
		l*=2;
		r*=2;
		p[i] = make_pair(l,r);
		imos[l]++;
		imos[r + 1]--;
	}

	rep(i,200001){
		imos[i + 1] += imos[i];
	}

	int maxi = 0;
	for(int i = 1; i < 200001; i+=2){
		maxi = max(maxi, imos[i]);
	}

	if(maxi == 1){
		cout << maxi << endl;
		return 0;
	}

	vector<int> v;
	for(int i = 1; i < 200001; i+=2){
		if(maxi == imos[i]) v.emplace_back(i);
	}
	//cout << v.front() << ' ' << v.back() << endl;

	rep(i,n){
		if(v.front() >= p[i].first and v.front() <= p[i].second and
			v.back() >= p[i].first and v.back() <= p[i].second){
			cout << maxi - 1 << endl;
			return 0;
		}
	}
	cout << maxi << endl;
}
