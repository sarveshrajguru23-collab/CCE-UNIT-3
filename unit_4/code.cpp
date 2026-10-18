
#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int id;
    Node *left;
    Node *right;
};

Node* createNode(int id) {
    Node *n = new Node;
    n->id = id;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Insert a file ID (smaller goes left, larger goes right)
Node* insertNode(Node *root, int id) {
    if (root == NULL) return createNode(id);
    if (id < root->id)
        root->left = insertNode(root->left, id);
    else if (id > root->id)
        root->right = insertNode(root->right, id);
    else
        cout << "  (ID " << id << " already exists, ignored)\n";
    return root;
}

void inorder(Node *root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->id << " ";
    inorder(root->right);
}

void preorder(Node *root) {
    if (root == NULL) return;
    cout << root->id << " ";
    preorder(root->left);
    preorder(root->right);
}

// Check 1: are the two backup structures identical?
bool isIdentical(Node *a, Node *b) {
    if (a == NULL && b == NULL) return true;
    if (a == NULL || b == NULL) return false;
    return (a->id == b->id) &&
           isIdentical(a->left, b->left) &&
           isIdentical(a->right, b->right);
}

// Check 2: is 'sub' a subtree of 'mainTree'?
bool isSubtree(Node *mainTree, Node *sub) {
    if (sub == NULL) return true;
    if (mainTree == NULL) return false;
    if (isIdentical(mainTree, sub)) return true;
    return isSubtree(mainTree->left, sub) || isSubtree(mainTree->right, sub);
}

void freeTree(Node *root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int readInt() {
    int x;
    while (!(cin >> x)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter a number: ";
    }
    return x;
}

Node* buildBackup(int backupNo) {
    cout << "Enter number of file IDs in Backup " << backupNo << ": ";
    int n = readInt();
    while (n < 0) {
        cout << "Count cannot be negative. Try again: ";
        n = readInt();
    }

    Node *root = NULL;
    for (int i = 1; i <= n; i++) {
        cout << "  Enter file ID " << i << ": ";
        int id = readInt();
        root = insertNode(root, id);
    }
    cout << endl;
    return root;
}

void showTree(const char *name, Node *root) {
    cout << name << "\n";
    cout << "  Inorder  : ";
    if (root == NULL) cout << "(empty)"; else inorder(root);
    cout << "\n  Preorder : ";
    if (root == NULL) cout << "(empty)"; else preorder(root);
    cout << "\n\n";
}

int main() {
    cout << "=====================================\n";
    cout << " BACKUP VERIFICATION APPLICATION\n";
    cout << "=====================================\n\n";

    Node *backup1 = buildBackup(1);
    Node *backup2 = buildBackup(2);

    cout << "-------------------------------------\n";
    cout << " BACKUP STRUCTURES\n";
    cout << "-------------------------------------\n";
    showTree("Backup 1:", backup1);
    showTree("Backup 2:", backup2);

    cout << "-------------------------------------\n";
    cout << " VERIFICATION RESULTS\n";
    cout << "-------------------------------------\n";

    if (isIdentical(backup1, backup2))
        cout << "1. Backup 1 and Backup 2 are IDENTICAL.\n";
    else
        cout << "1. Backup 1 and Backup 2 are NOT identical.\n";

    if (isSubtree(backup1, backup2))
        cout << "2. Backup 2 IS a subtree of Backup 1.\n";
    else
        cout << "2. Backup 2 is NOT a subtree of Backup 1.\n";

    if (isSubtree(backup2, backup1))
        cout << "3. Backup 1 IS a subtree of Backup 2.\n";
    else
        cout << "3. Backup 1 is NOT a subtree of Backup 2.\n";

    cout << endl;
    freeTree(backup1);
    freeTree(backup2);

    system("pause");
    return 0;
}
