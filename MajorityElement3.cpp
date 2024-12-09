#include<bits/stdc++.h>
using namespace std;

//brute -->TC->O(N^3)


vector<int> better(vector<int> v) {
	int n=v.size();
	vector<int> ans;

	unordered_map<int ,int> mp{0};
	for(int i=0;i<n;i++){
		mp[v[i]]+=1;

	}

	for(auto it:mp){
		if(it.second>n/3){
			ans.push_back(it.first);
			
		}
	}
	sort(ans.begin(),ans.end());
		return ans;

}

 vector<int> Optimal(vector<int>& nums) {  //--> TC-O(N)
        //since we can have two majority element
        int min=(int)(nums.size()/3);
        vector<int> ans;
        int ele1;
        int ele2;
        int cnt1=0;
        int cnt2=0;
        //logic similar to n/2 elements question
        for(int i=0;i<nums.size();i++){
            if(cnt1==0 && nums[i] != ele2){
                ele1=nums[i];
                cnt1=1;
            }else if(cnt2==0 && nums[i] != ele1){
                ele2=nums[i];
                cnt2=1;
            }
            else if(nums[i]==ele1){
                cnt1++;
            }
            else if(nums[i]==ele2){
                cnt2++;
            }
            else{
                cnt2--;
                cnt1--;
            }

        }
        //manually checking 
        int ck1=0;
        int ck2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele1){
                ck1++;
            } if(nums[i]==ele2){
                ck2++;
            }
        }

        if(ck1>min){
            ans.push_back(ele1);
        } 
        if(ck2>min){
            ans.push_back(ele2);
        }

        sort(ans.begin(),ans.end());
        return ans;
    }


int main(){
  
     vector<int> arr={1,2,2,2,3,4,5,6};
     better(arr);
     return 0;

}
