#include<iostream>
#include <vector>
void merge(std::vector<int> &arr, int left, int mid, int right, std::vector<int> temp);
void merge_sort(std::vector<int> &arr,int left,int right) {
	std::vector<int> temp(arr.size());
	if (left < right) {
		int mid = (left + right) / 2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid+1, right);
		merge(arr, left, mid, right,temp);
	}
}
void merge(std::vector<int> &arr,int left,int mid,int right,std::vector<int> temp) {
	int i = left;//左序列指针
	int j = mid + 1;//右序列指针
	int t = 0;//临时数组指针
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j])
			temp[t++] = arr[i++];
		else
			temp[t++] = arr[j++];
	}
	while (i <= mid)//将左边剩余元素填充进temp中
		temp[t++] = arr[i++];
	while (j <= right)//将右序列剩余元素填充进temp中	
		temp[t++] = arr[j++];
	t = 0;
	while (left <= right) {
		arr[left++] = temp[t++];
	}
}
int main() {
	std::vector<int> arr = { 9,8,7,6,5,4,3,2,1 };
	merge_sort(arr, 0, int(arr.size()-1));
	for (int i = 0; i < arr.size(); i++)
		std::cout << arr[i]<<",";
	return 1;
}