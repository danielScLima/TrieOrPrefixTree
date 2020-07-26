// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "trieorprefixtree.h"

TEST_CASE( "Testing the insert call in the tree", "[single-file]" )
{
	TrieOrPrefixTree r;
	NodeOfTrieOrPrefixTree *root = r.getRoot();
	REQUIRE(root != nullptr);
	
	r.insert("home");
	root = r.getRoot();
	REQUIRE(root != nullptr);
	
	REQUIRE(root->hasChildOfChar('h') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->data == 'h');
	REQUIRE(!root->isFinal);
	
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->data == 'o');
	REQUIRE(!root->hasChildOfChar('h')->hasChildOfChar('o')->isFinal);
	
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->data == 'm');
	REQUIRE(!root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->isFinal);
	
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->hasChildOfChar('e') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->hasChildOfChar('e')->data == 'e');
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->hasChildOfChar('e')->isFinal);
	
	r.insert("homeless");
	root = r.getRoot();
	REQUIRE(root != nullptr);
	
	REQUIRE(root->hasChildOfChar('h') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->data == 'h');
	REQUIRE(!root->isFinal);
	
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->data == 'o');
	REQUIRE(!root->hasChildOfChar('h')->hasChildOfChar('o')->isFinal);
	
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->data == 'm');
	REQUIRE(!root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->isFinal);
	
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->hasChildOfChar('e') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->hasChildOfChar('e')->data == 'e');
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->hasChildOfChar('e')->isFinal);
	
	NodeOfTrieOrPrefixTree *nodeEOfHome = root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->hasChildOfChar('e');
	REQUIRE (nodeEOfHome->data == 'e');
	
	REQUIRE(nodeEOfHome->hasChildOfChar('l') != nullptr);
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->data == 'l');
	REQUIRE(!nodeEOfHome->hasChildOfChar('l')->isFinal);
	
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e') != nullptr);
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->data == 'e');
	REQUIRE(!nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->isFinal);
	
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s') != nullptr);
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->data == 's');
	REQUIRE(!nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->isFinal);
	
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->hasChildOfChar('s') != nullptr);
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->hasChildOfChar('s')->data == 's');
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->hasChildOfChar('s')->isFinal);
	
	NodeOfTrieOrPrefixTree *nodeSOfHome = nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->hasChildOfChar('s');
	REQUIRE(nodeSOfHome->data == 's');

	r.insert("love");
	root = r.getRoot();
	REQUIRE(root != nullptr);

	REQUIRE(root->hasChildOfChar('h') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->data == 'h');
	REQUIRE(!root->isFinal);

	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->data == 'o');
	REQUIRE(!root->hasChildOfChar('h')->hasChildOfChar('o')->isFinal);

	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->data == 'm');
	REQUIRE(!root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->isFinal);

	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->hasChildOfChar('e') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->hasChildOfChar('e')->data == 'e');
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->hasChildOfChar('e')->isFinal);

	nodeEOfHome = root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->hasChildOfChar('e');
	REQUIRE(nodeEOfHome->data == 'e');

	REQUIRE(nodeEOfHome->hasChildOfChar('l') != nullptr);
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->data == 'l');
	REQUIRE(!nodeEOfHome->hasChildOfChar('l')->isFinal);

	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e') != nullptr);
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->data == 'e');
	REQUIRE(!nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->isFinal);

	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s') != nullptr);
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->data == 's');
	REQUIRE(!nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->isFinal);

	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->hasChildOfChar('s') != nullptr);
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->hasChildOfChar('s')->data == 's');
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->hasChildOfChar('s')->isFinal);

	//checking 'love'
	REQUIRE(root->hasChildOfChar('l') != nullptr);
	REQUIRE(root->hasChildOfChar('l')->data == 'l');
	REQUIRE(!root->isFinal);

	REQUIRE(root->hasChildOfChar('l')->hasChildOfChar('o') != nullptr);
	REQUIRE(root->hasChildOfChar('l')->hasChildOfChar('o')->data == 'o');
	REQUIRE(!root->hasChildOfChar('l')->hasChildOfChar('o')->isFinal);

	REQUIRE(root->hasChildOfChar('l')->hasChildOfChar('o')->hasChildOfChar('v') != nullptr);
	REQUIRE(root->hasChildOfChar('l')->hasChildOfChar('o')->hasChildOfChar('v')->data == 'v');
	REQUIRE(!root->hasChildOfChar('l')->hasChildOfChar('o')->hasChildOfChar('v')->isFinal);

	REQUIRE(root->hasChildOfChar('l')->hasChildOfChar('o')->hasChildOfChar('v')->hasChildOfChar('e') != nullptr);
	REQUIRE(root->hasChildOfChar('l')->hasChildOfChar('o')->hasChildOfChar('v')->hasChildOfChar('e')->data == 'e');
	REQUIRE(root->hasChildOfChar('l')->hasChildOfChar('o')->hasChildOfChar('v')->hasChildOfChar('e')->isFinal);

	r.insert("hi");
	root = r.getRoot();
	REQUIRE(root != nullptr);

	REQUIRE(root->hasChildOfChar('h') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->data == 'h');
	REQUIRE(!root->isFinal);

	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->data == 'o');
	REQUIRE(!root->hasChildOfChar('h')->hasChildOfChar('o')->isFinal);

	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->data == 'm');
	REQUIRE(!root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->isFinal);

	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->hasChildOfChar('e') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->hasChildOfChar('e')->data == 'e');
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->hasChildOfChar('e')->isFinal);

	nodeEOfHome = root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->hasChildOfChar('e');
	REQUIRE(nodeEOfHome->data == 'e');

	REQUIRE(nodeEOfHome->hasChildOfChar('l') != nullptr);
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->data == 'l');
	REQUIRE(!nodeEOfHome->hasChildOfChar('l')->isFinal);

	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e') != nullptr);
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->data == 'e');
	REQUIRE(!nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->isFinal);

	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s') != nullptr);
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->data == 's');
	REQUIRE(!nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->isFinal);

	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->hasChildOfChar('s') != nullptr);
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->hasChildOfChar('s')->data == 's');
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->hasChildOfChar('s')->isFinal);

	//checking 'love'
	REQUIRE(root->hasChildOfChar('l') != nullptr);
	REQUIRE(root->hasChildOfChar('l')->data == 'l');
	REQUIRE(!root->isFinal);

	REQUIRE(root->hasChildOfChar('l')->hasChildOfChar('o') != nullptr);
	REQUIRE(root->hasChildOfChar('l')->hasChildOfChar('o')->data == 'o');
	REQUIRE(!root->hasChildOfChar('l')->hasChildOfChar('o')->isFinal);

	REQUIRE(root->hasChildOfChar('l')->hasChildOfChar('o')->hasChildOfChar('v') != nullptr);
	REQUIRE(root->hasChildOfChar('l')->hasChildOfChar('o')->hasChildOfChar('v')->data == 'v');
	REQUIRE(!root->hasChildOfChar('l')->hasChildOfChar('o')->hasChildOfChar('v')->isFinal);

	REQUIRE(root->hasChildOfChar('l')->hasChildOfChar('o')->hasChildOfChar('v')->hasChildOfChar('e') != nullptr);
	REQUIRE(root->hasChildOfChar('l')->hasChildOfChar('o')->hasChildOfChar('v')->hasChildOfChar('e')->data == 'e');
	REQUIRE(root->hasChildOfChar('l')->hasChildOfChar('o')->hasChildOfChar('v')->hasChildOfChar('e')->isFinal);

	//checking 'hi'
	REQUIRE(root->hasChildOfChar('h') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->data == 'h');
	REQUIRE(!root->isFinal);

	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('i') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('i')->data == 'i');
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('i')->isFinal);
}

TEST_CASE( "Testing the remove call in the tree", "[single-file]" )
{
	TrieOrPrefixTree r;
	NodeOfTrieOrPrefixTree *root = r.getRoot();
	REQUIRE(root != nullptr);
	
	r.insert("home");
	r.insert("homeless");
	r.insert("love");
	r.insert("hi");
	
	root = r.getRoot();
	REQUIRE(root != nullptr);

	REQUIRE(root->hasChildOfChar('h') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->data == 'h');
	REQUIRE(!root->isFinal);

	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->data == 'o');
	REQUIRE(!root->hasChildOfChar('h')->hasChildOfChar('o')->isFinal);

	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->data == 'm');
	REQUIRE(!root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->isFinal);

	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->hasChildOfChar('e') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->hasChildOfChar('e')->data == 'e');
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->hasChildOfChar('e')->isFinal);

	NodeOfTrieOrPrefixTree *nodeEOfHome = root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->hasChildOfChar('e');
	REQUIRE(nodeEOfHome->data == 'e');

	REQUIRE(nodeEOfHome->hasChildOfChar('l') != nullptr);
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->data == 'l');
	REQUIRE(!nodeEOfHome->hasChildOfChar('l')->isFinal);

	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e') != nullptr);
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->data == 'e');
	REQUIRE(!nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->isFinal);

	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s') != nullptr);
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->data == 's');
	REQUIRE(!nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->isFinal);

	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->hasChildOfChar('s') != nullptr);
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->hasChildOfChar('s')->data == 's');
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->hasChildOfChar('s')->isFinal);

	//checking 'love'
	REQUIRE(root->hasChildOfChar('l') != nullptr);
	REQUIRE(root->hasChildOfChar('l')->data == 'l');
	REQUIRE(!root->isFinal);

	REQUIRE(root->hasChildOfChar('l')->hasChildOfChar('o') != nullptr);
	REQUIRE(root->hasChildOfChar('l')->hasChildOfChar('o')->data == 'o');
	REQUIRE(!root->hasChildOfChar('l')->hasChildOfChar('o')->isFinal);

	REQUIRE(root->hasChildOfChar('l')->hasChildOfChar('o')->hasChildOfChar('v') != nullptr);
	REQUIRE(root->hasChildOfChar('l')->hasChildOfChar('o')->hasChildOfChar('v')->data == 'v');
	REQUIRE(!root->hasChildOfChar('l')->hasChildOfChar('o')->hasChildOfChar('v')->isFinal);

	REQUIRE(root->hasChildOfChar('l')->hasChildOfChar('o')->hasChildOfChar('v')->hasChildOfChar('e') != nullptr);
	REQUIRE(root->hasChildOfChar('l')->hasChildOfChar('o')->hasChildOfChar('v')->hasChildOfChar('e')->data == 'e');
	REQUIRE(root->hasChildOfChar('l')->hasChildOfChar('o')->hasChildOfChar('v')->hasChildOfChar('e')->isFinal);

	//checking 'hi'
	REQUIRE(root->hasChildOfChar('h') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->data == 'h');
	REQUIRE(!root->isFinal);

	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('i') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('i')->data == 'i');
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('i')->isFinal);
	
	REQUIRE(r.remove("hi"));
	
	root = r.getRoot();
	REQUIRE(root != nullptr);

	REQUIRE(root->hasChildOfChar('h') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->data == 'h');
	REQUIRE(!root->isFinal);

	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->data == 'o');
	REQUIRE(!root->hasChildOfChar('h')->hasChildOfChar('o')->isFinal);

	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->data == 'm');
	REQUIRE(!root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->isFinal);

	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->hasChildOfChar('e') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->hasChildOfChar('e')->data == 'e');
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->hasChildOfChar('e')->isFinal);

	nodeEOfHome = root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->hasChildOfChar('e');
	REQUIRE(nodeEOfHome->data == 'e');

	REQUIRE(nodeEOfHome->hasChildOfChar('l') != nullptr);
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->data == 'l');
	REQUIRE(!nodeEOfHome->hasChildOfChar('l')->isFinal);

	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e') != nullptr);
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->data == 'e');
	REQUIRE(!nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->isFinal);

	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s') != nullptr);
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->data == 's');
	REQUIRE(!nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->isFinal);

	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->hasChildOfChar('s') != nullptr);
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->hasChildOfChar('s')->data == 's');
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->hasChildOfChar('s')->isFinal);

	//checking 'love'
	REQUIRE(root->hasChildOfChar('l') != nullptr);
	REQUIRE(root->hasChildOfChar('l')->data == 'l');
	REQUIRE(!root->isFinal);

	REQUIRE(root->hasChildOfChar('l')->hasChildOfChar('o') != nullptr);
	REQUIRE(root->hasChildOfChar('l')->hasChildOfChar('o')->data == 'o');
	REQUIRE(!root->hasChildOfChar('l')->hasChildOfChar('o')->isFinal);

	REQUIRE(root->hasChildOfChar('l')->hasChildOfChar('o')->hasChildOfChar('v') != nullptr);
	REQUIRE(root->hasChildOfChar('l')->hasChildOfChar('o')->hasChildOfChar('v')->data == 'v');
	REQUIRE(!root->hasChildOfChar('l')->hasChildOfChar('o')->hasChildOfChar('v')->isFinal);

	REQUIRE(root->hasChildOfChar('l')->hasChildOfChar('o')->hasChildOfChar('v')->hasChildOfChar('e') != nullptr);
	REQUIRE(root->hasChildOfChar('l')->hasChildOfChar('o')->hasChildOfChar('v')->hasChildOfChar('e')->data == 'e');
	REQUIRE(root->hasChildOfChar('l')->hasChildOfChar('o')->hasChildOfChar('v')->hasChildOfChar('e')->isFinal);
	
	REQUIRE(r.remove("love"));
	
	root = r.getRoot();
	REQUIRE(root != nullptr);

	REQUIRE(root->hasChildOfChar('h') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->data == 'h');
	REQUIRE(!root->isFinal);

	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->data == 'o');
	REQUIRE(!root->hasChildOfChar('h')->hasChildOfChar('o')->isFinal);

	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->data == 'm');
	REQUIRE(!root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->isFinal);

	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->hasChildOfChar('e') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->hasChildOfChar('e')->data == 'e');
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->hasChildOfChar('e')->isFinal);

	nodeEOfHome = root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->hasChildOfChar('e');
	REQUIRE(nodeEOfHome->data == 'e');

	REQUIRE(nodeEOfHome->hasChildOfChar('l') != nullptr);
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->data == 'l');
	REQUIRE(!nodeEOfHome->hasChildOfChar('l')->isFinal);

	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e') != nullptr);
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->data == 'e');
	REQUIRE(!nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->isFinal);

	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s') != nullptr);
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->data == 's');
	REQUIRE(!nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->isFinal);

	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->hasChildOfChar('s') != nullptr);
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->hasChildOfChar('s')->data == 's');
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->hasChildOfChar('s')->isFinal);
	
	REQUIRE(r.remove("home"));
	
	root = r.getRoot();
	REQUIRE(root != nullptr);

	REQUIRE(root->hasChildOfChar('h') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->data == 'h');
	REQUIRE(!root->isFinal);

	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->data == 'o');
	REQUIRE(!root->hasChildOfChar('h')->hasChildOfChar('o')->isFinal);

	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->data == 'm');
	REQUIRE(!root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->isFinal);

	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->hasChildOfChar('e') != nullptr);
	REQUIRE(root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->hasChildOfChar('e')->data == 'e');
	REQUIRE(!root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->hasChildOfChar('e')->isFinal);

	nodeEOfHome = root->hasChildOfChar('h')->hasChildOfChar('o')->hasChildOfChar('m')->hasChildOfChar('e');
	REQUIRE(nodeEOfHome->data == 'e');

	REQUIRE(nodeEOfHome->hasChildOfChar('l') != nullptr);
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->data == 'l');
	REQUIRE(!nodeEOfHome->hasChildOfChar('l')->isFinal);

	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e') != nullptr);
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->data == 'e');
	REQUIRE(!nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->isFinal);

	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s') != nullptr);
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->data == 's');
	REQUIRE(!nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->isFinal);

	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->hasChildOfChar('s') != nullptr);
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->hasChildOfChar('s')->data == 's');
	REQUIRE(nodeEOfHome->hasChildOfChar('l')->hasChildOfChar('e')->hasChildOfChar('s')->hasChildOfChar('s')->isFinal);
	
	REQUIRE(r.remove("homeless"));
	
	root = r.getRoot();
	REQUIRE(root != nullptr);
	
	//it must not have childrens
	REQUIRE(root->hasChildOfChar('h') == nullptr);
	
}

TEST_CASE( "Testing the search call in the tree", "[single-file]" )
{
	TrieOrPrefixTree r;
	NodeOfTrieOrPrefixTree *root = r.getRoot();
	REQUIRE(root != nullptr);
	
	r.insert("home");
	r.insert("homeless");
	r.insert("love");
	r.insert("hi");
	
	REQUIRE(r.search("home") != nullptr);
	REQUIRE(r.search("homeless") != nullptr);
	REQUIRE(r.search("love") != nullptr);
	REQUIRE(r.search("hi") != nullptr);
}

TEST_CASE( "Testing the search and remove calls in the tree", "[single-file]" )
{
	TrieOrPrefixTree r;
	NodeOfTrieOrPrefixTree *root = r.getRoot();
	REQUIRE(root != nullptr);
	
	r.insert("home");
	r.insert("homeless");
	r.insert("love");
	r.insert("hi");
	
	REQUIRE(r.search("home") != nullptr);
	REQUIRE(r.search("homeless") != nullptr);
	REQUIRE(r.search("love") != nullptr);
	REQUIRE(r.search("hi") != nullptr);
	
	REQUIRE(r.remove("love"));
	REQUIRE(r.remove("hi"));
	
	REQUIRE(r.search("home") != nullptr);
	REQUIRE(r.search("homeless") != nullptr);
	REQUIRE(r.search("love") == nullptr);
	REQUIRE(r.search("hi") == nullptr);
}
