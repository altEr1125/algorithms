#include<iostream>
#include <algorithm>
#include <vector>

int binary_serach(int *p_arr,int target,int left,int right) {
	int low = left;
	int high = right;
	int mid;
	while (low <= high) {//要用<=
		mid = (low + high) / 2;
		if (target == p_arr[mid])
			return mid;
		else if (target < p_arr[mid])
			high = mid - 1;
		else if(target > p_arr[mid])
			low = mid + 1;
	}
	return -1;

}

//int main() {
//	int target = 37;
//	std::vector<int> arr = { 5,13,92,56,19,21,37,80,88,64,75 };
//	sort(arr.begin(), arr.end());
//	int add = binary_serach(&arr[0], target,0, int(arr.size()-1));
//	std::cout << add << std::endl;
//	return 1;
//}