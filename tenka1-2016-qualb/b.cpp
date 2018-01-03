#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const int INF = 1e8;
using namespace std;

string s;

int memo[101][100][100];
int dfs(int cur, int pre, int diff){
	if(cur == s.size()){
		return diff == 0 ? max(0, pre - 1) : INF;
	}
	if(diff < 0) return INF;

	auto &p = memo[pre][cur][diff];
	if(p != -1) return p;

	int res = INF;
	if(s[cur] == '('){
		res = min(res, dfs(cur + 1, pre, diff + 1)); // そのまま
		res = min(res, dfs(cur + 1, cur + 1, diff - 1) + 1); // ( -> )
	}else{
		res = min(res, dfs(cur + 1, pre, diff - 1)); // そのまま
		res = min(res, dfs(cur + 1, cur + 1, diff + 1) + 1); // ) -> (
	}

	return p = res;
}

int main(){
	cin >> s;
	memset(memo, -1, sizeof(memo));
	cout << dfs(0,0,0) << endl;
}
