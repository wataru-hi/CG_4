#include "SpriteManger.h"


using namespace KamataEngine;

// デストラクタ
// クラスが破棄されるときに、管理している全てのスプライトとテクスチャを解放します。
inline SpriteManager::~SpriteManager() {
	for (auto const& [id, sprite_info] : sprites_) {
		if (sprite_info.sprite != nullptr) {
			delete sprite_info.sprite; // スプライトオブジェクトを解放
		}
		// テクスチャもアンロードする場合
		TextureManager::Unload(sprite_info.textureHandle);
	}
	sprites_.clear(); // マップをクリア
	std::cout << "SpriteManager: All sprites and textures cleared." << std::endl;
}

// 新しいスプライトを作成し、管理対象に追加します。
// id: スプライトを一意に識別するための文字列ID
// filePath: ロードする画像ファイルのパス
// initialPosition: スプライトの初期位置 (例: {0, 0})
// 成功した場合true、同じIDのスプライトが既に存在する場合falseを返します。
inline bool SpriteManager::CreateSprite(const std::string& id, const char* filePath, const Vector2 initialPosition) {
	if (sprites_.count(id)) {
		std::cerr << "Error: Sprite with ID '" << id << "' already exists. Cannot create." << std::endl;
		return false;
	}

	uint32_t textureHandle = TextureManager::Load(filePath);
	Sprite* newSprite = Sprite::Create(textureHandle, initialPosition);

	// スプライトとその関連情報を構造体にまとめて保存
	SpriteInfo info;
	info.textureHandle = textureHandle;
	info.sprite = newSprite;
	sprites_[id] = info;

	std::cout << "SpriteManager: Created and added sprite '" << id << "'." << std::endl;
	return true;
}

// 指定されたIDのスプライトを取得します。
// スプライトが存在しない場合はnullptrを返します。
inline Sprite* SpriteManager::GetSprite(const std::string& id) {
	auto it = sprites_.find(id);
	if (it != sprites_.end()) {
		return it->second.sprite;
	}
	std::cerr << "Warning: Sprite with ID '" << id << "' not found. Returning nullptr." << std::endl;
	return nullptr;
}

// 指定されたIDのスプライトを描画します。
inline void SpriteManager::DrawSprite(const std::string& id) {
	Sprite* sprite = GetSprite(id);
	if (sprite != nullptr) {
		sprite->Draw();
	}
}

// 指定されたIDのスプライトを管理対象から削除し、関連リソースを解放します。
// 成功した場合true、スプライトが存在しない場合falseを返します。
inline bool SpriteManager::RemoveSprite(const std::string& id) {
	auto it = sprites_.find(id);
	if (it != sprites_.end()) {
		if (it->second.sprite != nullptr) {
			delete it->second.sprite; // スプライトオブジェクトを解放
		}
		TextureManager::Unload(it->second.textureHandle); // 関連するテクスチャもアンロード
		sprites_.erase(it);                               // マップからエントリを削除
		std::cout << "SpriteManager: Removed sprite '" << id << "' and its resources." << std::endl;
		return true;
	}
	std::cerr << "Warning: Attempted to remove non-existent sprite with ID '" << id << "'." << std::endl;
	return false;
}

void SpriteManager::SetSpritePosition(const std::string& id, const Vector2 newPosition) {
	Sprite* sprite = GetSprite(id);
	if (sprite != nullptr) {
		sprite->SetPosition(newPosition);
	}
}
