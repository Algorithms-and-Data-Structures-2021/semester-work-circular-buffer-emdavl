#pragma once


// Заголовочный файл с объявлением структуры данных

namespace itis {

  inline constexpr auto kInitCapacity = 8;

  struct Circular_buffer final {

   private:
    int size_{0};
    int capacity_{0};
    // Указатель на самый старый добавленный элемент
    int *firstElem{nullptr};
    // Указатель на самый новый добавленный элемент
    int *lastElem{nullptr};

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
     * Теперь size = 0 и все указатели указывают на nullptr
     *
     */
    void clear();

    /***
     * Возвращает самый новый добавленный элемент (тот, на который ссылается newestElement), при этом передвигая
     * указатель на предыдущий по давности добавления элемент.
     *
     * [3, 4, 5, 1, x, x, x]
     *     ↑
     *     lastElem
     *
     * getFront() -> return 4
     * [3, x, 5, 1, x, x, x]
     *  ↑
     *  new lastElem
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
     *     firstElem
     *
     * getBack() -> return 4
     * [3, x, 5, 1, x, x, x]
     *        ↑
     *      new firstElem
     * При этом 4 не удаляется, а остается, в будущем его значение просто будет перезаписано.
     *
     * @return Самый старый добавленный элемент (тот на который ссылается oldestElement)
     */
    int getBack();

    /***
     *
     * Возвращает значение самого нового элемента (того, на который ссылается lastElem), при этом не удаляя его
     *
     * @return значение, на которое ссылается lastElem
     */
    int peekFront();

    /***
     *
     * Возвращает значение самого старого элемента (того, на который ссылкается firstElem), при этом не удаляя его
     *
     * @return значение, на которые ссылается firstElem
     */
    int peekBack();


    /***
     *
     * Добавляет новое значение после того, на которое указывает lastElem. В случае если буффер уже заполнен
     * перезаписывает значение firstElem передвигая указатель firstElem на следующее по давности значение
     *
     * @param value - значение нового элемента
     */
    void addFront(int value);

    /***
     *
     * Добавляет новое значение перед тем, на которое указывает firstElem. В случае если буффер уже заполнен
     * перезаписывает значение lastElem передвигая указатель lastElem на предыдущее по давности значение
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