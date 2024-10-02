/************************************
 Nombres: JULIANA PACHECO, DANIEL GONZALES, NICOLAS ALGARA
 TEMA: TALLER ARBOLES
 FECHA: 24/09/2024
 ***********************************/
#include <iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;

    // Constructor
    Node(int data) {
        this->data = data;
        left = right = parent = nullptr;
        this->color = RED;
    }
};

class RedBlackTree {
private:
    Node *root;

protected:
    // Rotaciones y balanceo
    void rotateLeft(Node *&, Node *&);
    void rotateRight(Node *&, Node *&);
    void fixViolation(Node *&, Node *&);

public:
    // Constructor
    RedBlackTree() { root = nullptr; }

    void insert(const int &n);
    void inorder();
    void inorderHelper(Node *node);
    Node* getRoot() { return root; }
};

// Rotación a la izquierda
void RedBlackTree::rotateLeft(Node *&root, Node *&pt) {
    Node *pt_right = pt->right;

    pt->right = pt_right->left;

    if (pt->right != nullptr)
        pt->right->parent = pt;

    pt_right->parent = pt->parent;

    if (pt->parent == nullptr)
        root = pt_right;
    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;
    else
        pt->parent->right = pt_right;

    pt_right->left = pt;
    pt->parent = pt_right;
}

// Rotación a la derecha
void RedBlackTree::rotateRight(Node *&root, Node *&pt) {
    Node *pt_left = pt->left;

    pt->left = pt_left->right;

    if (pt->left != nullptr)
        pt->left->parent = pt;

    pt_left->parent = pt->parent;

    if (pt->parent == nullptr)
        root = pt_left;
    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;
    else
        pt->parent->right = pt_left;

    pt_left->right = pt;
    pt->parent = pt_left;
}

// Insertar un nodo
void RedBlackTree::insert(const int &data) {
    Node *pt = new Node(data);

    // Procedimiento de inserción estándar de árbol binario
    if (root == nullptr) {
        root = pt;
        pt->color = BLACK;  // La raíz siempre debe ser negra
    } else {
        Node *parent = nullptr, *current = root;

        while (current != nullptr) {
            parent = current;
            if (pt->data < current->data)
                current = current->left;
            else
                current = current->right;
        }

        pt->parent = parent;

        if (pt->data < parent->data)
            parent->left = pt;
        else
            parent->right = pt;

        fixViolation(root, pt);  // Arreglar las violaciones del árbol Red-Black
    }
}

// Arreglar las violaciones del árbol Red-Black
void RedBlackTree::fixViolation(Node *&root, Node *&pt) {
    Node *parent_pt = nullptr;
    Node *grand_parent_pt = nullptr;

    while ((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED)) {
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        // El padre de pt es el hijo izquierdo del abuelo de pt
        if (parent_pt == grand_parent_pt->left) {
            Node *uncle_pt = grand_parent_pt->right;

            // Caso 1: El tío de pt también es rojo
            if (uncle_pt != nullptr && uncle_pt->color == RED) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                // Caso 2: pt es el hijo derecho de su padre
                if (pt == parent_pt->right) {
                    rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                // Caso 3: pt es el hijo izquierdo de su padre
                rotateRight(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
        // El padre de pt es el hijo derecho del abuelo de pt
        else {
            Node *uncle_pt = grand_parent_pt->left;

            // Caso 1: El tío de pt también es rojo
            if (uncle_pt != nullptr && uncle_pt->color == RED) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                // Caso 2: pt es el hijo izquierdo de su padre
                if (pt == parent_pt->left) {
                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                // Caso 3: pt es el hijo derecho de su padre
                rotateLeft(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }

    root->color = BLACK;
}

// Recorrido en orden
void RedBlackTree::inorder() { inorderHelper(root); }

void RedBlackTree::inorderHelper(Node *root) {
    if (root == nullptr)
        return;

    inorderHelper(root->left);
    cout << root->data << " ";
    inorderHelper(root->right);
}

// Programa principal para probar el árbol Red-Black
int main() {
    RedBlackTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    cout << "Recorrido en orden del árbol Red-Black:\n";
    tree.inorder();

    return 0;
}
