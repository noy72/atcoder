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

	string s;
	rep(i,n){
		cin >> s;
		int j = 0, cnt = 0;
		while(j < s.size() - 5){
			if(s.substr(j,5) == "tokyo"){
				cnt++;
				j += 5;
			}else if(s.substr(j,5) == "kyoto"){
				cnt++;
				j += 5;
			}else{
				j++;
			}
		}
		cout << cnt << endl;
	}
}
