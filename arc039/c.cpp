#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;


template <typename T> class DancingLinks{
    public:
        class Node{
            public:
                T value;
                class Node *left, *right, *up, *down;
        };
        map<T, Node> m;
        void set(T a){
            m[a] = {make_pair(0,0),NULL,NULL,NULL,NULL};
        }

        void horizonalReconnect(T center){
            T right = make_pair(center.first + 1, center.second);
            T left = make_pair(center.first - 1, center.second);
            if(m.count(right) && m.count(left)){
                linkRight(left,right);
            }
        }
        void verticalReconnect(T center){
            T up = make_pair(center.first, center.second + 1);
            T down = make_pair(center.first, center.second - 1);
            if(m.count(up) && m.count(down)){
                linkDown(up,down);
            }
        }
        void linkLeft(T center, T a){
            auto it = m[center];
            auto cur_it = m[a];
            it.left = &cur_it;
            cur_it.right = &it;
        }
        void linkRight(T center, T a){
            linkLeft(a, center);
        }
        void linkUp(T center, T a){
            auto it = m[center];
            auto cur_it = m[a];
            it.up = &cur_it;
            cur_it.down = &it;
        }
        void linkDown(T center, T a){
            linkUp(a,center);
        }
        T getNodeValue(Node *a){
            return m[a->value].value;
        }
};

int main(){
    int k;
    string str;
    cin >> k >> str;

    DancingLinks<pair<int, int>> dl;
    pair<int, int> cur = make_pair(0,0);
    dl.set(cur);
    rep(i,k){
        pair<int, int> nt;
        switch (str[i]) {
            case 'L':
                nt = (*(dl.m[make_pair(cur.first - 1, cur.second)].left)).value;
                break;
            case 'R':
                nt = (*(dl.m[make_pair(cur.first + 1, cur.second)].left)).value;
                break;
            case 'U':
                nt = (*(dl.m[make_pair(cur.first, cur.second - 1)].left)).value;
                break;
            case 'D':
                nt = (*(dl.m[make_pair(cur.first, cur.second + 1)].left)).value;
                break;
        }

        /*
        if(dl.m.count(make_pair(nt.first - 1, nt.second))){
            dl.linkLeft(nt, make_pair(nt.first - 1, nt.second));
        }
        if(dl.m.count(make_pair(nt.first, nt.second))){
            dl.linkRight(nt, make_pair(nt.first + 1, nt.second));
        }
        if(dl.m.count(make_pair(nt.first, nt.second + 1))){
            dl.linkUp(nt, make_pair(nt.first, nt.second + 1));
        }
        if(dl.m.count(make_pair(nt.first, nt.second - 1))){
            dl.linkDown(nt, make_pair(nt.first, nt.second - 1));
        }
        dl.horizonalReconnect(nt);
        dl.verticalReconnect(nt);
        */
    }
}
