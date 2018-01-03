#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	int a, b;
	string s;
	cin >> a >> b >> s;

	map<char,int> m;
	for(auto i : s){
		m[i]++;
	}

	size_t t = s.find('-');
	if(t == string::npos){
		cout << "No" << endl;
		return 0;
	}

	if(m['-'] == 1 && t == a && s.size() - t - 1 == b){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
}
