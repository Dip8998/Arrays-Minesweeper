#pragma once
#include "../../header/Graphics/GraphicService.h"
#include "../../header/Event/EventService.h"
#include "../../header/UI/UIService.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Gameplay/GameplayService.h"
#include "../../header/Gameplay/Board/BoardService.h"
#include "../../header/Time/TimeService.h"

using namespace Time;
namespace Global
{
    class ServiceLocator
    {
    private:
        EventM::EventService* event_service;
        Graphics::GraphicService* graphic_service;
        SoundM::SoundService* sound_service;
        UI::UIService* ui_service;
        Gameplay::GameplayService* gameplay_service;
        Gameplay::Board::BoardService* board_service;
        TimeService* time_service;

        ServiceLocator();
        ~ServiceLocator();

        void createServices();
        void clearAllServices();

    public:
        static ServiceLocator* getInstance();

        void initialize();
        void update();
        void render();

        EventM::EventService* getEventService();
        Graphics::GraphicService* getGraphicService();
        SoundM::SoundService* getSoundService();
        UI::UIService* getUIService();
        Gameplay::GameplayService* getGameplayService();
        Gameplay::Board::BoardService* getBoardService();
        TimeService* getTimeService();

        void deleteServiceLocator();
    };
}