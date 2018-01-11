#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int r, c, n;
map<int,char> up,rt,lt,dn;
char w = 'a';

bool C(int a, int b){
	if( (a == 0 || a == r) || (b == 0 || b == c) ) return true;
	return false;
}

bool isEdge(int a, int b, int c, int d){
	return C(a,b) && C(c,d);
}

void addVector(int a, int b){
	if(a == 0) up[b] = w;
	else if(b == c) rt[a] = w;
	else if(a == r) lt[-b] = w;
	else if(b == 0) dn[-a] = w;
}

int main(){
	cin >> r >> c >> n;

	rep(i,n){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if(isEdge(a,b,c,d)){
			addVector(a,b);
			addVector(c,d);
			w++;
		}
	}

	vector<char> al;
	for(auto i : up) al.emplace_back(i.second);
	for(auto i : rt) al.emplace_back(i.second);
	for(auto i : lt) al.emplace_back(i.second);
	for(auto i : dn) al.emplace_back(i.second);

	vector<char> ans;
	rep(i,al.size()){
		//show(al[i])
		if(ans.empty()) ans.emplace_back(al[i]);
		else{
			if(al[i] == ans.back()){
				ans.pop_back();
			}else{
				ans.emplace_back(al[i]);
			}
		}
	}
	if(ans.size() == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
}
