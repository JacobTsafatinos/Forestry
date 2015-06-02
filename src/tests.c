#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "binaryTree.h"

/* areEqual tests */
TEST_CASE("areEqual tests", "[areEqual]" ) {
    // empty trees are equal
    REQUIRE(areEqual(NULL, NULL) == 1);
    // single node equal
    REQUIRE(areEqual(newNode(1), newNode(1)) == 1);
    // single node not equal
    REQUIRE(areEqual(newNode(1), newNode(2)) == 0);
    // full tree of height 3
    REQUIRE(areEqual(newNode(4, newNode(2, newNode(1), newNode(3)), newNode(6, newNode(5), newNode(7))),
                     newNode(4, newNode(2, newNode(1), newNode(3)), newNode(6, newNode(5), newNode(7)))) == 1);
    // two big trees that have copy nodes
    struct Node *tree1 = bigTree(100, 1);
    struct Node *tree2 = bigTree(100, 1);
    REQUIRE(areEqual(tree1, tree2));
}

/* isBalanced tests */
TEST_CASE("isBalanced tests", "[isBalanced]" ) {
    // empty tree is balanced
    REQUIRE(isBalanced(NULL) == 1);
    // full tree of height 1 is balanced
    REQUIRE(isBalanced(newNode(1, newNode(2), newNode(3))) == 1);
    // three node path is not balanced
    REQUIRE(isBalanced(newNode(1, newNode(2, newNode(3), NULL), NULL)) == 0);
    // check speed on big tree of copies
    REQUIRE(isBalanced(bigTree(100, 1)) == 1);
}

/* search on value tests */
TEST_CASE("search with integer input tests", "[search]") {
    struct Node *small = newNode(1);
    struct Node *medium = newNode(5);
    // search on an empty tree
    REQUIRE(search(NULL, 1) == NULL);
    // search on single node tree
    REQUIRE(search(small, 1) == small);
    // unsuccessful search on a single node tree
    REQUIRE(search(small, 2) == NULL);
    // search on a path
    REQUIRE(search(newNode(3, newNode(2, small, NULL), NULL), 1) == small);
    // search on full tree of height 2
    REQUIRE(search(newNode(4, newNode(2, newNode(1), newNode(3)), newNode(6, medium, newNode(7))), 5) == medium);
}
