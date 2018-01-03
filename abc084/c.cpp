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
	n--;

	vector<int> c(n), s(n), f(n);
	rep(i,n){
		cin >> c[i] >> s[i] >> f[i];
	}

	rep(j,n){
		int cnt = s[j] + c[j];
		range(i,j + 1,n){
			if(cnt <= s[i]){
				cnt = s[i] + c[i];
			}else{
				int diff = cnt - s[i];
				int wait = diff / f[i];
				if(diff % f[i] != 0) wait++;

				cnt = s[i] + wait * f[i] + c[i];
			}
		}
		cout << cnt << endl;
	}

	cout << 0 << endl;
}
