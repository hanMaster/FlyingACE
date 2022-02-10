#ifndef WALLETSCENE_H_
#define WALLETSCENE_H_

#include "cocos2d.h"
#include "WalletBackgroundLayer.h"
#include "WalletButtonLayer.h"

class WalletScene :public cocos2d::Scene{
public:
	static cocos2d::Scene* create();
private:
	static Scene* walletScene;
};

#endif /* WALLETSCENE_H_*/
