

#include<bits/stdc++.h>
using namespace std;


int solve(vector<int> boxes, vector<int> unitsPerBox, int truckSize){
    priority_queue<pair<int,int>> pq;
    
    for(int i=0; i<boxes.size();i++){
        pq.push({unitsPerBox[i], boxes[i]});
    }
    
    int ans = 0;
    while(!pq.empty()){
        
        auto temp = pq.top();
        pq.pop();
        int units = temp.first;
        int box = temp.second;
        
        if(box<=truckSize){
            ans += (box*units);
            truckSize -= box;
        }else{
            ans += (units*truckSize);
            break;
        }
    }
    return ans;
}


int main(){
    int num;
    cin>>num;
    
    vector<int> boxes(num);
    for(int i=0; i<num; i++){
        cin>>boxes[i];
    }
    
    int unitSize;
    cin>>unitSize;
    
    vector<int> unitsPerBox(num);
    for(int i=0; i<num; i++){
        cin>>unitsPerBox[i];
    }
    
    int truckSize;
    cin>>truckSize;
    
    cout<<solve(boxes, unitsPerBox, truckSize);
    
    return 0;
}  
