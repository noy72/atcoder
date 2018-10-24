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
	string n;
	cin >> n;

	int sum = 0, maxi = 0;
	rep(i,n.size()){
		if(n[i] == '0') continue;
		sum += n[i] - '0';
		maxi = max<int>(maxi, sum - 1 + 9 * (n.size() - i - 1));
	}
	cout << max(maxi, sum) << endl;
}
