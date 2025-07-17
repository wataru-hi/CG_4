#include "ModelManager.h"
using namespace KamataEngine;

ModelManager::~ModelManager() {
	uint32_t i = 0;
	for (auto const& model : Models_) {
		
		
	}
}

bool ModelManager::CreateModel(std::string modelFilePath, std::string idName) {
	if (Models_.find(idName) != Models_.end()) {
		return false;
	}

	// ModelInfoを作成し、unique_ptrで管理
	ModelInfo info;
	info.model = std::make_unique<KamataEngine::Model>(Model::CreateFromOBJ(modelFilePath));
	info.worldTransform.Initialize();
	
	Models_.emplace(idName, std::move(info));
	return true;
}

bool ModelManager::DrawModel() { 
	
}
