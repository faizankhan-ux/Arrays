#include<bits/stdc++.h>
using namespace std;


//BRUTE FORCE APPROACH
vector<vector<int>> brute(vector<int> arr,int target){
     int  n=arr.size();
     //for storing trplets
    set<vector<int>> st;
    for(int i=0;i<n;i++){
     for(int j=i+1;j<n;j++){
          for(int k=j+1;j<n;j++){
               if(arr[i]+arr[j]+arr[k]==target){
                    vector<int> temp={arr[i],arr[j],arr[k]};
                    //sorting to avoid duplicates
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
               }
          }
     }

    }
    vector<vector<int>> ans(st.begin(),st.end());
     return ans;
    
}

//BETTER 
vector<vector<int>> better(vector<int>arr , int t){
     int n=arr.size();
     set<vector<int> > st;
     for(int i=0;i<n;i++){
          set<int> hashset;
       for(int j=i+1;j<n;j++){
          int third=-(arr[i]+arr[j]);
          if(hashset.find(third)!=hashset.end()){
               vector<int> temp={arr[i],arr[j],third};
               sort(temp.begin(),temp.end());
               st.insert(temp);
          }
               hashset.insert(arr[j]);
          
       }
     }
     vector<vector<int>> ans(st.begin(),st.end());
     return ans;
     
}


//OPTIMAL APPROACH
vector<vector<int>> OPtimal(vector<int>& nums) { //using two pointer approach
        sort(nums.begin(),nums.end());
      vector<vector<int>> ans;
      int n=nums.size();

      //pointers are i , j and k
         for(int i=0;i<n;i++){
         
           if(i>0 && nums[i]==nums[i-1]) continue; //if previous element is duplicate
           else{
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0){
                    j++;
                }else if(sum>0){
                    k--;
                }else{
                    vector<int> temp={nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }
        }
      }
    return ans;
    }


int main(){

 vector<int> arr={0,1,0,0,1,-1,0,-2,2,0,8,8,-16};
 vector<vector<int>> ans;

 ans=OPtimal(arr);
 
 for(int i=0;i<ans.size();i++){
     for(int j=0;j<ans[i].size();j++){
          cout<<ans[i][j]<<" ";
     }cout<<'\n';
 }

     return 0;


}
