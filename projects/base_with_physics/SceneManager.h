#pragma once
#include "Scene.h"
#include <vector>

class SceneManager
{
private:
	int currentSceneIndex;
	std::vector<Scene> scenes;

public:
	SceneManager();
	~SceneManager();
	void LoadScene(int sceneIndex);
	void AddScene(Scene& scene);
	void RemoveScene(int sceneIndex);
	//void Load();
	virtual void Update();
	void Render(sf::RenderWindow& window);
	inline const int& GetActiveScene() { return currentSceneIndex; }
};

