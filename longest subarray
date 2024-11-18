#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void BruteMethod(vector<int> &arr,int t){
  int n=arr.size();
  //let length of subarray
  int length=0;

  for(int i=0;i<n;i++){
    //we will be summing all subarrays
    int sum=0;
    for(int j=i;j<n;j++){
      sum=sum+arr[j];

      // check if sum of subarray is equal to target
      if(sum==t){
        length=max(length,j-i+1);
      }
    }

  }
  cout<<"its "<<length<<"(brute)";

}
  

  int Bettersolution(vector<int> arr,int t){
   int n=arr.size();
   int maxlength=0;
   int sum=0;
   map<long long,int> psm;
   for(int i=0;i<n;i++){
    sum+=arr[i];
    int length=0;
    if(sum==t){
      length=i+1;
      maxlength=max(maxlength,length);
      }
      int rem=sum-t;

      if(psm.find(rem)!=psm.end()){
        maxlength=max(maxlength,i-psm[rem]);
      }

      if(psm.find(sum)==psm.end()){
        psm[sum]=i;
      }


   }




   return maxlength;
  }

  void Optimal(vector<int> arr,int t){
    int n=arr.size();
    int left=0;int right=0;
    long long sum=arr[0];
    int maxlen=0;
    while(right<n){
      while(left<=right && sum>t){
        sum-=arr[left];
        left++;
      }
      if(sum==t){
        maxlen=max(maxlen,right-left+1);
      }

      right++;
      if(right<n){sum+=arr[right];
    }
    
    }
  cout<<"it is "<< maxlen<<"(OPtimal)";
  
    }




int main(){
  vector<int> arr={-1,-1,-3,-4,5,6,7,0,1,1,1,0,0,0};
  cout<<'\n';
  BruteMethod(arr,-9);cout<<'\n';
  cout<<"it is "<<Bettersolution(arr,-9)<<"(Better)"<<endl;
 Optimal(arr,-9);
  cout<<'\n';

 


}
