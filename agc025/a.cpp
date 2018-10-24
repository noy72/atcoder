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

int get(int a){
	int res = 0;
	while(a != 0){
		res += a % 10;
		a/=10;
	}
	return res;
}

int main(){
	int n;
	cin >> n;

	int mini = 1e9;
	range(i,1,n){
		int b = n - i;
		mini = min(mini, get(i) + get(b));
	}
	cout << mini << endl;
}
