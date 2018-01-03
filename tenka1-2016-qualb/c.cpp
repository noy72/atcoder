#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	int n;
	double p, a, b;
	char g;
	cin >> n >> a >> g >> b;
	p = a / b;

	vector<pair<int, int>> win(n); //勝利数、予選の順位
	rep(i,n){
		int cnt = 0;
		rep(j,n){
			int a;
			cin >> a;
			cnt += a;
		}
		win[i] = make_pair(cnt, i + 1);
	}
	sort(all(win));

	vector<double> per(n + 1,1); //per[i] := 勝敗の結果をi回間違える確率
	rep(i,n) per[0] *= p;
	rep(i,n - 1) per[i + 1] *= per[i] / p * (1.0 - p);

	double dp[30][30] = {{0}};
	dp[0][0] = 1;
	rep(i,n){
		int w = win[i].first;
		rep(j,n + 1){
			rep(k,n + 1){
				if(j + k > n) continue;
				dp[i + 1][j + k] += dp[i][j] * per[abs(w - j)];
			}
		}
	}
}
