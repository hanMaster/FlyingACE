
#ifndef WALLETBUTTONLAYER_H_
#define WALLETBUTTONLAYER_H_

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "WelcomeScene.h"
#include "WalletScene.h"

class WalletButtonLayer : public cocos2d::Layer{
public:
	CREATE_FUNC(WalletButtonLayer);
private:
	void goToWelcomeCallback(Ref* pSender);
	void connectCallback(Ref* pSender);
    void textFieldEvent(Ref *pSender, cocos2d::ui::TextField::EventType type);
	virtual bool init() override;
};

#endif /* WALLETBUTTONLAYER_H_ */
