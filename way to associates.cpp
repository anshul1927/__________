
/*
An amazon area manager is trying to assemble a speclized team from a roster of available associates.
there is a minimum number of associates to be involved and each associates needs to have a skill rating within a certain range.
given a list of associates skill level with desired upper and lower bounds , determine how many teams can be created from the list.


write an algorithm to find the number of teams that can be created fullfilling the criteria.

*/







#include<bits/stdc++.h>
using namespace std;


int main(){
    
    int num;
    cin>>num;
    
    vector<int> skills(num);
    for(int i=0; i<num; i++){
        cin>>skills[i];
    }
    
    int minAssociates;
    cin>>minAssociates;
    
    int minLevel, maxLevel;
    cin>>minLevel>>maxLevel;
    int count = 0;
    for(auto it: skills){
        if(it>=minLevel and it<=maxLevel){
            count++;
        }
    }
    
    cout<<count<<endl;
    if(minAssociates==count) cout<<count<<endl;
    
    else{
        int ans = 0;
        for(int i=minAssociates ; i<=count; i++){
            if(i==count){
                ans++;
            }else{
                int t = i;
                int k = count;
                float temp = 1;
                for(int j=0; j<t; j++){
                    cout<<temp<<" "<<j<<" "<<k-j<<" "<<t-j<<endl;
                    temp *= (float)(k-j)/(float)(t-j);
                }
                ans += temp;
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
