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

bool check(vector<string>& s, int n){
	rep(i,n){
		rep(j,n){
			if(s[i][j] != s[j][i]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	int n;
	cin >> n;

	vector<string> s(n);
	rep(i,n){
		cin >> s[i];
		s[i] += s[i];
	}

	int cnt = 0;
	rep(i,n){
		vector<string> t(n);
		rep(j,n){
			rep(k,n){
				t[j] += s[j][i + k];
			}
		}
		if(check(t, n)) cnt++;
	}
	cout << cnt * n << endl;
}
