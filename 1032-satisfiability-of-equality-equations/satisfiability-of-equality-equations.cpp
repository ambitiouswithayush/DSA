class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }
    void unite(int x,int y){
        int parent_x=find(x);
        int parent_y=find(y);

        if(parent_x==parent_y) return;
        if(rank[parent_x]>rank[parent_y])
        parent[parent_y]=parent_x;
        else if(rank[parent_x]<rank[parent_y])
        parent[parent_x]=parent_y;
        else{
            parent[parent_x]=parent_y;
            rank[parent_y]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26,0);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        for(string &s:equations){
            if(s[1]=='='){//"a==b"
                unite(s[0]-'a',s[3]-'a');
            }
        }
        for(string &s:equations){
            if(s[1]=='!'){//"a!=b"
                char first=s[0];
                char second=s[3];
                int parent_first=find(first-'a');
                int parent_second=find(second-'a');

                if(parent_first==parent_second)
                return false;
            }
        }
        return true;
    }
};