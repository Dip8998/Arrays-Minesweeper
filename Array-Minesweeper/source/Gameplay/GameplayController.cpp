#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Gameplay/Board/BoardService.h"
#include "../../header/Global/ServiceLocator.h"

namespace Gameplay
{
    using namespace Board;
    using namespace Global;

    GameplayController::GameplayController() {}

    GameplayController::~GameplayController() {  }

    void GameplayController::initialize() {  }

    void GameplayController::update()
    {
    }

    void GameplayController::render() {  }

    void GameplayController::restart() 
    { 
        ServiceLocator::getInstance()->getBoardService()->resetBoard();
    }
}