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

	vector<long long> a(n),b(n);
	rep(i,n){ cin >> a[i]; }
	rep(i,n){ cin >> b[i]; }

	long long up = 0, down = 0;
	rep(i,n){
		if(a[i] <= b[i]) up+= (b[i] - a[i]) / 2;
		else down += a[i] - b[i];
	}
	if(up >= down) cout << "Yes" << endl;
	else cout << "No" << endl;
}
