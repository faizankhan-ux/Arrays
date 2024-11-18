#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int MisingBrute(vector<int> &arr,int n){
     int ans=0;
  for(int i=1;i<n;i++){
     int flag=0;
     for(int j=0;j<n-1;j++){
          if(arr[j]==i){
               flag=1;
               break;
          }
     }
     if(flag==0){
          ans=i;
     }
  }
  return ans;
}

int missingBetter(vector<int>  a,int N){
      int hash[N+1]={0};
  for(int i=0;i<N-1;i++){
      hash[a[i]]++;
  }

  for(int i=1;i<=N;i++){
      if(hash[i]==0){
          return i;
      }
  }
}

int missingOptimal_one(vector<int> arr,int n){
    int sum=n*(n+1)/2;
    int sum2=0;
    for(int i=0;i<n;i++){
        sum2=sum2+arr[i];
    }
    int ans =sum-sum2;
    return ans;
}

int missingOPtimal_two(vector<int> arr,int n){
    int Xor=n;
    int Xor2=0;
    for(int i=0;i<n-1;i++){
        Xor2=arr[i]^Xor2;
        Xor=Xor^i+1;
    }
    
    int ans=Xor^Xor2;
    return ans;
}

int ConsicativeOne_brute(vector<int> arr,int n){
    int cnt=0;
    int max=0;
    for(int i=0;i<n;i++){
        
        if(arr[i]==1){
            cnt+=1;
             if(cnt>max){
            max=cnt;
        }
        }else{
     
            cnt=0;
        }
       
       
    } 
    return max;

}


int getSingleElement_brute(vector<int> &arr){
	int n=arr.size();
	int ans;
	for(int i=0;i<n;i++){
		int cnt=0;
		for(int j=0;j<n;j++){
			if(arr[i]==arr[j]){
				cnt+=1;
			}
		}
		if(cnt==1){
			ans=arr[i];
		}


	}
  return ans;

}


int getSingleElement_better(vector<int> &arr){
	int n=arr.size();
	int ans;
	map<int,int> mp;
	for(int i=0;i<n;i++){
		mp[arr[i]]++;
	}
	for(auto it:mp){
		if(it.second==1){
			ans=it.first;
		}
	}
  return ans;

}



int main(){
 vector<int> arr={2,3,4,5,6};
  vector<int> arr2={1,1,0,1,0,1,1,1,1,1,1};
  vector<int> arr3;
 
   

 cout<<"consicative ones : "<<ConsicativeOne_brute(arr2,10);
}
