#include<iostream>
#include<vector>
using namespace std;
void Sort_0s_1s_2s(vector<int> &arr,int n){
     int left=0;
     int mid=0;
     int high=n-1;
     while(mid<=high){
          if(arr[mid]==0){
               swap(arr[mid],arr[left]);
               left++;
               mid++;
          }
          else if(arr[mid]==1){
               mid++;

          }
          else{
               swap(arr[mid],arr[high]);
               high--;
          }
     }
}


int main(){
 vector<int> arr={0,1,1,2,2,0,0,1,1,0,1,1,1,2,2,0};
 Sort_0s_1s_2s(arr,16);
 for(auto it:arr){
     cout<<it<<" ";
 }
}
