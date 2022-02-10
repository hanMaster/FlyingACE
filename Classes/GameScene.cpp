/*
 * GameScene.cpp
 *
 *  Created on: 2015年1月25日
 *      Author: netbeen
 */

#include "GameScene.h"

USING_NS_CC;

Scene* GameScene::gameScene = nullptr;
GameBackgroundLayer* GameScene::gameBackgroundLayer = nullptr;
UFOLayer* GameScene::ufoLayer = nullptr;
BulletLayer* GameScene::bulletLayer = nullptr;
EnemyLayer* GameScene::enemyLayer = nullptr;
PlaneLayer* GameScene::planeLayer = nullptr;
ControlLayer* GameScene::controlLayer = nullptr;
EnemyBulletLayer* GameScene::enemyBulletLayer = nullptr;

Scene* GameScene::create() {
	gameScene = Scene::create();

	gameBackgroundLayer = GameBackgroundLayer::create();
	planeLayer = PlaneLayer::create();
	ufoLayer = UFOLayer::create();
	bulletLayer = BulletLayer::create();
	enemyLayer = EnemyLayer::create();
	controlLayer = ControlLayer::create();
	enemyBulletLayer = EnemyBulletLayer::create();


	gameScene->addChild(gameBackgroundLayer);
	gameScene->addChild(bulletLayer);
	gameScene->addChild(enemyBulletLayer);
	gameScene->addChild(enemyLayer);
	gameScene->addChild(planeLayer);
	gameScene->addChild(ufoLayer);
	gameScene->addChild(controlLayer);

	return gameScene;
}

PlaneLayer* GameScene::getPlaneLayer(){
	return this->planeLayer;
}

GameBackgroundLayer* GameScene::getGameBackgroundLayer(){
	return this->gameBackgroundLayer;
}

UFOLayer* GameScene::getUFOLayer(){
	return this->ufoLayer;
}
BulletLayer* GameScene::getBulletLayer(){
	return this->bulletLayer;
}
EnemyLayer* GameScene::getEnemyLayer(){
	return this->enemyLayer;
}
ControlLayer* GameScene::getControlLayer(){
	return this->controlLayer;
}

EnemyBulletLayer* GameScene::getEnemyBulletLayer(){
	return this->enemyBulletLayer;
}
