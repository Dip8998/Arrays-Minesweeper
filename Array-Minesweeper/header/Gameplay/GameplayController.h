#pragma once
#include "../../header/Gameplay/Board/BoardController.h"
#include <SFML/Graphics.hpp>

namespace Gameplay
{
    class GameplayController
    {
    private:
        float remaining_time;


    public:
        GameplayController();
        ~GameplayController();

        void initialize();
        void update();
        void render();

        void restart();
        void updateRemainingTime();
        float getRemainingTime();

        int getMinesCount();

    };
}