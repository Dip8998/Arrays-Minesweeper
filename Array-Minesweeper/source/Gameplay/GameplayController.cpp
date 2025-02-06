#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Gameplay/Board/BoardService.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GameService.h"


namespace Gameplay
{
    using namespace Board;
    using namespace Global;
    using namespace Main;


    GameplayController::~GameplayController() { board_service = nullptr; }

    void GameplayController::initialize() { board_service = ServiceLocator::getInstance()->getBoardService(); }

    void GameplayController::update()
    {
        updateRemainingTime();
        if (isTimeOver())
            endGame(GameResult::LOST);
    }

    void GameplayController::render() {  }

    void GameplayController::restart() 
    { 
        game_result = GameResult::NONE;
        board_service->resetBoard();
        remaining_time = max_level_duration;
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
    bool GameplayController::isTimeOver() { return (remaining_time <= 1); }

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