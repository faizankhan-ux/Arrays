#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void brute(vector<int> arr,int t){
  int n=arr.size();
  int f;
  int l;
  int sum2=0;
  string str="not exist";
  for(int i=0;i<n;i++){
     int sum=0;
     for(int j=i;j<n;j++){
          
       sum=arr[i]+arr[j];
          if(sum==t){
               
       f=arr[i];
       l=arr[j];
       str="yes exist";
          }
     }
  }cout<<str;
  
}

void BETTER(vector<int> arr,int t){
     map<int,int> mp;
     int n=arr.size();
     string str="not exist";
    
     for(int i=0;i<n;i++){
          mp[arr[i]]=i;
          int more=t-arr[i];
          if(mp.find(more)!=mp.end()){
               if(more+arr[i]==t && more!=arr[i]){
               str="yes exist";}
          }
     }
     cout<<str;
}
int findPivet(vector<int> &arr,int s,int n){
 int pivet=arr[s];
 int left=s;
 int right=n;
 while(left< right){
     while(arr[left]<=pivet && left<=n-1){
          left++;
     }
     while(pivet<arr[right] && right>=s+1){
          right--;
     }
     if(left<right){
          swap(arr[left],arr[right]);
     }
 } 
 swap(arr[s],arr[right]);
 return right;


}

void Quicksort(vector<int> &arr,int s,int n){
     if(s<n){
    
     int pivet=findPivet(arr,s,n);
     Quicksort(arr,s,pivet-1);
     Quicksort(arr,pivet+1,n);
    
  
 }
  
}

void slightlyOptimal(vector<int> arr,int t){
      int n=arr.size();
      string str="not exist";
      Quicksort(arr,0,n);
      int i=0;;
      int j=n-1;
     while(i<j){
          if(arr[i]+arr[j]>t){
               j--;
          }
          if(arr[i]+arr[j]<t){
               i++;
          }
          if(arr[i]+arr[j]==t){
               str = "yes exixst";
          }
     }cout<<str;
}

int main(){
 vector<int> arr={4,5,2,1,6,3};
 //brute(arr,11);
 //BETTER(arr,11);
 int n=arr.size();
 slightlyOptimal(arr,11);
 //Quicksort(arr,0,n-1);
//  for(auto it:arr){
//      cout<<it<<" "<<'\n';
//   }
 
}
