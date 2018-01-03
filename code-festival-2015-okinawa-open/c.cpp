#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	int n;
	cin >> n;

	int cnt = 0;
	rep(i,n){
		string s[3];
		if(i % 2){
			string p;
			rep(i,3){
				cin >> s[i];
				p += s[i].front();
			}
			if(p == "#.#") cnt++;
		}else{ //vertical
			rep(i,3) cin >> s[i];
			if(s[i] == "#.#") cnt++;
		}
	}
	cout << ((n * 2 - cnt) % 2 == 0 ? "Sothe" : "Snuke")  << endl;
}
