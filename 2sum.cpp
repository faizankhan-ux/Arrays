#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        //hashing to save sum and indices
        unordered_map<int,int> mp;

        vector<int> ans;
        int n=arr.size();

        for(int i=0;i<n;i++){
            int num=arr[i];
            int rem=target-arr[i];

            //if remaning is found in map
            if(mp.find(rem)!=mp.end()){
               ans.push_back(mp[rem]);
               ans.push_back(i);
            }
            //adding sum and indices in map
            mp[arr[i]]=i;
        }
        return ans;
    }
};
