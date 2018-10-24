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
	string s;
	long long k;
	cin >> s >> k;

	rep(i,s.size()){
		if(s[i] == '1' and k == i + 1){
			cout << 1 << endl;
			return 0;
		}else if(s[i] != '1'){
			cout << s[i] << endl;
			return 0;
		}
	}
}
