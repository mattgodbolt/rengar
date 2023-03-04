# pragma once

# include "board.hpp"

# include <tuple>
# include <list>
# include <string>

using BookPosition = std::tuple<bool, Board, std::string>;

std::list<BookPosition> read_openings_from_file(const std::string book_name);
BookPosition read_specific_opening(const std::string book_name, const std::string opening_name);
