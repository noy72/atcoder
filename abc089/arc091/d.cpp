#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	long long n, k;
	cin >> n >> k;

	if(k == 0){
		cout << n * n << endl;
		return 0;
	}

	long long ans = 0;
	range(i,k + 1,n + 1){
		ans += n / i * (i - k);
		ans += max<long long>(n % i + 1 - k, 0);
	}
	cout << ans << endl;
}
