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

typedef tuple<int,int,int> T;

map<long long, int> prime_factor(long long n){
	map<long long, int> res;
	for(long long i = 2; i * i <= n; i++){
		while(n % i == 0){
			++res[i];
			n /= i;
		}
	}
	if(n != 1) res[n] = 1;
	return res;
}

bool impossible(map<long long, int>& p){
	for(auto i : p){
		if(i.first > 5) return true;
	}
	return false;
}

double dp[2][70][70][70];

int main(){
	int n;
	long long d;
	cin >> n >> d;

	map<long long, int> p = prime_factor(d);
	if(impossible(p)){
		cout << 0 << endl;
		return 0;
	}

	vector<T> cnt = {
		T(0, 0, 0),
		T(1, 0, 0),
		T(0, 1, 0),
		T(2, 0, 0),
		T(0, 0, 1),
		T(1, 1, 0),
	};

	dp[0][0][0][0] = 1.00;
	rep(i,n){
		rep(j,65) rep(k,65) rep(l,65){
			rep(m,6){
				int x, y, z;
				tie(x, y, z) = cnt[m];
				dp[(i + 1) % 2][j + x][k + y][l + z] += dp[i % 2][j][k][l] / 6.0;
			}
		}
		rep(j,65) rep(k,65) rep(l,65) dp[i % 2][j][k][l] = 0;
	}
	//rep(i,n + 1){
	//	rep(j,4){
	//		rep(k,2){
	//			rep(l,2){
	//				cout << i << ' ' << j << ' ' << k << ' ' << l << endl;
	//				cout << dp[i][j][k][l] << endl;
	//			}
	//		}
	//	}
	//}

	double ans = 0;
	//cout << p[2] << ' ' << p[3] << ' ' << p[5] << endl;
	range(i,p[2],67){
		range(j,p[3],67){
			range(k,p[5],67){
				ans += dp[n % 2][i][j][k];
			}
		}
	}
	cout << fixed << setprecision(10) << ans << endl;
}
