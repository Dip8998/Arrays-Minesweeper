#pragma once
#include <sfml/Graphics.hpp>
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../../header/UI/UIElement/ButtonView.h"

namespace Gameplay
{
    namespace Board
    {
        class BoardView;

        class BoardController
        {
        public:
            static const int number_of_rows = 9;
            static const int number_of_colums = 9;
            static const int mines_count = 8;

            int flagged_cells;

            BoardController();
            ~BoardController();

            void initialize();
            void update();
            void render();
            void reset();
            int getMinesCount();

            void openCell(sf::Vector2i cell_position);
            void processCellInput(Cell::CellController* cell_controller, UI::UIElement::ButtonType button_type);
            void flagCell(sf::Vector2i cell_position);

        private:
            BoardView* board_view;
            Gameplay::Cell::CellController* board[number_of_rows][number_of_colums];
            void createBoard();
            void initializeCells();
            void resetBoard();
            void deleteBoard();
            void destroy();
        };
    }
}