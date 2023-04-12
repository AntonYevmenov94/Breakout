#pragma once
#include <glad/glad.h>
#include <glfw3.h>

enum GameState
{
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};

class Game
{
public:
	// Game state
	GameState State;
	bool Keys[1024];
	unsigned int Width, Height;

	Game(unsigned int width, unsigned int height);

	~Game();

	// Initialize start game state(load shaders, textures, levels)
	void Init();

	// Game loop
	void ProcessInput(float dt);
	void Update(float dt);
	void Render();
};

