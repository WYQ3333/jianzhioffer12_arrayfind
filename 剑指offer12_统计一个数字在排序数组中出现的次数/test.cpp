#include<iostream>
#include<vector>

using namespace std;

//ͳ��һ�����������������г��ֵĴ���

class Solution {
public:
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

void TestFunc(){
	vector<int> array = { 1, 2, 3, 4, 4, 4, 4, 5, 5, 6, 7 };
	int k = 4;
	Solution s1;
	int count = 0;
	count = s1.GetNumberOfK(array, k);
	cout << k << "���ֵĴ���Ϊ��" << count << endl;
}


int main(){
	TestFunc();
	system("pause");
	return 0;
}