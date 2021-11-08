#include <iostream>
#include <vector>

using namespace std;

//定数
const int MAX_N = 1000;

//入力
int n;
vector<int>V[MAX_N];
int C[MAX_N];

bool dfs(int v, int c){
    C[v] = c;
    for (auto& i : V[v]){
        if (C[i] == c)return false;
        if (C[i] == 0 && !dfs(i, -c)) return false;
    }

    //すべての色をぬれたら
    return true;
}


int main(){
    cin >> n;
    for (int i=0;i<n;i++){
        int k;
        cin >> k;
        for (int j=0;j<k;j++){
            int x;
            cin >> x;
            V[i].push_back(x);
        }
    }

    if (dfs(0, 1)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}
