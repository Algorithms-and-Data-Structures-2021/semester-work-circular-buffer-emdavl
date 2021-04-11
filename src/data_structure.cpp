#include "data_structure.hpp"
#include <cassert>

// файл с определениями

namespace itis {

  // здесь должны быть определения методов вашей структуры

  Circular_buffer::Circular_buffer(int capacity_arg) {
    assert(capacity_arg > 0);
    capacity_ = capacity_arg;
  }

  void Circular_buffer::add(int e) {
    if(isFull()){
      addIfFull(e);
    }else{
      addIfNotFull(e);
    }
  }

  int Circular_buffer::get() {
    assert(size_ != 0);
    int data = oldest_node->data;
    SinglyNode *node = oldest_node;
    oldest_node = oldest_node->next;
    delete node;
    size_--;
    return data;
  }

  int Circular_buffer::peek() {
    assert(size_ != 0);
    return oldest_node->data;
  }

  void Circular_buffer::clear() {
    SinglyNode *node = oldest_node;
    for (int i = 0; i < size_; ++i) {
      oldest_node = oldest_node->next;
      delete node;
      node = oldest_node;
    }
    size_ = 0;
    capacity_ = 0;
    oldest_node = nullptr;
    newest_node = nullptr;
    delete node;
  }

  bool Circular_buffer::isFull() {
    return size_ == capacity_;
  }

  bool Circular_buffer::isEmpty() {
    return size_ == 0;
  }

  int Circular_buffer::currentSize() {
    return size_;
  }

  Circular_buffer::~Circular_buffer() {
    clear();
  }

  void Circular_buffer::addIfFull(int e) {
    SinglyNode *node = oldest_node;
    oldest_node = oldest_node->next;
    node->data = e;
    newest_node->next = node;
    newest_node = node;
  }

  void Circular_buffer::addIfNotFull(int e) {
    auto *node = new SinglyNode(e, nullptr);
    if(isEmpty()){
      oldest_node = node;
      newest_node = node;
    }else{
      if(size_ == capacity_ - 1){
        node->next = oldest_node;
        newest_node->next = node;
        newest_node = node;
      }else{
        newest_node->next = node;
        newest_node = node;
      }
    }
    size_++;
  }
}  // namespace itis