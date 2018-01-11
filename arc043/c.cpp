#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

const int MAX_N = 100005;

//[1, n]
int bit[MAX_N + 1] = {0};

int sum(int i){
    int s = 0;
    while(i > 0){
        s += bit[i];
        i -= i & -i;
    }
    return s;
}

void add(int i, int x){
    while(i <= MAX_N){
        bit[i] += x;
        //bit[i] = max(bit[i], x);
        i += i & - i;
    }
}

int main(){
    int n;
    cin >> n;

    map<int,int> B; //A,B:value, pos
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    rep(i,n){
        int x;
        cin >> x;
        B[x] = i + 1;
    }

    long long ans = 0;
    rep(i,n){
        ans += (i - sum(B[a[i]]));
        add(B[a[i]], 1);
    }
    if(ans % 2){
        cout << -1 << endl;
        return 0;
    }

    memset(bit, 0, sizeof(bit));
    ans /= 2;
    vector<int> table(n,0);
    rep(i,n){
        table[i] = sum(B[a[i]]);
        add(n + 1 - B[a[i]], 1);
        show(table[i])
    }

    vector<int> num ;
    rep(i,n){
        if(ans >= table[i]){
            ans -= table[i];
            num.emplace_back(B[a[i]]);
        }else{
            if(ans == 0) goto END;
            show("JI")
            rep(j,num.size()){
                show(num[j])
            }
            range(j,i,n){
                num.emplace_back(B[a[j]]);
            }
            rep(j,1e8){
                range(k,i + j,n - 1){
                    if(B[a[k]] > B[a[k + 1]]){
                        ans--;
                        swap(B[a[k]], B[a[k + 1]]);
                    }
                    if(ans == 0) goto END;
                }
            }
        }
    }
END:
    rep(i,n){
        cout << num[i] << (i == n - 1 ? '\n' : ' ');
    }
}
