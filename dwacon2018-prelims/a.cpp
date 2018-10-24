#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	string s;
	cin >> s;

	if(s[0] == s[2] and s[1] == s[3]) cout << "Yes" << endl;
	else cout << "No" << endl;
}
