#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> brute(vector<int> a,int t){ //tc--> O(N^$4)  sc-->O()
   set<vector<int>> st;
        int n=a.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int l=k+1;k<n;k++){
                        long long sum;
                        sum=a[i]+a[j]+a[k]+a[l];
                        if(sum==t){
                            vector<int> row={a[i],a[j],a[k],a[l]};
                            sort(row.begin(),row.end());
                            st.insert(row);
                        }
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
}


vector<vector<int>> Better(vector<int> a,int t){
  int n=a.size();

  set<vector<int>> st;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
       set<int> mp;
      for(int k=j+1;k<n;k++){
        int rem=t-(a[i]+a[j]+a[k]);
        if(mp.find(rem)!=mp.end()){
          vector<int> row={a[i],a[j],a[k],rem};
          sort(row.begin(),row.end());
          st.insert(row);
        }
          mp.insert(a[k]);
        
      }
    }  
  }
  vector<vector<int>> ans(st.begin(),st.end());
  return ans;
}

vector<vector<int>> Optimal(vector<int> a,int t){
  sort(a.begin(),a.end());
  vector<vector<int>> ans;
  int n=a.size();
  for(int i=0;i<n;i++){
    if(i>0 && a[i]==a[i-1]) {continue;} //to avoid duplicates
    for(int j=i+1;j<n;j++){
      if(j>i+1 && a[j]==a[j-1]) {continue;} //to avoid duplicates
      int k=j+1;
      int l=n-1;
      while(k<l){
        long long sum=a[i]+a[j]+a[k]+a[l];
        if(sum==t){
          vector<int> temp;
          temp={a[i],a[j],a[k],a[l]};
          ans.push_back(temp);
          k++;l--;
          while(k<l && a[k]==a[k-1]) k++;
          while(k<l && a[l]==a[l-1]) l--;
        }
        else if(sum<t){
          k++;
        }
        else{
          l--;
        }
      }
    }
  }return ans;
  

}


int main(){
  vector<int> arr={-1,0,-5,-2,-2,-4,0,1,-2};
  vector<vector<int>> ans=Optimal(arr,-9);

  for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
       cout<<ans[i][j]<<"\t";
    }cout<<"\n";
  }
  

     return 0;
}
