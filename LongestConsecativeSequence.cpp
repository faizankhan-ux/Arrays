#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//finding if next element exists in array
bool linearsearch(vector<int> arr,int x,int n){
     for(int i=0;i<n;i++){
          if(x==arr[i]){
               return true;
          }
     }return false;
}
void brute(vector<int> &arr,int n){
 int longLen=0;

//iterating in array
 for(int i=0;i<n;i++){
  int x=arr[i];
   int cnt=1;
   
  while(linearsearch(arr,x+1,n)== true){
     x=x+1;
     cnt+=1;
  }
  longLen=max(cnt,longLen);
   }

   cout<<longLen;
}



void better(vector<int> arr,int n){
     sort(arr.begin(),arr.end());
     //current length
     int cnt=0;

     //final length
     int lng=1;

     //checking if previous number exists
     int smal=INT_MIN;

     for(int i=0;i<n;i++){
         //if there is 2 then there should be 2-1=1
          int x=arr[i];
          if(smal==x-1){
               smal=x;
               cnt+=1;
          }else if(x!=smal){
               cnt=1;
               smal=x;
          }
          lng=max(lng,cnt);
     }
     cout<<lng;
}




int optimal(vector<int> arr,int n){
     if(n==0){
          return 0;
     }
     int longlen=1;
     unordered_set<int> st;
     for(int i=0;i<n;i++){
          st.insert(arr[i]);
     }
     for(auto it:st){
          int cnt=1;
          if(st.find(it-1)==st.end()){
               cnt=1;
               int x=it;
               while(st.find(x+1)!=st.end()){
                    cnt+=1;
                    x+=1;
               }
               longlen=max(longlen,cnt);          }
     }
     return longlen;

}






int main(){
 vector<int> arr={102,4,100,1,101,3,2,6,5};
 int n=arr.size();
 cout<<optimal(arr,n);

     return 0;
}
