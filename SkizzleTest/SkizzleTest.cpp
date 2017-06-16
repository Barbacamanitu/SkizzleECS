// SkizzleTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <gtest\gtest.h>
#include "skizzleECS.h"
#include <memory>



//Component Types
struct CompA{};
struct CompB{};
struct CompC{};
//End Component Types



//Test fixture for creating and testing the ECS capabilities.
struct ECSTests : testing::Test {
	using CompList = ComponentTypeList<CompA, CompB,CompC>;
	using ECSType = skizzle<CompList>;
	std::unique_ptr<ECSType> theEcs;

	ECSTests() {
		theEcs = std::make_unique<ECSType>(ECSType());
	}
};


TEST_F(ECSTests, EMPTY_COMPONENT_CONTAINERS)
{
	ASSERT_EQ(theEcs->getComponents()->ofType<CompA>().size(), 0);
	ASSERT_EQ(theEcs->getComponents()->ofType<CompB>().size(), 0);
	ASSERT_EQ(theEcs->getComponents()->ofType<CompC>().size(), 0);
}

TEST_F(ECSTests, EMPTY_ENTITY_CONTAINER)
{
	ASSERT_EQ(theEcs->getEntities().size(), 0);
}


int main(int argc, char ** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

