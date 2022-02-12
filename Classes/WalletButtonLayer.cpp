#include <iostream>
#include "ui/CocosGUI.h"
#include "WalletButtonLayer.h"
#include "wallet.h"

USING_NS_CC;

bool WalletButtonLayer::init() {
    /**
     * Seed label
     */
    auto seedLabel = Label::createWithTTF("Seed phrase", "fonts/MarkerFelt.ttf", 30);
    seedLabel->enableShadow();
    seedLabel->setColor(Color3B::ORANGE);
    seedLabel->setAnchorPoint(Point(0.0f, 1.0f));
    seedLabel->setPosition(Vec2(30, 1250));

    /**
     * Seed inputs
     */

    auto inputImage1 = MenuItemImage::create("images/small-input.png", "images/small-input.png", CC_CALLBACK_1(WalletButtonLayer::goToWelcomeCallback, this));
    inputImage1->setAnchorPoint(Point(0.0f, 0.5f));
    inputImage1->setPosition(Vec2(30 , 1185));

    ui::TextField* seedField1 = ui::TextField::create("Seed1", "fonts/MarkerFelt.ttf", 30);
    seedField1->setAnchorPoint(Point(0.0f, 0.5f));
    seedField1->setPosition(Vec2(40, 1185));
    seedField1->setColor(Color3B::BLUE);
    seedField1->setMaxLength(8);
    seedField1->setMaxLengthEnabled(true);
    seedField1->setTouchAreaEnabled(true);
    seedField1->setTouchSize(Size(220, 56));
    seedField1->addEventListener(CC_CALLBACK_2(WalletButtonLayer::textFieldEvent, this));

    auto inputImage2 = MenuItemImage::create("images/small-input.png", "images/small-input.png", CC_CALLBACK_1(WalletButtonLayer::goToWelcomeCallback, this));
    inputImage2->setAnchorPoint(Point(0.0f, 0.5f));
    inputImage2->setPosition(Vec2(195, 1185));

    ui::TextField* seedField2 = ui::TextField::create("Seed2","fonts/MarkerFelt.ttf",30);
    seedField2->setAnchorPoint(Point(0.0f, 0.5f));
    seedField2->setPosition(Vec2(205, 1185));
    seedField2->setColor(Color3B::BLUE);
    seedField2->setMaxLength(8);
    seedField2->setMaxLengthEnabled(true);
    seedField2->setTouchAreaEnabled(true);
    seedField2->setTouchSize(Size(220, 56));
    seedField2->addEventListener(CC_CALLBACK_2(WalletButtonLayer::textFieldEvent, this));

    auto inputImage3 = MenuItemImage::create("images/small-input.png", "images/small-input.png", CC_CALLBACK_1(WalletButtonLayer::goToWelcomeCallback, this));
    inputImage3->setAnchorPoint(Point(0.0f, 0.5f));
    inputImage3->setPosition(Vec2(360, 1185));

    ui::TextField* seedField3 = ui::TextField::create("Seed3","fonts/MarkerFelt.ttf",30);
    seedField3->setAnchorPoint(Point(0.0f, 0.5f));
    seedField3->setPosition(Vec2(370, 1185));
    seedField3->setColor(Color3B::BLUE);
    seedField3->setMaxLength(8);
    seedField3->setMaxLengthEnabled(true);
    seedField3->setTouchAreaEnabled(true);
    seedField3->setTouchSize(Size(220, 56));
    seedField3->addEventListener(CC_CALLBACK_2(WalletButtonLayer::textFieldEvent, this));

    auto inputImage4 = MenuItemImage::create("images/small-input.png", "images/small-input.png", CC_CALLBACK_1(WalletButtonLayer::goToWelcomeCallback, this));
    inputImage4->setAnchorPoint(Point(0.0f, 0.5f));
    inputImage4->setPosition(Vec2(525, 1185));

    ui::TextField* seedField4 = ui::TextField::create("Seed4","fonts/MarkerFelt.ttf",30);
    seedField4->setAnchorPoint(Point(0.0f, 0.5f));
    seedField4->setPosition(Vec2(535, 1185));
    seedField4->setColor(Color3B::BLUE);
    seedField4->setMaxLength(8);
    seedField4->setMaxLengthEnabled(true);
    seedField4->setTouchAreaEnabled(true);
    seedField4->setTouchSize(Size(220, 56));
    seedField4->addEventListener(CC_CALLBACK_2(WalletButtonLayer::textFieldEvent, this));

    auto inputImage5 = MenuItemImage::create("images/small-input.png", "images/small-input.png", CC_CALLBACK_1(WalletButtonLayer::goToWelcomeCallback, this));
    inputImage5->setAnchorPoint(Point(0.0f, 0.5f));
    inputImage5->setPosition(Vec2(30, 1125));

    ui::TextField* seedField5 = ui::TextField::create("Seed5","fonts/MarkerFelt.ttf",30);
    seedField5->setAnchorPoint(Point(0.0f, 0.5f));
    seedField5->setPosition(Vec2(40, 1125));
    seedField5->setColor(Color3B::BLUE);
    seedField5->setMaxLength(8);
    seedField5->setMaxLengthEnabled(true);
    seedField5->setTouchAreaEnabled(true);
    seedField5->setTouchSize(Size(220, 56));
    seedField5->addEventListener(CC_CALLBACK_2(WalletButtonLayer::textFieldEvent, this));

    auto inputImage6 = MenuItemImage::create("images/small-input.png", "images/small-input.png", CC_CALLBACK_1(WalletButtonLayer::goToWelcomeCallback, this));
    inputImage6->setAnchorPoint(Point(0.0f, 0.5f));
    inputImage6->setPosition(Vec2(195, 1125));

    ui::TextField* seedField6 = ui::TextField::create("Seed6","fonts/MarkerFelt.ttf",30);
    seedField6->setAnchorPoint(Point(0.0f, 0.5f));
    seedField6->setPosition(Vec2(205, 1125));
    seedField6->setColor(Color3B::BLUE);
    seedField6->setMaxLength(8);
    seedField6->setMaxLengthEnabled(true);
    seedField6->setTouchAreaEnabled(true);
    seedField6->setTouchSize(Size(220, 56));
    seedField6->addEventListener(CC_CALLBACK_2(WalletButtonLayer::textFieldEvent, this));

    auto inputImage7 = MenuItemImage::create("images/small-input.png", "images/small-input.png", CC_CALLBACK_1(WalletButtonLayer::goToWelcomeCallback, this));
    inputImage7->setAnchorPoint(Point(0.0f, 0.5f));
    inputImage7->setPosition(Vec2(360, 1125));

    ui::TextField* seedField7 = ui::TextField::create("Seed7","fonts/MarkerFelt.ttf",30);
    seedField7->setAnchorPoint(Point(0.0f, 0.5f));
    seedField7->setPosition(Vec2(370, 1125));
    seedField7->setColor(Color3B::BLUE);
    seedField7->setMaxLength(8);
    seedField7->setMaxLengthEnabled(true);
    seedField7->setTouchAreaEnabled(true);
    seedField7->setTouchSize(Size(220, 56));
    seedField7->addEventListener(CC_CALLBACK_2(WalletButtonLayer::textFieldEvent, this));

    auto inputImage8 = MenuItemImage::create("images/small-input.png", "images/small-input.png", CC_CALLBACK_1(WalletButtonLayer::goToWelcomeCallback, this));
    inputImage8->setAnchorPoint(Point(0.0f, 0.5f));
    inputImage8->setPosition(Vec2(525, 1125));

    ui::TextField* seedField8 = ui::TextField::create("Seed8","fonts/MarkerFelt.ttf",30);
    seedField8->setAnchorPoint(Point(0.0f, 0.5f));
    seedField8->setPosition(Vec2(535, 1125));
    seedField8->setColor(Color3B::BLUE);
    seedField8->setMaxLength(8);
    seedField8->setMaxLengthEnabled(true);
    seedField8->setTouchAreaEnabled(true);
    seedField8->setTouchSize(Size(220, 56));
    seedField8->addEventListener(CC_CALLBACK_2(WalletButtonLayer::textFieldEvent, this));

    auto inputImage9 = MenuItemImage::create("images/small-input.png", "images/small-input.png", CC_CALLBACK_1(WalletButtonLayer::goToWelcomeCallback, this));
    inputImage9->setAnchorPoint(Point(0.0f, 0.5f));
    inputImage9->setPosition(Vec2(30, 1065));

    ui::TextField* seedField9 = ui::TextField::create("Seed9","fonts/MarkerFelt.ttf",30);
    seedField9->setAnchorPoint(Point(0.0f, 0.5f));
    seedField9->setPosition(Vec2(40, 1065));
    seedField9->setColor(Color3B::BLUE);
    seedField9->setMaxLength(8);
    seedField9->setMaxLengthEnabled(true);
    seedField9->setTouchAreaEnabled(true);
    seedField9->setTouchSize(Size(220, 56));
    seedField9->addEventListener(CC_CALLBACK_2(WalletButtonLayer::textFieldEvent, this));

    auto inputImage10 = MenuItemImage::create("images/small-input.png", "images/small-input.png", CC_CALLBACK_1(WalletButtonLayer::goToWelcomeCallback, this));
    inputImage10->setAnchorPoint(Point(0.0f, 0.5f));
    inputImage10->setPosition(Vec2(195, 1065));

    ui::TextField* seedField10 = ui::TextField::create("Seed10","fonts/MarkerFelt.ttf",30);
    seedField10->setAnchorPoint(Point(0.0f, 0.5f));
    seedField10->setPosition(Vec2(205, 1065));
    seedField10->setColor(Color3B::BLUE);
    seedField10->setMaxLength(8);
    seedField10->setMaxLengthEnabled(true);
    seedField10->setTouchAreaEnabled(true);
    seedField10->setTouchSize(Size(220, 56));
    seedField10->addEventListener(CC_CALLBACK_2(WalletButtonLayer::textFieldEvent, this));

    auto inputImage11 = MenuItemImage::create("images/small-input.png", "images/small-input.png", CC_CALLBACK_1(WalletButtonLayer::goToWelcomeCallback, this));
    inputImage11->setAnchorPoint(Point(0.0f, 0.5f));
    inputImage11->setPosition(Vec2(360, 1065));

    ui::TextField* seedField11 = ui::TextField::create("Seed11","fonts/MarkerFelt.ttf",30);
    seedField11->setAnchorPoint(Point(0.0f, 0.5f));
    seedField11->setPosition(Vec2(370, 1065));
    seedField11->setColor(Color3B::BLUE);
    seedField11->setMaxLength(8);
    seedField11->setMaxLengthEnabled(true);
    seedField11->setTouchAreaEnabled(true);
    seedField11->setTouchSize(Size(220, 56));
    seedField11->addEventListener(CC_CALLBACK_2(WalletButtonLayer::textFieldEvent, this));

    auto inputImage12 = MenuItemImage::create("images/small-input.png", "images/small-input.png", CC_CALLBACK_1(WalletButtonLayer::goToWelcomeCallback, this));
    inputImage12->setAnchorPoint(Point(0.0f, 0.5f));
    inputImage12->setPosition(Vec2(525, 1065));

    ui::TextField* seedField12 = ui::TextField::create("Seed12","fonts/MarkerFelt.ttf",30);
    seedField12->setAnchorPoint(Point(0.0f, 0.5f));
    seedField12->setPosition(Vec2(535, 1065));
    seedField12->setColor(Color3B::BLUE);
    seedField12->setMaxLength(8);
    seedField12->setMaxLengthEnabled(true);
    seedField12->setTouchAreaEnabled(true);
    seedField12->setTouchSize(Size(220, 56));
    seedField12->addEventListener(CC_CALLBACK_2(WalletButtonLayer::textFieldEvent, this));

    /**
     * Passprase label
     */

    auto passPhraseLabel = Label::createWithTTF("Passphrase", "fonts/MarkerFelt.ttf", 30);
    passPhraseLabel->enableShadow();
    passPhraseLabel->setColor(Color3B::ORANGE);
    passPhraseLabel->setAnchorPoint(Point(0.0f, 1.0f));
    passPhraseLabel->setPosition(Vec2(30, 1010));

    /**
     * Passphrase input
     */

    auto wideImage = MenuItemImage::create("images/wide-input.png", "images/wide-input.png", CC_CALLBACK_1(WalletButtonLayer::goToWelcomeCallback, this));
    wideImage->setAnchorPoint(Point(0.0f, 0.5f));
    wideImage->setPosition(Vec2(30, 945));

    ui::TextField* passPhraseField = ui::TextField::create("Passphrase","fonts/MarkerFelt.ttf",30);
    passPhraseField->setAnchorPoint(Point(0.0f, 0.5f));
    passPhraseField->setPosition(Vec2(40, 945));
    passPhraseField->setColor(Color3B::BLUE);
    passPhraseField->setMaxLength(8);
    passPhraseField->setMaxLengthEnabled(true);
    passPhraseField->setTouchAreaEnabled(true);
    passPhraseField->setTouchSize(Size(220, 56));
    passPhraseField->addEventListener(CC_CALLBACK_2(WalletButtonLayer::textFieldEvent, this));


    /**
     * balance SOL Label
     */

    auto balanceSolLabel = Label::createWithTTF("SOL Balance: NOT CONNECTED", "fonts/MarkerFelt.ttf", 30);
    balanceSolLabel->enableShadow();
    balanceSolLabel->setAnchorPoint(Point(0.0f, 1.0f));
    balanceSolLabel->setPosition(Vec2(70, 600));
    balanceSolLabel->setName("balance");
    balanceSolLabel->setColor(Color3B::ORANGE);

    /**
     * Connect button
     */
    auto connectItem = MenuItemImage::create(
            "images/connect_btn.png",
            "images/connect_btn.png",
            CC_CALLBACK_1(WalletButtonLayer::connectCallback, this));

    connectItem->setScale(0.5);
    auto menuConnect = Menu::create(connectItem, NULL);
    menuConnect->setAnchorPoint(Point(0.0f, 1.0f));
    menuConnect->setPosition(Director::getInstance()->getWinSize().width - 100, 600);

    /**
     * Back button
     */
	auto walletItem = MenuItemImage::create(
            "images/back.png",
            "images/back.png",
            CC_CALLBACK_1(WalletButtonLayer::goToWelcomeCallback, this));

    walletItem->setScale(0.5);

    auto menuBack = Menu::create(walletItem, NULL);
    menuBack->setAnchorPoint(Point(0.0f, 1.0f));
    menuBack->setPosition(Director::getInstance()->getWinSize().width - 200, 100);

    

    
   

    
    
    this->addChild(seedLabel, 1);
    this->addChild(inputImage1, 1);
    this->addChild(seedField1, 2);
    this->addChild(inputImage2, 1);
    this->addChild(seedField2, 2);
    this->addChild(inputImage3, 1);
    this->addChild(seedField3, 2);
    this->addChild(inputImage4, 1);
    this->addChild(seedField4, 2);
    this->addChild(inputImage5, 1);
    this->addChild(seedField5, 2);
    this->addChild(inputImage6, 1);
    this->addChild(seedField6, 2);
    this->addChild(inputImage7, 1);
    this->addChild(seedField7, 2);
    this->addChild(inputImage8, 1);
    this->addChild(seedField8, 2);
    this->addChild(inputImage9, 1);
    this->addChild(seedField9, 2);
    this->addChild(inputImage10, 1);
    this->addChild(seedField10, 2);
    this->addChild(inputImage11, 1);
    this->addChild(seedField11, 2);
    this->addChild(inputImage12, 1);
    this->addChild(seedField12, 2);

    this->addChild(passPhraseLabel, 1);
    this->addChild(wideImage, 1);
    this->addChild(passPhraseField, 2);

    this->addChild(balanceSolLabel, 1);
    this->addChild(menuConnect, 1);
    this->addChild(menuBack, 1);

	return true;
}

void WalletButtonLayer::goToWelcomeCallback(Ref* pSender) {
	Scene* welcomeSceneWithAnimation = TransitionFade::create(2.0f, WelcomeScene::create());
	Director::getInstance()->replaceScene(welcomeSceneWithAnimation);
}
void WalletButtonLayer::connectCallback(Ref* pSender) {
    auto *balanceLabel = dynamic_cast<Label *>(this->getChildByName("balance"));
    const char *seed_phrase = "pitch trust globe fish fever anchor type used aunt enemy crop spatial";
    const char *passphrase = "localhost";

    const char* signer = init_signer(seed_phrase, passphrase);
    int balance = get_balance(signer);
    double bal = double (balance) / 1000000000;

    log("Balance: %d", balance);
    balanceLabel->setString(cocos2d::StringUtils::format("SOL Balance: %f", bal));
}

void WalletButtonLayer::textFieldEvent(Ref *pSender, cocos2d::ui::TextField::EventType type)
{
    auto *seedField = dynamic_cast<ui::TextField *>(pSender);

    switch (type)
    {
        case cocos2d::ui::TextField::EventType::ATTACH_WITH_IME:
        {
            seedField->setColor(Color3B::BLACK);
            log("Start typing");
            break;
        }
        case cocos2d::ui::TextField::EventType::DETACH_WITH_IME:
        {
            seedField->setColor(Color3B::GRAY);
            log("Stop typing");
            break;
        }
            
        case cocos2d::ui::TextField::EventType::INSERT_TEXT:
        {
            log("Inserted: %s", seedField->getString().c_str());
            break;
        }
            
        case cocos2d::ui::TextField::EventType::DELETE_BACKWARD:
        {
            break;
        }
        default:
            break;
    }
}
