#include<iostream>
#include<vector>
#include<array>


int main() {
	std::vector<int> v{ 1,2,3,4,5,6,7 };

	//for (std::vector<int>::size_type i = 0; i != v.size(); i++) {
	//	std::cout << v[i] << " ";
	//	if (v[i] == 3) {
	//		v.erase(v.begin() + i);
	//		i--;
	//		
	//	}
	//}
	
	int* arr = new int[v.size()]{ 0, };
	for (int i = 0; i != v.size(); i++) {
		std::cout << arr[i] << " ";
	}

	
	return 0;
}