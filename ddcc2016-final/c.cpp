#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

#define int long long

signed main(){
	long long a, b, c;
	string s;
	cin >> a >> b >> c >> s;

	char t = '0';
	int cnt = 0;
	vector<int> v1(s.size() + 5), v2(s.size() + 5);
	rep(i,s.size() + 1){
		v1[i] = cnt;
		if(i == s.size()) break;
		if(t != s[i]){
			cnt++;
			t = s[i];
		}
	}

	t = '1';
	cnt = 0;
	for(int i = s.size(); i >= 0; i--){
		v2[i] = cnt;
		if(i == 0) break;
		if(t != s[i - 1]){
			cnt++;
			t = s[i - 1];
		}
	}

	int ans = (1LL << 60);
	rep(i,s.size() + 1){
		ans = min<int>(ans, a * i + b * (s.size() - i) + c * max(v1[i], v2[i]));
	}
	cout << ans << endl;
}
