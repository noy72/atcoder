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
	reverse(all(s));

	vector<int> v = {-1, 0, 1, 2};
	for(auto& i : v){
		for(auto j : s){
			if(j == '-'){
				i*=-1;
			}else{
				if(i == 0) i = 1;
				else i = 0;
			}
		}
	}

	vector<int> a[6];
	a[0] = {-1,0,1,2};
	a[1] = {0,-1,0,0};
	a[2] = {1,0,1,1};
	a[3] = {0,1,0,0};
	a[4] = {-1,0,-1,-1};
	a[5] = {1,0,-1,-2};

	if(v == a[0]){
		cout << endl;
	}else if(v == a[1]){
		cout << "-!" << endl;
	}else if(v == a[2]){
		cout << "!!" << endl;
	}else if(v == a[3]){
		cout << "!" << endl;
	}else if(v == a[4]){
		cout << "-!!" << endl;
	}else if(v == a[5]){
		cout << "-" << endl;
	}
}
