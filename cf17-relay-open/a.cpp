#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	long long k, a, b;
	cin >> k >> a >> b;

	if(k <= a){
		cout << 1 << endl;
		return 0;
	}

	if(a <= b){
		cout << -1 << endl;
	}else{
		long long ans = 1;
		k -= a;
		if(k % (a - b)) ans += 2;
		ans += k / (a - b) * 2;

		cout << ans << endl;
	}
}
