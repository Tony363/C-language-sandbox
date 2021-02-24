#include <iostream>
#include <cstdlib>

struct Node {
    int value;
    struct Node * next;
};

class LinkedList
{
public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void createNode(int value)
    {
        Node *temp = new Node;
        temp->value = value;
        temp->next = nullptr;

        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {	
            tail->next = temp;
            tail = temp;
        }
    }

    void pushNode(int value) {
        Node * new_node;
        new_node = new Node;

        new_node->value = value;
        new_node->next = head;

        head = new_node;
    }
    
    int pop() {
        int retval = 0;
        Node * next_node = nullptr;

        next_node = head->next;
        retval = head->value;
        delete head;
        head = next_node;

        return retval;
    }

    void removeByValue(int value) {
        /* Add your implementation here */
        Node *previous = nullptr;
        Node *current = head;
        while (current != nullptr){
            if (current->value == value){
                previous->next = current->next;
                delete current;
                break;
            }
            // std::cout<<current->value<<std::endl;
            previous = current;
            current = current->next;
        }
    }

    void printList() {
        Node * current = head;

        while (current != nullptr) {
            std::cout << current->value << std::endl;
            current = current->next;
        }
    }

private:
    Node *head;
    Node *tail;
};


int main() {

    LinkedList linkedlist;

    linkedlist.pushNode(1);
    linkedlist.pushNode(3);
    linkedlist.pushNode(2);
    linkedlist.pushNode(5);

    linkedlist.removeByValue(3);

    linkedlist.printList();

    return 0;
}