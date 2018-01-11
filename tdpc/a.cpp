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

	vector<int> p(n);
	rep(i,n){
		cin >> p[i];
	}

	vector<int> dp(10001,0);
	dp[0] = 1;
	rep(i,n){
		for(int j = 10000; j >= 0; j--){
			if(j - p[i] < 0) continue;
			dp[j] |= dp[j - p[i]];
		}
	}

	cout << accumulate(all(dp), 0) << endl;
}
