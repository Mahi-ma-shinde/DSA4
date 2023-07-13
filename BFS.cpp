#include<iostream>
#define n 6
using namespace std;

int a[n][n], stack[10], queue[10], visited[n];
int top=-1, front=-1, rear=-1;

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
//	for(int i=0;i<n;i++){
//		visited[i]=0;
//	}
	
	cout<<"Enter the starting vertex: ";
	cin>>v;
	cout<<"BFS Graph is: "<<endl;
	queue[++rear]=v;
	bfs(queue[++front]);
}
