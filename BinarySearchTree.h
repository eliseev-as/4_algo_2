//
// Created by Alexander Eliseev on 01.12.2024.
//

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include <ostream>


using namespace std;

class BinarySearchTree {
public:
    // Конструктор для создания пустого дерева
    BinarySearchTree() : root(nullptr) {
    }

    // Публичный метод для вставки нового значения в дерево
    void insert(const int value) {
        root = insert(root, value);
    }

    // Публичный метод для удаления значения из дерева
    void remove(const int value) {
        root = remove(root, value);
    }

    // Публичный метод для поиска значения в дереве
    int search(const int value) {
        return search(root, value) != nullptr;
    }

    // Публичный метод для печати дерева в консоль
    void print() {
        inorder();
        cout << endl;
    }

private:
    // Определение структуры узла дерева
    struct Node {
        int value; // Значение узла
        Node *left; // Указатель на левого потомка
        Node *right; // Указатель на правого потомка

        // Конструктор для создания нового узла с заданным значением
        explicit Node(const int value) : value(value), left(nullptr), right(nullptr) {
        }
    };

    Node *root; // Корень дерева

    // Приватный метод для вставки нового значения в дерево
    Node *insert(Node *root, const int value) {
        // Если дерево пустое, создаем новый корень
        if (root == nullptr) {
            return new Node(value);
        }

        // Если значение меньше значения корня, вставляем его в левое поддерево
        if (value < root->value) {
            root->left = insert(root->left, value);
        }
        // Иначе вставляем его в правое поддерево
        else {
            root->right = insert(root->right, value);
        }

        // Возвращаем новый корень дерева
        return root;
    }

    // Приватный метод для поиска значения в дереве
    Node *search(Node *root, const int value) {
        // Если дерево пустое или значение найдено, возвращаем корень
        if (root == nullptr || root->value == value) {
            return root;
        }

        // Если значение меньше значения корня, ищем его в левом поддереве
        if (value < root->value) {
            return search(root->left, value);
        }

        // Иначе ищем его в правом поддереве
        return search(root->right, value);
    }

    // Приватный метод для нахождения узла с минимальным значением в дереве
    static Node *findMin(Node *root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    // Приватный метод для удаления значения из дерева
    Node *remove(Node *root, const int value) {
        // Если дерево пустое, возвращаем nullptr
        if (root == nullptr) {
            return nullptr;
        }

        // Если значение меньше значения корня, удаляем его из левого поддерева
        if (value < root->value) {
            root->left = remove(root->left, value);
        }
        // Если значение больше значения корня, удаляем его из правого поддерева
        else if (value > root->value) {
            root->right = remove(root->right, value);
        }
        // Иначе удаляем корень
        else {
            // Если у корня нет потомков или только один потомок
            if (root->left == nullptr) {
                Node *temp = root->right;
                delete root;
                return temp;
            }

            if (root->right == nullptr) {
                Node *temp = root->left;
                delete root;
                return temp;
            }

            // Если у корня есть оба потомка

            // Находим узел с минимальным значением в правом поддереве
            const Node *temp = findMin(root->right);
            // Копируем значение этого узла в корень
            root->value = temp->value;
            // Удаляем этот узел из правого поддерева
            root->right = remove(root->right, temp->value);
        }

        // Возвращаем новый корень дерева
        return root;
    }

    // Приватный метод для печати узлов дерева в порядке возрастания
    void inorder() {
        inorderHelper(root);
    }

    // Приватный рекурсивный метод-помощник для печати
    void inorderHelper(const Node *root) {
        // Если дерево не пустое
        if (root != nullptr) {
            // Обходим левое поддерево
            inorderHelper(root->left);
            // Печатаем значение корня
            cout << root->value << ' ';
            // Обходим правое поддерево
            inorderHelper(root->right);
        }
    }
};


#endif //BINARYSEARCHTREE_H
