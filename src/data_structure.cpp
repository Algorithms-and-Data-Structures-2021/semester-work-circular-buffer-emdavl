#include "data_structure.hpp"
#include <cassert>
#include <algorithm>
#include <iostream>
#include <iostream>

// файл с определениями

namespace itis {

  void Circular_buffer::clear() {
    oldestElem = newestElem = nullptr;
    dataArr[0] = 0;
    size_ = 0;
  }

  Circular_buffer::Circular_buffer(int capacity) {
    assert(capacity > 0);
    capacity_ = capacity;
    dataArr = new int[capacity];
    oldestElem = newestElem = nullptr;
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
    oldestElem = newestElem = dataArr;
    size_++;
  }


  void Circular_buffer::addFrontToNotEmpty(int value) {
    if(isFull()){
      *oldestElem = value;
      newestElem = oldestElem++;
      if(oldestElem > &dataArr[capacity_-1]){
        oldestElem = &dataArr[0];
      }
    }else{
      newestElem = newestElem + 1;
      if(newestElem > &dataArr[capacity_ - 1]){
        newestElem = &dataArr[0];
      }
      *newestElem = value;
      size_++;
    }
  }

  void Circular_buffer::addBackToNotEmpty(int value) {
    if(isFull()){
      *newestElem = value;
      oldestElem = newestElem--;
      if(newestElem < &dataArr[0]){
        newestElem = &dataArr[capacity_ -1];
      }
    }else{
      oldestElem = oldestElem - 1;
      if(oldestElem < &dataArr[0]){
        oldestElem = &dataArr[capacity_ - 1];
      }
      *oldestElem = value;
      size_++;
    }
  }

  int Circular_buffer::peekFront() {
    if(size_ == 0){
      throw "Peeking into an empty array";
    }
    return *newestElem;
  }

  int Circular_buffer::peekBack() {
    if(size_ == 0){
      throw "Peeking into an empty array";
    }
    return *oldestElem;
  }

  int Circular_buffer::getSize() {
    return size_;
  }

  void Circular_buffer::expand(int newCapacity) {
    assert(newCapacity > capacity_);
    int *newDataArr = new int[newCapacity];

    for (int i = 0; i < size_; ++i) {
      newDataArr[i] = *oldestElem;
      oldestElem++;
      if(oldestElem > &dataArr[capacity_ - 1]){
        oldestElem = dataArr;
      }
    }
    oldestElem = &newDataArr[0];
    newestElem = &newDataArr[size_-1];

    capacity_ = newCapacity;
    delete[] dataArr;
    dataArr = newDataArr;
  }

  int Circular_buffer::getCapacity() {
    return capacity_;
  }

  int Circular_buffer::getBack() {
    if(size_ == 0){
      throw "Trying to get elem from empty array";
    }
    int elem = *oldestElem;
    oldestElem = oldestElem + 1;
    if(oldestElem > &dataArr[capacity_ - 1]){
      oldestElem = dataArr;
    }
    size_--;
    return elem;
  }

  int Circular_buffer::getFront() {
    if(size_ == 0){
      throw "Trying to get elem from empty array";
    }
    int elem = *newestElem;
    if(--newestElem < dataArr){
      newestElem = &dataArr[capacity_ - 1];
    }
    size_--;
    return elem;
  }

  Circular_buffer::~Circular_buffer() {
    delete[] dataArr;
    oldestElem = newestElem = nullptr;
    size_ = 0;
    capacity_ = 0;
  }

}  // namespace itis