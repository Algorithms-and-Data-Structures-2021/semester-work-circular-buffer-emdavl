# Circular Buffer

[![CMake](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-template/actions/workflows/cmake.yml/badge.svg)](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-template/actions/workflows/cmake.yml)


- _Circular Buffer_
- _Кольцевой буфер - буфер фиксированного размера, который работает так, как если бы память была непрерывной и циклической.
  Работает на основе массива._
- _Часто применяется при программировании микроконтроллеров. А именно для организации различных очередей сообщений и буферов
  приема-передачи различных коммуникационных интерфейсов._
- _Добавление элемента, чтение элемента, удаление элемента, очистка буфера, проверка на заполненность и на пустоту._
- _У всех операций константная сложность._
- _Популярен т.к. не использует динамическую память, т.е. не требуется выделение дополнительной памяти для добавления элементов._

## Команда "♂Billy Herrington♂"


| Фамилия Имя      | Вклад (%) | Прозвище              |
| :---             |   ---:    |  ---:                 |
| Давлятов Эмиль   | 100       |  _босс_               |


**Девиз команды**
> _С самого начала у меня была какая-то тактика и я её придерживался_

## Структура проекта


- [`src`](src)/[`include`](include) - реализация структуры данных (исходный код и заголовочные файлы);
- [`benchmark`](benchmark) - контрольные тесты производительности структуры данных (операции добавления, удаления,
  поиска и пр.);
- [`examples`](examples) - примеры работы со структурой данных;
- [`dataset`](dataset) - наборы данных для запуска контрольных тестов и их генерация;

## Требования (Prerequisites)

**Пример**. Рекомендуемые требования:

1. С++ компилятор c поддержкой стандарта C++17 (например, _GNU GCC 8.1.x_ и выше).
2. Система автоматизации сборки _CMake_ (версия _3.12.x_ и выше).
3. Рекомендуемый объем оперативной памяти - не менее 4 ГБ.
4. Свободное дисковое пространство объемом ~ 3 ГБ (набор данных для контрольных тестов).
5. JDK 8+.

## Сборка и запуск

_Инструкция по сборке проекта, генерации тестовых данных, запуска контрольных тестов и примеров работы._

_Постарайтесь написать инструкцию так, чтобы незнакомый с проектом человек смог самостоятельно всё запустить._

#### Сборка проекта

Склонируйте проект к себе на устройство через [Git for Windows](https://gitforwindows.org/) (либо используйте
возможности IDE):

```shell
git clone https://github.com/Algorithms-and-Data-Structures-2021/semester-work-circular-buffer-emdavl.git
```

Для ручной сборки проекта в терминале введите:

```shell
# переход в папку с проектом
cd C:\Users\username\asd-projects\semester-work-circular-buffer-emdavl

# создание папки для файлов сборки (чтобы не засорять папку с проектом) 
mkdir -p build && cd build 

# сборка проекта
cmake .. -DCMAKE_BUILD_TYPE=RelWithDebInfo && cmake --config RelWithDebInfo --build . 
```

#### Генерация тестовых данных

Тестовые данные хранятся в формате CSV, сгенерировать их вы можете при помощи приложенных
в google drive java файлов, либо же взять уже готовые. \


Генерация тестового набора данных в
формате [comma-seperated values (CSV)](https://en.wikipedia.org/wiki/Comma-separated_values):

```shell
# переход в папку генерации набора данных
cd dataset

# запуск Python-скрипта
python generate_csv_bench_dataset.py --samples 1000 <output> [args ...]
```


#### Контрольные тесты (benchmarks)

_Опишите, как запустить контрольные тесты, что они из себя представляют, какие метрики замеряют (время работы,
потребление памяти и пр.)._

Для запуска контрольных тестов необходимо предварительно сгенерировать или скачать готовый набор тестовых данных.

##### Список контрольных тестов

| Название                  | Описание                                | Метрики         |
| :---                      | ---                                     | :---            |
| `add_benchmark`           | добавление элементов в структуру данных | _время_         |
| `get_benchmark`           | взятие элементов из структуры данных    | _время_         |            |

##### Примеры запуска

Генерируете набор тестовых данных, либо скачиваете с google drive\
Помещаете его по пути dataset\data
Открываете .cpp файл нужного бенчмарка\
Запускаете метод main\
Результаты будут сохранены в отдельный csv файл по пути dataset\data

## Источники

Список использованных источников можете найти в отчете, который лежит в папке google drive. 
Там же имеется более подробное описание всех методов.
