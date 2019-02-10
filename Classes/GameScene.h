#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Pipe.h"
#include "Bird.h"

class GameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);

private:
	void SetPhysicsWorld(cocos2d::PhysicsWorld *world) { sceneWorld = world; }
	cocos2d::PhysicsWorld *sceneWorld;

	void SpawnPipe(float dt);

	bool onContactBegan(cocos2d::PhysicsContact &contact);

	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	//moj
	bool onKeyBegan(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

	void StopFlying(float dt);
	void update(float dt);

	Pipe pipe;

	Bird *bird;

	unsigned int score;

	cocos2d::Label *scoreLabel;
};

#endif // __HELLOWORLD_SCENE_H__
