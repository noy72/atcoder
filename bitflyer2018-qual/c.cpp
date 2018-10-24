#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

template<typename T>
ostream& operator << (ostream& os, vector<T>& v){
	rep(i,v.size()){ os << v[i] << (i == v.size() - 1 ? "" : " "); } return os;
}
template<typename T>
istream& operator >> (istream& is, vector<T>& v){
	for(T& x: v){ is >> x; } return is;
}

const long long M = 1000000007;

class Combination{
	public:
		vector<long long> fact, rev;
		Combination(int n = 200005) : fact(n), rev(n) { // n = h + w
			fact[0] = fact[1] = 1;
			range(i,2,n){
				(fact[i] = fact[i - 1] * i) %= M;
			}
			rev[n - 1] = power(fact[n - 1], M - 2) % M;
			for (int i = n - 1; i > 0; i--) {
				rev[i - 1] = rev[i] * i % M;
			}
		}
		long long power(long long x, long long n){ //べき乗 x^n mod M
			long long res = 1;
			if(n > 0){
				res = power(x, n / 2);
				if(n % 2 == 0) res = (res * res) % M;
				else res = (((res * res) % M) * x ) % M;
			}
			return res;
		}
		long long factorial(long long l, long long r){ return fact[r] * rev[l - 1] % M; }
		long long factorial(long long n){ return fact[n]; }
		long long combination(long long n, long long r){ //nCr (1,1)から(w,h)だと、引数は(w - 1, h - 1, M)
			return factorial(n - r + 1, n) * rev[r] % M;
		}
};

//S:sumの条件 n:個数
long long solve(vector<pair<int, int>>& seg, vector<long long>& x, long long n, long long d){
	long long S = d;
	long long s = 0, t = 0;

	long long res = 0;
	while(true){
		show("------")
		while(t + 1 < n && x[t] - x[s] < S){
			t++;
			cout << " JI " << x[t] - x[s] << ' ' << t << ' ' << s << endl;
			if(t - s >= 2 and x[t] - x[s] <= S){
				cout << t << ' ' << s << endl;
				res += t - s - 1;
			}
		}
		if(x[t] - x[s] > S) seg.emplace_back(s, t);
		s++;
		if(t - s >= 2 and x[t] - x[s] <= S){
			cout << t << ' ' << s << endl;
			res += t - s - 1;
		}
		if(t == s) break;
			//cout << " JI " << sum << ' ' << t << ' ' << s << endl;
	}
	return res;
}

int main(){
	long long n, d;
	cin >> n >> d;

	vector<long long> x(n);
	cin >> x;

	Combination com;
	long long ans = com.combination(n, 3);

	show(ans)
	vector<pair<int, int>> s;
	ans -= solve(s, x, n, d);
	show(ans)
	for(auto i : s){ cout << i.first << ' ' << i.second << endl; }

	cout << endl;
	for(auto p : s){
		cout << p.first << ' ' << n - p.second - 1 << endl;
		if(p.first == 0 or n - p.second - 1 == 0){
			ans -= p.first;
			ans -= n - p.second - 1;
		}else{
			ans -= (p.first + 1) * (n - p.second);
		}
		//ans -= n - p.second;
	}
	cout << ans << endl;
}
