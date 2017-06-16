#pragma once
#include <brigand\brigand.hpp>
#include <iostream>
#include <vector>





// Component Collection expects a brigand list of Component types.
template <typename CTypes>
struct ComponentCollection {


private:
	// Store a copy of the tuple representing the component types.
	using RComponentTypes = brigand::as_tuple<CTypes>;
	RComponentTypes rComponentTypes;

	//Simple metafunction that creates a vector of the given type.
	//Used to create the tuple of vectors of component types.
	template <typename T>
	struct vecOfType
	{
		using type = std::vector<T>;
	};

	using CComponentStorage = brigand::transform<CTypes, vecOfType<brigand::_1>>;
	using RComponentStorage = brigand::as_tuple<CComponentStorage>;
	RComponentStorage rComponentStorage;

public:
	template<typename T>
	std::vector<T>& ofType() {
		return std::get<std::vector<T>>(rComponentStorage);
	}	




};

