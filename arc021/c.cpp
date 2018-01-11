#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

vector<long long> a, d;
long long k, n;

bool C(long long mid){
	long long sum = 0;
	rep(i,n){
		long long dif = mid - a[i];
		if(dif < 0) continue;

		long long tmp = dif / d[i] + 1;
		sum = min(k, sum + tmp);
	}
	return sum >= k;
}

int main(){
	cin >> k >> n;

	a = vector<long long>(n);
	d = vector<long long>(n);
	rep(i,n){
		cin >> a[i] >> d[i];
	}

	long long right = (1LL << 60), left = 0;
	rep(i,200){
		long long mid = (right + left ) / 2;
		if(C(mid)) right = mid;
		else left = mid;
	}
	//cout << right << endl;

	long long ans = 0;
	long long sum = 0;
	typedef pair<long long,int> P;
	priority_queue<P, vector<P>, greater<P>> q;

	rep(i,n){
		long long dif = right - a[i];
		if(dif < 0) continue;

		long long tmp = dif / d[i] + 1;
		sum += tmp;
		q.push(make_pair(a[i] + tmp * d[i],i));
		ans += tmp * a[i] + (tmp - 1) * tmp / 2 * d[i];
	}
	ans -= (sum - k) * right;

	cout << ans << endl;
}
