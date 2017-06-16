#pragma once
#include <unordered_map>
#include <atomic>

struct ComponentTypeMap {
	
private:
	std::atomic_int last_id;

public:
	//Uses a static variable so the value only gets set once.
	//This works because the template function is generated once for each type.
	template<typename T>
	int getId() {
		static int id = last_id++;
		return id;
	}

	ComponentTypeMap() {
		last_id = 0;
	}

};