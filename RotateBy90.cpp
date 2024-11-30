#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void brute( vector<vector<int>> arr){
     //declaring another matrix for returning the answer
     vector<vector<int>> ans;

     //swaping elements above the diagonal and below
     for(int i=0;i<3;i++){
          for(int j=0;j<3;j++){
               ans[j][3-1-i]=arr[i][j];
          }
     }
     for(int i=0;i<3;i++){
          for(int j=0;j<3;j++){
               cout<<ans[i][j]<<"\t";
          }cout<<'\n';
     }
}

void optimal(vector<vector<int>> &arr){
     //Transpose of matrix
     for(int i=0;i<3;i++){
          for(int j=0;j<i;j++){
               swap(arr[i][j],arr[j][i]);
          }
     }
     //Reversing each row
     for(int i=0;i<3;i++){
         reverse(arr[i].begin(),arr[i].end());
     }



      for(int i=0;i<3;i++){
          for(int j=0;j<3;j++){
               cout<<arr[i][j]<<"\t";
          }cout<<'\n';
     }

}

 

int main(){
     vector<vector<int>> arr={{1,2,3},
                    {4,5,6},
                    {7,8,9}};
     
     optimal(arr);
    

    


     return 0;
}