#include "kamataEngine.h"

#include <iostream>
#include <map>    // std::map のために必要
#include <string> // std::string のために必要

// 複数のスプライトを管理するクラス
class SpriteManager {
public:
	// コンストラクタ
	// デフォルトコンストラクタを使用します。
	SpriteManager() = default;

	// デストラクタ
	// クラスが破棄されるときに、管理している全てのスプライトとテクスチャを解放します。
	~SpriteManager();

	// 新しいスプライトを作成し、管理対象に追加します。
	// id: スプライトを一意に識別するための文字列ID
	// filePath: ロードする画像ファイルのパス
	// initialPosition: スプライトの初期位置 (例: {0, 0})
	// 成功した場合true、同じIDのスプライトが既に存在する場合falseを返します。
	bool CreateSprite(const std::string& id, const char* filePath, const KamataEngine::Vector2 initialPosition);

	// 指定されたIDのスプライトを取得します。
	// スプライトが存在しない場合はnullptrを返します。
	KamataEngine::Sprite* GetSprite(const std::string& id);

	// 指定されたIDのスプライトを描画します。
	void DrawSprite(const std::string& id);

	// 指定されたIDのスプライトを管理対象から削除し、関連リソースを解放します。
	// 成功した場合true、スプライトが存在しない場合falseを返します。
	bool RemoveSprite(const std::string& id);

	void SetSpritePosition(const std::string& id, const KamataEngine::Vector2 newPosition);

private:
	// スプライトオブジェクトとテクスチャハンドルを一緒に保持するための構造体
	struct SpriteInfo {
		uint32_t textureHandle;
		KamataEngine::Sprite* sprite;
	};
	// スプライトのIDをキーとして、SpriteInfoを管理するマップ
	std::map<std::string, SpriteInfo> sprites_;
};