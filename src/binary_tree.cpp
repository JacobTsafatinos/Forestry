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
    if(!(rootA) || !(rootB))
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

TEST_CASE( "Empty tree is balenced", "[isBalanced]" ) {
    REQUIRE( isBalanced(NULL) == 1 );
}
TEST_CASE( "Full tree of height 1 is balanced", "[isBalanced]" ) {
    Node *a, *b, *c;
    a = newNode(1);
    b = newNode(2);
    c = newNode(3);
    b->r = a;
    b->l = c;
    REQUIRE( isBalanced(b) == 1 );
}
TEST_CASE( "Three node path not balanced", "[isBalanced]" ) {
    Node *a, *b, *c;
    a = newNode(1);
    b = newNode(2);
    c = newNode(3);
    a->r = b;
    b->r = c;
    REQUIRE( isBalanced(a) == 0 );
}


