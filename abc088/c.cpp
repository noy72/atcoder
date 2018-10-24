#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

bool equals(int a[3], int b[3], int c[3]){
	rep(i,3){
		if(not (a[i] == b[i] and b[i] == c[i])){
			return false;
		}
	}
	return true;
}

int main(){
	int a[3][3];
	rep(i,3){
		rep(j,3){
			cin >> a[i][j];
		}
	}

	int l1[3], l2[3], l3[3];
	rep(a1,101){
		rep(i,3) l1[i] = a[0][i] - a1;
		rep(a2,101){
			rep(i,3) l2[i] = a[1][i] - a2;
			rep(a3,101){
				rep(i,3) l3[i] = a[2][i] - a3;
				if(equals(l1, l2, l3)){
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}
	cout << "No" << endl;
}
