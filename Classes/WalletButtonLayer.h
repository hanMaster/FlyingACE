
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
    std::string seed1;
    std::string seed2;
    std::string seed3;
    std::string seed4;
    std::string seed5;
    std::string seed6;
    std::string seed7;
    std::string seed8;
    std::string seed9;
    std::string seed10;
    std::string seed11;
    std::string seed12;

    std::string seedPhrase;
    std::string passphrase;
    const char *signer;
    std::string address;
    int score;

	virtual bool init() override;
    void initSeed();
	void goToWelcomeCallback(Ref* pSender);
	void connectCallback(Ref* pSender);
	void saveCallback(Ref* pSender);
	void loadCallback(Ref* pSender);
	void resetCallback(Ref* pSender);
	void setLocalCallback(Ref* pSender);
	void buyTokenCallback(Ref* pSender);
	void sellTokenCallback(Ref* pSender);
    void textFieldEvent(Ref *pSender, cocos2d::ui::TextField::EventType type);
    void buildSeedPhrase();
    void setStatus(const std::string&, bool);
    double parseAmount();
};

#endif /* WALLETBUTTONLAYER_H_ */
