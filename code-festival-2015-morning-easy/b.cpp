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

	if(s.size() % 2){
		cout << -1 << endl;
	}else{
		int h = s.size() / 2;
		int cnt = 0;
		rep(i,n / 2){
			if(s[i] != s[h + i]) cnt++;
		}
		cout << cnt << endl;
	}
}
