#include <iostream>
class Node {
    int data; 
    Node * next; 
public:
    Node(Node * next, int data) {
        this->next = next; 
        this->data = data;
    }

    Node(int data) {
        this->next = NULL; 
        this->data = data;
    }

    int get_data() {
        return this->data;
    }

    Node * get_next() {
        return this->next;
    }

    void set_next(Node * node) {
        this->next = node;
    }
};

class LinkedList {
    Node * head;

    Node * find_predecessor(Node * node, int data) {
        if (node == NULL || node->get_next() == NULL) {
            std::cout << "Could not find element" << std::endl;
            return NULL;
        }

        if (node->get_next()->get_data() == data) {
            return node;
        } else {
            return find_predecessor(node->get_next(), data);
        }
    }
public: 
    LinkedList(int data) {
        Node * new_head = new Node(data);
        this->head = new_head;
    }

    void insert(int data) {
        Node * new_node = new Node(this->head, data);
        this->head = new_node; 
    }

    void del(int data) { 
        Node * predecessor = find_predecessor(this->head, data);
        if (predecessor == NULL) {
            return;
        }

        Node * to_delete = predecessor->get_next();
        predecessor->set_next(to_delete->get_next());
        delete to_delete;
    }

    Node * search(Node * node, int data) {
        if (node == NULL) {
            return NULL;
        }

        if (node->get_data() == data) {
            return node; 
        } else {
            return this->search(node->get_next(), data);
        }
    }

    void print() {
        if (this->head == NULL)
        {
            printf("Not printing anything\n");
            return;
        }

        Node * next;
        next = this->head;

        while (next != NULL)
        {
            std::cout << next->get_data() << " ";
            next = next->get_next();
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList list(5);
    list.insert(12);
    list.insert(18);
    list.insert(22);
    list.print();
    list.del(12);
    list.print();

    return 0;
}