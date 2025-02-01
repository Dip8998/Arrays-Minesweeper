#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/Gameplay/Cell/CellView.h"
#include "../../../header/Gameplay/Cell/CellModel.h"
#include "../../../header/Global/ServiceLocator.h"
#include "../../../header/Sound/SoundService.h"

namespace Gameplay
{
	namespace Cell
	{
		using namespace Global;
		using namespace SoundM;

		CellController::CellController(int cell_index) 
		{
			cell_model = new CellModel(cell_index);
			cell_view = new CellView(this);
		}

		CellController::~CellController()
		{
			destroy();
		}

		CellState CellController::getCellState()
		{
			return cell_model->getCellState();
		}

		CellValue CellController::getCellValue()
		{
			return cell_model->getCellValue();
		}

		sf::Vector2i CellController::getCellPosition()
		{
			return cell_model->getCellPosition();
		}

		void CellController::initialize(float cell_width, float cell_height)
		{
			cell_view->initialize(cell_width, cell_height);
		}

		void CellController::update()
		{
			cell_view->update();
		}

		void CellController::render()
		{
			cell_view->render();
		}

		void CellController::destroy()
		{
			delete (cell_view);
			delete (cell_model);

		}

		void CellController::reset()
		{
			cell_model->reset();
		}

		int CellController::getCellIndex()
		{
			return cell_model->cell_index;
		}
	}
}