// T.C. ==> O(1) constant 
// S.C ==> O(V)

#include<bits/stdc++.h>
using namespace std;
//rankOfVertices denotes the depth of the tree created after the union

vector<int> parent(10000,0);
vector<int> rankOfVertices(10000,0);

void makeSet(int n){
    for(int i=1;i<=n ;i++){
        parent[i]=i;
    }
}
// T.C. ==>O(4*ALPHA)  constant
//7 -> 5 -> 2 -> 6      
int findParent(int node){
    if(parent[node]==node){
        return node;
    }
    else{
        return parent[node]= findParent(parent[node]);   //path Compression
    }
}

void unionOfVertices(int u, int v){
    u=findParent(u);
    v=findParent(v);
    if(rankOfVertices[u]<rankOfVertices[v]){
        parent[u]=v;
    }
    else if(rankOfVertices[u]>rankOfVertices[v]){
        parent[v]=u;
    }     
    else{         //agar rankOfVertices equal h
        parent[v]=u;
        rankOfVertices[u]++;
    }
}

int main(){
    int vertices;
    cin>>vertices;
    makeSet(vertices);
    int m;   //total no of union operations
    cin>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        unionOfVertices(u,v);
    }
    //IF 2 AND 3 Belong to the same component or not
    if(findParent(2)==findParent(3)){
        cout<<"Same Component";
    }
    else{
        cout<<"Different Component";
    }
    return 0;
}