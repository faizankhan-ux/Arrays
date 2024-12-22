#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> brute(vector<int> &a,vector<int> &b){
 int n=a.size();
 int m=b.size();
 int i=0,j=0;
 vector<int> c(m+n);
 int index=0;
 while(i<n && j<m){
     if(a[i]<=b[j]){
          c[index] = a[i];
          i++;
          index++;
     }else{
          c[index]=b[j];
          j++;
          index++;
     }
 } 
 while(i<n){
     c[index]=a[i];
     i++;
     index++;
 }
 while(j<m){
     c[index]=b[j];
     index++;
     j++;
 }
 for(int i=0;i<n+m;i++){
     if(i<n){
          a[i]=c[i];
     }else{
          b[i-n]=c[i];
     }
 }
}


void optimal1(vector<int> &a,vector<int> &b){
     int n=a.size();
     int m=b.size();
     int i=n-1;
     int j=0;
     while(j<m && i>=0){
          if(a[i]>=b[j]){
               swap(a[i],b[j]);
               i--;
               j++;
          }else{
               i--;j++;
          }
     }
     sort(a.begin(),a.end());
     sort(b.begin(),b.end());  
}


int main(){
  vector<int> a={1,2,7,4};
  vector<int> b={3,4,5,5,6};
  optimal1(a,b);
  for(auto it:a){
     cout<<it<<" ";
  }cout<<'\n';
  for(auto t:b){
     cout<<t<<" ";
  }
     return 0;
}





