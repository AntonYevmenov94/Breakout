#include "Game.h"

Game::Game(unsigned int width, unsigned int height)
{
	State = GameState::GAME_ACTIVE;
	Width = width;
	Height = height;
}

Game::~Game()
{
}

void Game::Init()
{
}

void Game::ProcessInput(float dt)
{
}

void Game::Update(float dt)
{
}

void Game::Render()
{
}
