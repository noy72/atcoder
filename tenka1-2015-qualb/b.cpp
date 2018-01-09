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

	if(s == "{}"){
		cout << "dict" << endl;
		return 0;
	}

	int cnt = 0;
	for(auto i : s){
		if(i == '{') cnt++;
		else if(i == '}') cnt--;
		if(cnt == 1){
			if(i == ':'){
				cout << "dict" << endl;
				return 0;
			}else if(i == ','){
				cout << "set" << endl;
				return 0;
			}
		}
	}
	cout << "set" << endl;
}
