#include <iostream>
using namespace std;

template <typename K, typename V>
class Map
{

public:

    struct Node
    {
        K key;
        V value;
        Node* next;
        Node(const K& key, const V& value) : key(key), value(value), next(nullptr) {}
    };

    Node* head;
    int size;

    Map() : head(nullptr), size(0) {}

    ~Map()
    {
        Clear();
    }

    V& operator[](const K& key)
    {
        Node* node = head;
        while (node)
        {
            if (node->key == key)
                return node->value;
            node = node->next;
        }
        Node* newNode = new Node(key, V());
        newNode->next = head;
        head = newNode;
        size++;
        return head->value;
    }

    bool Get(const K& key, V& value) const
    {
        Node* node = head;
        while (node)
        {
            if (node->key == key)
            {
                value = node->value;
                return true;
            }
            node = node->next;
        }
        return false;
    }

    void Set(const K& key, const V& value)
    {
        Node* node = head;
        while (node)
        {
            if (node->key == key)
            {
                node->value = value;
                return;
            }
            node = node->next;
        }
        Node* newNode = new Node(key, value);
        newNode->next = head;
        head = newNode;
        size++;
    }

    int Count() const
    {
        return size;
    }

    void Clear()
    {
        Node* node = head;
        while (node)
        {
            Node* temp = node;
            node = node->next;
            delete temp;
        }
        head = nullptr;
        size = 0;
    }

    bool Delete(const K& key)
    {
        Node* node = head;
        Node* prev = nullptr;
        while (node)
        {
            if (node->key == key)
            {
                if (prev)
                {
                    prev->next = node->next;
                }
                else
                {
                    head = node->next;
                }
                delete node;
                size--;
                return true;
            }
            prev = node;
            node = node->next;
        }
        return false;
    }

    bool Includes(const Map<K, V>& map) const
    {
        Node* node = map.head;
        while (node)
        {
            V value;
            if (!Get(node->key, value) || value != node->value)
            {
                return false;
            }
            node = node->next;
        }
        return true;
    }

    class KeyValueIndex {
    public:
        K key;
        V value;
        int index;

        KeyValueIndex(const K& key, const V& value, int index) : key(key), value(value), index(index) {}
    };

    class Iterator {
    private:
        Node* current;
        int index;

    public:
        Iterator(Node* startNode, int startIndex = 0) : current(startNode), index(startIndex) {}

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }

        void operator++() {
            if (current) {
                current = current->next;
                index++;
            }
        }

        KeyValueIndex operator*() const {
            return KeyValueIndex(current->key, current->value, index);
        }
    };

    Iterator begin() const {
        return Iterator(head);
    }

    Iterator end() const {
        return Iterator(nullptr);
    }

    
};

int main()
{
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto iter = m.begin(); iter != m.end(); ++iter)
    {
        auto [key, value, index] = *iter;
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto iter = m.begin(); iter != m.end(); ++iter)
    {
        auto [key, value, index] = *iter;
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;
}
