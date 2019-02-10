#include "Bird.h"
#include "Definitions.h"
#include "spine/extension.h"

USING_NS_CC;

Bird::Bird(cocos2d::Layer *layer)
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	flappyBird = Sprite::create(BIRD_SPRITE);
	flappyBird->setContentSize(flappyBird->getContentSize() * 1.5);
	flappyBird->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	auto flappyBody = PhysicsBody::createCircle( flappyBird->getContentSize().width/2);
	flappyBody->setCollisionBitmask(BIRD_COLLISION_BITMASK);
	flappyBody->setContactTestBitmask(true);

	flappyBird->setPhysicsBody(flappyBody);
	layer->addChild(flappyBird, 100);

	isFalling = true;
}

void Bird::Fall()
{
	if (true == isFalling)
	{
		flappyBird->setRotation(atan(BIRD_FALLING_SPEED * visibleSize.height / (PIPE_MOVEMENT_SPEED * visibleSize.width)) * 180 / PI);
		flappyBird->setPositionX(visibleSize.width / 2 + origin.x);
		flappyBird->setPositionY(flappyBird->getPositionY() - (BIRD_FALLING_SPEED * visibleSize.height));
	}
	else
	{
		flappyBird->setRotation(-atan(BIRD_FALLING_SPEED * visibleSize.height / (PIPE_MOVEMENT_SPEED * visibleSize.width)) * 180 / PI);

		flappyBird->setPositionX(visibleSize.width / 2 + origin.x);
		flappyBird->setPositionY(flappyBird->getPositionY() + (BIRD_FALLING_SPEED * visibleSize.height));

	}
}

void Bird::Fly()
{
	flappyBird->setTexture(BIRD_SPRITE_FLY);
	flappyBird->setContentSize(flappyBird->getContentSize() * 1.5);
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sounds/Wing.mp3");
	isFalling = false;

}

void Bird::StopFlying()
{
	flappyBird->setTexture(BIRD_SPRITE);
	flappyBird->setContentSize(flappyBird->getContentSize() * 1.5);
	isFalling = true;
}


