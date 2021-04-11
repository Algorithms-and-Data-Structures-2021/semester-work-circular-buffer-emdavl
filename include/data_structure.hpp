#pragma once

#include "node.hpp"
#include "linked_dequeue.hpp"

// Заголовочный файл с объявлением структуры данных

namespace itis {

  // Tip 1: объявите здесь необходимые структуры, функции, константы и прочее

  //inline constexpr auto kStringConstant = "Hello, stranger!";

  // Пример: объявление структуры с полями и методами
  struct Circular_buffer final {
   private:
    // Указатель на самый старый добавленный узел.
    SinglyNode *oldest_node{nullptr};
    // Указатель на последний добавленный узел
    SinglyNode *newest_node{nullptr};
    int capacity_{0};
    int size_{0};

   public:
    //Вроде конструктор
    explicit Circular_buffer(int capacity_arg);

    // Добавляет элемент на следующую, после предыдущего добавленного позицию. Если она занята самым старым элементом,
    // то происходит перезаписывание.
    void add(int e);

    // Возвращает значение самого старого элемента, при этом элемент изымается из очереди и его место становится пустым;
    int get();

    // Возвращает значение самого старого элемента, при это не удаляя элемент из очереди
    int peek();

    // Очищает буфер
    void clear();

    // Возвращает true - если capacity==size, иначе false
    bool isFull();

    // Возвращает true - если capacity!=size, иначе false
    bool isEmpty();

    //Возвращает текущее количество элементов
    int currentSize();

    // Вспомогательный метод для добавления элементов, когда буфер заполнен
    void addIfFull(int e);

    // Вспомогательный методо для добавления элементов, когда буфер не заполнен
    void addIfNotFull(int e);

    ~Circular_buffer();

  };
}  // namespace itis