#pragma once
#include "../../header/UI/Interface/IUIController.h"

namespace UI {

	namespace GameplayUI {

		class GameplayUIController : public Interface::IUIController {
		private:

		public:
			const int font_size = 110;
			const sf::Color text_color = sf::Color::Red;
			const float time_text_top_offset = 65.f;
			const float time_text_left_offset = 1090.f;
			UIElement::TextView* time_text;
			GameplayUIController();
			~GameplayUIController();
			void createTexts();
			void initialize();
			void initializeTexts();
			void initializeTimeText();
			void show();
			void update();
			void render();
			void updateTimeText();
			void destroy();

		};

	}

}