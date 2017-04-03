#include <bintree.cpp>
#include <catch.hpp>

SCENARIO("def constructor") 
{
	BST Node;
	REQUIRE(Node.val() == 0);
}

