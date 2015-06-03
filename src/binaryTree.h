struct Node {
    int value;
    Node *r;
    Node *l;
};

/* CONSTRUCTORS */
struct Node *newNode(int value);
struct Node *newNode(int value, struct Node *l, struct Node *r);
struct Node *bigTree(int height, int value);

/* BASIC METHODS */
void insertSearch(Node *root, Node *node);
void insertSearch(Node *root, int value);
struct Node *search(Node *root, int value);
bool deleteSearch(Node *root, int value);

/* OTHER */
bool areEqual(Node *rootA, Node *rootB);
bool isBalanced(Node *root);
