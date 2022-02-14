#include <iostream>
#include <libc.h>
#include "ui/CocosGUI.h"
#include "WalletButtonLayer.h"
#include "wallet.h"

USING_NS_CC;

bool WalletButtonLayer::init() {
    this->initSeed();
    this->signer = "";

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

    auto inputImage1 = MenuItemImage::create("images/small-input.png", "images/small-input.png");
    inputImage1->setAnchorPoint(Point(0.0f, 0.5f));
    inputImage1->setPosition(Vec2(30, 1185));

    ui::TextField *seedField1 = ui::TextField::create("Seed1", "fonts/MarkerFelt.ttf", 30);
    seedField1->setAnchorPoint(Point(0.0f, 0.5f));
    seedField1->setPosition(Vec2(40, 1185));
    seedField1->setColor(Color3B::BLUE);
    seedField1->setMaxLength(8);
    seedField1->setMaxLengthEnabled(true);
    seedField1->setTouchAreaEnabled(true);
    seedField1->setTouchSize(Size(220, 56));
    seedField1->addEventListener(CC_CALLBACK_2(WalletButtonLayer::textFieldEvent, this));
    seedField1->setName("seed1");
    seedField1->setString(this->seed1);

    auto inputImage2 = MenuItemImage::create("images/small-input.png", "images/small-input.png");
    inputImage2->setAnchorPoint(Point(0.0f, 0.5f));
    inputImage2->setPosition(Vec2(195, 1185));

    ui::TextField *seedField2 = ui::TextField::create("Seed2", "fonts/MarkerFelt.ttf", 30);
    seedField2->setAnchorPoint(Point(0.0f, 0.5f));
    seedField2->setPosition(Vec2(205, 1185));
    seedField2->setColor(Color3B::BLUE);
    seedField2->setMaxLength(8);
    seedField2->setMaxLengthEnabled(true);
    seedField2->setTouchAreaEnabled(true);
    seedField2->setTouchSize(Size(220, 56));
    seedField2->addEventListener(CC_CALLBACK_2(WalletButtonLayer::textFieldEvent, this));
    seedField2->setName("seed2");
    seedField2->setString(this->seed2);

    auto inputImage3 = MenuItemImage::create("images/small-input.png", "images/small-input.png");
    inputImage3->setAnchorPoint(Point(0.0f, 0.5f));
    inputImage3->setPosition(Vec2(360, 1185));

    ui::TextField *seedField3 = ui::TextField::create("Seed3", "fonts/MarkerFelt.ttf", 30);
    seedField3->setAnchorPoint(Point(0.0f, 0.5f));
    seedField3->setPosition(Vec2(370, 1185));
    seedField3->setColor(Color3B::BLUE);
    seedField3->setMaxLength(8);
    seedField3->setMaxLengthEnabled(true);
    seedField3->setTouchAreaEnabled(true);
    seedField3->setTouchSize(Size(220, 56));
    seedField3->addEventListener(CC_CALLBACK_2(WalletButtonLayer::textFieldEvent, this));
    seedField3->setName("seed3");
    seedField3->setString(this->seed3);

    auto inputImage4 = MenuItemImage::create("images/small-input.png", "images/small-input.png");
    inputImage4->setAnchorPoint(Point(0.0f, 0.5f));
    inputImage4->setPosition(Vec2(525, 1185));

    ui::TextField *seedField4 = ui::TextField::create("Seed4", "fonts/MarkerFelt.ttf", 30);
    seedField4->setAnchorPoint(Point(0.0f, 0.5f));
    seedField4->setPosition(Vec2(535, 1185));
    seedField4->setColor(Color3B::BLUE);
    seedField4->setMaxLength(8);
    seedField4->setMaxLengthEnabled(true);
    seedField4->setTouchAreaEnabled(true);
    seedField4->setTouchSize(Size(220, 56));
    seedField4->addEventListener(CC_CALLBACK_2(WalletButtonLayer::textFieldEvent, this));
    seedField4->setName("seed4");
    seedField4->setString(this->seed4);

    auto inputImage5 = MenuItemImage::create("images/small-input.png", "images/small-input.png");
    inputImage5->setAnchorPoint(Point(0.0f, 0.5f));
    inputImage5->setPosition(Vec2(30, 1125));

    ui::TextField *seedField5 = ui::TextField::create("Seed5", "fonts/MarkerFelt.ttf", 30);
    seedField5->setAnchorPoint(Point(0.0f, 0.5f));
    seedField5->setPosition(Vec2(40, 1125));
    seedField5->setColor(Color3B::BLUE);
    seedField5->setMaxLength(8);
    seedField5->setMaxLengthEnabled(true);
    seedField5->setTouchAreaEnabled(true);
    seedField5->setTouchSize(Size(220, 56));
    seedField5->addEventListener(CC_CALLBACK_2(WalletButtonLayer::textFieldEvent, this));
    seedField5->setName("seed5");
    seedField5->setString(this->seed5);

    auto inputImage6 = MenuItemImage::create("images/small-input.png", "images/small-input.png");
    inputImage6->setAnchorPoint(Point(0.0f, 0.5f));
    inputImage6->setPosition(Vec2(195, 1125));

    ui::TextField *seedField6 = ui::TextField::create("Seed6", "fonts/MarkerFelt.ttf", 30);
    seedField6->setAnchorPoint(Point(0.0f, 0.5f));
    seedField6->setPosition(Vec2(205, 1125));
    seedField6->setColor(Color3B::BLUE);
    seedField6->setMaxLength(8);
    seedField6->setMaxLengthEnabled(true);
    seedField6->setTouchAreaEnabled(true);
    seedField6->setTouchSize(Size(220, 56));
    seedField6->addEventListener(CC_CALLBACK_2(WalletButtonLayer::textFieldEvent, this));
    seedField6->setName("seed6");
    seedField6->setString(this->seed6);

    auto inputImage7 = MenuItemImage::create("images/small-input.png", "images/small-input.png");
    inputImage7->setAnchorPoint(Point(0.0f, 0.5f));
    inputImage7->setPosition(Vec2(360, 1125));

    ui::TextField *seedField7 = ui::TextField::create("Seed7", "fonts/MarkerFelt.ttf", 30);
    seedField7->setAnchorPoint(Point(0.0f, 0.5f));
    seedField7->setPosition(Vec2(370, 1125));
    seedField7->setColor(Color3B::BLUE);
    seedField7->setMaxLength(8);
    seedField7->setMaxLengthEnabled(true);
    seedField7->setTouchAreaEnabled(true);
    seedField7->setTouchSize(Size(220, 56));
    seedField7->addEventListener(CC_CALLBACK_2(WalletButtonLayer::textFieldEvent, this));
    seedField7->setName("seed7");
    seedField7->setString(this->seed7);

    auto inputImage8 = MenuItemImage::create("images/small-input.png", "images/small-input.png");
    inputImage8->setAnchorPoint(Point(0.0f, 0.5f));
    inputImage8->setPosition(Vec2(525, 1125));

    ui::TextField *seedField8 = ui::TextField::create("Seed8", "fonts/MarkerFelt.ttf", 30);
    seedField8->setAnchorPoint(Point(0.0f, 0.5f));
    seedField8->setPosition(Vec2(535, 1125));
    seedField8->setColor(Color3B::BLUE);
    seedField8->setMaxLength(8);
    seedField8->setMaxLengthEnabled(true);
    seedField8->setTouchAreaEnabled(true);
    seedField8->setTouchSize(Size(220, 56));
    seedField8->addEventListener(CC_CALLBACK_2(WalletButtonLayer::textFieldEvent, this));
    seedField8->setName("seed8");
    seedField8->setString(this->seed8);

    auto inputImage9 = MenuItemImage::create("images/small-input.png", "images/small-input.png");
    inputImage9->setAnchorPoint(Point(0.0f, 0.5f));
    inputImage9->setPosition(Vec2(30, 1065));

    ui::TextField *seedField9 = ui::TextField::create("Seed9", "fonts/MarkerFelt.ttf", 30);
    seedField9->setAnchorPoint(Point(0.0f, 0.5f));
    seedField9->setPosition(Vec2(40, 1065));
    seedField9->setColor(Color3B::BLUE);
    seedField9->setMaxLength(8);
    seedField9->setMaxLengthEnabled(true);
    seedField9->setTouchAreaEnabled(true);
    seedField9->setTouchSize(Size(220, 56));
    seedField9->addEventListener(CC_CALLBACK_2(WalletButtonLayer::textFieldEvent, this));
    seedField9->setName("seed9");
    seedField9->setString(this->seed9);

    auto inputImage10 = MenuItemImage::create("images/small-input.png", "images/small-input.png");
    inputImage10->setAnchorPoint(Point(0.0f, 0.5f));
    inputImage10->setPosition(Vec2(195, 1065));

    ui::TextField *seedField10 = ui::TextField::create("Seed10", "fonts/MarkerFelt.ttf", 30);
    seedField10->setAnchorPoint(Point(0.0f, 0.5f));
    seedField10->setPosition(Vec2(205, 1065));
    seedField10->setColor(Color3B::BLUE);
    seedField10->setMaxLength(8);
    seedField10->setMaxLengthEnabled(true);
    seedField10->setTouchAreaEnabled(true);
    seedField10->setTouchSize(Size(220, 56));
    seedField10->addEventListener(CC_CALLBACK_2(WalletButtonLayer::textFieldEvent, this));
    seedField10->setName("seed10");
    seedField10->setString(this->seed10);

    auto inputImage11 = MenuItemImage::create("images/small-input.png", "images/small-input.png");
    inputImage11->setAnchorPoint(Point(0.0f, 0.5f));
    inputImage11->setPosition(Vec2(360, 1065));

    ui::TextField *seedField11 = ui::TextField::create("Seed11", "fonts/MarkerFelt.ttf", 30);
    seedField11->setAnchorPoint(Point(0.0f, 0.5f));
    seedField11->setPosition(Vec2(370, 1065));
    seedField11->setColor(Color3B::BLUE);
    seedField11->setMaxLength(8);
    seedField11->setMaxLengthEnabled(true);
    seedField11->setTouchAreaEnabled(true);
    seedField11->setTouchSize(Size(220, 56));
    seedField11->addEventListener(CC_CALLBACK_2(WalletButtonLayer::textFieldEvent, this));
    seedField11->setName("seed11");
    seedField11->setString(this->seed11);

    auto inputImage12 = MenuItemImage::create("images/small-input.png", "images/small-input.png");
    inputImage12->setAnchorPoint(Point(0.0f, 0.5f));
    inputImage12->setPosition(Vec2(525, 1065));

    ui::TextField *seedField12 = ui::TextField::create("Seed12", "fonts/MarkerFelt.ttf", 30);
    seedField12->setAnchorPoint(Point(0.0f, 0.5f));
    seedField12->setPosition(Vec2(535, 1065));
    seedField12->setColor(Color3B::BLUE);
    seedField12->setMaxLength(8);
    seedField12->setMaxLengthEnabled(true);
    seedField12->setTouchAreaEnabled(true);
    seedField12->setTouchSize(Size(220, 56));
    seedField12->addEventListener(CC_CALLBACK_2(WalletButtonLayer::textFieldEvent, this));
    seedField12->setName("seed12");
    seedField12->setString(this->seed12);

    /**
     * Passphrase label
     */

    auto passPhraseLabel = Label::createWithTTF("Passphrase", "fonts/MarkerFelt.ttf", 30);
    passPhraseLabel->enableShadow();
    passPhraseLabel->setColor(Color3B::ORANGE);
    passPhraseLabel->setAnchorPoint(Point(0.0f, 1.0f));
    passPhraseLabel->setPosition(Vec2(30, 1010));

    /**
     * Passphrase input
     */

    auto wideImage = MenuItemImage::create("images/wide-input.png", "images/wide-input.png");
    wideImage->setAnchorPoint(Point(0.0f, 0.5f));
    wideImage->setPosition(Vec2(30, 945));

    ui::TextField *passPhraseField = ui::TextField::create("Passphrase", "fonts/MarkerFelt.ttf", 30);
    passPhraseField->setAnchorPoint(Point(0.0f, 0.5f));
    passPhraseField->setPosition(Vec2(40, 945));
    passPhraseField->setColor(Color3B::BLUE);
    passPhraseField->setMaxLength(50);
    passPhraseField->setMaxLengthEnabled(true);
    passPhraseField->setTouchAreaEnabled(true);
    passPhraseField->setTouchSize(Size(485, 56));
    passPhraseField->addEventListener(CC_CALLBACK_2(WalletButtonLayer::textFieldEvent, this));
    passPhraseField->setName("passphrase");
    passPhraseField->setPasswordEnabled(true);
    passPhraseField->setPasswordStyleText("*");
    passPhraseField->setString(this->passphrase);

    /**
     * address Label
     */

    auto addressLabel = Label::createWithTTF(this->address, "fonts/MarkerFelt.ttf", 30);
    addressLabel->enableShadow();
    addressLabel->setAnchorPoint(Point(0.0f, 1.0f));
    addressLabel->setPosition(Vec2(30, 900));
    addressLabel->setName("address");
    addressLabel->setColor(Color3B::ORANGE);

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
    menuConnect->setPosition(Director::getInstance()->getWinSize().width - 100, 945);

    /**
     * Game token balance Label
     */

    auto balanceTokenLabel = Label::createWithTTF("Game token balance: NOT CONNECTED", "fonts/MarkerFelt.ttf", 30);
    balanceTokenLabel->enableShadow();
    balanceTokenLabel->setAnchorPoint(Point(0.0f, 1.0f));
    balanceTokenLabel->setPosition(Vec2(30, 855));
    balanceTokenLabel->setName("tokenBalance");
    balanceTokenLabel->setColor(Color3B::ORANGE);

    /**
     * Token amount input
     */

    auto inputTokenAmount = MenuItemImage::create("images/amount-input.png", "images/small-input.png");
    inputTokenAmount->setAnchorPoint(Point(0.0f, 0.5f));
    inputTokenAmount->setPosition(Vec2(30, 780));

    ui::TextField *tokenAmountField = ui::TextField::create("Amount", "fonts/MarkerFelt.ttf", 30);
    tokenAmountField->setAnchorPoint(Point(0.0f, 0.5f));
    tokenAmountField->setPosition(Vec2(40, 780));
    tokenAmountField->setColor(Color3B::BLUE);
    tokenAmountField->setMaxLength(18);
    tokenAmountField->setMaxLengthEnabled(true);
    tokenAmountField->setTouchAreaEnabled(true);
    tokenAmountField->setTouchSize(Size(280, 56));
    tokenAmountField->addEventListener(CC_CALLBACK_2(WalletButtonLayer::textFieldEvent, this));
    tokenAmountField->setName("tokenAmount");

    /**
     * Buy token button
     */
    auto buyTokenItem = MenuItemImage::create(
            "images/buy_btn.png",
            "images/buy_btn.png",
            CC_CALLBACK_1(WalletButtonLayer::buyTokenCallback, this));

    buyTokenItem->setScale(0.5);
    auto menuBuy = Menu::create(buyTokenItem, NULL);
    menuBuy->setAnchorPoint(Point(0.0f, 1.0f));
    menuBuy->setPosition(420, 780);

    /**
     * Sell token button
     */
    auto sellTokenItem = MenuItemImage::create(
            "images/sell_btn.png",
            "images/sell_btn.png",
            CC_CALLBACK_1(WalletButtonLayer::sellTokenCallback, this));

    sellTokenItem->setScale(0.5);
    auto menuSell = Menu::create(sellTokenItem, NULL);
    menuSell->setAnchorPoint(Point(0.0f, 1.0f));
    menuSell->setPosition(580, 780);

    /**
     * balance SOL Label
     */

    auto balanceSolLabel = Label::createWithTTF("SOL balance: NOT CONNECTED", "fonts/MarkerFelt.ttf", 30);
    balanceSolLabel->enableShadow();
    balanceSolLabel->setAnchorPoint(Point(0.0f, 1.0f));
    balanceSolLabel->setPosition(Vec2(30, 600));
    balanceSolLabel->setName("balance");
    balanceSolLabel->setColor(Color3B::ORANGE);


    /**
     * score Label
     */

    this->score = UserDefault::getInstance()->getIntegerForKey("score", 0);
    auto scoreLabelValue = cocos2d::StringUtils::format("Best score: %d", this->score);

    auto scoreSolLabel = Label::createWithTTF(scoreLabelValue, "fonts/MarkerFelt.ttf", 30);
    scoreSolLabel->enableShadow();
    scoreSolLabel->setAnchorPoint(Point(0.0f, 1.0f));
    scoreSolLabel->setPosition(Vec2(30, 530));
    scoreSolLabel->setName("score");
    scoreSolLabel->setColor(Color3B::ORANGE);

    /**
     * Load score button
     */
    auto loadScoreItem = MenuItemImage::create(
            "images/load_score.png",
            "images/load_score.png",
            CC_CALLBACK_1(WalletButtonLayer::loadCallback, this));

    loadScoreItem->setScale(0.5);
    auto menuLoad = Menu::create(loadScoreItem, NULL);
    menuLoad->setAnchorPoint(Point(0.0f, 1.0f));
    menuLoad->setPosition(100, 445);

    /**
     * Save score button
     */
    auto saveScoreItem = MenuItemImage::create(
            "images/save_score.png",
            "images/save_score.png",
            CC_CALLBACK_1(WalletButtonLayer::saveCallback, this));

    saveScoreItem->setScale(0.5);
    auto menuSave = Menu::create(saveScoreItem, NULL);
    menuSave->setAnchorPoint(Point(0.0f, 1.0f));
    menuSave->setPosition(260, 445);

    /**
     * Reset local score button
     */
    auto resetScoreItem = MenuItemImage::create(
            "images/reset_score.png",
            "images/reset_score.png",
            CC_CALLBACK_1(WalletButtonLayer::resetCallback, this));

    resetScoreItem->setScale(0.5);
    auto menuReset = Menu::create(resetScoreItem, NULL);
    menuReset->setAnchorPoint(Point(0.0f, 1.0f));
    menuReset->setPosition(420, 445);

    /**
     * Set local score button
     */
    auto setLocalScoreItem = MenuItemImage::create(
            "images/set_score.png",
            "images/set_score.png",
            CC_CALLBACK_1(WalletButtonLayer::setLocalCallback, this));

    setLocalScoreItem->setScale(0.5);
    auto menuSetLocal = Menu::create(setLocalScoreItem, NULL);
    menuSetLocal->setAnchorPoint(Point(0.0f, 1.0f));
    menuSetLocal->setPosition(580, 445);

    /**
     * Status Label
     */
    auto statusLabel = Label::createWithTTF("", "fonts/MarkerFelt.ttf", 30);
    statusLabel->enableShadow();
    statusLabel->setAnchorPoint(Point(0.0f, 1.0f));
    statusLabel->setPosition(Vec2(30, 200));
    statusLabel->setName("status");
    statusLabel->setColor(Color3B::RED);

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

    this->addChild(addressLabel, 1);
    this->addChild(balanceTokenLabel, 1);
    this->addChild(inputTokenAmount, 1);
    this->addChild(tokenAmountField, 2);
    this->addChild(menuBuy, 1);
    this->addChild(menuSell, 1);

    this->addChild(balanceSolLabel, 1);
    this->addChild(scoreSolLabel, 1);
    this->addChild(menuConnect, 1);
    this->addChild(menuLoad, 1);
    this->addChild(menuSave, 1);
    this->addChild(menuReset, 1);
    this->addChild(menuSetLocal, 1);
    this->addChild(statusLabel, 1);
    this->addChild(menuBack, 1);

    return true;
}

void WalletButtonLayer::goToWelcomeCallback(Ref *pSender) {
    Scene *welcomeSceneWithAnimation = TransitionFade::create(2.0f, WelcomeScene::create());
    Director::getInstance()->replaceScene(welcomeSceneWithAnimation);
}

void WalletButtonLayer::connectCallback(Ref *pSender) {
    auto *balanceLabel = dynamic_cast<Label *>(this->getChildByName("balance"));
    auto *tokenBalanceLabel = dynamic_cast<Label *>(this->getChildByName("tokenBalance"));
    auto *addressLabel = dynamic_cast<Label *>(this->getChildByName("address"));
    this->buildSeedPhrase();

    this->signer = init_signer(this->seedPhrase.c_str(), this->passphrase.c_str());
    long int balance = get_balance(signer);
    double tokenBalance = get_token_balance(signer);
    this->address = get_address(signer);
    double bal = double(balance) / 1000000000;

    balanceLabel->setString(cocos2d::StringUtils::format("SOL Balance: %f", bal));
    tokenBalanceLabel->setString(cocos2d::StringUtils::format("Game token balance: %f", tokenBalance));
    addressLabel->setString(this->address);
    this->setStatus("Wallet connected", false);
}

void WalletButtonLayer::textFieldEvent(Ref *pSender, cocos2d::ui::TextField::EventType type) {
    auto *textField = dynamic_cast<ui::TextField *>(pSender);

    switch (type) {
        case cocos2d::ui::TextField::EventType::ATTACH_WITH_IME: {
            textField->setColor(Color3B::BLACK);
            log("Start typing");
            break;
        }

        case cocos2d::ui::TextField::EventType::DETACH_WITH_IME: {
            textField->setColor(Color3B::GRAY);
            log("Stop typing");
            UserDefault::getInstance()->setStringForKey(textField->getName().c_str(), textField->getString());
            this->initSeed();
            break;
        }

        case cocos2d::ui::TextField::EventType::INSERT_TEXT: {
            if (textField->getName() == "tokenAmount") {
                log("Amount entered: %s", textField->getString().c_str());
            }
        }

        case cocos2d::ui::TextField::EventType::DELETE_BACKWARD: {
            break;
        }

        default:
            break;
    }
}

void WalletButtonLayer::initSeed() {
    this->seed1 = UserDefault::getInstance()->getStringForKey("seed1");
    this->seed2 = UserDefault::getInstance()->getStringForKey("seed2");
    this->seed3 = UserDefault::getInstance()->getStringForKey("seed3");
    this->seed4 = UserDefault::getInstance()->getStringForKey("seed4");
    this->seed5 = UserDefault::getInstance()->getStringForKey("seed5");
    this->seed6 = UserDefault::getInstance()->getStringForKey("seed6");
    this->seed7 = UserDefault::getInstance()->getStringForKey("seed7");
    this->seed8 = UserDefault::getInstance()->getStringForKey("seed8");
    this->seed9 = UserDefault::getInstance()->getStringForKey("seed9");
    this->seed10 = UserDefault::getInstance()->getStringForKey("seed10");
    this->seed11 = UserDefault::getInstance()->getStringForKey("seed11");
    this->seed12 = UserDefault::getInstance()->getStringForKey("seed12");
    this->passphrase = UserDefault::getInstance()->getStringForKey("passphrase");
}

void WalletButtonLayer::buildSeedPhrase() {
    this->seedPhrase = this->seed1 + " " +
                       this->seed2 + " " +
                       this->seed3 + " " +
                       this->seed4 + " " +
                       this->seed5 + " " +
                       this->seed6 + " " +
                       this->seed7 + " " +
                       this->seed8 + " " +
                       this->seed9 + " " +
                       this->seed10 + " " +
                       this->seed11 + " " +
                       this->seed12;
}

void WalletButtonLayer::loadCallback(Ref *pSender) {
    auto *scoreLabel = dynamic_cast<Label *>(this->getChildByName("score"));
    this->score = get_score();
    scoreLabel->setString(cocos2d::StringUtils::format("Best score: %d", this->score));
    this->setStatus("Best score loaded from blockchain", false);
}

void WalletButtonLayer::saveCallback(Ref *pSender) {
    if (strlen(this->signer) > 0) {
        save_score(this->signer, this->score);
        this->setStatus("Best score has been saved in blockchain", false);
    } else {
        this->setStatus("Need to connect to the wallet", true);
    }
}

void WalletButtonLayer::resetCallback(Ref *pSender) {
    auto *scoreLabel = dynamic_cast<Label *>(this->getChildByName("score"));
    scoreLabel->setString("Best score: 0");
    this->score = 0;
    UserDefault::getInstance()->setIntegerForKey("score", this->score);
    this->setStatus("Local best score has been reset to 0", false);
}

void WalletButtonLayer::setLocalCallback(Ref *pSender) {
    UserDefault::getInstance()->setIntegerForKey("score", this->score);
    this->setStatus("Best score has been set as local score", false);
}

void WalletButtonLayer::buyTokenCallback(Ref *pSender) {
    double amount = this->parseAmount();
    if (strlen(this->signer) > 0) {
        buy_token(this->signer, amount);
        auto *tokenBalanceLabel = dynamic_cast<Label *>(this->getChildByName("tokenBalance"));
        auto tokenBalance = get_token_balance(this->signer);
        tokenBalanceLabel->setString(cocos2d::StringUtils::format("Game token balance: %f", tokenBalance));
        this->setStatus("You got new tokens!", false);
    } else {
        this->setStatus("Need to connect to the wallet", true);
    }
}

void WalletButtonLayer::sellTokenCallback(Ref *pSender) {
    double amount = this->parseAmount();
    auto message = cocos2d::StringUtils::format("Going to sell tokens with amount: %f", amount);
    this->setStatus(message, false);
}

void WalletButtonLayer::setStatus(const std::string &message, bool isError) {
    auto *statusLabel = dynamic_cast<Label *>(this->getChildByName("status"));
    auto color = isError ? Color3B::RED : Color3B::GREEN;
    statusLabel->setColor(color);
    statusLabel->setString(message);
}

double WalletButtonLayer::parseAmount() {
    auto *textField = dynamic_cast<ui::TextField *>(this->getChildByName("tokenAmount"));
    try{
        return std::stod(textField->getString());
    } catch (...) {
        this->setStatus("Please enter correct amount of tokens", true);
    }
    return 0;
}