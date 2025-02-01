#include "../../header/Gameplay/Board/BoardView.h"
#include "../../header/Gameplay/Board/BoardController.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Graphics/GraphicService.h"


namespace Gameplay {

	namespace Board {

		using namespace UI::UIElement;
		//using namespace Cell;
		using namespace Global;

		BoardView::BoardView(BoardController* controller) {
			board_controller = controller;
			background_image = new ImageView();
			board_image = new ImageView();
			 
		}

		BoardView::~BoardView() {
			delete(background_image);
			delete(board_image);
		}

		void BoardView::initialize() {
			initializeBackgroundImage();
			initializeBoardImage();
		}

		void BoardView::update() {
			background_image->update();
			board_image->update();
		}

		void BoardView::render() {
			background_image->render();
			board_image->render();
		}

		void BoardView::initializeBackgroundImage()
		{
			sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

			background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
			background_image->setImageAlpha(background_alpha);
		}

		void BoardView::initializeBoardImage()
		{
			board_image->initialize(Config::board_texture_path, board_width, board_height, sf::Vector2f(0, 0));
			board_image->setCentreAlinged();
		}
	}

}
