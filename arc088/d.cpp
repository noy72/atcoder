#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const int INF = 1e8;
using namespace std;

int main(){
	string s;
	cin >> s;
	s = "0" + s + "0";

	int ans = s.size() - 2;
	range(i,1,s.size() - 1){
		if(s[i] != s[i + 1]){
			ans = min(ans, max<int>(i, s.size() - 2 - i));
		}
	}
	cout << ans << endl;
}
