#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

#define int long long

int gcd(int x, int y) {
	int r;
	if(x < y) swap(x, y);

	while(y > 0){
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}

int lcm( int m, int n ) {
	// 引数に０がある場合は０を返す
	if ( ( 0 == m ) || ( 0 == n ) ) return 0;
	return ((m / gcd(m, n)) * n); // lcm = m * n / gcd(m,n)
}

signed main(){
	int n, k;
	cin >> n >> k;
	assert(k <= 100);

	range(i,0,k + 1){
		sum += 
	}
}
