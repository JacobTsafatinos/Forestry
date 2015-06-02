#include <stdio.h>
#include "binaryTree.h"

/* Constructors */

// constructs a new node and returns a pointer to it
struct Node *newNode(int value) {
    struct Node* node = new(struct Node);
    node->value = value;
    node->r = NULL;
    node->l = NULL;

    return node;
}

struct Node *newNode(int value, struct Node *l, struct Node *r) {
    struct Node *node = newNode(value);
    node->l = l;
    node->r = r;

    return node;
}

struct Node *bigTree(int height, int value) {
    if (height == 0) {
        return newNode(value);
    } 
    struct Node *node = bigTree(--height, value);
    return newNode(value, node, node);
}


/* BASIC METHODS */

/* Inserting node into a search tree */
void insertSearch(Node *root, Node *node) {
    if (!(root)) {
        root->value = node->value;
    }
    else if(root->value < node->value) {
        if(root->r) {
            insertSearch(root->r, node);
        }
        else {
            root->r = node;
        }
    }
    else {
        if(root->l) {
            insertSearch(root->l, node);
        }
        else {
            root->r = node;
        }
    }
}

/* Inserting value into a search tree */
void insertSearch(Node *root, int value) {
    Node *node = newNode(value);
    insertSearch(root, node);
}

/* Search for a node in a search tree */
struct Node *search(Node *root, int value) {
    if (!(root)) {
        return NULL;
    }
    else if(root->value == value) {
        return root;
    } else if(root->value < value) {
        return search(root->r, value);
    } else {
        return search(root->l, value);
    }
}

bool deleteSearch(Node *root, int value) {
    struct Node *node;
    if ((node = search(root, value))) {
        delete node;
        return 1;
    }
    return 0;
}

/* OTHER */

/* Checks if any two binary trees share the same structure and values */
bool areEqual(Node *rootA, Node *rootB) {
    // two empty trees are equal
    if(!(rootA) || !(rootB)) {
        return 1;
    }
    // if root values are the same
    if (rootA->value == rootB->value) {
        // if both trees have both children
        if (rootA->r && rootB->r && rootA->l && rootB->l) {
            // if both trees only have one unique child check only one
            if(rootA->r == rootA->l && rootB->l == rootB->r) {
                return areEqual(rootA->r, rootB->r);
            }
            return areEqual(rootA->r, rootB->r) && areEqual(rootA->l, rootB->l);
        // if only right subtree exists
        } else if (rootA->r && rootB->r && !(rootA->l) && !(rootB->l)) {
            return areEqual(rootA->r, rootB->r);
        // if only left subtree exists
        } else if (!(rootA->r) && !(rootB->r) && rootA->l && rootB->l) {
            return areEqual(rootA->l, rootB->l);
        // if neither tree has any children
        } else if (!(rootA->r) && !(rootB->r) && !(rootA->l) && !(rootB->l)) {
            return 1;
        }
    }
    return 0;
}

/* Checks to see if any binary tree is balanced.
 * Every root to leaf path is within 1 of each other */
bool isBalanced(Node *root) {
    // empty tree is balanced
    if(!(root)) {
        return 1;
    // single node is balanced
    } else if(!(root->l) && !(root->r)) {
        return 1;
    // no left subtree; check if right has too much height 
    } else if(!(root->l) && root->r) {
        return !(root->r->r) && !(root->r->l);
    // no right subtree; check if left has too much height 
    } else if(root->l && !(root->r)) {
        return !(root->l->r) && !(root->l->l);
    // check if both subtrees are balanced
    } else {
        // check if both children are the same node
        if(root->l == root->r) {
            return isBalanced(root->r);
        }
        return isBalanced(root->l) && isBalanced(root->r);
    }
}
