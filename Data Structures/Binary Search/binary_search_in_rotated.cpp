int findPivot(vector<int> arr,int start,int end){
    if(end<start) return -1;
    if(end==start) return start;
	int mid = (start+end)/2;
    if(mid<end and arr[mid]>arr[mid+1]) return mid;
    if(mid>start and arr[mid]<arr[mid-1]) return mid-1;
    if(arr[start]>=arr[mid]) return findPivot(arr,start,mid-1);
    return findPivot(arr,mid+1,end);
}
//finding pivot in o(logn) time
int binarySearchForRotated(vector<int> arr,int start,int k,int length,int n){
    if(length==0) return -1;
    int mid = ((2*start+length-1)/2)%n;
    if(arr[mid]==k) return mid;
    else if(arr[mid]>k){
        return binarySearchForRotated(arr,start,k,(length-1)/2,n);
    }
    else{
        return binarySearchForRotated(arr,mid+1,k,length/2,n);
    }
}
//modified binary search
int findPosition(vector<int>& arr, int n, int k)
{
    int pivot = (findPivot(arr,0,n-1)+1)%n;
    return binarySearchForRotated(arr,pivot,k,n,n);
    // Write your code here.
    // Return the position of K in ARR else return -1.
}

