#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute(vector<int> arr,int k){
     int n=arr.size();
     int cnt=0;
     for(int i=0;i<n;i++){
          for(int j=i;j<n;j++){
               int xr=0;
               for(int k=i;k<=j;k++){
                    xr=xr^arr[k];
                    
               }if(xr==k)cnt++;
          }
     }
     return cnt;
}

int better(vector<int> arr,int k){
 int n=arr.size();
 int cnt=0;
 for(int i=0;i<n;i++){
     int xr=0;
     for(int j=i;j<n;j++){
          xr=xr^arr[j];
          if(xr==k)cnt++;
     }
 }
 return cnt;
}

int Optimal(vector<int> arr,int k){
     int cnt=0;
     int xr=0;
     unordered_map<int,int> mp;
     mp[xr]++;
     for(int i=0;i<arr.size();i++){
          xr=xr^arr[i];
          int x=xr^k;
          cnt+=mp[x];
          mp[xr]++;

     }
     return cnt;
}

int main(){
 vector<int>arr={0,0,1};
 cout<<Optimal(arr,0);

     return 0;
}
