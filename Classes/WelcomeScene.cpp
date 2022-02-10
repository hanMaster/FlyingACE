
#include "WelcomeScene.h"

USING_NS_CC;

Scene* WelcomeScene::welcomeScene = nullptr;

Scene* WelcomeScene::create() {
	auto welcomeScene = Scene::create();

    WelcomeBackgroundLayer* welcomeBackgroundLayer = WelcomeBackgroundLayer::create();
	welcomeScene->addChild(welcomeBackgroundLayer);

    WelcomeButtonLayer* welcomeButtonLayer = WelcomeButtonLayer::create();
	welcomeScene->addChild(welcomeButtonLayer);

	return welcomeScene;
}

