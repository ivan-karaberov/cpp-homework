#ifndef _H_STACK_H_
#define _H_STACK_H_

#include <typeinfo>

namespace my {
    template <class T> class stack {
    private:
        class Node {
            public: 
                T data;
                Node* next;

                Node(T data) {
                    this->data = data;
                    this->next = NULL;
                }
        };

        Node* head;
        int sizeOfTop;

    private:
        bool isInt() {
            return typeid(head->data).name() == typeid(int).name();
        }
        bool isFloat() {
            return typeid(head->data).name() == typeid(float).name();
        }
        bool isDouble() {
            return typeid(head->data).name() == typeid(double).name();
        }

    public:
        stack() {
            sizeOfTop = 0;
            head = NULL;
        }
        
        ~stack() {
            while (!empty()) {
                pop();
            }
        }

        int size() {
            return sizeOfTop;
        }

        bool empty() {
            return sizeOfTop == 0;
        }

        T top() {
            if (empty()) return 0;
            return head->data;
        }
        
        Node* getByIndex(int index) {
            if (empty()) return 0;

            Node* ptr = head;
            int counter = 0;

            while (ptr) {
                if (counter == index) return ptr;
                counter++;
                ptr = ptr->next;
            }

            return 0;
        }

        Node* operator [] (int index) {
            return getByIndex(index);
        }

        void push(T data) {
            Node* ptr = new Node(data);
            ptr->next = head;
            head = ptr;
            sizeOfTop++;
        }
        
        T pop() {
            if (empty()) return 0;

            Node* ptr = head;
            T tmp = ptr->data;
            head = ptr->next;
            delete ptr;

            sizeOfTop--;
            return tmp;
        }
        
        void swap(int index1, int index2) {
            Node* val1 = getByIndex(index1);
            Node* val2 = getByIndex(index2);

            if (val1 == 0 || val2 == 0) return;

            T tmp = val1->data;
            val1->data = val2->data;
            val2->data = tmp;
        }

        void invert() {
            if (empty()) return;
            if (!isInt() and !isFloat() and !isDouble()) return;
            Node* ptr = head;
            while (ptr) {
                ptr->data *= -1;
                ptr = ptr->next;
            }
        }
    };
};

#endif