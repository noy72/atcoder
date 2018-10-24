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

long long getDigit(long long a){
	int res = 0;
	while(a > 0){
		res += a % 10;
		a/=10;
	}
	return res;
}

int main(){
	vector<pair<double, long long>> v;
	range(i,1,10000){
		v.emplace_back(i * 1.0 / getDigit(i), i);
	}

	long long base = 10000, ni = 99;
	rep(k,15){
		range(i,1,10){
			rep(j,10){
				rep(k,10){
					long long temp =
						i * base +
						j * base / 10 +
						k * base / 100 + ni;
					v.emplace_back(static_cast<double>(temp) / getDigit(temp), temp);
				}
			}
		}
		base *= 10;
		ni = ni * 10 + 9;
	}
	//cout << i << ' ' << static_cast<double>(i) / getDigit(i) << endl;
	sort(all(v));
	long long maxi = -1;

	vector<long long> ans;
	for(auto i : v){
		if(maxi < i.second){
			maxi = i.second;
		}else{
			continue;
		}
		ans.emplace_back(i.second);
		//cout << i.second << endl;
		//cout << i.first << ' ' << i.second << endl;
	}

	int n;
	cin >> n;
	rep(i,n){
		cout << ans[i] << endl;
	}
}
