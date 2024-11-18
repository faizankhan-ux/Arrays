#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void largestelement(int arr[],int n){
    int max=arr[0];
    int index;
    for(int i=0;i<n;i++){
      if(arr[i]>max){
            max=arr[i];
            index=i;
      }
      
    }
     
  
 
 cout<<max<<" at index arr["<<index<<"]";
}

void secondlargest(int arr[],int n){
   // int max=arr[0];
   //  int index;
   //  for(int i=0;i<n;i++){
   //    if(arr[i]>max){
   //        index=i;
   //        max=arr[i]; }}

   //  //int seclarg=arr[0];
   //  int idx;
   // int seclarg=-1;
   //  for(int j=0;j<n;j++){
   //   if(arr[j]==max)break;
   //    if(arr[j]>seclarg  ){
         
   //       seclarg=arr[j];
   //       idx=j;
   //    }
   //  }


   //optimal approach
   int larg=arr[0],seclarg=INT16_MAX;
   for(int i=0;i<n;i++){
    if(arr[i]<larg){
      seclarg=larg;
      larg=arr[i];
    }
    else if(arr[i]>larg && arr[i]<seclarg){
      seclarg=arr[i];
    }
   }
    cout<<seclarg;
}

bool checksorted(int arr[],int n){
   // int ck=0;
   // for(int i=0;i<n-1;i++){
   //    if(arr[i]<arr[i+1]){
   //       ck;
   //    }else{
   //       ck++;
   //    }
   // }
   // if(ck==0){
   //    cout<<"array is sorted"<<'\n';
   // }else{
   //    cout<<"not sorted"<<'\n';
   // }

   //opyimal approach
   bool chk=true;
   for(int i=0;i<n-1;i++){
      
      if(arr[i]<arr[i+1]){

      }else{
         chk=false;
      }
   }
   return chk;
}

void removeduplicate(vector<int> &arr){
   int arrsz=arr.size();
 set<int> st;int x;
 int uni=arr[0];
 for(int i=0;i<arrsz;i++){
   
   if(arr[i]!=arr[i+1]){
      st.insert(arr[i]);
      uni=arr[i];
   }
  }

 x=st.size();
 int ind=0;
   
 for(auto ite:st){
      cout<<ite<<endl;
      
 }
 cout<<"size="<<x<<'\n';
    
    
}

int main(){

int arr[7]={5,4,3,2,1};
vector<int> arr1={1,1,1,2,2,2,2,3,4,4,4,5};

removeduplicate(arr1);
checksorted(arr,arr1.size());
largestelement(arr,12);
secondlargest(arr,12);

}
