#include<iostream>
#define n 6
using namespace std;

int a[n][n], visited[n], queue[10], stack[10];
int top=-1, front=-1, rear=-1;

void dfs(int v){
	visited[v]=1;
	stack[++top]=v;
	for(int i=0;i<n;i++){
		if(a[v][i]==1 && !visited[i]){
			cout<<i<<" ";
			dfs(i);
		}
	}
}

void bfs(int v){
	visited[v]=1;
	cout<<v<<" ";
	for(int i=0;i<n;i++){
		if(a[v][i]==1 && !visited[i]){
			queue[++rear]=i;
			visited[i]=1;
		}
	}
	if(front<rear){
		bfs(queue[++front]);
	}
}

int main(){
	int v;
	cout<<"Enter the matrix: "<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	visited[1]=0;
	cout<<"Enter the starting vertex: "<<endl;
	cin>>v;
	
	cout<<"DFS Traversal: "<<endl;
	cout<<v<<" ";
	dfs(v);
	
	for(int i=0;i<n;i++){
		visited[i]=0;
	}
	cout<<"\nBFS Traversal: "<<endl;
	queue[++rear]=v;
	bfs(queue[++front]);
}

/*
0 1 1 0 0 0
1 0 1 0 0 0
1 1 0 1 1 0 
0 0 1 0 0 1
0 0 1 0 0 1
0 0 0 1 1 0
*/
