#include<iostream>
#define n 6
using namespace std;

int stack[10], queue[10], visited[n], a[n][n];
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
//	int e;
//	while(top!=-1){
//		int f=0;
//		e=stack[top];
//		for(int i=0; i<n; i++){
//			if(a[e][i]==1 && !visited[i]){
//				dfs(i);
//				f=1;
//			}	
//		}
//		if(f==0){
//			top--;
//		}
//	}
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
	cout<<"DFS Graph Traversal: "<<endl;
	cout<<v<<" ";
	dfs(v);
}

/*
0 1 1 0 0 0
1 0 1 0 0 0
1 1 0 1 1 0 
0 0 1 0 0 1
0 0 1 0 0 1
0 0 0 1 1 0
*/
