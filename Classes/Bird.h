#ifndef __BIRD_SCENE_H__
#define __BIRD_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

class Bird : public cocos2d::Scene
{
public:
	Bird(cocos2d::Layer *layer);

	void Fall();
	void Fly(); //{ CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sounds/Wing.mp3");
				 //isFalling = false; }
	void StopFlying();// {  }


private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	bool isFalling;

	cocos2d::Sprite *flappyBird;
};



#endif // __HELLOWORLD_SCENE_H__
