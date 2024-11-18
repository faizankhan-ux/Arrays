#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//using maps
void hashing(int arr[],int n){
     map<int,int> mmp;
     for(int i=0;i<n;i++){
          mmp[arr[i]]++;
     }
     for(auto it:mmp){
          cout<<it.first<<"-->"<<it.second<<endl; 
     }
   
}

//using unordered map
void hashUnordered(int arr[],int n){
     unordered_map<int,int> ump;
     for(int i=0;i<n;i++){
          ump[arr[i]]++;
     }
      for(auto it:ump){
          cout<<it.first<<"-->"<<it.second<<endl; 
     }

}






int main(){

     //cout<<"hash";
     
 int arr[12]={1,2,2,3,4,5,4,2,2,1,3,1};
 hashUnordered(arr,12);
 //frequency of element 

// int hash[6]={0};
// for(int i=0;i<6;i++){
//      hash[arr[i]]++;
// }


//    for(int i=0;i<6;i++){
//      cout<<i<<"-->"<<hash[i]<<'\n';
//    }


}