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

	set<char> st(all(s));
	if(st.size() == 26){
		int i = 25;
		while(i != 0 and s[i - 1] > s[i]){
			i--;
		}
		if(i == 0){
			cout << -1 << endl;
			return 0;
		}

		char c = 127;
		range(j,i,s.size()){
			if(s[i - 1] > s[j]) continue;
			c = min(c, s[j]);
		}
		cout << s.substr(0,i - 1) + c << endl;
	}else{
		char i = 'a';
		while(st.count(i)){
			i++;
		}
		cout << s + i << endl;
	}
}
