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
	
	vector<int> a(n);
	cin >> a;

	int maxi = *max_element(all(a));

	int ans;
	int diff = -1;
	for(auto i : a){
		if(i == maxi) continue;
		if(diff < min(i, abs(maxi - i))){
			diff = min(i, abs(maxi - i));
			ans = i;
		}
	}
	cout << maxi << ' ' << ans << endl;
}
