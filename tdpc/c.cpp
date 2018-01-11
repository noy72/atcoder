#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

double win(double p, double q){
	return 1.0 / (1.0 + pow(10, (q - p) / 400.0));
}

double par[1024][1024];

int main(){
	int k;
	cin >> k;

	int n = 1 << k;
	vector<double> r(n);
	rep(i,n){
		cin >> r[i];
	}

	rep(i,n){
		rep(j,n){
			par[i][j] = win(r[i], r[j]);
		}
	}

	double dp[11][1024];
	rep(i,1024) dp[0][i] = 1;

	range(i,1,k + 1){
		int tmp = 1 << i;
		rep(j,n){
			int p = tmp / 2, s;
			if(j % tmp >= tmp / 2) s = j / tmp * tmp;
			else s = tmp / 2 + j / tmp * tmp;

			double sum = 0;
			for(int k = s; k < s + p; k++){
				sum += dp[i - 1][k] * par[j][k];
			}
			dp[i][j] = dp[i - 1][j] * sum;
		}
	}
	
	double sum = 0;
	rep(i,n){
		sum += dp[k][i];
	}
	rep(i,n){
		cout << fixed << setprecision(10)<<dp[k][i] / sum << endl;
	}
}
