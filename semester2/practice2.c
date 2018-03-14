int *binarysearch(int A[],int target,int n){
int *low=&A[0];
int *high=&A[n];
int *mid;
while(low<high){
mid=low+(high-low)/2;
if(target==*mid)
return mid;
else if(target<*mid)
high=mid;
else if(target>*mid)
low=mid+1;
}
return NULL;
}
