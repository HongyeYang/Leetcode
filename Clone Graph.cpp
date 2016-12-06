class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node)return node;
        UndirectedGraphNode * root=new UndirectedGraphNode(node->label);
        unordered_map<UndirectedGraphNode *,UndirectedGraphNode*>roc;
        queue<UndirectedGraphNode*>q;
        q.push(node);
        roc[node]=root;
        while(!q.empty()){
            UndirectedGraphNode * cur=q.front();
            UndirectedGraphNode * tep=roc[cur];
            q.pop();
            for(auto c:cur->neighbors){
                if(roc.find(c)!=roc.end()){
                    tep->neighbors.push_back(roc[c]);
                    continue;
                }
                else{
                    UndirectedGraphNode* kk=new UndirectedGraphNode(c->label);
                    roc[c]=kk;
                    tep->neighbors.push_back(kk);
                    q.push(c);
                }
            }
            
        }
        return root;
    }
};
