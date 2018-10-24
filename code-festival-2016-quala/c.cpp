#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	string s;
	int k;
	cin >> s >> k;

	string ans;
	for(auto i : s){
		int cost = 'z' - i + 1;
		if(i == 'a' or k < cost){
			ans += i;
		}else{
			k -= cost;
			ans += 'a';
		}
	}

	k %= 26;
	rep(i,k) ans.back()++;
	cout << ans << endl;
}
