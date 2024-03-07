#include <iostream>
#define DEBUG
// delete the line above to disable debug mode

// first in last out
template<typename L>
class List
{
public:

    List();
    ~List();

    L& operator[](const int index);

    int getSize() { return size; }

    void push_front(L data);

    void push_back(L data);

    void insert(L data, int index);

    void pop_front();

    void clear();

private:

    template<typename N>
    class Node
    {
    public:
        Node *pNext;
        N data;

        Node(N data = N(), Node *pNext=nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };

    int size;
    Node<L> *head;
};


// constructor
template<typename L>
List<L>::List() {
    size = 0;
    head = nullptr;
};

// delete the front element of a list
template<typename L>
void List<L>::pop_front() {
    Node<L> *temp = head;

    head = head->pNext;

    delete temp;

    size--;
}

// add element to the front of the list
template<typename L>
void List<L>::push_front(L data) {
    head = new Node<L>(data, head);
    size++;
}

// add element to the back of the list
template<typename L>
void List<L>::push_back(L data) {

    if (head == nullptr)
    {
        head = new Node<L>(data);
    }
    else {
        Node<L> *current = this->head;
        while (current->pNext != nullptr) {
            current = current->pNext;
        }
        current->pNext = new Node<L>(data);
    }

    size++;
}

// insert element at given index
template<typename L>
void List<L>::insert(L data, int index) {
    if (index == 0)
        push_front(data);
    else {
        Node<L> *previous = this->head;

        for (int i = 0; i < index - 1; i++)
            previous = previous->pNext;

        Node<L> *newNode = new Node<L>(data, previous->pNext);
        previous->pNext = newNode;
        size++;
    }
}

// reuse pop_front to delete all elements of list
template<typename L>
void List<L>::clear() {
    while (size)
    {
        pop_front();
    }
}

// overloading of [ ] operator to access list elements (nodes) via index
template<typename L>
L &List<L>::operator[](const int index) {
    int counter = 0;
    Node<L> *current = this->head;

    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}

// just destructor
template<typename L>
List<L>::~List() {
    clear();
};


int main() {
    List<int> lst;

// idk maybe there is some better way to do this, but I'll keep it for some time
#ifdef DEBUG
    int length;
    std::cout<< "choose length(size) of list: ";
    std::cin >> length;
    for (size_t i = 0; i < length; i++)
        lst.push_back(rand()%10);

    for (int i = 0; i < lst.getSize(); i++)
       std::cout<< lst[i] <<'\t';
    std::cout<< "size:" << lst.getSize() <<std::endl;

    std::cout<< "pop_front()" <<std::endl;
    lst.pop_front();

    for (int i = 0; i < lst.getSize(); i++)
        std::cout<< lst[i] <<'\t';
    std::cout<< "size:" << lst.getSize() <<std::endl;

    std::cout<< "push_front()" <<std::endl;
    lst.push_front(11);
    for (int i = 0; i < lst.getSize(); i++)
        std::cout<< lst[i] <<'\t';
    std::cout<< "size:" << lst.getSize() <<std::endl;

    std::cout<< "insert()" <<std::endl;
    lst.insert(12,1);
    for (int i = 0; i < lst.getSize(); i++)
        std::cout<< lst[i] <<'\t';
    std::cout<< "size:" << lst.getSize() <<std::endl;

    std::cout<< "clear" <<'\t';
    lst.clear();
    std::cout<< "size:" << lst.getSize() <<std::endl;
#endif
    // see you, space cowboy
    return 0;
}
