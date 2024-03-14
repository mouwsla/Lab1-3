#include <iostream>
#include <algorithm>

using namespace std;

// Структура для узла дерева
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

// Функция для создания нового узла
Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1; // Начальная высота узла - 1
    return node;
}

// Функция для вычисления высоты узла
int height(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

// Функция для выполнения правого поворота в поддереве с корнем y
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* temp = x->right; // временная переменная для хранения ссылки на правое поддерево x

    // Поворот
    x->right = y;
    y->left = temp;

    // Обновление высоты узлов
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Возвращает новый корень поддерева
    return x;
}

// Функция для выполнения левого поворота в поддереве с корнем x
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* temp = y->left; // временная переменная для хранения ссылки на левое поддерево y

    // Поворот
    y->left = x;
    x->right = temp;

    // Обновление высоты узлов
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Возвращает новый корень поддерева
    return y;
}

// Функция для получения баланса узла
int getBalance(Node* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

// Функция для вставки ключа в AVL дерево
Node* insert(Node* node, int key) {
    // 1. Обычная вставка BST
    if (node == nullptr)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Игнорируем дубликаты ключей
        return node;

    // 2. Обновляем высоту текущего узла
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. Получаем баланс узла
    int balance = getBalance(node);

    // Если узел несбалансирован, то есть 4 возможных случая:

    // LL случай
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // RR случай
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // LR случай
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL случай
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Узел сбалансирован
    return node;
}

// Функция для обхода дерева в прямом порядке (inorder traversal)
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main() {
    setlocale(LC_ALL,"");
    Node* root = nullptr;

    int numKeys;
    cout << "Введите количество ключей для вставки: \n";
    cin >> numKeys;

    cout << "Введите ключи для вставки в дерево AVL: \n";
    for (int i = 0; i < numKeys; ++i) {
        int key;
        cin >> key;
        root = insert(root, key);
    }

    cout << "Oбход построенного AVL-дерева: \n";
    inorder(root);
    cout << endl;

    return 0;
}
