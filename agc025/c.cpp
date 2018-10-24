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

typedef tuple<int,int,int> T;

int main(){
	int n;
	cin >> n;

	vector<T> t(n);
	rep(i,n){
		int a, b;
		cin >> a >> b;
		t[i] = T(a,b,0);
	}

	sort(all(t));

	long long ans = 0;

	long long cur = 0;
	long long sum = 0;
	rep(i,n){
		if(i % 2){
			auto it = lower_bound(all(t), make_tuple(1ecur, 1e9, 0));
			int a, b, c;
			tie(a,b,c) = *it;
			*it = T(a, b, -1);

			sum += abs(cur - a);
			cur = a;

		}else{
			auto it = lower_bound(all(t), make_tuple(cur, 1e9, 0));
			int a, b, c;
			tie(a,b,c) = *it;
			*it = T(a, b, -1);

			sum += abs(cur - a);
			cur = a;
		}
	}
}
