#pragma once
#include "../../header/Gameplay/Board/BoardController.h"
#include "../../header/UI/UIElement/ButtonView.h"
#include "../../../header/Gameplay/Cell/CellController.h"


namespace Gameplay
{
    namespace Board
    {
        enum class ButtonType;

        class BoardService
        {
        private:
            Board::BoardController* board_controller;

            void destroy();

        public:
            BoardService();
            ~BoardService();
            void initialize();
            void update();
            void render();


            void resetBoard();
            int getMinesCount();
            void processCellInput(Cell::CellController* cell_controller, UI::UIElement::ButtonType button_type);
        };
    }
}