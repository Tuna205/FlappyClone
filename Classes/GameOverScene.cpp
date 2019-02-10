#include <stdio.h>
#include "GameOverScene.h"
#include "GameScene.h"
#include "MainMenuScene.h"
#include "Definitions.h"

USING_NS_CC;
unsigned int score;

Scene* GameOverScene::createScene(unsigned int tempScore)
{
	score = tempScore;
    return GameOverScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool  GameOverScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backgroundSprite = Sprite::create(BACKGROUND_SPRITE);
	backgroundSprite->setContentSize(visibleSize);
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(backgroundSprite);

	auto gameOver = Sprite::create(GAMEOVER_SPRITE);
	gameOver->setContentSize(gameOver->getContentSize()*1.5);
	gameOver->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 4 * 3));
	this->addChild(gameOver);

	auto retryItem = MenuItemImage::create(RETRY_SPRITE, RETRY_CLICKED_SPRITE, CC_CALLBACK_1(GameOverScene::GoToGameScene, this));
	retryItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 4 * 1.5));

	auto mainMenuItem = MenuItemImage::create(MENU_SPRITE, MENU_CLICKED_SPRITE, CC_CALLBACK_1(GameOverScene::GoToMainMenuScene, this));
	mainMenuItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 4));

	auto menu = Menu::create(retryItem, mainMenuItem, NULL);
	menu->setScale(1.5);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

	UserDefault *def = UserDefault::getInstance();
	unsigned int highScore = def->getIntegerForKey("HIGHSCORE", 0);

	if( score > highScore)
	{
		highScore = score;
		def->setIntegerForKey("HIGHSCORE", highScore);
	}
	def->flush();

	__String *tempScore = __String::createWithFormat("Score: %i", score);
	auto currentScore = Label::createWithTTF(tempScore->getCString(), FONT_TTF, visibleSize.height * SCORE_FONT_SIZE);
	currentScore->setPosition(Point(visibleSize.width /2 + origin.x, visibleSize.height / 1.75 + origin.y));
	this->addChild(currentScore);

	__String *tempHighScore = __String::createWithFormat("High Score: %i", highScore);
	auto highScoreLabel = Label::createWithTTF(tempHighScore->getCString(), FONT_TTF, visibleSize.height * SCORE_FONT_SIZE);

	highScoreLabel->setColor(Color3B::YELLOW);
	highScoreLabel->setPosition(Point(visibleSize.width /2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(highScoreLabel);

    return true;
}

void GameOverScene::GoToMainMenuScene(cocos2d::Ref* sender)
{
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void GameOverScene::GoToGameScene(cocos2d::Ref* sender)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
