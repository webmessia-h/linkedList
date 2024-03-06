#include <iostream>

template<typename L>
class List
{
public:
    List();
    ~List();

    L& operator[](const int index);

    int getSize() {return size;}

    void push_back(L data);

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
        size++;
    }
}

template<typename L>
List<L>::List() {
    size = 0;
    head = nullptr;
};

template<typename L>
List<L>::~List() {

};

int main() {
    List<int> lst;

    // lst.push_back(5);

    // std::cout<< lst[2] <<std::endl;



    int size = 0;
    std::cin >> size;
    for (size_t i = 0; i < size; i++)
        lst.push_back(rand()%51);

    for (int i = 0; i <= lst.getSize(); i++)
       std::cout<< lst[i] <<std::endl;

    std::cout<< "size:" << lst.getSize() + 1 <<std::endl;
   return 0;
}
