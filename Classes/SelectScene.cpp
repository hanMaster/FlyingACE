/*
 * SelectScene.cpp
 *
 *  Created on: 2015年1月30日
 *      Author: netbeen
 */

#include "SelectScene.h"

USING_NS_CC;

Scene* SelectScene::selectScene = nullptr;

Scene* SelectScene::create() {
	selectScene = Scene::create();

	SelectBackgroundLayer* selectBackgroundLayer = SelectBackgroundLayer::create();
	selectScene->addChild(selectBackgroundLayer);

	SelectButtonLayer* selectButtonLayer = SelectButtonLayer::create();
	selectScene->addChild(selectButtonLayer);

	return selectScene;

}
