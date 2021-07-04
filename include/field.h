// Copyright 2021 DPeshkoff;
// Distributed under the GNU General Public License, Version 3.0. (See
// accompanying file LICENSE)

#pragma once

#include <algorithm>   // std::transform and std::max_element
#include <chrono>      // ...
#include <cstdint>     // fixed-width integers
#include <functional>  // std::ref
#include <iostream>    // ...
#include <thread>      // ...
#include <vector>      // std::vector

#include "coroutine.h"  //

/*!
        \brief Класс, реализующий карту.

    Реализована улучшенная матричная реализация графа. Двухмерныый массив
   реализован в виде двух векторов; элементы представлены в виде пар элементов,
   где первое значение - собственно значение клетки на карте (0: вода, 1: суша),
   второе - статус (0: не посещено, 1: посещено)
*/
class MapMatrix {
   public:
    /// Конструктор класса по количеству рядов и столбцов.
    MapMatrix(std::size_t rows, std::size_t columns);

    /// Конструктор копирования.
    MapMatrix(const MapMatrix& map);

    /// Процедура, осуществляющая линейную загрузка данных.
    void AddLine(const std::string& line, const std::size_t& row);

    /// Процедура, осуществляющая главный проход по карте.
    void Traverse(const std::size_t& row_position,
                  const std::size_t& column_position);

    /// Процедура, выводящая площади всех фигур.
    void OutputAreas();

    /// Функция, выводящая максимальную площадь.
    std::size_t GetMaxArea();

    /// Оператор потокового вывода для карты.
    friend std::ostream& operator<<(std::ostream& os, const MapMatrix& m);

   private:
    /// Контейнер, содержащий подсчитанные площади островов.
    std::vector<std::size_t> areas_;

    /// Контейнер, содержащий карту.
    std::vector<std::vector<std::pair<bool, bool>>> map_matrix_;

    /// Массив направлений по оси x - ряды матрицы.
    static constexpr int8_t dx_[] = {+1, 0, -1, 0};

    /// Массив направлений по оси y - столбцы матрицы.
    static constexpr int8_t dy_[] = {0, +1, 0, -1};

    /// "Корутина" поиска в глубину.
    task _DFS(int32_t row_position, int32_t col_position);

    /// Рекурсивная процедура поиска в глубину.
    void _DFS_(const int32_t& row_position, const int32_t& col_position,
               std::size_t& area);

    /// Процедура, выполняющая очистку меток пройденного пути (вторых значений пар).
    void _ClearPath();
};