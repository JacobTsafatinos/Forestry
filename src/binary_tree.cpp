#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <stdio.h>
#include "catch.hpp"

// Node struct for binary tree
struct Node {
    int value;
    Node *r;
    Node *l;
};

// constructs a new node and returns a pointer to it
struct Node *newNode(int value) {
    struct Node* node = new(struct Node);
    node->value = value;
    node->r = NULL;
    node->l = NULL;

    return node;
}

struct Node *newNode(int value, struct Node *r, struct Node *l) {
    struct Node *node = newNode(value);
    node->r = r;
    node->l = l;

    return node;
}

/* BASIC METHODS */

/* Inserting node into a search tree */
void insert(Node *root, Node *node) {
    if (!(root)) {
        root->value = node->value;
    }
    else if(root->value >= node->value) {
        if(root->r) {
            insert(root->r, node);
        }
        else {
            root->r = node;
        }
    }
    else {
        if(root->l) {
            insert(root->l, node);
        }
        else {
            root->r = node;
        }
    }
}

/* Inserting value into a search tree */
void insert(Node *root, int value) {
    Node *node = newNode(value);
    insert(root, node);
}

/* OTHER */

bool areEqual(Node *rootA, Node *rootB) {
    if(!(rootA) || !(rootB)) {
        return 1;
    }
    if (rootA->value == rootB->value) {
        if (rootA->r && rootB->r && rootA->l && rootB->l) {
            return areEqual(rootA->r, rootB->r) && areEqual(rootA->l, rootB->l);
        } else if (rootA->r && rootB->r && !(rootA->l) && !(rootB->l)) {
            return areEqual(rootA->r, rootB->r);
        } else if (!(rootA->r) && !(rootB->r) && rootA->l && rootB->l) {
            return areEqual(rootA->l, rootB->l);
        } else if (!(rootA->r) && !(rootB->r) && !(rootA->l) && !(rootB->l)) {
            return 1;
        }
    }
    return 0;
}

bool isBalanced(Node *root) {
    if(!(root)) {
        return 1;
    }
    else if(!(root->l) && !(root->r)) {
        return 1;
    } else if(!(root->l) && root->r) {
        return !(root->r->r) && !(root->r->l);
    } else if(root->l && !(root->r)) {
        return !(root->l->r) && !(root->l->l);
    } else {
        return isBalanced(root->l) && isBalanced(root->r);
    }
}


/* TESTS */

/* areEqual tests */
TEST_CASE( "areEqual tests", "[areEqual]" ) {
    // empty trees are equal
    REQUIRE(areEqual(NULL, NULL) == 1);
    // single node equal
    REQUIRE(areEqual(newNode(1), newNode(1)) == 1);
    // single node not equal
    REQUIRE(areEqual(newNode(1), newNode(2)) == 0);
}

/* isBalanced tests */
TEST_CASE( "isBalanced tests", "[isBalanced]" ) {
    // empty tree is balanced
    REQUIRE(isBalanced(NULL) == 1);
    // full tree of height 1 is balanced
    REQUIRE(isBalanced(newNode(1, newNode(2), newNode(3))) == 1);
    // three node path is not balanced
    REQUIRE(isBalanced(newNode(1, newNode(2, newNode(3), NULL), NULL)) == 0);
}
