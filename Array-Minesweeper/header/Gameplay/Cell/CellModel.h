#pragma once
#include <SFML/Graphics.hpp>

namespace Gameplay
{
    namespace Cell
    {
        enum class CellState
        {
            HIDDEN,
            OPEN,
            FLAGGED,
        };

        enum class CellValue
        {
            EMPTY,
            ONE,
            TWO,
            THREE,
            FOUR,
            FIVE,
            SIX,
            SEVEN,
            EIGHT,
            MINE,
        };

        class CellModel
        {
        private:
            CellState cell_state;
            CellValue cell_value;


        public:
            CellModel(int cell_index);
            ~CellModel();

            CellState getCellState();
            void setCellState(CellState state);

            CellValue getCellValue();
            void setCellValue(CellValue value);

            void reset();

            int cell_index;
            int getCellIndex();

            sf::Vector2i position;
            sf::Vector2i getCellPosition();
        };
    }
}