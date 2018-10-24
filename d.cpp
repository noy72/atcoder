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

	vector<long long> a(n);
	cin >> a;

	long long p = 0;
	rep(i,n){
		if(abs(a[p]) < abs(a[i])) p = i;
	}

	vector<pair<int, int>> ans;
	if(a[p] > 0){
		rep(i,n){
			if(a[i] < 0){
				ans.emplace_back(p,i);
			}
		}
		rep(i,n - 1){
			ans.emplace_back(i, i + 1);
		}
	}else if(a[p] < 0){
		rep(i,n){
			if(a[i] > 0){
				ans.emplace_back(p,i);
			}
		}
		for(int i = n - 1; i > 0; i--){
			ans.emplace_back(i, i - 1);
		}
	}
	cout << ans.size() << endl;
	for(auto i : ans){
		cout << i.first + 1 << ' ' << i.second + 1 << endl;
	}
}
