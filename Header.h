#include<iostream>
using namespace std;


class AVLTree {
    struct Node {
        int key;
        Node* left;
        Node* right;
        int height;
        Node(int k) {

            key = k;
            left = nullptr;
            right = nullptr;
            height = 1;
        }
    };

    Node* root;

    int height(Node* n);

    // 1. Insertion:
    Node* insert(Node* node, int key);


    // 2. Deletion:
    Node* deleteNode(Node* root, int key);

    // 3. Searching:
    Node* search(Node* root, int key);

    // 4. Traversals:
    void preOrder(Node* root);

    void inOrder(Node* root);

    void postOrder(Node* root);


    // 5. Balancing Factor Calculations:
    int balanceFactor(Node* n);

    // 6. Rotation Operations:
    Node* rightRotate(Node* y);

    Node* leftRotate(Node* x);

    Node* leftRightRotate(Node* node);

    Node* rightLeftRotate(Node* node);

    int diameter(Node* node);

  

    Node* minValueNode(Node* node);


    Node* maxValueNode(Node* node);


    Node* successor(Node* root, Node* n);

    Node* predecessor(Node* root, Node* n);



   

    int max(int a, int b);

    int height(Node* node, int* diameter);

   
   
  

public:
    AVLTree() {
        root = nullptr;
    }

    void insert(int key);

    void deleteKey(int key);

    bool search(int key);

    void preOrder();

    void inOrder();

    void postOrder();

    int findMin();

    int findMax();

    int getDiameter();

    int getSuccessor(int key);

    int getPredecessor(int key);
};

