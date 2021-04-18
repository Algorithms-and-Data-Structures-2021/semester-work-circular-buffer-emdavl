#pragma once

#include "node.hpp"

// Заголовочный файл с объявлением структуры данных

namespace itis {

  inline constexpr auto kInitCapacity = 8;

  struct Circular_buffer final {

   private:
    int size_{0};
    int capacity_{0};
    // Указатель на самый старый добавленный элемент
    int *oldestElem{nullptr};
    // Указатель на самый новый добавленный элемент
    int *newestElem{nullptr};

    int *dataArr{nullptr};

    //Вспомогательные методы
    void addToEmpty(int value);
    void addFrontToNotEmpty(int value);
    void addBackToNotEmpty(int value);

   public:
    // Деструктор
    ~Circular_buffer();
    // Конструктор
    explicit Circular_buffer(int capacity = kInitCapacity);

    /***
     *
     * Метод для расширения буффера
     *
     * @param newCapacity - новая вместимость буффера, обязательно должна быть больше старой.
     */
    void expand(int newCapacity);

    /***
     *
     * Теперь size = 0 и все указатели указывают на начало массива dataArr
     *
     */
    void clear();

    /***
     * Возвращает самый новый добавленный элемент (тот, на который ссылается newestElement), при этом передвигая
     * указатель на предыдущий по давности добавления элемент.
     *
     * [3, 4, 5, 1, x, x, x]
     *     ↑
     *     newestElem
     *
     * getFront() -> return 4
     * [3, x, 5, 1, x, x, x]
     *  ↑
     *  new newestElem
     * При этом 4 не удаляется, а остается, в будущем его значение просто будет перезаписано.
     *
     *
     * @return Самый новый добавленный элемент
     */
    int getFront();

    /***
     * Возвращает самый старый добавленный элемент (тот, на который ссылается oldestElement), при этом передвигая
     * указатель на следующий по давности добавления элемент.
     *
     * [3, 4, 5, 1, x, x, x]
     *     ↑
     *     oldestElem
     *
     * getBack() -> return 4
     * [3, x, 5, 1, x, x, x]
     *        ↑
     *      new oldestElem
     * При этом 4 не удаляется, а остается, в будущем его значение просто будет перезаписано.
     *
     * @return Самый старый добавленный элемент (тот на который ссылается oldestElement)
     */
    int getBack();

    /***
     *
     * Возвращает значение самого нового элемента (того, на который ссылается newestElem), при этом не удаляя его
     *
     * @return значение, на которое ссылается newestElem
     */
    int peekFront();

    /***
     *
     * Возвращает значение самого старого элемента (того, на который ссылкается oldestElem), при этом не удаляя его
     *
     * @return значение, на которые ссылается oldestElem
     */
    int peekBack();


    /***
     *
     * Добавляет новое значение после того, на которое указывает newestElem. В случае если буффер уже заполнен
     * перезаписывает значение oldestElem передвигая указатель oldestElem на следующее по давности значение
     *
     * @param value - значение нового элемента
     */
    void addFront(int value);
    /***
     *
     * Добавляет новое значение перед тем, на которое указывает oldestElem. В случае если буффер уже заполнен
     * перезаписывает значение newestElem передвигая указатель newestElem на предыдущее по давности значение
     *
     * @param value - значение нового элемента
     */
    void addBack(int value);

    /***
     * @return значение поля size
     */
    int getSize();
    /***
     * @return значение поля capacity
     */
    int getCapacity();

    bool isFull();
    bool isEmpty();
  };
}  // namespace itis