#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

template<typename T>
ostream& operator << (ostream& os, vector<T>& v){
	rep(i,v.size()){ os << v[i] << (i == v.size() - 1 ? "" : " "); } return os;
}
template<typename T>
istream& operator >> (istream& is, vector<T>& v){
	for(T& x: v){ is >> x; } return is;
}

int main(){
	int d, g;
	cin >> d >> g;

	vector<int> p(d), c(d);
	rep(i,d){
		cin >> p[i] >> c[i];
	}

	int ans = 1e9;
	rep(s, 1 << d){
		rep(i,d){
			int point = g;
			int prob = 0;
			if(s >> i bitand 1){
				rep(j,d){
					if(s >> j bitand 1){
						if(i == j) continue;
						prob += p[j];
						point -= (j + 1) * 100 * p[j] + c[j];
					}
				}

				rep(j,p[i]){
					if(point <= 0) break;
					point -= (i + 1) * 100;
					prob++;

					if(j + 1 == p[i]) point -= c[i];
				}

				if(point <= 0){
					//cout << prob << ' ' << s << endl;
					ans = min(ans, prob);
				}
			}
		}
	}
	cout << ans << endl;
}
