#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

string toStr(int n){
	string str;
	int len = static_cast<int>(log10(n));
	int K = 1;
	rep(i,len) K*=10;
	rep(i,len + 1){
		if(n / K == 0) str+= '0';
		else str+= ('0' + n / K);
		n%=K; K/=10;
	}
	return str;
}

int main(){
	int n;
	string s;
	cin >> n >> s;

	while(n--){
		string nt;

		s += '@';
		char t = s[0];
		int cnt = 0;
		rep(i,s.size()){
			if(s[i] == t){
				cnt++;
			}else{
				nt += toStr(cnt);
				nt += t;
				cnt = 1;
				t = s[i];
			}
		}
		s = nt;
	}
	cout << s << endl;

}
