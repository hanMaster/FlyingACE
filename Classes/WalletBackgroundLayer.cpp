#include "WalletBackgroundLayer.h"

USING_NS_CC;

bool WalletBackgroundLayer::init() {
//	auto listenerkeyPad = EventListenerKeyboard::create();
//	listenerkeyPad->onKeyReleased = CC_CALLBACK_2(WalletBackgroundLayer::onKeyReleased, this);
//	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerkeyPad, this);

    Sprite* background = Sprite::createWithSpriteFrameName("img_bg_welcome.jpg");
	background->setAnchorPoint(Point(0, 0));
	background->setScale(2);
	this->addChild(background);

	return true;
}

void WalletBackgroundLayer::onKeyReleased(EventKeyboard::KeyCode keycode, Event* event) {
//	switch (keycode) {
//	case EventKeyboard::KeyCode::KEY_BACK:
//		Director::getInstance()->end();
//		break;
//	default:
//		break;
//	}
}
