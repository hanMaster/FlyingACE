
#ifndef WALLETBACKGROUNDLAYER_H_
#define WALLETBACKGROUNDLAYER_H_

#include "cocos2d.h"

class WalletBackgroundLayer : public cocos2d::Layer{
public:
	CREATE_FUNC(WalletBackgroundLayer);
private:
	virtual bool init() override;
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event) override;
};

#endif /* WALLETBACKGROUNDLAYER_H_ */
