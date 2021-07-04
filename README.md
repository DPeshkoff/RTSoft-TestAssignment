[![CMake](https://github.com/DPeshkoff/RTSoft-TestAssignment/actions/workflows/cmake.yml/badge.svg)](https://github.com/DPeshkoff/RTSoft-TestAssignment/actions/workflows/cmake.yml)

# RTSoft-TestAssignment
#### Нулевое задание, RTSoftSummerSchool, лето 2021
##### Пешков Дмитрий, ИУ6-43Б
Требуется написать программу, которая:

* Принимает на вход двухмерный массив нулей и единиц определенного размера;
* Определяет площадь острова максимального размера (в состав острова входят ячейки, содержащие 1, смежные по горизонтали или вертикали);

Алгоритм должен предусматривать возможность распараллеливания на несколько ядер процессора.

Был выбран C++ 20, соответственно, использовался компилятор g++ версии 11.1.0.

Тесты реализованы с помощью GTest. 

На вкладке ```Actions``` можно посмотреть CI, собирающий проект, прогоняющий его через cppcheck и запускающий три заранее заданных теста.

## Оформление проекта
### Структура папок проекта

```bash
RTSoft-TestAssignment
|--doxygen #документация в формате html (см. index.html)
|--include #заголовочные файлы 
|  |-coroutine.h #вспомогательный заголовочный файл
|  |-field.h #заголовочный файл собственно класса карты
|
|--src #исходники
|  |-main.cpp
|  |-field.cpp #основная часть кода
|  |-CMakeLists.txt
|
|--test #тесты
|  |-src
|  |  |-test_init.cpp
|  |  |-test_field.cpp #запуск трех тестов
|  |-test
|  |  |-test0.txt #исходный тест, ответ - 6
|  |  |-test1.txt #большой тест, ответ - 27
|  |  |-test2.txt #заключительный тест, ответ - 10
|  |-CMakeLists.txt
|
|-.clang-format
|
|-.gitignore
|
|-LICENSE
|
|-CMakeLists.txt
```

### Стиль написания кода

За основу взят [google style guide](https://google.github.io/styleguide/cppguide.html), но с некоторыми оговорками:

* Отступ - 4 пробела (IndentWidth: 4)
* Разрешаются только пустые блоки на одной строке (AllowShortBlocksOnASingleLine: Empty)
* Не разрешаются пустые циклы на одной строке (AllowShortLoopsOnASingleLine: false)
* Разрешаются только пустые короткие функции на одной строке (AllowShortFunctionsOnASingleLine: Empty)
* Не разрешаются условные выражения на одной строке (AllowShortIfStatementsOnASingleLine: Never)