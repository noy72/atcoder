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

const int MAX_N = 200000;

template <typename T>
class BIT{
private:
	vector<T> bit; //[1, n]
public:
	BIT(){
		bit = vector<T>(MAX_N + 1, 0);
	}
	T sum(int i){
		if(i == 0) return 0;
		assert(1 <= i and i <= MAX_N and "invalid argument");
		T s = 0;
		while(i > 0){
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}

	void add(int i, int x){
		assert(1 <= i and i <= MAX_N and "invalid argument");
		while(i <= MAX_N){
			bit[i] += x;
			//bit[i] = max(bit[i], x);
			i += i & - i;
		}
	}
};

int main(){
	int n, k;
	cin >> n >> k;

	vector<long long> origin(n);
	vector<pair<long long, int>> a(n);
	rep(i,n){
		cin >> origin[i];
		origin[i] -= k;
		a[i] = make_pair(origin[i], i);
	}
	rep(i,n - 1) a[i + 1].first += a[i].first;
	sort(all(a));

	map<int,int> m;
	rep(i,a.size()) m[ a[i].second ] = i;

	//rep(i,n){ cout << a[i].first << ' ' ; } cout << endl;

	long long ans = 0;
	long long t = 0;
	BIT<long long> bit;
	rep(i,n){
		long long p = distance(a.begin(), lower_bound(all(a), make_pair(t, - 1)));
		ans += n - p;
		t+=origin[i];

		ans -= bit.sum(MAX_N) - bit.sum(p);
		bit.add(m[i] + 1, 1);
	}
	cout << ans << endl;
}
