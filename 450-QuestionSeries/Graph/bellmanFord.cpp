int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
      vector<int> distance(n+1,INT_MAX);
    
    distance[src]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int w=edges[j][2];
            if(distance[u]!=INT_MAX && distance[u]+w<distance[v]){
                distance[v]=distance[u]+w;
            }
            
        }
    }
    //CHECK FOR NEGATIVE WEIGHT CYCLE
    bool flag=false;
     for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int w=edges[j][2];
            if(distance[u]!=INT_MAX && distance[u]+w<distance[v]){
               flag=true;
            }
        }
     if(distance[dest]==INT_MAX){
        return 1000000000;
    }
   if(flag) cout<<"negative weight cycle";
   else return distance[dest];
    
}