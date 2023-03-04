# include <iostream>
# include <exception>
# include <stdexcept>
# include <tuple>
# include <string>

# include "board.hpp"
# include "move.hpp"
# include "parse_format.hpp"
# include "search.hpp"
# include "history.hpp"
# include "openings.hpp"


void play_game(bool wtm, Board board, const int node_count){
	History history = nullptr;
	int eval;
	Variation variation = nullptr;

	while(true) {
		std::tie(eval, variation) = (wtm ? search_for_move<true> : search_for_move<false>)(board, history, my_nodes);

		if (variation == nullptr){
			if (eval == 0) {
				std::cout << "Draw by stalemate" << std::endl;
				return;
			}
			if (eval <= CHECKMATED) {
				std::cout << (wtm ? "Black won by checkmate" : "White won by checkmate") << std::endl;
				return;
			}
			throw std::logic_error("Empty variation without checkmate or stalemate eval");
		}

		auto move = variation->head;
		std::cout << format_move_xboard(move) << " ";
		board = (wtm ? make_move<true> : make_move<false>)(board, move);
		wtm = !wtm;
		history = is_irreversible(board, move) ? nullptr : extend_history(board, history);

		if (history != nullptr and (history->length) >= 100) {
			std::cout << "Draw by 50-move rule" << std::endl;
			return;
		}
		if (exists_in_history(board, history)) {
			std::cout << "Draw by repetition" << std::endl;
			return;
		}
	}
}


int main(int argc, char** argv){
	if (argc != 4){ trhow std::invalid_argument("Usage: [book_name] [opening_name] [node_count]")
	auto opening = read_specific_opening(argv[1], argv[2]);

	bool wtm = std::get<0>(opening);
	Board board = std::get<1>(opening);
	int node_count = std::stoi(node_count);

	play_game(wtm, board, node_count);

}
