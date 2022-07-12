// https://www.codingninjas.com/codestudio/problems/1082553?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

// DISJOINT SET IS THE PRE REQUISITE FOR THE KRUSKAL'S ALGORITHM.

// Time Complexity: O(ElogE)+O(E*4*alpha), ElogE for sorting and E*4*alpha for findParent operation ‘E’ times
// Space Complexity: O(N). Parent array+Rank Array

#include<bits/stdc++.h>
using namespace std;

vector<int> par;
vector<int> rankk;
int findPar(int u){
    if(u == par[u]){
        return u;
    }
    return par[u] = findPar(par[u]);
}
    
int union_(int u, int v){
    if(rankk[u]<rankk[v]){
        par[u] = v;
    }else if(rankk[v]<rankk[u]){
        par[v] = u;
    }else{
        par[v] = u;
        rankk[u]++;
    }
}
    
bool comp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
    // Write your code here.
    sort(graph.begin(),graph.end(),comp);  //sorted by weights
    int cost = 0;
    par.resize(n+1);
    rankk.resize(n+1,0);
    for(int i=1;i<par.size();++i) par[i] = i;
    
    for(auto i:graph){
        if(findPar(i[0])!=findPar(i[1])){  //same component ka part nhi h
            cost+=i[2];
            union_(findPar(i[0]),findPar(i[1]));
        }
    }
    
    return cost;
    
}