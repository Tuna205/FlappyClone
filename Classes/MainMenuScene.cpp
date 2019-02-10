#include <stdio.h>
#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"
#include "GameScene.h"
#include "Definitions.h"

USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    return MainMenuScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool  MainMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//Background sprite
	auto backgroundSprite = Sprite::create(BACKGROUND_SPRITE);
	backgroundSprite->setContentSize(visibleSize);
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(backgroundSprite);

	//Title sprite
	auto titleSprite = Sprite::create(TITLE_SPRITE);
	titleSprite->setContentSize(titleSprite->getContentSize()*1.5);
	titleSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height * 0.9 - titleSprite->getContentSize().height));
	this->addChild(titleSprite);

	//MainMenu play button
	auto playItem = MenuItemImage::create(PLAY_SPRITE, PLAY_CLICKED_SPRITE, CC_CALLBACK_1(MainMenuScene::GoToGameScene, this));
	playItem->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height / 2 + origin.y));

	auto menu = Menu::create(playItem, NULL);
	menu->setScale(1.5);
	menu->setPosition(Point::ZERO);

	this->addChild(menu);

    return true;
}

void MainMenuScene::GoToGameScene(cocos2d::Ref* sender)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}


