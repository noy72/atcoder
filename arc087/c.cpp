#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

const int MAX = 26;
const char OFFSET = '0';

struct Node{
	int depth;
	int nxt[MAX+1];			// 次のalphabeteのノード番号
	int exist;				// 子ども以下に存在する文字列の数の合計
	vector<int> accept;		// その文字列id
	Node() : depth(-1), exist(0){memset(nxt, -1, sizeof(nxt));}
};

class Trie{
	private:
		void update_direct(int node,int id){
			nodes[node].accept.push_back(id);
		}
		void update_child(int node,int child,int id){
			++nodes[node].exist;
		}
		void add(const string &str,int str_index,int node_index,int id, int depth = -1){
			if(str_index == str.size())
				update_direct(node_index, id);
			else{
				const int c = str[str_index] - OFFSET;
				if(nodes[node_index].nxt[c] == -1) {
					nodes[node_index].nxt[c] = (int) nodes.size();
					nodes[node_index].depth = depth + 1;
					nodes.push_back(Node());
				}
				add(str, str_index + 1, nodes[node_index].nxt[c], id, depth + 1);
				update_child(node_index, nodes[node_index].nxt[c], id);
			}
		}

	public:
		vector<Node>nodes;
		int root;
		Trie() : root(0){nodes.push_back(Node());}
		void add(const string &str,int id){add(str, 0, 0, id);}
		void add(const string &str){add(str, nodes[0].exist);}
		int size(){return (nodes[0].exist);}
		int nodesize(){return ((int) nodes.size());}
};

class AhoCorasick : public Trie{
	public: 
		static const int FAIL = MAX;
		vector<int> correct;
		AhoCorasick() : Trie() {}

		void build(){
			correct.resize(nodes.size());
			rep(i,nodes.size())correct[i]=(int)nodes[i].accept.size();

			queue<int> que;
			rep(i,MAX+1){
				if(~nodes[0].nxt[i]) {
					nodes[nodes[0].nxt[i]].nxt[FAIL] = 0;
					que.emplace(nodes[0].nxt[i]);
				}else nodes[0].nxt[i] = 0;
			}
			while(!que.empty()) {
				Node now = nodes[que.front()];
				correct[que.front()] += correct[now.nxt[FAIL]];
				que.pop();
				rep(i,MAX){
					if(now.nxt[i] == -1) continue;
					int fail = now.nxt[FAIL];
					while(nodes[fail].nxt[i] == -1) {
						fail = nodes[fail].nxt[FAIL];
					}
					nodes[now.nxt[i]].nxt[FAIL] = nodes[fail].nxt[i];

					auto &u = nodes[now.nxt[i]].accept;
					auto &v = nodes[nodes[fail].nxt[i]].accept;
					vector<int> accept;
					set_union(all(u),all(v),back_inserter(accept));
					u=accept;
					que.emplace(now.nxt[i]);
				}
			}
		}
		int match(const string &str,vector<int> &result,int now=0){
			result.assign(size(),0);
			int count=0;
			for(auto &c:str) {
				while(nodes[now].nxt[c-OFFSET]==-1)now=nodes[now].nxt[FAIL];
				now = nodes[now].nxt[c-OFFSET];
				count += correct[now];
				for(auto &v:nodes[now].accept)result[v]++;
			}
			return count;
		}
		int next(int now,char c){
			while(nodes[now].nxt[c-OFFSET]==-1)now=nodes[now].nxt[FAIL];
			return nodes[now].nxt[c-OFFSET];
		}
};

long long l;
vector<long long> item;
void dfs(int cur, int depth, const Trie& trie){
	int a = trie.nodes[cur].nxt[0];
	int b = trie.nodes[cur].nxt[1];
	//show(cur)
	//cout << a << ' ' << b << endl;
	if(a != -1 && b != -1){
		dfs(a, depth + 1, trie);
		dfs(b, depth + 1, trie);
	}else if(a == -1 && b == -1) return;
	else if(a != -1){
		item.emplace_back(l - depth);
		dfs(a, depth + 1, trie);
	}else if(b != -1){
		item.emplace_back(l - depth);
		dfs(b, depth + 1, trie);
	}
}

bool getBit(int num, int i){
	return ((num & (1 << i)) != 0);
}

int main(){
	int n;
	cin >> n >> l;

	Trie trie;
	rep(i,n){
		string s;
		cin >> s;
		trie.add(s);
	}

	long long ans = 0;
	//dfs(trie.root, 0, trie);

	//for(auto i : trie.nodes){ cout << i.nxt[0] << ' ' << i.nxt[1] << endl; cout << i.depth << endl; }
	
	for(auto i : trie.nodes){
		//long long grundy = 0;
		if(i.nxt[0] != -1 ^ i.nxt[1] != -1){
			long long high = l - i.depth;
			//if(high == 0) continue;
			//for(; getBit(l - i.depth, grundy) == 0; grundy++);
			ans ^= high & -high;
		}
	}

	if(ans == 0) cout << "Bob" << endl;
	else cout << "Alice" << endl;
}
