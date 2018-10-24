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

int main(){
	int n;
	cin >> n;

	vector<long long> a(n), b(n);

	long long mini = 1e9 + 1;
	rep(i,n){
		cin >> a[i] >> b[i];
		if(a[i] > b[i]) mini = min(mini, b[i]);
	}

	if(a == b) cout << 0 << endl;
	else cout << accumulate(all(a), 0LL) - mini << endl;
}
