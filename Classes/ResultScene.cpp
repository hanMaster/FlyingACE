
#include "ResultScene.h"

USING_NS_CC;

Scene* ResultScene::resultScene = nullptr;

Scene* ResultScene::create(bool isWin, int score) {
	resultScene = Scene::create();

	ResultBackgroundLayer* resultBackgroundLayer = ResultBackgroundLayer::create();
	resultScene->addChild(resultBackgroundLayer);

	resultBackgroundLayer->setIsWin(isWin);
	resultBackgroundLayer->setScore(score);
	resultBackgroundLayer->displayInfomation();

	ResultButtonLayer* resultButtonLayer = ResultButtonLayer::create();
    resultButtonLayer->setScore(score);
	resultScene->addChild(resultButtonLayer);

	return resultScene;

}
