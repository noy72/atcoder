#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

template<typename T>
ostream& operator << (ostream& os, vector<T>& v){
	rep(i,v.size()){ os << v[i] << (i == v.size() - 1 ? "" : " "); } return os;
}
template<typename T>
istream& operator >> (istream& is, vector<T>& v){
	for(T& x: v){ is >> x; } return is;
}

class UnionFind{
private:
	vector<int> par, depth;
public:
	UnionFind() {}
	UnionFind(int n){
		init(n);
	}
	void init(int n){
		par = vector<int>(n);
		depth = vector<int>(n);
		rep(i,n){
			par[i] = i;
			depth[i] = 0;
		}
	}
	int find(int x){
		if(par[x] == x){
			return x;
		}else {
			return par[x] = find(par[x]);
		}
	}
	void unite(int x, int y){
		x = find(x);
		y = find(y);
		if(x == y) return;

		if(depth[x] < depth[y]){
			par[x] = y;
		}else{
			par[y] = x;
			if(depth[x] == depth[y]) depth[x]++;
		}
	}
	bool same(int x, int y){
		return find(x) == find(y);
	}
};

int main(){
	int n, q;
	cin >> n >> q;

	UnionFind uni(n * 2);
	rep(i,q){
		int com, x, y, z;
		cin >> com >> x >> y >> z;
		x--; y--;
		if(com == 1){
			if(z % 2){
				uni.unite(x, y + n);
				uni.unite(x + n, y);
			}else{
				uni.unite(x,y);
				uni.unite(x + n, y + n);
			}
		}else{
			if(uni.same(x, y)){
				assert(uni.same(x + n, y + n));
				cout << "YES" << endl;
			}else{
				cout << "NO" << endl;
			}
		}
	}
}
