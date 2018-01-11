#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

const int M = 1000000007;

//x^n mod M
typedef long long ull;
ull power(ull x, ull n, ull M){
	ull res = 1;
	if(n > 0){
		res = power(x, n / 2, M);
		if(n % 2 == 0) res = (res * res) % M;
		else res = (((res * res) % M) * x ) %M;
	}
	return res;
}

int main(){
	long long n, a, b;
	cin >> n >> a >> b;

	vector<long long> v(n);
	long long maxi = 0;
	rep(i,n){
		long long x;
		cin >> x;
		v[i] = x;
		maxi = max(maxi, x);
	}

	if(a == 1){
		sort(all(v));
		for(auto i : v){
			cout << i << endl;
		}
		return 0;
	}

	long long k = 0;
	rep(i,n){
		k += log(maxi / v[i]) / log(a);
	}

	priority_queue<long long, vector<long long>, greater<long long>> q;
	if(b <= k){
		rep(i,n) q.push(v[i]);
		rep(i,b){
			long long t = q.top(); q.pop();
			t *= a;
			q.push(t);
		}
		while(not q.empty()){
			long long t = q.top(); q.pop();
			cout << t % M << endl;
		}
		return 0;
	}

	rep(i,n){
		long long k = log(maxi / v[i]) / log(a);
		v[i] *= power(a,k,M);
		q.push(v[i]);
		//show(v[i])
		b-=k;
	}
	//show(b)

	//while(not q.empty()){ cout << q.top() << endl; q.pop(); } return 0;

	vector<long long> bak;
	rep(i,b % n){
		bak.emplace_back(q.top());
		q.pop();
	}

	while(not q.empty()){
		cout << q.top() * power(a, b / n, M) % M << endl;
		q.pop();
	}

	rep(i,bak.size()){
		//show(bak[i])
		//	show(power(a,b / n + 1, M))
		cout << bak[i] * power(a, b / n + 1, M) % M << endl;
	}
}
