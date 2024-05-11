#include "Heap.h"
#include <iostream>
#include <queue>

using namespace std;

#define SecondHeapSize 5
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

heap::CMP cmpAAA(void* a1, void* a2) 
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
    heap::CMP
        rc = heap::EQUAL;
    if (A1->x > A2->x)
        rc = heap::GREAT;
    else
        if (A2->x > A1->x)
            rc = heap::LESS;
    return rc;
#undef A2
#undef A1
}

void deleteBST(TreeNode* root)
{
    if (root == nullptr)
        return;

    deleteBST(root->left);
    deleteBST(root->right);
    delete root;
}

void deleteHeap(heap::Heap& minHeap)
{
    for (int i = 0; i < minHeap.size; i++)
    {
        delete (AAA*)minHeap.storage[i];
    }
    delete[] minHeap.storage;
}


void convertBSTToMinHeap(TreeNode* root, heap::Heap& minHeap)
{
    if (root == nullptr)
        return;

    
    convertBSTToMinHeap(root->left, minHeap);

    
    minHeap.insert(new AAA{ root->val });

    
    convertBSTToMinHeap(root->right, minHeap);
}

TreeNode* buildTree()
{
    int val;
    cout << "Введите корень дерева: ";
    cin >> val;
    TreeNode* root = new TreeNode(val);

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode* curr = q.front();
        q.pop();

        int leftVal, rightVal;
        cout << "Введите значение для левого потомка узла " << curr->val << " (или -1, если нет левого потомка): ";
        cin >> leftVal;
        if (leftVal != -1)
        {
            curr->left = new TreeNode(leftVal);
            q.push(curr->left);
        }

        cout << "Введите значение для правого потомка узла " << curr->val << " (или -1, если нет правого потомка): ";
        cin >> rightVal;
        if (rightVal != -1)
        {
            curr->right = new TreeNode(rightVal);
            q.push(curr->right);
        }
    }

    return root;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int choice;
    heap::Heap h1 = heap::create(30, cmpAAA);
    TreeNode* root = nullptr;

    for (;;)
    {
        cout << "1 - вывод кучи на экран" << endl;
        cout << "2 - добавить элемент" << endl;
        cout << "3 - удалить максимальный элемент" << endl;
        cout << "4 - удалить минимальный элемент" << endl;
        cout << "5 - удалить i-тый элемент" << endl;
        cout << "6 - объединить две кучи" << endl;
        cout << "7 - ввести бинарное дерево и преобразовать его в кучу (доп)" << endl;
        cout << "0 - выход" << endl;
        cout << "сделайте выбор" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            h1.scan(0);
            break;
        case 2:
        {
            AAA* a = new AAA;
            cout << "введите ключ" << endl;
            cin >> a->x;
            h1.insert(a);
        }
        break;
        case 3:
            h1.extractMax();
            break;
        case 4:
            h1.extractMin();
            break;
        case 5: 
            printf("Введите номер элемента, который Вы хотите удалить: ");
            int n;
            scanf_s("%d", &n);
            h1.extractI(n);
            break;
        case 6: {
            static heap::Heap h2 = heap::create(30, cmpAAA);
            for (int i = 0; i < SecondHeapSize; i++)
            {
                AAA* b = new AAA;
                b->x = rand() % 20;
                h2.insert(b);
            }
            printf("Вторая куча создана автоматически. Ее содержимое:\n");
            h2.scan(0);
            heap::UnionHeap(&h1, &h2);
            printf("Содержимое итоговой кучи:\n");
            h1.scan(0);
        }
              break;
        
        case 7:
            if (root != nullptr)
            {
                cout << "Дерево уже введено. Перезаписать? (1 - да, 0 - нет): ";
                int overwrite;
                cin >> overwrite;
                if (overwrite == 0)
                    break;
            }
            if (root != nullptr)
                deleteBST(root);
            root = buildTree();
            h1 = heap::create(30, cmpAAA);
            convertBSTToMinHeap(root, h1);
            cout << "Дерево преобразовано в кучу." << endl;
            break;
        default:
            cout << endl << "Введена неверная команда!" << endl;
        }
    }

    if (root != nullptr)
        deleteBST(root);
    deleteHeap(h1);

    return 0;
}
