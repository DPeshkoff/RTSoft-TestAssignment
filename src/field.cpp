// Copyright 2021 DPeshkoff;
// Distributed under the GNU General Public License, Version 3.0. (See
// accompanying file LICENSE)

#include "field.h"

//////////////////////////////////////////////////////////////////////////////////////////////
// Конструкторы класса
//////////////////////////////////////////////////////////////////////////////////////////////

MapMatrix::MapMatrix(std::size_t rows, std::size_t columns)
    : map_matrix_(rows, std::vector<std::pair<bool, bool>>(
                            columns, std::make_pair(false, false))) {}

MapMatrix::MapMatrix(const MapMatrix& map) {
    std::copy(map.map_matrix_.begin(), map.map_matrix_.end(),
              map_matrix_.begin());
}

//////////////////////////////////////////////////////////////////////////////////////////////
// Публичные методы класса
//////////////////////////////////////////////////////////////////////////////////////////////

void MapMatrix::AddLine(const std::string& line, const std::size_t& row) {
    if (row == map_matrix_.size()) {
        map_matrix_.resize(row + 1);
    }

    std::transform(std::cbegin(line), std::cend(line),
                   std::back_inserter(map_matrix_[row]),
                   [](char str) -> std::pair<bool, bool> {
                       return std::make_pair(((str != '0') ? true : false),
                                             false);
                   });
}

void MapMatrix::Traverse(const std::size_t& row_position,
                         const std::size_t& col_position) {
    for (std::size_t row = row_position; row < map_matrix_.size(); ++row) {
        for (std::size_t col = col_position; col < map_matrix_[row].size();
             ++col) {
            if (!map_matrix_[row][col].second) {
                if (map_matrix_[row][col].first) {
                    std::jthread jt1(&MapMatrix::_DFS, this, std::cref(row),
                                     std::cref(col));
                    // For debugging purposes
                    // std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    // std::cout << *this << std::endl;
                }
                map_matrix_[row][col].second = true;
            }
        }
    }
    _ClearPath();
}

void MapMatrix::OutputAreas() {
    for (auto i : areas_) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

std::size_t MapMatrix::GetMaxArea() {
    return *std::max_element(areas_.begin(), areas_.end());
}

std::ostream& operator<<(std::ostream& os, const MapMatrix& m) {
    for (std::size_t row = 0; row < m.map_matrix_.size(); ++row) {
        for (std::size_t col = 0; col < m.map_matrix_[row].size(); ++col) {
            if (m.map_matrix_[row][col].second == true) {
                os << "\033[1;32m" << m.map_matrix_[row][col].first
                   << "\033[0m";
            } else {
                os << "\033[1;31m" << m.map_matrix_[row][col].first
                   << "\033[0m";
            }
        }
        os << "\n";
    }
    os << "\n";
    return os;
}

//////////////////////////////////////////////////////////////////////////////////////////////
// Приватные методы класса
//////////////////////////////////////////////////////////////////////////////////////////////

void MapMatrix::_ClearPath() {
    for (std::size_t row = 0; row < map_matrix_.size(); ++row) {
        for (std::size_t col = 0; col < map_matrix_[row].size(); ++col) {
            map_matrix_[row][col].second = false;
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////
// Методы поиска в глубину
//////////////////////////////////////////////////////////////////////////////////////////////

// Попытка использования coroutines, но весьма кривая.
task MapMatrix::_DFS(int32_t row_position, int32_t col_position) {
    std::size_t area = 0;
    _DFS_(row_position, col_position, area);
    areas_.push_back(area);
    std::cout << *this << std::endl;
    co_return;
}

void MapMatrix::_DFS_(const int32_t& row_position, const int32_t& col_position,
                      std::size_t& area) {
    if (row_position < 0 or
        static_cast<std::size_t>(row_position) == map_matrix_.size()) {
        return;
    }

    if (col_position < 0 or
        static_cast<std::size_t>(col_position) == map_matrix_[0].size()) {
        return;
    }

    if (map_matrix_[row_position][col_position].second) {
        return;
    }

    map_matrix_[row_position][col_position].second = true;

    if (map_matrix_[row_position][col_position].first == true) {
        ++area;
        for (uint8_t direction = 0; direction < 4; ++direction) {
            _DFS_(row_position + dx_[direction], col_position + dy_[direction],
                  area);
        }
    }
}
