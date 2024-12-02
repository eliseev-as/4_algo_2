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
    void insert(int value) {
        root = insert(root, value);
    }

    // Публичный метод для удаления значения из дерева
    void remove(int value) {
        root = remove(root, value);
    }

    // Публичный метод для поиска значения в дереве
    int search(int value) {
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
        Node(int value) : value(value), left(nullptr), right(nullptr) {
        }
    };

    Node *root; // Корень дерева

    // Приватный метод для вставки нового значения в дерево
    Node *insert(Node *root, int value) {
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

    // Приватный метод для удаления значения из дерева
    Node *remove(Node *root, int value) {
    }

    // Приватный метод для поиска значения в дереве
    Node *search(Node *root, int value) {
    }

    // Приватный метод для печати узлов дерева в порядке возрастания
    void inorder() {
    }
};


#endif //BINARYSEARCHTREE_H
