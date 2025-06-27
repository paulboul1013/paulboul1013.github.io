#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <sstream>
#include <array>
#include <cassert>
#include <set>
#include <algorithm>


typedef long long ll;

using namespace std;

const int MOD=1e9+7;

// void insertionsort(vector<int> &arr){
//     int n=arr.size();
//     for (int i=1;i<n;i++){
//         int key=arr[i];
//         int j=i-1;
//         while (j>=0 && arr[j]>key){
//             arr[j+1]=arr[j];
//             --j;
//         }

//         arr[j+1]=key;
//     }
// }

void insertionsort_desc(vector<int> &arr){
    int n=arr.size();
    for (int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while (j>=0 && arr[j]<key){
            arr[j+1]=arr[j];
            --j;
        }

        arr[j+1]=key;
    }
}

int lienar_search(vector<int>&arr,int target){
    for (int i=0;i<arr.size();i++){
        if (arr[i]==target){
            return i;
        }
    }
    return -1;
}

vector<int> binaryAdd(const vector<int> &a,const vector<int> &b){
    int n=a.size();
    vector<int> c(n+1,0);
    int carry=0;

    for (int i=n-1;i>=0;i--){
        int sum=a[i]+b[i]+carry;
        c[i+1]=sum%2;
        carry=sum/2;
    }
    c[0]=carry;

    return c;
}

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void selection_sort(vector<int> &arr){
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        int min_ele=i;
        for (int j=i+1;j<n;j++){
            if (arr[j]< arr[min_ele]){
                min_ele=j;
            }
        }
        swap(arr[i],arr[min_ele]);
    }
}

// void merge(vector<int>&arr,int p,int q,int r){
//     int n1=q-p+1;
//     int n2=r-q;
//     vector<int> L(n1+1);
//     vector<int> R(n2+1);

//     for (int i=0;i<n1;i++){
//         L[i]=arr[p+i];
//     }

//     for (int j=0;j<n2;j++){
//         R[j]=arr[q+j];
//     }

//     L[n1+1]=INT_MAX;
//     R[n2+1]=INT_MAX;

//     int i=0;
//     int j=0;
//     int k=p;
    
//     while (i<n1 && j<n2){
//         if (L[i]<=R[j]){
//             arr[k]=L[i];
//             i++;
//         }
//         else{
//             arr[k]=R[j];
//             j++;
//         }
//         k++;
//     }

//     while (i<n1){
//         arr[k]=L[i];
//         i++;
//         k++;
//     }
    
//     while (j<n2){
//         arr[k]=L[j];
//         j++;
//         k++;
//     }

// }

void recursiveInsertionSort(vector<int> &A, int n) {
    // 基礎情況：若只剩一個元素或沒有元素，已經是有序
    if (n <= 1) {
        return;
    }

    // 步驟 1：遞迴處理前面 n-1 個元素
    recursiveInsertionSort(A, n - 1);

    // 步驟 2：插入最後一個元素 A[n-1] 到已排序的 A[0 .. n-2] 中
    int key = A[n-1];
    int i = n - 2;

    while (i >= 0 && A[i] > key) {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = key;
}

int binarysearch(vector<int> arr,int left,int right,int target){
    if (left>right){
        return -1;
    }
    while (left<right){
        int mid=left+(right-left)/2;
        if (target==arr[mid]){
            return mid;
        }
        else if (mid>target){
            right=mid;
        }
        else{
            left=mid+1;
        }
    }
    return -1;
}

vector<int> two_sum(vector<int>arr,int target){
    int n=arr.size();
    for (int i=0;i<n;i++){
       int t_sum=target-arr[i];
       int index=binarysearch(arr,0,i,t_sum);
       if (index!=-1){
            return {index,i};
       }
    }
    return {-1,-1};
}

//insertion sort for small subarrays
void insertionsort(vector<int> &arr,int left,int right){
    for (int i=left+1;i<=right;i++){
        int key=arr[i];
        int j=i-1;
        while (j>=left && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

//standard merge function
void merge(vector<int> &arr,int left,int mid,int right){
    vector<int> leftpart(arr.begin()+left,arr.begin()+mid+1);
    vector<int> rightpart(arr.begin()+mid+1,arr.begin()+right+1);
    
    int i=0,j=0,k=left;

    while (i<leftpart.size(),j<rightpart.size()){
        if (leftpart[i]<=rightpart[j]){
            arr[k++]=leftpart[i++];
        }else{
            arr[k++]=rightpart[j++];
        }
    }

    while (i < leftpart.size()) arr[k++]=leftpart[i++];
    while (j < rightpart.size()) arr[k++]=rightpart[j++];

}

//hybrid merge-insertion sort
void hybrid_sort(vector<int>&arr,int left,int right,int k){
    if (right-left+1<=k){
        insertionsort(arr,left,right);
        return;
    }
    
    int mid=left+(right-left)/2;
    hybrid_sort(arr,left,mid,k);
    hybrid_sort(arr,mid+1,right,k);
    merge(arr,left,mid,right);
}

void hybrid_merge_sort(vector<int> &arr,int k){
    hybrid_sort(arr,0,arr.size()-1,k);
}


void bubblesort(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if (arr[j]<arr[i]){
                swap(arr[j],arr[i]);
            }
        }
    }
}


int main(){


    cout.setf(ios_base::fixed,ios_base::floatfield);

    string word = "abcdefghij";
    vector<int> arr = {-2,-1,-1,1,2,3};
    vector<int> arr2 = {2, 4, -22, 10, 2, 3, 1, 5, 20};
    vector<int> data = {38, 27, 43, 3, 9, 82, 10};
    int k=16;

    
    for(int num:data){
        cout<<num<<" ";
    }

    cout<<endl;

    bubblesort(data,data.size());

    for(int num:data){
        cout<<num<<" ";
    }


    
    cout<<endl;




    return 0;
}



