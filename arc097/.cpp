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

	vector<pair<char, int>> a(n);
	rep(i,n){
		cin >> a[i].first >> a[i].second;
	}

	if(n == 1){
		cout << 0 << endl;
		return 0;
	}

	int w = n, b = n;
	int ans = 0;
	while(w != 1 or b != 1){
		if(a.back().first == 'W'){
			for(int i = w; i > a.back().second; i--){
				for(int j = a.size() - 1; j >= 0; j--, ans++){
					if(a[j].first == 'W' and a[j].second == i){
						a.erase(next(a.begin(), j));
					}
				}
			}
		}else{
			for(int i = b; i > a.back().second; i--){
				for(int j = a.size() - 1; j >= 0; j--, ans++){
					if(a[j].first == 'B' and a[j].second == i){
						a.erase(next(a.begin(), j));
					}
				}
			}
		}
	}
	cout << ans << endl;
}
