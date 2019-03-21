#pragma once
#include "pch.h"
#include <vector>
#include <iostream>
//#include <map>
#include <unordered_map>
using namespace std;

class twoSum
{
public:
	twoSum();
	~twoSum();
	vector<int> proc(vector<int>& nums, int target);
};

