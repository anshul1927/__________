#include<bits/stdc++.h>
using namespace std;




int solve(vector<int> segment, int k){
    
    deque<pair<int,int>> dq;
    int ans = INT_MIN;
    
    for(int i=0; i<segment.size(); i++){
        if(!dq.empty() and dq.front().second<=(i-k)){
            dq.pop_front();
        }
        
        while(!dq.empty() and dq.back().first>segment[i]){
            dq.pop_back();
        }
        dq.push_back({segment[i], i});
        if(i>=(k-1)){
            ans = max(ans, dq.front().first);
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> segment(n);
    for(int i=0; i<n; i++){
        cin>>segment[i];
    }
    
    int segment_length;
    cin>>segment_length;
    
    
    cout<<solve(segment, segment_length);
    return 0;
}
