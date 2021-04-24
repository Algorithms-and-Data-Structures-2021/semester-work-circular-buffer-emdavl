#include "data_structure.hpp"
#include <cassert>
#include <algorithm>
#include <iostream>
#include <iostream>

// файл с определениями

namespace itis {

    void Circular_buffer::clear() {
        firstElem = lastElem = nullptr;
        dataArr[0] = 0;
        size_ = 0;
    }

    Circular_buffer::Circular_buffer(int capacity) {
        assert(capacity > 0);
        capacity_ = capacity;
        dataArr = new int[capacity];
        firstElem = lastElem = nullptr;
    }

    bool Circular_buffer::isEmpty() {
        return size_ == 0;
    }

    bool Circular_buffer::isFull() {
        return size_ == capacity_;
    }

    void Circular_buffer::addFront(int value) {
        if (isEmpty()) {
            addToEmpty(value);
        } else {
            addFrontToNotEmpty(value);
        }
    }

    void Circular_buffer::addBack(int value) {
        if (isEmpty()) {
            addToEmpty(value);
        } else {
            addBackToNotEmpty(value);
        }
    }

    void Circular_buffer::addToEmpty(int value) {
        dataArr[0] = value;
        firstElem = lastElem = dataArr;
        size_++;
    }


    void Circular_buffer::addFrontToNotEmpty(int value) {
        if (isFull()) {
            *firstElem = value;
            lastElem = firstElem++;
            if (firstElem > &dataArr[capacity_ - 1]) {
                firstElem = &dataArr[0];
            }
        } else {
            lastElem = lastElem + 1;
            if (lastElem > &dataArr[capacity_ - 1]) {
                lastElem = &dataArr[0];
            }
            *lastElem = value;
            size_++;
        }
    }

    void Circular_buffer::addBackToNotEmpty(int value) {
        if (isFull()) {
            *lastElem = value;
            firstElem = lastElem--;
            if (lastElem < &dataArr[0]) {
                lastElem = &dataArr[capacity_ - 1];
            }
        } else {
            firstElem = firstElem - 1;
            if (firstElem < dataArr) {
                firstElem = &dataArr[capacity_ - 1];
            }
            *firstElem = value;
            size_++;
        }
    }

    int Circular_buffer::peekFront() {
        if (size_ == 0) {
            throw "Peeking into an empty array";
        }
        return *lastElem;
    }

    int Circular_buffer::peekBack() {
        if (size_ == 0) {
            throw "Peeking into an empty array";
        }
        return *firstElem;
    }

    int Circular_buffer::getSize() {
        return size_;
    }

    void Circular_buffer::expand(int newCapacity) {
        assert(newCapacity > capacity_);
        int *newDataArr = new int[newCapacity];

        for (int i = 0; i < size_; ++i) {
            newDataArr[i] = *firstElem;
            firstElem++;
            if (firstElem > &dataArr[capacity_ - 1]) {
                firstElem = dataArr;
            }
        }
        firstElem = &newDataArr[0];
        lastElem = &newDataArr[size_ - 1];

        capacity_ = newCapacity;
        delete[] dataArr;
        dataArr = newDataArr;
    }

    int Circular_buffer::getCapacity() {
        return capacity_;
    }

    int Circular_buffer::getBack() {
        assert(size_ > 0);
        int elem = *firstElem;
        firstElem = firstElem + 1;
        if (firstElem > &dataArr[capacity_ - 1]) {
            firstElem = dataArr;
        }
        size_--;
        return elem;
    }

    int Circular_buffer::getFront() {
      assert(size_ > 0);

      int elem = *lastElem;
        if (--lastElem < dataArr) {
            lastElem = &dataArr[capacity_ - 1];
        }
        size_--;
        return elem;
    }

    Circular_buffer::~Circular_buffer() {
        delete[] dataArr;
        firstElem = lastElem = nullptr;
        size_ = 0;
        capacity_ = 0;
    }

}  // namespace itis