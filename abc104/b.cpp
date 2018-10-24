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
	cin >> s;

	bool a = false, b = false, c = true;
	if(s.front() == 'A') a = true;

	int cnt = 0;
	range(i,2,s.size() - 1){
		if(s[i] == 'C') cnt++;
	}
	if(cnt == 1) b = true;

	rep(i,s.size()){
		if(s[i] == 'A' or s[i] == 'C') continue;
		if(isupper(s[i])) c = false;
	}

	cout << (a and b and c ? "AC" : "WA") << endl;
}
