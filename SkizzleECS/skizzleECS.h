#pragma once
#include <tuple>
#include <brigand\brigand.hpp>
#include "ComponentCollection.h"
#include "Entity.h"
/*
	SkizzleECS has a mixture of compile time and runtime containers. 
	The compile time containers are used to create the runtime representations.

	Runtime:
	The component types are stored in the private field named ComponentTypes. It is a tuple
	representing each of the component types.

	The actual components are stored in ComponentStorage.

*/

//ComponentTypeList is a brigand::list of all the component types.
template<typename ...CompTypes>
using ComponentTypeList = brigand::list<CompTypes...>;

//Expects a brigand::list of the supported component types.
template <typename CTypeList>
struct skizzle {
	using CompColl = ComponentCollection<CTypeList>;
	skizzle() {
		
		mComponents = std::make_unique<CompColl>(CompColl());
	}

	std::unique_ptr<CompColl> const& getComponents() {
		return mComponents;
	}

	std::vector<Entity>& getEntities() {
		return mEntities;
	}

	int addEntity(Entity entity) {
		mEntities.push_back(entity);
		int id = mEntities.size() - 1;
		mEntities[id].ID = id;
		return id;
	}
private:
	std::unique_ptr<ComponentCollection<CTypeList>> mComponents;

	//Entities
	/*
		TODO:
		-Create proper entity container that automatically handles IDs.
		-Make container sortable.
		-Keep an internal mapping of IDs to entity index.

	*/

	std::vector<Entity> mEntities;
};