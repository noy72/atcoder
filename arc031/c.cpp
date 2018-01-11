#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

#define int long long

const int MAX_N = 110005;

class segTree{
	public:
		int n, dat[4 * MAX_N];
		virtual int query(int, int, int, int, int) = 0;
		void init(int n_){}
		void init(int a[MAX_N], int n_){
			n = 1;
			while(n <= n_) n *= 2;
			for(int i = n; i < n * n; i++){
				dat[i] = a[i - n];
			}
			for(int i = n - 1; i >= 1; i--){
				dat[i] = min(dat[i * 2], dat[i * 2 + 1]);
			}
		}
};

class rangeAddQuery : public segTree{
	private:
		int dat_add[4 * MAX_N];
		int query(int a, int b, int k, int l, int r){
			if(b <= l || r <= a) return 0;
			else if(a <= l && r <= b) return dat[k] * (r - l) + dat_add[k];
			else{
				int res = (min(b, r) - max(a, l)) * dat[k];
				res += query(a, b, k * 2, l, (l + r) / 2);
				res += query(a, b, k * 2 + 1, (l + r) / 2, r);
				return res;
			}
		}
		void add(int a, int b, int k, int l, int r, int x){
			if(a <= l && r <= b){
				dat[k] += x;
			}else if(l < b && a < r){
				dat_add[k] += (min(b, r) - max(a, l)) * x;
				add(a, b, k * 2, l, (l + r) / 2, x);
				add(a, b, k * 2 + 1, (l + r) / 2, r, x);
			}
		}
	public:
		void init(int n_){
			n = 1;
			while(n <= n_) n *= 2;
			rep(i,2 * n) dat[i] = dat_add[i] = 0;
		}

		void update(int i, int x){
			add(i, i + 1, 1, 0, n, x);
		}
		int query(int a, int b){
			return query(a,b,1,0,n);
		}
		void add(int s, int t, int x){
			add(s, t, 1, 0, n, x);
		}
		int get(int a){ return query(a, a + 1); }
};

class rangeSumQuery : public segTree{
	private:
		int query(int a, int b, int k, int l, int r){
			if(r <= a || b <= l) return 0;

			if(a <= l && r <= b) return dat[k];
			else{
				int vl = query(a, b, k * 2, l, ( l + r) / 2);
				int vr = query(a, b, k * 2 + 1, (l + r) / 2, r);
				return vl + vr;
			}
		}
	public:
		void init(int n_){
			n = 1;
			while(n <= n_) n *= 2;
			rep(i,2 * n) dat[i] = 0;
		}
		void update(int i, int x){
			i += n;
			dat[i] += x;
			while(i > 0){
				dat[i / 2] = dat[i] + dat[i^1];
				i = i / 2;
			}
		}
		int query(int a, int b){
			return query(a,b,1,0,n);
		}
};

class rangeMinimumQuery : public segTree{
	private:
		int query(int a, int b, int k, int l, int r){
			if(r <= a || b <= l) return INT_MAX;

			if(a <= l && r <= b) return dat[k];
			else{
				int vl = query(a, b, k * 2, l, ( l + r) / 2);
				int vr = query(a, b, k * 2 + 1, (l + r) / 2, r);
				return min(vl, vr);
			}
		}
	public:
		void init(int _n){
			n = 1;
			while(n < _n) n *= 2;
			rep(i,2 * n) dat[i] = INT_MAX;
		}
		void update(int i, int x){
			i += n;
			dat[i] = x;
			while(i > 0){
				dat[i / 2] = min(dat[i], dat[i^1]);
				i = i / 2;
			}
		}
		int query(int a, int b){
			return query(a,b,1,0,n);
		}
};

class rangeUpdateQuery : public segTree{
	private:
		int dat_lazy[4 * MAX_N];
		int query(int a, int b, int k, int l, int r){
			evaluate(k);

			if(b <= l || r <= a) return INT_MAX;
			else if(a <= l && r <= b) return dat[k];
			else{
				int vl = query(a, b, k * 2, l, (l + r) / 2);
				int vr = query(a, b, k * 2 + 1, (l + r) / 2, r);
				return min(vl, vr);
			}
		}
		inline void evaluate(int k){
			if(dat_lazy[k] == INT_MAX) return;
			dat[k] = dat_lazy[k];
			if(k < n){
				dat_lazy[2 * k] = dat_lazy[k];
				dat_lazy[2 * k + 1] = dat_lazy[k];
			}
			dat_lazy[k] = INT_MAX;
		}
		void update(int a, int b, int k, int l, int r, int x){
			evaluate(k);

			if(r <= a || b <= l) return;

			if(a <= l && r <= b){
				dat_lazy[k] = x;
			}else if(l < b && a < r){
				evaluate(k);
				update(a, b, k * 2, l, (l + r) / 2, x);
				update(a, b, k * 2 + 1, (l + r) / 2, r, x);
			}
		}
	public:
		void init(int n_){
			n = 1;
			while(n <= n_) n *= 2;
			rep(i,2 * n){
				dat[i] = dat_lazy[i] = INT_MAX;
			}
		}

		int query(int a, int b){
			return query(a,b,1,0,n);
		}
		void update(int s, int t, int x){
			update(s, t, 1, 0, n, x);
		}
		int get(int a){ return query(a, a + 1); };
		void print(){
			show("dat")
				rep(i,n * 2){ cout << (dat[i + 1] == INT_MAX ? 0 : dat[i + 1]) << ' '; }
			cout << endl;
			show("lazy")
				rep(i,n * 2){ cout << (dat_lazy[i + 1] == INT_MAX ? 0 : dat_lazy[i + 1]) << ' '; }
			cout << endl;
			cout << endl;
		}
};

signed main(){
	int n;
	while(cin >> n){

		vector<int> v(n);
		vector<pair<int, int>> p(n);
		rep(i,n){
			cin >> v[i];
			p[i] = make_pair(v[i],i);
		}
		sort(all(p));

		rangeAddQuery seg;
		seg.init(n);
		rep(i,n){ seg.update(i + 1,i); }
		//rep(i,n){ show(seg.get(i + 1)) }

		int left = 0, right = n - 1;
		int cnt = 0;
		rep(i,n){
			int cur = seg.get(p[i].second + 1);
			//cout << left << ' ' << right << endl;
			//show(cur)
			if(cur - left <= right - cur){
				cnt+=cur - left;
				left++;
				seg.add(1,p[i].second + 1,1);
			}else{
				cnt+=right - cur;
				right--;
				seg.add(p[i].second + 1,n + 1,-1);
			}
			//show(cnt)
			//rep(i,n){ cout << seg.get(i + 1) << ' '; }
			//cout << endl;
		}
		cout << cnt << endl;
	}
}
