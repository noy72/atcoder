#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	double a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	set<double> w, s;
	rep(i,31){
		rep(j,31){
			double tmp = 100.0 * a * i + 100.0 * b * j;
			if(tmp <= f) w.emplace(tmp);
		}
	}

	rep(i,3001){
		rep(j,3001){
			double tmp = c * i + d * j;
			if(tmp <= f) s.emplace(tmp);
		}
	}

	double answ = a * 100, anss = 0, k = -1;
	for(auto i : w){
		if(i == 0) continue;
		for(auto j : s){
			if(i + j > f || i * e < 100.0 * j) continue;
			if(k < j / (i + j)){
				k = j / (i + j);
				answ = i;
				anss = j;
			}
		}
	}
	cout << answ + anss << ' ' << anss << endl;
}
