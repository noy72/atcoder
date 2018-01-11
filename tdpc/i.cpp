#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

string s;


int main(){
	cin >> s;
	int dp[305][305] = {{0}}; //r から l までで消せるiwi

	range(W,3,s.size() + 1){
		rep(i,s.size()){ //[i,j]
			int j = i + W - 1;
			if(i + W - 1 > s.size()) break;
			if(s[i] == 'i' && s[j - 1] == 'w' && s[j] == 'i' && dp[i + 1][j - 2] + 3 == W ){
				dp[i][j] = W;
			}
			if(s[i] == 'i' && s[i + 1] == 'w' && s[j] == 'i' && dp[i + 2][j - 1] + 3 == W ){
				dp[i][j] = W;
			}
			range(k,i,j){
				dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
			}
		}
	}
	assert(dp[0][s.size() - 1] % 3 == 0);
	cout << dp[0][s.size() - 1] / 3 << endl;
}
