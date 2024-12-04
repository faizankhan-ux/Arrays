#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> SpiralMatrix(vector<vector<int>>&arr) {
    vector<int> ans;
    int top=0;int left=0;
    int n=arr.size();
    int m=arr[0].size();
    int right=m-1;
    int bottom=n-1;

    while(left<=right && top<=bottom){
        //left to right keeping top as constant
        for(int i=left;i<=right;i++){
            ans.push_back(arr[top][i]);
        }
        top++;

        //top to bottom keeping right as constant
        for(int i=top;i<=bottom;i++){
            ans.push_back(arr[i][right]);
        }right--;

        // right to left keeping bottom as constant
        if(top<=bottom){//edge case for row matrix
            for(int i=right;i>=left;i--){
                ans.push_back(arr[bottom][i]);
            }bottom--;

        }
        
        //bottom to top keeping left as constant
        if(left<=right){//edge case for row matrix
            for(int i=bottom;i>=top;i--){
                ans.push_back(arr[i][left]);
               
            } left++;
        }
    }
    return ans;
    //or print it
    for(auto it:ans){
    cout<<it<<" ";
    }
  
}


int main(){
 vector<vector<int>> arr={{1,2,3},{4,5,6},{7,8,9}};
  Spiralmatrix(arr);
  
 return 0;
}
