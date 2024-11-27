#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void brute(vector<int> &arr,int n){
//generate all posible permutations
//find next permutation 
}

void optimal(vector<int > &arr,int n){

     //find the pivet  -->a=[1 2 3 6 5 4]  = 3(pivet)
     int pivet=-1;
     for(int i=n-2;i>=0;i--){
          if(arr[i]<arr[i+1]){
               pivet=i;
               break;
          }
     }
     //find the right most bigg elemnt than pivet  -->a=[1 2 4 6 5 3]  =4(big elemnt)
     for(int i=n-1;i>pivet;i--){
          if(arr[i]>arr[pivet]){
               swap(arr[i],arr[pivet]);
               break;
          }
     }

     //final answer  --> a=[ 1 2 4 3 5 6]
     reverse(arr.begin()+pivet+1,arr.end());
     

}


int main(){
 vector<int> arr={1,2,3,6,5,4};
 int n=arr.size();

 optimal(arr,n);
 for(auto it :arr){
     cout<<it<<" ";
 }
     return 0;
}
