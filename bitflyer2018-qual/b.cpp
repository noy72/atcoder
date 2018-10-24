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
	int a, b, n;
	cin >> a >> b >> n;

	string s;
	cin >> s;

	rep(i,n){
		if(s[i] == 'S'){
			if(a > 0) a--;
		}else if(s[i] == 'C'){
			if(b > 0) b--;
		}else{
			if(a >= b and a > 0) a--;
			else if(a < b and b > 0) b--;
		}
	}
	cout << a << endl << b << endl;
}
