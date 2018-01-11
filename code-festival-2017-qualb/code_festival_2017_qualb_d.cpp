#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	int n;
	string s;
	cin >> n >> s;
	s = "0" + s + "0";

	vector<int> dp(s.size(), 0);
	range(i,1,s.size() - 1){
		dp[i + 1] = max(dp[i + 1], dp[i]);

		if(s[i - 1] == '1' && s[i] == '0' && s[i + 1] == '1'){
			int back = i - 1, front = i + 1;

			while(s[back] == '1'){
				dp[i + 1] = max(dp[i + 1], dp[back - 1] + i - back);
				back--;
			}
			while(s[front] == '1'){
				dp[front] = max(dp[front], dp[i - 2] + front - i);
				front++;
			}
		}
		//for(auto i : dp){ cout << i <<' '; } cout << endl;
	}
	cout << dp[s.size() - 1] << endl;
}
