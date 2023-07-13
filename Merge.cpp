#include<iostream>
using namespace std;

void merge(int a[], int b, int mid, int e){
	int i, j, k;
	int n1=mid-b+1;
	int n2=e-mid;
	int left[n1], right[n2];
	for(i=0;i<n1;i++){
		left[i]=a[b+i];
	}
	for(j=0;j<n2;j++){
		right[j]=a[mid+1+j];
	}
	i=0;
	j=0;
	k=b;
	while(i<n1 && j<n2){
		if(left[i]<right[j]){
			a[k]=left[i];
			i++;
			k++;
		}
		else{
			a[k]=right[j];
			j++;
			k++;
		}
	}
	while(i<n1){
		a[k]=left[i];
			i++;
			k++;
	}
	while(j<n2){
		a[k]=right[j];
			j++;
			k++;
	}
}

void merge_sort(int a[], int b, int e){
	int mid;
	if(b<e){
		mid=(b+e)/2;
		merge_sort(a,b,mid);
		merge_sort(a,mid+1,e);
		merge(a,b,mid,e);
	}
}

 int main(){
	int n,b,e;
	b=0;
	cout<<"Enter the size of array: ";
	cin>>n;
	int a[n];
	e=n-1;
	
	cout<<"Enter the array elements: ";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	merge_sort(a,b,e);
	
	cout<<"Sorted Array: ";
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
 }
