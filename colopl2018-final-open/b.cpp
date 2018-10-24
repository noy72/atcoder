#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;


	string s;
typedef string::const_iterator State;

string number(State& begin){
	string res;
	while(isdigit(*begin)){
		res += *begin;
		begin++;
	}
	return res;
}

void dfs(State& begin, char op){
	if(isdigit(*begin)){
		cout << number(begin);
		if(begin == s.end()) return;

		dfs(begin, op);
	}else if(*begin == ','){
		cout << op;
		begin++;
		dfs(begin, op);
	}else if(*begin != ')'){
		char nextOp = *begin;

		begin++; begin++;
		cout << '(';
		dfs(begin, nextOp);
		cout << ')';

		begin++;
		if(begin == s.end()) return;

		dfs(begin, op);
	}
}

int main(){
	cin >> s;

	State tmp = s.begin();
	dfs(tmp, ' ');
	cout << endl;
}
