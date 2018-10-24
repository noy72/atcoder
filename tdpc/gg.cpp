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

const int MAX_N = 1000000;

template <typename T>
class BIT{
	private:
		vector<T> bit; //[1, n]
	public:
		BIT(){
			bit = vector<T>(MAX_N + 1, vector<int>(26,0));
		}
		T sum(int i){
			assert(1 <= i and i <= MAX_N and "invalid argument");
			T s = vector<int>(26,0);
			while(i > 0){
				rep(j,26) s[j] += bit[i][j];
				i -= i & -i;
			}
			return s;
		}

		void add(int i, char x){
			assert(1 <= i and i <= MAX_N and "invalid argument");
			while(i <= MAX_N){
				bit[i][x - 'a']++;
				//bit[i] = max(bit[i], x);
				i += i & - i;
			}
		}

		vector<int> get(int l, int r){
			vector<int> res = sum(r);
			vector<int> left = sum(l);
			rep(i,26){
				res[i] -= left[i];
			}
			return res;
		}
};

long long fact[1000005];
void factorial(){
	fact[1] = 1;
	range(i,2,1000001){
		fact[i] = fact[i - 1] * i;
	}
}

long long div(long long lim, vector<int>& d){
	int i = 0;
	int j = 1;
	long long res = 1;
	for(auto i : d) cout << i << ' ';
	cout << endl;
	while(j <= lim){
		if(i == d.size()){
			res *= j;
			j++;
			continue;
		}

		if(d[i] == 0){
			i++;
			continue;
		}
		if(res % fact[d[i]] == 0){
			res /= fact[d[i]];
			i++;
		}else{
			res *= j;
			j++;
		}
	}
	return res;
}

int main(){
	string s;
	long long k;
	cin >> s >> k;

	BIT<vector<int>> bit;
	vector<queue<int>> q(26);
	rep(i,s.size()){
		bit.add(i + 1, s[i]);
		q[s[i] - 'a'].emplace(i);
	}

	memset(fact, -1, sizeof(fact));
	factorial();

	long long now = 0;
	string ans;
	int curIdx = -1;
	show("JI")
	while(now != k){
		if(curIdx == s.size() - 1){
			cout << "Eel" << endl;
		}

		vector<long long> result(26, -1);
		rep(i,26){
			show(i)
			while(not q[i].empty() and q[i].front() < curIdx){
				q[i].pop();
			}
			if(q[i].empty()) continue;
			int idx = q[i].front() + 1;
			vector<int> alp = bit.get(idx + 1, s.size() + 1);
			result[i] = div(s.size() - idx - 1, alp);
		}

		int maxi;
		char nxt = '@';
		rep(i,26){
			if(now + result[i] <= k and maxi < now + result[i]){
				maxi = result[i];
				nxt = i + 'a';
			}
		}
		show(ans)
		assert(maxi != -1);
		assert(nxt != '@');
		show("JI")
		now += maxi;
		ans += nxt;
		show(nxt)
		curIdx = q[nxt - 'a'].front();
		show("end")
	}
	cout << ans << endl;
}
