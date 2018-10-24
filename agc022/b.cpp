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


long long gcd(long long x, long long y) {
	long long r;
	if(x < y) swap(x, y);

	while(y > 0){
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}

int main(){
	int n;
	cin >> n;

	vector<long long> ans;
	if(n % 2){
		ans = vector<long long>({2, 3, 25});
	}else{
		ans = vector<long long>({2, 3, 25, 15000});
	}

	vector<bool> used(30000, 0);
	for(auto i : ans) used[i] = true;
	for (int i = 4; i < 15000; i+=2) {
		if(ans.size() == n) break;
		if(used[i]) continue;
		ans.emplace_back(i);
		ans.emplace_back(30000 - i);
		used[i] = used[30000 - i] = true;
	}
	for (int i = 3; i < 15000; i+=3) {
		if(ans.size() == n) break;
		if(used[i]) continue;
		ans.emplace_back(i);
		ans.emplace_back(30000 - i);
		used[i] = used[30000 - i] = true;
	}
	for (int i = 5; i < 15000; i+=5) {
		if(ans.size() == n) break;
		if(used[i]) continue;
		ans.emplace_back(i);
		ans.emplace_back(30000 - i);
		used[i] = used[30000 - i] = true;
	}


	assert(n == ans.size());

	rep(i,n){
		assert(ans[i] <= 30000);
		assert(ans[i] >= 1);
	}

	set<long long> s(all(ans));
	assert(s.size() == n);

	long long sum = accumulate(all(ans),0LL);
	rep(i,n){
		assert(gcd(sum - ans[i], ans[i]) != 1); 
	}

	long long cur = gcd(ans[0], ans[1]);
	rep(i,n){
		cur = gcd(cur, ans[i]);
	}
	assert(cur == 1);

	for(auto i : ans){ cout << i << endl; }
}
