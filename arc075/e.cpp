#include<bits/stdc++.h>
#define range(i,a,b) for(long long i = (a); i < (b); i++)
#define rep(i,b) for(long long i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const long long INF = 1e8;
using namespace std;

const int MAX_N = 200105;

//[1, n]
long long bit[MAX_N + 1] = {0};

long long sum(long long i){
	i++;
	long long s = 0;
	while(i > 0){
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

void add(long long i, long long x){
	i++;
	while(i <= MAX_N){
		bit[i] += x;
		//bit[i] = max(bit[i], x);
		i += i & - i;
	}
}

int main(){
	long long n, k;
	cin >> n >> k;

	vector<long long> a(n);
	vector<pair<long long,int>> v(n), cp(n);
	long long cur = 0;
	rep(i,n){
		cin >> a[i];
		a[i] -= k;
		cur += a[i];
		v[i] = make_pair(cur,i);
	}
	cp = v;
	sort(all(v));

	long long q = 0;
	long long ans = 0;
	rep(i,n){
			//show(distance(v.begin(), lower_bound(all(v), make_pair(q, -1))))
			long long dis = distance(v.begin(), lower_bound(all(v), make_pair(q, -1)));
			ans += n - dis;
			q += a[i];
			//show(dis)
			if(dis != 0) ans -= sum(n) - sum(dis - 1);
			else ans -= sum(n);
			add(distance(v.begin(), lower_bound(all(v), cp[i])), 1);
			//show(distance(v.begin(), lower_bound(all(v), cp[i])))
	}
	cout << ans << endl;
}
