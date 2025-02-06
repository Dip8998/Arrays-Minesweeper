#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Gameplay/Board/BoardService.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GameService.h"


namespace Gameplay
{
    using namespace Board;
    using namespace Global;
    using namespace Main;


    GameplayController::~GameplayController() {  }

    void GameplayController::initialize() {  }

    void GameplayController::update()
    {
        updateRemainingTime();
    }

    void GameplayController::render() {  }

    void GameplayController::restart() 
    { 
        ServiceLocator::getInstance()->getBoardService()->resetBoard();
    }

    void GameplayController::updateRemainingTime()
    {
        remaining_time -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
    }
    float GameplayController::getRemainingTime()
    {
        return remaining_time;
    }

    int GameplayController::getMinesCount()
    {
        return 10;
    }

    void GameplayController::beginGameOverTimer() { remaining_time = game_over_time; }

    void GameplayController::endGame(GameResult result)
    {
        // The switch statement handles the different possible outcomes of the game.
        switch (result)
        {
            // In case the game is won, the gameWon() method is called.
        case GameResult::WON:
            gameWon();
            break;
            // In case the game is lost, the gameLost() method is called.
        case GameResult::LOST:
            gameLost();
            break;
            // The default case is not used here as all possible game outcomes should be WON or LOST.
        default:
            // No action is needed for default case.
            break;
        }
    }

    void GameplayController::gameLost()
    {
        if (game_result == GameResult::NONE)
        {
            game_result = GameResult::LOST;
            beginGameOverTimer();
            board_service->showBoard();
            board_service->setBoardState(BoardState::COMPLETED);
        }
        else
        {
            showCredits();
        }

    }

    void GameplayController::gameWon()
    {
        // Implement game won specific logic here.
    }
    void GameplayController::showCredits() { 
        GameService::setGameState(GameState::CREDITS); 
    }
}