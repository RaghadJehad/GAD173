#include "SceneManager.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::LoadScene(int sceneIndex)
{
	currentSceneIndex = sceneIndex;
}

void SceneManager::AddScene(Scene& scene)
{
	scenes.push_back(scene); //adding a scene
}

void SceneManager::RemoveScene(int sceneIndex)
{
}

void SceneManager::Update()
{
	scenes[currentSceneIndex].Update();
}

void SceneManager::Render(sf::RenderWindow& window)
{
	scenes[currentSceneIndex].Render(window);
}
