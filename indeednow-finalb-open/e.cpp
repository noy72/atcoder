#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

#define int long long

const int MAX_N = 100005;

//[1, n]
int bit[MAX_N + 1] = {0};

int sum(int i){
	int s = 0;
	while(i > 0){
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

void add(int i, int x){
	while(i <= MAX_N){
		bit[i] += x;
		//bit[i] = max(bit[i], x);
		i += i & - i;
	}
}

void compress(vector<int> &v) {
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
}

int lb(vector<int>& v, int num){
	return lower_bound(all(v), num) - v.begin();
}

signed main(){
	int n;
	cin >> n;

	vector<int> h(n);
	set<int> s;
	rep(i,n){
		cin >> h[i];
		s.emplace(h[i]);
	}

	if(s.size() != n){
		cout << -1 << endl;
		return 0;
	}

	vector<int> comp(all(h));
	compress(comp);

	vector<int> a(n);
	rep(i,n){
		a[i] = lb(comp, h[i]);
	}

	long long cnt = 0;
	rep(i,n){
		cnt += static_cast<long long>((sum(100001) - sum(a[i] + 1))) * h[i];
		add(a[i] + 1, 1);
	}

	cout << cnt << endl;
}
