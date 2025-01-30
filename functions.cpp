#include<iostream>
#include"Header.h"

using namespace std;

int AVLTree:: height(Node* n) {
    return n ? n->height : 0;
}

int AVLTree::balanceFactor(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

AVLTree::Node* AVLTree::rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}
AVLTree::Node* AVLTree::leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

AVLTree::Node* AVLTree::leftRightRotate(Node* node) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
}

AVLTree::Node* AVLTree::rightLeftRotate(Node* node) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
}


AVLTree::Node* AVLTree::insert(Node* node, int key) {
    if (!node)
        return new Node(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = balanceFactor(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key)
        return leftRightRotate(node);

    // Right Left Case
    if (balance < -1 && key < node->right->key)
        return rightLeftRotate(node);

    return node;
}

AVLTree::Node* AVLTree::minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}


AVLTree::Node* AVLTree::maxValueNode(Node* node) {
    Node* current = node;
    while (current->right != nullptr)
        current = current->right;
    return current;
}



// 2. Deletion:
AVLTree::Node* AVLTree::deleteNode(Node* root, int key) {
    if (!root)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = nullptr;
            }
            else
                *root = *temp;
            delete temp;
        }
        else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (!root)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = balanceFactor(root);

    // Left Left Case
    if (balance > 1 && balanceFactor(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && balanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && balanceFactor(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && balanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}


// 3. Searching:
AVLTree::Node* AVLTree::search(Node* root, int key) {
    if (root == nullptr || root->key == key)
        return root;
    if (root->key < key)
        return search(root->right, key);
    return search(root->left, key);
}

int AVLTree::max(int a, int b) {
    return (a > b) ? a : b;
}

int AVLTree::height(Node* node, int* diameter) {
    if (node == nullptr)
        return 0;

    int left_height = height(node->left, diameter);
    int right_height = height(node->right, diameter);

    int max_diameter = left_height + right_height;
    if (max_diameter > *diameter)
        *diameter = max_diameter;

    return max(left_height, right_height) + 1;
}

int AVLTree::diameter(Node* node) {
    int diameter = 0;
    height(node, &diameter);
    return diameter;
}

AVLTree::Node* AVLTree::successor(Node* root, Node* n) {
    if (n->right != nullptr)
        return minValueNode(n->right);

    Node* succ = nullptr;
    while (root != nullptr) {
        if (n->key < root->key) {
            succ = root;
            root = root->left;
        }
        else if (n->key > root->key) {
            root = root->right;
        }
        else
            break;
    }
    return succ;
}

AVLTree::Node* AVLTree::predecessor(Node* root, Node* n) {
    if (n->left != nullptr)
        return maxValueNode(n->left);

    Node* pred = nullptr;
    while (root != nullptr) {
        if (n->key < root->key) {
            root = root->left;
        }
        else if (n->key > root->key) {
            pred = root;
            root = root->right;
        }
        else
            break;
    }
    return pred;
}

// 4. Traversals:
void AVLTree::preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void AVLTree::inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

void AVLTree::postOrder(Node* root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->key << " ";
    }
}


   

    void AVLTree::insert(int key) {
        root = insert(root, key);
    }

    void AVLTree::deleteKey(int key) {
        root = deleteNode(root, key);
    }

    bool AVLTree::search(int key) {
        return search(root, key) != nullptr;
    }

    void AVLTree::preOrder() {
        preOrder(root);
    }

    void AVLTree::inOrder() {
        inOrder(root);
    }

    void AVLTree::postOrder() {
        postOrder(root);
    }
    int AVLTree::findMin() {
        Node* node = minValueNode(root);
        return node ? node->key : -1;
    }

    int AVLTree::findMax() {
        Node* node = maxValueNode(root);
        return node ? node->key : -1;
    }

    int AVLTree::getDiameter() {
        return diameter(root);
    }

    int AVLTree::getSuccessor(int key) {
        Node* node = search(root, key);
        if (node) {
            Node* succ = successor(root, node);
            return succ ? succ->key : -1;
        }
        return -1;
    }

    int AVLTree::getPredecessor(int key) {
        Node* node = search(root, key);
        if (node) {
            Node* pred = predecessor(root, node);
            return pred ? pred->key : -1;
        }
        return -1;
    }