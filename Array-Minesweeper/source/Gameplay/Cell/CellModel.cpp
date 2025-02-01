#include "../../header/Gameplay/Cell/CellModel.h"
#include <SFML/Graphics.hpp>
using namespace sf;

namespace Gameplay
{
	namespace Cell
	{
		CellModel::CellModel(int cell_index)
		{
			this->cell_index = cell_index;
		}

		CellModel::~CellModel() = default;

		CellState CellModel::getCellState()
		{
			return cell_state;
		}

		void CellModel::setCellState(CellState state)
		{
			cell_state = state;
		}

		CellValue CellModel::getCellValue()
		{
			return cell_value;
		}

		void CellModel::setCellValue(CellValue value)
		{
			cell_value = value;
		}

		void CellModel::reset()
		{
			cell_state = CellState::HIDDEN;
			cell_value = CellValue::EMPTY;
		}

		sf::Vector2i CellModel::getCellPosition()
		{
			return position;
		}

		int CellModel::getCellIndex()
		{
			return cell_index;
		}
	}
}