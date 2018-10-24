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

double battle(double a, double b){
	return 1 / (1 + pow(10, ((b - a) / 400)));
}

int main(){
	int k;
	cin >> k;

	vector<double> p(1 << k);
	rep(i,1 << k) cin >> p[i];

	vector<vector<double>> dp(1 << k, vector<double>(k + 1, 0));
	rep(i,1 << k) dp[i][0] = 1.00;
	rep(i,k){
		rep(j,1 << k){
			int t = pow(2,i + 1);
			double sum = 0;
			if(j % t >= t / 2){
				range(k, j / t * t, j / t * t + t / 2){
					sum += dp[j][i] * dp[k][i] * battle(p[j], p[k]);
				}
			}else{
				range(k, j / t * t + t / 2, j / t * t + t){
					sum += dp[j][i] * dp[k][i] * battle(p[j], p[k]);
				}
			}
			dp[j][i + 1] = sum;
		}
	}
	rep(i,1 << k){
		cout << fixed << setprecision(10) << dp[i][k] << endl;
	}
}
