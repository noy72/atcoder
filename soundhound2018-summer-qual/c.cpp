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
	double n, m, d;
	cin >> n >> m >> d;

	double a;
	if(d == 0) a = n;
	else {
		a = 2 * (n - 1) - (2 * (d - 1));
	}
	//a *= n * (m - 2);

	cout << fixed << setprecision(8) << a / (n * n) * (m - 1) << endl;
}
