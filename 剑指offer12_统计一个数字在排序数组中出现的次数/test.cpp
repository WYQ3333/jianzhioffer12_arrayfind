#include<iostream>
#include<vector>

using namespace std;

//统计一个数字在排序数组中出现的次数

class Solution1 {
public:
	//暴力搜索，时间复杂度为O(n）；
	int GetNumberOfK(vector<int> data, int k) {
		int i = 0;
		int count = 0;
		int temp = data.size();
		for (i = 0; i < temp; ++i){
			if (data[i] == k){
				++count;
			}
		}
		return count;
	}
};

class Solution2 {
public:
	int BinarySearch(vector<int> data, int low, int high, int k)
	{
		while (low <= high)
		{
			int m = (high + low) / 2;
			if (data[m] == k)return m;
			else if (data[m] < k) low = m + 1;
			else high = m - 1;
		}
		return -1;
	}
	int GetNumberOfK(vector<int> data, int k) {
		if (data.size() == 0)return 0;
		int len = data.size();
		int KeyIndex = 0;

		KeyIndex = BinarySearch(data, 0, len - 1, k);
		if (KeyIndex == -1) return 0;
		int sumber = 1;
		int m = KeyIndex - 1;
		int n = KeyIndex + 1;

		while (m >= 0 && data[m] == k)
		{
			m--; sumber++;
		}
		while (n<len&&data[n] == k)
		{
			n++; sumber++;
		}
		return sumber;
	}
};

void TestFunc1(){
	vector<int> array = { 1, 2, 3, 4, 4, 4, 4, 5, 5, 6, 7 };
	int k = 4;
	Solution1 s1;
	int count = 0;
	count = s1.GetNumberOfK(array, k);
	cout << k << "出现的次数为：" << count << endl;
}

void TestFunc2(){
	vector<int> array = { 1, 2, 3, 4, 4, 4, 4, 5, 5, 6, 7 };
	int k = 4;
	Solution2 s2;
	int count = 0;
	count = s2.GetNumberOfK(array, k);
	cout << k << "出现的次数为：" << count << endl;
}


int main(){
	TestFunc2();
	system("pause");
	return 0;
}