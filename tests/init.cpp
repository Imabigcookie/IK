#include <bintree.hpp>
#include <catch.hpp>

SCENARIO(" Zero ") 
{
tree <int> test;
REQUIRE(test.root_() == nullptr);
REQUIRE(test.get_count() == 0);	
}
SCENARIO(" 1 ")
{
  tree <int> test;
  test.ins_node(7);
  REQUIRE(test.get_count() == 1);
  REQUIRE(test.find_node(7, test.root_()) -> key == 7);
}
SCENARIO("find")
{
  tree <int> test;
  test.ins_node(6);
  REQUIRE(test.find_node(6, test.root_()) != nullptr);
  REQUIRE(test.find_node(6, test.root_()) -> key == 6);
}
SCENARIO("Get root")
{
  tree <int> test;
  test.ins_node(6);
  REQUIRE(test.root_() != 0);
}
SCENARIO ("Read and Write")
{
  tree <int> testread;
  testread.ins_node(6);
  testread.ins_node(5);
  testread.writing("bin.txt");
  
  tree <int> testwrite;
  testwrite.reading("newbin.txt");
  REQUIRE(testwrite.find_node(6, testwrite.root_())!= nullptr);
  REQUIRE(testwrite.find_node(5, testwrite.root_())!= nullptr);
  REQUIRE(testread.get_count() == testwrite.get_count());
}
