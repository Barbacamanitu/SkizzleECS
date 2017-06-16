#pragma once
#include <vector>
#include "Entity.h"
#include <algorithm>
struct System {
private:
	std::vector<int> mComponentIds;
public:

	//Checks if every id in this system is also present in the entity.
	bool canProcessEntity(Entity& entity) {
		const std::vector<int>& entIds = entity.getComponentIds();
		for (auto a = mComponentIds.begin(); a != mComponentIds.end(); a++) {
			if (std::find(entIds.begin(), entIds.end(), *a) == entIds.end()) {
				return false;
			}			
		}
		return true;
	}

	void addComponentId(int id) {
		mComponentIds.push_back(id);
		std::sort(mComponentIds.begin(), mComponentIds.end());
		mComponentIds.erase(std::unique(mComponentIds.begin(), mComponentIds.end()), mComponentIds.end());
	}

	std::vector<int>& getComponentIds() {
		return mComponentIds;
	}
};