#include "BinarySearchTree.h"


using namespace std;

int main() {
    // Создаем новое бинарное дерево поиска
    BinarySearchTree tree;

    // Вставляем значения в дерево
    tree.insert(8);
    tree.insert(3);
    tree.insert(10);
    tree.insert(1);
    tree.insert(6);
    tree.insert(14);
    tree.insert(4);
    tree.insert(7);
    tree.insert(13);

    // Печатаем исходное дерево
    tree.print();

    // Проверяем, что значения находятся в дереве
    cout << "Search 3: " << tree.search(3) << endl;
    cout << "Search 9: " << tree.search(9) << endl;

    // Удаляем значение из дерева
    tree.remove(3);

    // Проверяем, что значение удалено
    cout << "Search 3: " << tree.search(3) << endl;

    // Печатаем измененное дерево
    tree.print();

    return 0;
}
