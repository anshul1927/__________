/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    void solve(Node* root, vector<int>& ans){
        if(root==nullptr){
            return;
        }
        ans.push_back(root->val);
        
        for(auto it: root->children){
            solve(it, ans);
        }
    }
    
    float ans = 0;
    float node = 0;
    pair<int,float> solveavg(Node* root){
        pair<int,float> p;
        if(root==NULL) return p;
        
        if(root->children.size()==0){
            return {1,root->val};
        }
        int count = 0;
        float sum = 0;
        for(auto it: root->children){
            p = solveavg(it);
            
            count+=p.first;
            sum+=p.second;
        }
        
        sum += root->val;
        count+=1;
        cout<<sum<<" "<<count<<endl;
        float avg = sum*1.0/count;
        
        if(ans<avg){
            ans = avg;
            node = root->val;
        }
        
        return {count , sum};
        
    }
    
    vector<int> preorder(Node* root) {
        
        if(root==nullptr) return {};
        
        // vector<int> ans;
        // solve(root, ans);
        
        solveavg(root);
        
        cout<<ans<<" "<<node;
        return {};
        
    }
};
