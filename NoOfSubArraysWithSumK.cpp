#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute(vector<int> arr,int t,int n){
     //generating all the subarrays and checking if there sum is equal to target
     //time complexity--> o(n^3)
     //space complexity -->o(1)
     int cnt=0;
     for(int i=0;i<n;i++ ){
          for(int j=i;j<n;j++){
               int sum=0;
               for(int k=i;k<j;k++){
                    sum=sum+arr[k];
                    if(sum==t){
                         cnt+=1;
                    }
               }
          }
     }
     return cnt;
}

int better(vector<int> arr,int t,int n){
      //generating all the subarrays and checking if there sum is equal to target but using previous 
      //sum
     //time complexity--> o(n^2)
     //space complexity -->o(1)
     int cnt=0;
     for(int i=0;i<n;i++ ){
          int sum=0;
          for(int j=i;j<n;j++){
                 sum=sum+arr[j];
               if(sum==t){
                   cnt+=1;
               }
               
          }
     }
     return cnt;
}

int optimal(vector<int> arr,int t,int n){
  //hashing using a map ,storing the sum and how many time it is occured map[sum]=frequency
  //checking if remaining =sum - target is present in a map

     unordered_map<int,int> mp{0};
     mp[0]=1;
     int cnt=0; int sum=0;
     for(int i=0;i<n;i++){
         sum=sum+arr[i];
          int rem=sum-t;
          if(mp.find(rem)!=mp.end()){
               cnt+=1;
               mp[sum]+=1;
          }else{
          mp[sum]=i;
       }
     }
     return cnt;
}


int main(){

     vector<int> arr={2,1,1,1,1};
   cout<< optimal(arr,2,7);
     return 0;
}
