#pragma once
#include "kamataEngine.h"

#include <iostream>
#include <map>    // std::map ‚Ì‚½‚ß‚É•K—v

enum class ModelType {
	player,
	Enemy,
	Item,
	Attack,
};

class ModelManager {
public:
	ModelManager();

	~ModelManager();

	bool CreateModel(std::string modelName, std::string idName);

	bool DrawModel();

	KamataEngine::Model* GetModel(std::string idName);

private:
	struct ModelInfo {
		std::unique_ptr<KamataEngine::Model> model;
		KamataEngine::WorldTransform worldTransform;
	};
	std::string idName;
	std::map<std::string, ModelInfo> Models_;
};
