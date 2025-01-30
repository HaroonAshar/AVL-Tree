#include <iostream>
#include"Header.h"
using namespace std;


int main() {
    AVLTree tree;

    tree.insert(15);
    tree.insert(10);
    tree.insert(20);
    tree.insert(8);
    tree.insert(12);
    tree.insert(17);
    tree.insert(25);

    cout << "Preorder traversal of the AVL tree is: ";
    tree.preOrder();
    cout << endl;
    cout << "Inorder traversal of the AVL tree is: ";
    tree.inOrder();
    cout << endl;
    cout << "Postorder traversal of the AVL tree is; ";
    tree.postOrder();
    cout << endl;

    // Deleting a node
    tree.deleteKey(20);
    cout << "Preorder traversal after deletion of 20: ";
    tree.preOrder();
    cout << endl;
    cout << "Inorder traversal after deletion of 20: ";
    tree.inOrder();
    cout << endl;
    cout << "Postorder traversal after deletion of 20: ";
    tree.postOrder();
    cout << endl;

    // Searching for a node
    cout << "Searching for 15 in the AVL tree: " << (tree.search(15) ? "Found" : "Not Found") << endl;
    cout << "Searching for 30 in the AVL tree: " << (tree.search(30) ? "Found" : "Not Found") << endl;

    // Finding minimum and maximum
    cout << "Minimum value in the AVL tree is " << tree.findMin() << endl;
    cout << "Maximum value in the AVL tree is " << tree.findMax() << endl;

    // Calculating diameter
    cout << "Diameter of the AVL tree is " << tree.getDiameter() << endl;

    // Finding successor and predecessor
    int key = 15;
    cout << "Successor of " << key << " is " << tree.getSuccessor(key) << endl;
    cout << "Predecessor of " << key << " is " << tree.getPredecessor(key) << endl;

    return 0;
}
