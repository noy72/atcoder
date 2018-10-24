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

vector<int> p;

const int kN = 55556;
void primeNumber(){
	bool prime[kN];
	rep(i,kN) prime[i] = 1;
	prime[0] = prime[1] = 0;
	rep(i,kN){
		if(prime[i]){
			if(i != 2) p.emplace_back(i);
			for(int j = i + i; j < kN; j+=i){
				prime[j] = 0;
			}
		}
	}
}

int main(){
	int n;
	cin >> n;

	primeNumber();

	vector<int> ans;
	rep(i,p.size()){
		if(ans.size() == n) break;
		if(p[i] % 10 == 1) ans.emplace_back(p[i]);
	}
	cout << ans << endl;
}
