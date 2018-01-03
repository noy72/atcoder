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

	int cnt  = 0;
	rep(i,s.size() - 1){
		if(s[i] != s[i + 1]){
			cnt++;
			i++;
		}
	}
	cout << n - cnt << endl;
}
