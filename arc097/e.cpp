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

void remove(vector<pair<char,int>>& a, int& s, int t, char c, int& ans){
	for(int i = s; i >= t; i--){
		for(int j = a.size() - 1; j >= 0; j--, ans++){
			if(a[j].first == c and a[j].second == i){
				a.erase(next(a.begin(), j));
				break;
			}
		}
	}
	s = t - 1;
}

int main(){
	int n;
	cin >> n;

	vector<pair<char,int>> a(n * 2);
	rep(i,n * 2){
		cin >> a[i].first >> a[i].second;
	}

	int ans = 0;
	int b = n, w = n;
	//rep(i,a.size()){
	//	cout << a[i].first << ' ';
	//}
	//cout << endl;
	//rep(i,a.size()){
	//	cout << a[i].second << ' ';
	//}
	//cout << endl;
	while(a.size() != 0){
		if(a.back().first == 'W'){
			remove(a, w, a.back().second, 'W', ans);
		}else{
			remove(a, b, a.back().second, 'B', ans);
		}
		//show(ans)
		//rep(i,a.size()){
		//	cout << a[i].first << ' ';
		//}
		//cout << endl;
		//rep(i,a.size()){
		//	cout << a[i].second << ' ';
		//}
		//cout << endl;
		//cout << b << ' ' << w << endl;
	}
	assert(b == 0 and w == 0);
	assert(a.size() == 0);
	cout << ans << endl;
}
