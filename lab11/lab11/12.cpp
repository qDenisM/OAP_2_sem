#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

void inOrder(Node* root) {
    if (root == nullptr)
        return;

    inOrder(root->left);
    cout << root->key << " ";
    inOrder(root->right);
}

int countEvenKeys(Node* root) {
    if (root == nullptr)
        return 0;

    int count = (root->key % 2 == 0) ? 1 : 0;
    count += countEvenKeys(root->left);
    count += countEvenKeys(root->right);

    return count;
}

void printMenu() {
    cout << "Меню:\n";
    cout << "1. Добавить ключ в дерево\n";
    cout << "2. Вывести дерево в порядке возрастания ключей\n";
    cout << "3. Посчитать количество узлов с четными ключами\n";
    cout << "4. Выйти из программы\n";
    cout << "Выберите операцию: ";
}

void handleMenu(Node*& root) {
    int choice;
    do {
        printMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            int key;
            cout << "Введите ключ: ";
            cin >> key;
            root = insert(root, key);
            break;
        case 2:
            cout << "Дерево в порядке возрастания ключей: ";
            inOrder(root);
            cout << endl;
            break;
        case 3:
            cout << "Количество узлов с четными ключами: " << countEvenKeys(root) << endl;
            break;
        case 4:
            cout << "Выход из программы...\n";
            break;
        default:
            cout << "Некорректный ввод. Попробуйте еще раз.\n";
            break;
        }
    } while (choice != 4);
}

int main() {
    setlocale(LC_ALL, "ru");
    Node* root = nullptr;
    handleMenu(root);
    return 0;
}
