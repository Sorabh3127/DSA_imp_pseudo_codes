    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }


    void Union(int x, int y){
        int x_parent=find(parent[x]);
        int y_parent=find(parent[y]);

        if(x_parent==y_parent){
            return;
        }
        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }
        else if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;
        }
        else{
            parent[x_parent]=y_parent;
            rank[y_parent]+=1;
        }
    }


    int main(){
        parent.resize(n);
        rank.resize(n);

         // each element ko parent de de rah as initially all parents are there own elements
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
    }