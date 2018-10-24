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

	rep(i,n){
		long long a, b;
		cin >> a >> b;
		if(a > b) swap(a,b);

		if(a == b){
			cout << 2 * a - 2 << endl;
		}else if(b - a == 1){
			cout << 2 * a - 2 << endl;
		}else{
			long long c = sqrt(a * b - 1);
			if(c * (c + 1) >= a * b) cout << 2 * c - 2 << endl;
			else cout << 2 * c - 1 << endl;
		}
	}
}
