#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	int n;
	string s;
	cin >> n >> s;

	string patern[] = {"SS", "SW", "WS" , "WW"};
	for(auto p : patern){
		string a = p;
		range(i,2,n){
			char hint = s[i - 1];
			if(a[i - 1] == 'W') hint = hint == 'o' ? 'x' : 'o';

			if(hint == 'o'){
				a += a[i - 2];
			}else{
				a += a[i - 2] == 'W' ? "S" : "W";
			}
		}

		string c = a.back() + a + a;
		bool f = true;
		rep(i,n){
			char hint = s[i];
			if(a[i] == 'W') hint = hint == 'o' ? 'x' : 'o';

			if(hint == 'o' and c[i] != c[i + 2]) f = false;
			if(hint == 'x' and c[i] == c[i + 2]) f = false;
		}
		if(f){
			cout << a << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}
