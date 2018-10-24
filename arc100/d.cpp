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

void popIn(queue<long long>& a, queue<long long>& b, long long& p, long long& q){
	long long k = b.front(); b.pop();
	q-=k;
	a.emplace(k);
	p+=k;
}

long long diff(long long a, long long b, long long c, long long d){
	return max({a, b, c, d}) - min({a, b, c, d});
}

void out(queue<long long> a){
	while(not a.empty()){
		cout << a.front() << ' ';
		a.pop();
	}
	cout <<" / ";
}

int main(){
	int n;
	cin >> n;

	vector<long long> a(n);
	cin >> a;

	queue<long long> b, c, d, e;
	long long p = a[0], q = a[1], r = a[2], s = 0;
	b.emplace(a[0]);
	c.emplace(a[1]);
	d.emplace(a[2]);
	range(i,3,n){
		s += a[i];
		e.emplace(a[i]);
	}

	long long ans = diff(p, q, r, s);
		while(e.size() >= 2 and abs(r - s) >= abs( (r + e.front()) - (s - e.front()) )){
			popIn(d, e, r, s);
			ans = min(ans, diff(p, q, r, s));
		}
	while(d.size() + e.size() > 2){
	//rep(i,n - 1 - 2){
		popIn(c, d, q, r);
		ans = min(ans, diff(p, q, r, s));

		while(c.size() >= 2 and abs(p - q) >= abs( (p + c.front()) - (q - c.front()) )){
			popIn(b, c, p, q);
			ans = min(ans, diff(p, q, r, s));
		}
		while(e.size() >= 2 and abs(r - s) >= abs( (r + e.front()) - (s - e.front()) )){
			popIn(d, e, r, s);
			ans = min(ans, diff(p, q, r, s));
		}


		//cout << b.size() << ' ' << c.size() << ' ' << d.size() << ' ' << e.size() << endl;
		assert(b.size() >= 1);
		assert(c.size() >= 1);
		assert(d.size() >= 1);
		assert(e.size() >= 1);
		//cout << p << ' ' << q << ' ' << r << ' ' << s << endl;
		//out(b); out(c); out(d); out(e); cout << endl;
		ans = min(ans, diff(p, q, r, s));
	}
	cout << ans << endl;
}
