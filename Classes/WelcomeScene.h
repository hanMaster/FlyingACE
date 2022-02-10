#ifndef WELCOMESCENE_H_
#define WELCOMESCENE_H_

#include "cocos2d.h"
#include "WelcomeButtonLayer.h"
#include "WelcomeBackgroundLayer.h"

class WelcomeScene : public cocos2d::Scene{
public:
	static cocos2d::Scene* create();
private:
	static Scene* welcomeScene;
};

#endif /* WELCOMESCENE_H_ */
