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

void SceneManager::AddScene(Scene* scene)
{
	scenes.push_back(scene); //adding a scene from the list of scenes
}

void SceneManager::RemoveScene(int sceneIndex)
{
}

void SceneManager::Update()
{
	if(scenes.size() > 0)
	scenes[currentSceneIndex]->Update();
}

void SceneManager::Render(sf::RenderWindow& window)
{
	if (scenes.size() > 0)
	scenes[currentSceneIndex]->Render(window);
}
