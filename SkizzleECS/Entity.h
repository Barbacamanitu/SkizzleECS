#pragma once
#include <vector>
#include <algorithm>
struct Entity {
private:
	std::vector<int> mComponentIds;
public:
	int ID;

	void addComponentId(int id) {
		mComponentIds.push_back(id);
		std::sort(mComponentIds.begin(), mComponentIds.end());
		mComponentIds.erase(std::unique(mComponentIds.begin(), mComponentIds.end()), mComponentIds.end());
	}

	std::vector<int>& getComponentIds() {
		return mComponentIds;
	}
};