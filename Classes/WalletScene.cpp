
#include "WalletScene.h"

USING_NS_CC;

Scene* WalletScene::walletScene = nullptr;

Scene* WalletScene::create() {
	walletScene = Scene::create();

    WalletBackgroundLayer* walletBackgroundLayer = WalletBackgroundLayer::create();
	walletScene->addChild(walletBackgroundLayer);

    WalletButtonLayer* walletButtonLayer = WalletButtonLayer::create();
	walletScene->addChild(walletButtonLayer);

	return walletScene;
}
