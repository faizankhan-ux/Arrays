#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>  rotatebyDpalce(vector<int> &arr,int n,int d){
   
     d=d%n;
   // store ele in diff arr
     int temp[d];
     for(int i=0;i<d;i++){
          temp[i]=arr[i];
          //cout<<temp[i];
     }

 //shift ele by d
     for(int i=d;i<n;i++){
          arr[i-d]=arr[i];
          //cout<<arr[i];
     }
 
     for(int i=n-d;i<n;i++){
          arr[i]=temp[i-(n-d)];
          //cout<<arr[i];
          
     }
     cout<<'\n';

    return arr;

}

void rotateoptimal(int arr[],int n,int d){
  reverse(arr,arr+d);
  reverse(arr+d,arr+n);
  reverse(arr,arr+n);
   for(int i=0;i<n;i++){
     cout<<arr[i]<<" ";
 }
 
}
void rightrotate(int arr[],int n,int d){
  // {1,2,3,4,5,6,7}
  // {6,7,1,2,3,4,5}
  d=d%n;
  int tmp[d];
  for(int i=n-d;i<n;i++){ 
    tmp[i-(n-d)]=arr[i] ;
    cout<<tmp[i-(n-d)];
  }
  cout<<'\n';
  int i=0;
  int j = n-1;
  while(j>0){
     arr[j]=arr[j-d];
     cout<<arr[i];
     i++;
     j--;
     
  }cout<<'\n';
  
  for(int i=0;i<d;i++){
     arr[i]=tmp[i];
     cout<<arr[i]<<" ";
  }
  cout<<'\n';
   for(int i=0;i<n;i++){
     cout<<arr[i]<<" ";
 }

 
}

void rightoptimal(int arr[],int n,int d){
     int k=n-d;
     reverse(arr+k,arr+n);
     reverse(arr,arr+k);
     reverse(arr,arr+n);for(int i=0;i<7;i++){
     cout<<arr[i]<<" ";
}
}

void movezero(vector<int> &arr,int n){
    
     vector<int> temp;
     for(auto it:arr){
          if(it!=0){
           temp.push_back(it);
            
          }
          
     }cout<<'\n';
 for(int i=0;i<temp.size();i++){
     
          arr[i]=temp[i];
     }
     for(int i=0;i<n-temp.size();i++){
          arr.push_back(0);
     }

} 

void move0Optimal(vector<int> &arr,int n){
     int j=1;
     for(int i=0;i<n;i++){
          if(arr[i]==0 && arr[j]!=0){
               swap(arr[i],arr[j]);
               j++;
          }
     }
}
vector<int> unionbrute(vector<int> arr,vector<int> arr2,vector<int> &uni){
set<int> st;

for(int i=0;i<arr.size();i++){
     st.insert(arr[i]);
 
}

for(int i=0;i<arr2.size();i++){
     st.insert(arr2[i]);
}
for(auto it:st){
     uni.push_back(it);
     }

return uni;

}
vector<int> unionOptimal(vector<int> &a,vector<int> &b){
    int i=0;
    int j=0;
    int n = a.size();
    int m = b.size();
    vector<int> uni;
    
    while(i<n && j<m){
        if(a[i]<=b[j]){
            if( uni.size()==0 || uni.back()!=a[i] ){
                uni.push_back(a[i]);
                
            }i++;
        
        }else{
            if(uni.size()==0 || uni.back()!=b[j] ){
                uni.push_back(b[j]);
                
            }j++;
        }
    }
    while(i<n){
        if(uni.back()!=a[i]){
            uni.push_back(a[i]);
            i++;
        }
    }
     while(j<m){
        if(uni.back()!=b[j]){
            uni.push_back(b[j]);
            j++;
        }
    }

    return uni;

}


vector<int> intersectionBrute(vector<int> &a,vector<int> &b,vector<int> &ans){
     int n=a.size();
     int m=b.size();
     int vs[m]={0};
     for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
               if(a[i]==b[j] && vs[j]==0){
                    ans.push_back(a[i]);
                    vs[j]=1;
                    break;
               }
               if(a[i]<b[i]){
                    break;
               }
          }

     }
     for(auto it:ans){
     cout<<it<<" ";
}
     
}

void intersectionOptimal(vector<int> &a,vector<int> &b,vector<int> &ans){
     int n=a.size();
     int m=b.size();
     int i=0;
     int j=0;
     int vs[m]={0};
          while(i<n && j<m){
          if(a[i]<b[j] ){
               i++;
          }else if(a[i]>b[j]){
               j++;
          }else{
               ans.push_back(a[i]);
               i++;
               j++;

          }
     }
     

}





int main(){
 vector<int> arr={1,2,3,4,5,6};
 vector<int> arr2={2,2,3,3,4,5,6};
 int arr0[7]={1,2,3,4,5,6,7};

 vector<int> ans;
 cout<<arr.size();
 //intersectionOptimal(arr,arr2,ans);
//intersectionBrute  (arr,arr2,ans);
 //unionOptimal(arr,arr2);
//unionbrute(arr,arr2,uni);
// for(auto it:uni){
//      cout<<it<<" ";
// }


//  move0Optimal(arr,12);
 //movezero(arr,12);
 //rotateoptimal(arr1,7,2); //
// rotatebyDpalce(arr,7,7-2); //it takes space
 //rightrotate(arr1,7,3);
 //rightoptimal(arr1,7,2);


// for(int i=0;i<7;i++){
//      cout<<arr[i]<<" ";
// // }
for(auto it:ans){
     cout<<it<<" ";
}


}
