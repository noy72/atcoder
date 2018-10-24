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

	vector<int> idx(n);
	rep(i,n){
		int a;
		cin >> a;
		idx[a - 1] = i;
	}

	int t = 1, maxi = 1;
	rep(i,n - 1){
		if(idx[i] < idx[i + 1]){
			t++;
		}else{
			t = 1;
		}
		maxi = max(maxi, t);
	}
	cout << n - maxi << endl;
}
