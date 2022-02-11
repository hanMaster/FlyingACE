
#include "WalletButtonLayer.h"
#include "ui/CocosGUI.h"
#include "wallet.h"
#include "test.h"
#include <iostream>

USING_NS_CC;

bool WalletButtonLayer::init() {
    const char *seed_phrase = "pitch trust globe fish fever anchor type used aunt enemy crop spatial";
    const char *passphrase = "localhost";

    const char* signer = init_signer(seed_phrase, passphrase);
    int balance = get_balance(signer);
//    int balance = 5;

    print_hello();

	auto walletItem = MenuItemImage::create("images/back.png", "images/back.png", CC_CALLBACK_1(WalletButtonLayer::goToWelcomeCallback, this));
    walletItem->setScale(0.5);

    auto menu = Menu::create(walletItem, NULL);
    menu->setAnchorPoint(Point(0.0f, 1.0f));
    menu->setPosition(Director::getInstance()->getWinSize().width - 200, 100);

    
    auto seedLabel = Label::createWithTTF("Seed", "fonts/MarkerFelt.ttf", 30);
    seedLabel->enableShadow();
    seedLabel->setAnchorPoint(Point(0.0f, 1.0f));
    seedLabel->setPosition(Vec2(70, 1180));
    
   
    auto balanceSolLabel = Label::createWithTTF(std::to_string(balance), "fonts/MarkerFelt.ttf", 30);
    balanceSolLabel->enableShadow();
    balanceSolLabel->setAnchorPoint(Point(0.0f, 1.0f));
    balanceSolLabel->setPosition(Vec2(70, 980));
    balanceSolLabel->setName("balance");
    
    
    auto input1 = MenuItemImage::create("images/text-input-icon.png", "images/text-input-icon.png", CC_CALLBACK_1(WalletButtonLayer::goToWelcomeCallback, this));
    input1->setAnchorPoint(Point(0.5f, 0.5f));
    input1->setPosition(Vec2(Director::getInstance()->getWinSize().width/2, 1100));
    this->addChild(input1, 1);
    ui::TextField* seedField = ui::TextField::create("Seed","fonts/MarkerFelt.ttf",30);
    seedField->setPosition(Vec2(Director::getInstance()->getWinSize().width/2, 1100));
    seedField->setColor(Color3B::BLUE);
    seedField->setMaxLength(20);
    seedField->setMaxLengthEnabled(true);
    seedField->setTouchAreaEnabled(true);
    seedField->setTouchSize(Size(200,600));

    
    seedField->addEventListener(CC_CALLBACK_2(WalletButtonLayer::textFieldEvent, this));
    
    this->addChild(seedLabel, 1);
    this->addChild(seedField, 2);
    this->addChild(balanceSolLabel, 1);
    this->addChild(menu, 1);
    
    balanceSolLabel->setString("Fuck");
    
	return true;
}

void WalletButtonLayer::goToWelcomeCallback(Ref* pSender) {
	Scene* welcomeSceneWithAnimation = TransitionFade::create(2.0f, WelcomeScene::create());
	Director::getInstance()->replaceScene(welcomeSceneWithAnimation);
}

void WalletButtonLayer::textFieldEvent(Ref *pSender, cocos2d::ui::TextField::EventType type)
{
    ui::TextField *seedField = dynamic_cast<ui::TextField *>(pSender);
    Label * balance = dynamic_cast<Label *>(this->getChildByName("balance"));
    
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
            balance->setString(cocos2d::StringUtils::format("Balance: %s", seedField->getString().c_str()));
            break;
        }
            
        case cocos2d::ui::TextField::EventType::DELETE_BACKWARD:
        {
            balance->setString(seedField->getString().c_str());
            break;
        }
        default:
            break;
    }
}
