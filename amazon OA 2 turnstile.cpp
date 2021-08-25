
#include<bits/stdc++.h>
using namespace std;



vector<int> solve(vector<int> arrTime, vector<int> dir){
    
    queue<pair<int,int>> en, ex;
    for(int i=0; i<arrTime.size(); i++){
        if(dir[i]==1){
            ex.push({arrTime[i], i});
        }else{
            en.push({arrTime[i], i});
        }
    }
    
    int tc = 0;
    int lastTurn = -1;
    
    vector<int> res(arrTime.size());
    while(!en.empty() or !ex.empty()){
        
        if(ex.size()>0 and ex.front().first<=tc   and ( (lastTurn == -1) or (lastTurn == 1) or en.size()==0 or (lastTurn ==0 and en.front().first>tc))){
            res[ex.front().second] = tc;
            lastTurn = 1;
            ex.pop();
        }
        else if(en.size()>0 and en.front().first<=tc){
            res[en.front().second] = tc;
            lastTurn = 0;
            en.pop();
        }else{
            lastTurn = -1;
        }
        tc++;
    }
    return res;
}





int main() {
    
    int n;
    cin>>n;
    vector<int> arrTime(n);
    vector<int> dir(n);
    for(int i=0; i<n; i++){
        cin>>arrTime[i];
    }
    for(int i=0; i<n; i++){
        cin>>dir[i];
    }
    
    vector<int> ans = solve(arrTime, dir);
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}
