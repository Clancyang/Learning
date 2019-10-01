#include<stdio.h>
#include<math.h>

int binarySearch(arr,key){
	var low=0; //数组最小索引值
	var high=arr.length-1; //数组最大索引值
	while(low<=high){
		var mid=Math.floor((low+high)/2);
		if(key==arr[mid]){
			return mid;
		}else if(key>arr[mid]){
			low=mid+1;
		}else{
			high=mid-1;
		}
	}
	return -1; //low>high的情况，这种情况下key的值大于arr中最大的元素值或者key的值小于arr中最小的元素值
}