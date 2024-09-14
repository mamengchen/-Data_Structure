#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

const int MAX_LEVEL = 16;  // 跳表的最大层数
const float P = 0.5;       // 用于随机生成层数的概率

// 节点结构体
struct Node {
    int key;
    std::vector<Node*> forward;  // 每个节点的forward数组，表示该节点在不同层的下一个节点

    Node(int key, int level) : key(key), forward(level, nullptr) {}
};

// 跳表类
class SkipList {
public:
    SkipList() : level(0), header(new Node(-1, MAX_LEVEL)) {
        std::srand(std::time(nullptr));  // 初始化随机数生成器
    }

    ~SkipList() {
        Node* node = header;
        while (node) {
            Node* next = node->forward[0];
            delete node;
            node = next;
        }
    }

    // 查找操作
    Node* search(int key) {
        Node* x = header;
        for (int i = level; i >= 0; --i) {
            while (x->forward[i] && x->forward[i]->key < key) {
                x = x->forward[i];
            }
        }
        x = x->forward[0];
        if (x && x->key == key) {
            return x;
        }
        return nullptr;
    }

    // 插入操作
    void insert(int key) {
        std::vector<Node*> update(MAX_LEVEL);
        Node* x = header;

        for (int i = level; i >= 0; --i) {
            while (x->forward[i] && x->forward[i]->key < key) {
                x = x->forward[i];
            }
            update[i] = x;
        }

        x = x->forward[0];

        if (!x || x->key != key) {
            int newLevel = randomLevel();

            if (newLevel > level) {
                for (int i = level + 1; i <= newLevel; ++i) {
                    update[i] = header;
                }
                level = newLevel;
            }

            Node* newNode = new Node(key, newLevel + 1);
            for (int i = 0; i <= newLevel; ++i) {
                newNode->forward[i] = update[i]->forward[i];
                update[i]->forward[i] = newNode;
            }
        }
    }

    // 删除操作
    void erase(int key) {
        std::vector<Node*> update(MAX_LEVEL);
        Node* x = header;

        for (int i = level; i >= 0; --i) {
            while (x->forward[i] && x->forward[i]->key < key) {
                x = x->forward[i];
            }
            update[i] = x;
        }

        x = x->forward[0];

        if (x && x->key == key) {
            for (int i = 0; i <= level; ++i) {
                if (update[i]->forward[i] != x) {
                    break;
                }
                update[i]->forward[i] = x->forward[i];
            }

            delete x;

            while (level > 0 && !header->forward[level]) {
                --level;
            }
        }
    }

private:
    int level;
    Node* header;

    // 随机生成层数
    int randomLevel() {
        int lvl = 0;
        while (std::rand() / double(RAND_MAX) < P && lvl < MAX_LEVEL - 1) {
            ++lvl;
        }
        return lvl;
    }
};

int main() {
    SkipList skipList;

    skipList.insert(3);
    skipList.insert(6);
    skipList.insert(7);
    skipList.insert(9);
    skipList.insert(12);
    skipList.insert(19);
    skipList.insert(17);
    skipList.insert(26);

    std::cout << "Searching for 19: " << (skipList.search(19) ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching for 15: " << (skipList.search(15) ? "Found" : "Not Found") << std::endl;

    skipList.erase(19);
    std::cout << "After deleting 19, searching for 19: " << (skipList.search(19) ? "Found" : "Not Found") << std::endl;

    return 0;
}
