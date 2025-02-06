#pragma once
#include <sfml/Graphics.hpp>
#include <random>
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../../header/UI/UIElement/ButtonView.h"

namespace Gameplay
{
    namespace Board
    {
        enum class BoardState {
            FIRST_CELL,
            PLAYING,
            COMPLETED
        };

        class BoardView;

        class BoardController
        {
        public:
            static const int number_of_rows = 9;
            static const int number_of_colums = 9;
            static const int mines_count = 8;

            int flagged_cells;
            std::default_random_engine random_engine;
            std::random_device random_device;

            BoardController();
            ~BoardController();

            void initialize();
            void update();
            void render();
            void reset();
            int getMinesCount();

            void openCell(sf::Vector2i cell_position);
            void openEmptyCells(sf::Vector2i cell_position);
            void openAllCells();
            void processCellInput(Cell::CellController* cell_controller, UI::UIElement::ButtonType button_type);
            void flagCell(sf::Vector2i cell_position);
            void processCellValue(sf::Vector2i cell_position);
            void processEmptyCell(sf::Vector2i cell_position);
            void populateBoard(sf::Vector2i cell_position);

            int countMinesAround(sf::Vector2i cell_position);

            bool isValidCellPosition(sf::Vector2i cell_position);

            void populateCells();

        private:
            BoardView* board_view;
            BoardState board_state;
            Gameplay::Cell::CellController* board[number_of_rows][number_of_colums];
            void createBoard();
            void initializeCells();
            void resetBoard();
            void deleteBoard();
            void destroy();
            BoardState getBoardState();
            void setBoardState(BoardState state);
        };
    }
}