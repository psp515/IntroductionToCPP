//
// Created by psp515 on 06.04.2023.
//

#ifndef ZAD5MYLISTANDSORTING_MYLIST_H
#define ZAD5MYLISTANDSORTING_MYLIST_H

#include <cstdlib>
#include <memory>
#include <stdexcept>

#define IMPLEMENTED_constructorOfEmptyList
#define IMPLEMENTED_pushingAndPopingElementsFront
#define IMPLEMENTED_nodesStoredAsUniquePtrs
#define IMPLEMENTED_popFromWhenEmptyList
#define IMPLEMENTED_copyingDisabled
#define IMPLEMENTED_removingElements
#define IMPLEMENTED_iteratorOperations
#define IMPLEMENTED_iteratorWithRangedForLoop
#define IMPLEMENTED_iteratorWithStlAlgorithm
#define IMPLEMENTED_ostreamOperator

template<class T> class MyList {
protected:
    struct Node
    {
        T data;
        std::unique_ptr<Node> next_;
    };

    std::unique_ptr<Node> head_;

private:
    size_t size_;

public:


    class Iterator : public std::iterator<std::forward_iterator_tag, int>
    {
    public:
        explicit Iterator(Node* newNode): point(newNode){}

        Iterator &operator=(Node* newNode)
        {
            this->point = newNode;
            return *this;
        }

        Iterator& operator++()
        {
            if(this->point != nullptr)
                this->point = this->point->next_.get();
            return *this;
        }

        Iterator& operator++(int)
        {
            Iterator that = *this;
            ++*this;
            return that;
        }

        friend bool operator!=(Iterator iterator1, Iterator iterator2) {
            return iterator1.point != iterator2.point;
        }

        friend bool operator==(Iterator iterator1, Iterator iterator2) {
            return iterator1.point == iterator2.point;
        }

        T &operator*() {
            return this->point->data;
        }

        T *operator->() {
            return &this->point->data;
        }

    private:
        Node* point;
    };

    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using iterator = Node*;
    using const_iterator = const Node*;

    Iterator begin() const { return Iterator(head_.get()); }
    Iterator end() const { return Iterator(nullptr); }


    MyList() : head_{}, size_(0) {};

    // Disable copy
    MyList(MyList<T> &list) = delete;
    MyList<T> operator=(MyList<T> &array) = delete;

    // functions
    void push_front(T element);
    T pop_front();
    [[nodiscard]] size_t size() const;
    T front();
    void remove(T element);

    // Operators
    friend std::ostream& operator<<(std::ostream& stream, const MyList<T>& list)
    {
        for(auto val: list)
            stream << val << " ";

        return stream;
    }
};


template<typename T>
void MyList<T>::remove(const T element) {
    if (head_ == nullptr)
        return;

    std::unique_ptr<Node> *itr = &(head_->next_);
    std::unique_ptr<Node> *prev = &head_;

    while (*itr != nullptr) {
        if ((*itr).get()->data == element) {
            (*prev)->next_ = std::move((*itr).get()->next_);
            itr = prev;
            size_--;
        }
        prev = itr;
        itr = &((*itr).get()->next_);
    }

    if (head_->data == element) {
        std::unique_ptr<Node> new_head = std::move(head_->next_);
        head_ = std::move(new_head);
        size_--;
    }
}

template<class T>
void MyList<T>::push_front(T element) {

    std::unique_ptr<MyList::Node> new_head = std::make_unique<Node>();
    new_head->data = element;
    new_head->next_ = std::move(this->head_);

    this->head_ = std::move(new_head);

    size_++;
}

template<class T>
T MyList<T>::pop_front() {
    if(head_ == nullptr)
        throw std::out_of_range("No elements in list.");

    size_--;
    T returnable = head_->data;
    head_ = std::move(head_->next_);

    return returnable;
}

template<class T>
T MyList<T>::front() {
    return head_->data;
}

template<class T>
size_t MyList<T>::size() const{
    return size_;
}


#endif //ZAD5MYLISTANDSORTING_MYLIST_H
