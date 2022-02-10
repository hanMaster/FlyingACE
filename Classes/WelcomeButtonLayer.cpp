/*
 * WelcomeButtonLayer.cpp
 *
 *  Created on: 2015年1月25日
 *      Author: netbeen
 */
#include "WelcomeButtonLayer.h"

USING_NS_CC;

bool WelcomeButtonLayer::init() {
    Vector<MenuItem*> MenuItems;

	MenuItemSprite* startGameButtonItemSprite = MenuItemSprite::create(Sprite::createWithSpriteFrameName("startGameButton.png"),
            Sprite::createWithSpriteFrameName("startGameButton.png"), CC_CALLBACK_1(WelcomeButtonLayer::startGameButtonCallback, this));

    MenuItems.pushBack(startGameButtonItemSprite);
	Menu* startGameButton = Menu::createWithArray(MenuItems);


	startGameButton->setAnchorPoint(Point(0.0f, 1.0f));
	startGameButton->setPosition(Director::getInstance()->getWinSize().width/2, 200);

	auto walletItem = MenuItemImage::create("images/solana-coin.png", "images/solana-coin.png", CC_CALLBACK_1(WelcomeButtonLayer::goToWalletCallback, this));
    walletItem->setScale(0.5);

    auto menu = Menu::create(walletItem, NULL);
    menu->setAnchorPoint(Point(0.0f, 1.0f));
    menu->setPosition(Director::getInstance()->getWinSize().width - 100, 1200);


    this->addChild(menu, 1);
	this->addChild(startGameButton, 1);
	return true;
}

void WelcomeButtonLayer::startGameButtonCallback(Ref* pSender) {
	Scene* resultSceneWithAnimation = TransitionFade::create(2.0f, SelectScene::create());
	Director::getInstance()->replaceScene(resultSceneWithAnimation);
}

void WelcomeButtonLayer::goToWalletCallback(Ref* pSender) {
	Scene* walletSceneWithAnimation = TransitionFade::create(2.0f, WalletScene::create());
//    Director::getInstance()->getEventDispatcher()->removeEventListener(listener);
	Director::getInstance()->replaceScene(walletSceneWithAnimation);
}
