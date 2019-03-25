#include "pch.h"
#include <iostream>
#include "twoSum.h"

twoSum::twoSum()
{
}


twoSum::~twoSum()
{
}

vector<int> twoSum::proc(vector<int>& nums, int target)
{
	unordered_map<int, int> m;
	vector<int> res;
	decltype(nums.size()) i;
	for (i = 0; i < nums.size(); i++) {
		m[nums[i]] = i;
	}
	for (i = 0; i < nums.size(); i++) {
		int t = target - nums[i];
		if (m.count(t) && m[t] != i) {
			res.push_back(i);
			res.push_back(m[t]);
			break;
		}
	}
	return res;
}



int main()
{
	vector<int> twoSumData = { 2, 7, 11, 15 }, result;
	twoSum a = twoSum();
	result = a.proc(twoSumData, 13);
	decltype(result.size()) i;
	for (i = 0; i < result.size(); i++) {
		cout << result[i];
	}

	std::cout << "Hello World!\n";
}