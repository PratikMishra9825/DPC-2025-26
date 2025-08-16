#include<iostream>
#include<vector>
using namespace std;
void sort0s1s2s(vector<int>& arr, int n){
    int mid=0, low=0, high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid], arr[low]);
            mid++;
            low++
        }else if(arr[mid]==1){
            mid++;
        }else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr={2,0,1,2,0,1};
    sort0s1s2s(arr, n);
    printArray(arr, n);
    return 0;
}
