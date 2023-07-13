#include<iostream>
#define n 5
using namespace std;

void sortArray(float arr1[], float arr2[], bool ascending){
	for(int i=1;i<n;i++){
		for(int j=0;j<n-i;j++){
			if(ascending){
				if(arr1[j]>arr1[j+1]){
					swap(arr1[j], arr1[j+1]);
					swap(arr2[j], arr2[j+1]);
				}
			}
			else{
				if(arr1[j]<arr1[j+1]){
					swap(arr1[j], arr1[j+1]);
					swap(arr2[j], arr2[j+1]);
				}
			}
		}
	}
}

float calculateProfit(float profit[], float weight[], float capacity){
	float x[n]{0};
	int w=0;
	for(int i=0;i<n;i++){
		if(w+weight[i]<=capacity){
			x[i]=1;
			w+=weight[i];
		}
		else{
			x[i]=(capacity-w)/weight[i];
			break;
		}
	}
	float ans = 0;
	for(int i=0;i<n;i++){
		ans+= x[i]*profit[i];
	}
	return ans;
}

int main(){
	float profit[n]{0}, weight[n]{0}, capacity=12;
	
	for(int i=0;i<n;i++){
		cout<<"Enter the Profit weight (separated by space): ";
		cin>>profit[i]>>weight[i];
	}
	
	sortArray(profit, weight, false);
	
	float ans = calculateProfit(profit, weight, capacity);
	
	cout<<"Total Profit is = "<<ans;
	return 0;
}
