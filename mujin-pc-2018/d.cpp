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

const int MAX = 1000;

int rev(string r){
	if(r.back() == '0') return INT_MAX;

	reverse(all(r));
	return stoi(r);
}

const string zero[] = {"", "0", "00"};
void revPair(pair<int, int> p, queue<pair<int, int>>& q){
	if(not (p.first < MAX and p.second < MAX)) return;

	string s = to_string(p.first);
	rep(i,3) if(rev(zero[i] + s) < p.second){
		q.emplace(make_pair(rev(zero[i] + s), p.second));
	}

	s = to_string(p.second);
	rep(i,3)
		if(rev(zero[i] + s) <= p.first)
			q.emplace(make_pair(p.first, rev(zero[i] + s)));
}

bool used[MAX][MAX] = {};
void bfs(pair<int, int> s){
	queue<pair<int, int>> q;
	q.emplace(s);

	while(not q.empty()){
		pair<int, int> cur = q.front(); q.pop();

		if(not (cur.first < MAX and cur.second < MAX)) continue;

		if(used[cur.first][cur.second]) continue;
		used[cur.first][cur.second] = true;

		revPair(pair<int, int>(cur.first + cur.second, cur.second), q);
		revPair(pair<int, int>(cur.second, cur.first + cur.second), q);
	}

}

void solve(int n, int m){
	memset(used, false, sizeof(used));
	range(i,1,MAX) bfs(pair<int, int>(i,0));
	range(i,1,MAX) bfs(pair<int, int>(0,i));

	int sum = 0;
	range(i,1,n + 1){
		range(j,1,m + 1){
			if(used[i][j]){
				sum ++;
			}else{
				//cout << i << ' ' << j << endl;
			}
		}
	}
	cout << n * m - sum << endl;

}

void test(){
	solve(13, 13);
	solve(20, 30);
	solve(314, 159);
}

int main(){
	//test(); return 0;
	int n, m;
	cin >> n >> m;
	solve(n,m);
}
