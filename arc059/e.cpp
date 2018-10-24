#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

template <typename X, typename T>
auto vectors(X x, T a) {
	return vector<T>(x, a);
}

template <typename X, typename Y, typename Z, typename... Zs>
auto vectors(X x, Y y, Z z, Zs... zs) {
	auto cont = vectors(y, z, zs...);
	return vector<decltype(cont)>(x, cont);
}

template<typename T>
ostream& operator << (ostream& os, vector<T>& v){
	rep(i,v.size()){ os << v[i] << (i == v.size() - 1 ? "" : " "); } return os;
}
template<typename T>
istream& operator >> (istream& is, vector<T>& v){
	for(T& x: v){ is >> x; } return is;
}

const long long M = 1000000007;

void solveNCC(){
	int n, c;
	cin >> n >> c;

	vector<int> a(n), b(n);
	cin >> a >> b;

	assert(a == b);

	// make table
	auto t = vectors(500, 500, 0LL);
	range(i,1,500){
		t[i][0] = 1;
		range(j,1,500){
			(t[i][j] = t[i][j - 1] * i) %= M;
		}
	}

	auto dp = vectors(n + 1, c + 1, 0LL);
	dp[0][0] = 1;
	rep(i,n){
		rep(j,c + 1){
			rep(k,c + 1){
				if(j + k > c) break;
				(dp[i + 1][j + k] += (dp[i][j] * t[a[i]][k]) % M) %= M;
			}
		}

		rep(i,dp.size()){ rep(j,dp[0].size()){ cout << dp[i][j] << ' '; } cout << endl; } cout << endl;
	}
	cout << dp[n][c] << endl;
}

void solveNC(){
	int n, c;
	cin >> n >> c;

	vector<int> a(n), b(n);
	cin >> a >> b;

	assert(a == b);

	auto dp = vectors(n + 1, c + 1, 0LL);
	dp[0][0] = 1;
	range(i,1,n + 1){
		dp[i][0] = 1;
		rep(j,c){
			dp[i][j + 1] = (dp[i][j] * a[i - 1] % M + dp[i - 1][j + 1]) % M;
		}

		//rep(i,dp.size()){ rep(j,dp[0].size()){ cout << dp[i][j] << ' '; } cout << endl; } cout << endl;
	}
	cout << dp[n][c] << endl;
}

int main(){
	int n, c;
	cin >> n >> c;

	vector<int> a(n), b(n);
	cin >> a >> b;


	auto dp = vectors(n + 1, c + 1, 0LL);
	dp[0][0] = 1;
	range(i,1,n + 1){
		//dp[i][0] = 1;

		auto _dp = vectors(c + 1, 405, 0LL);
		range(k,a[i - 1],b[i - 1] + 1){
			_dp[0][k] = dp[i - 1][0];
			rep(j,c){
				_dp[j + 1][k] = (_dp[j][k] * k % M + dp[i - 1][j + 1]) % M;
			}
		}

		//rep(i,_dp.size()){ rep(j,4){ cout << _dp[i][j] << ' '; } cout << endl; } cout << endl;

		rep(j,c + 1){
			rep(k,405){
				(dp[i][j] += _dp[j][k]) %= M;
			}
		}

		//rep(i,dp.size()){ rep(j,dp[0].size()){ cout << dp[i][j] << ' '; } cout << endl; } cout << endl;
	}
	cout << dp[n][c] << endl;
}
