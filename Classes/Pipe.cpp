#include "Pipe.h"
#include "Definitions.h"
#include <debugapi.h>
#include <cmath>

USING_NS_CC;

Pipe::Pipe()
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
}

void Pipe::SpawnPipe(cocos2d::Layer *layer)
{
	auto topPipe = Sprite::create(PIPE_SPRITE);
	topPipe->setContentSize(topPipe->getTexture()->getContentSize() * 1.6f);
	topPipe->setRotation(180);
	auto bottomPipe = Sprite::create(PIPE_SPRITE);
	bottomPipe->setContentSize(bottomPipe->getTexture()->getContentSize() * 1.6f);

	auto topPipeBody = PhysicsBody::createBox(topPipe->getContentSize());
	auto bottomPipeBody = PhysicsBody::createBox(bottomPipe->getContentSize());

	//pozicija pipa po y
	float random = CCRANDOM_0_1()*(UPPER_SCREEN_PIPE_TRESHOLD - LOWER_SCREEN_PIPE_TRESHOLD) + LOWER_SCREEN_PIPE_TRESHOLD;	
	auto topPipePosition = random * visibleSize.height + topPipe->getContentSize().height / 2;

	topPipeBody->setDynamic(false);
	bottomPipeBody->setDynamic(false);

	topPipeBody->setCollisionBitmask(OBSTACLE_COLLISION_BITMASK);
	bottomPipeBody->setCollisionBitmask(OBSTACLE_COLLISION_BITMASK);
	topPipeBody->setContactTestBitmask(true);
	bottomPipeBody->setContactTestBitmask(true);

	topPipe->setPhysicsBody(topPipeBody);
	bottomPipe->setPhysicsBody(bottomPipeBody);

	topPipe->setPosition(Point(visibleSize.width + topPipe->getContentSize().width + origin.x, topPipePosition));
	bottomPipe->setPosition(Point(topPipe->getPositionX(), topPipePosition - (Sprite::create(BIRD_SPRITE)->getContentSize().height * PIPE_GAP) - topPipe->getContentSize().height));

	layer->addChild(topPipe);
	layer->addChild(bottomPipe);

	auto delay = DelayTime::create(OBSTACLE_DESTROY_TIME);
	auto destroyTop = RemoveSelf::create(topPipe);
	auto seqTop = Sequence::create(delay, destroyTop, NULL);
	topPipe->runAction(seqTop);

	auto destroyBottom = RemoveSelf::create(bottomPipe);
	auto seqBottom = Sequence::create(delay, destroyBottom, NULL);
	bottomPipe->runAction(seqBottom);


	auto topPipeAction = MoveBy::create(PIPE_MOVEMENT_SPEED * visibleSize.width, Point(-visibleSize.width * 1.5, 0));
	auto bottomPipeAction = MoveBy::create(PIPE_MOVEMENT_SPEED * visibleSize.width, Point(-visibleSize.width * 1.5, 0));

	topPipe->runAction(topPipeAction);
	bottomPipe->runAction(bottomPipeAction);

	auto pointNode = Node::create();
	auto pointBody = PhysicsBody::createBox(Size(1, Sprite::create(BIRD_SPRITE)->getContentSize().height * PIPE_GAP));

	pointBody->setDynamic(false);
	pointBody->setCollisionBitmask(POINT_COLLISION_BITMASK);
	pointBody->setContactTestBitmask(true);

	pointNode->setPhysicsBody(pointBody);
	pointNode->setPosition(Point(topPipe->getPositionX(), topPipe->getPositionY() - (topPipe->getContentSize().height / 2) -
		(Sprite::create(BIRD_SPRITE)->getContentSize().height * PIPE_GAP / 2)));
	layer->addChild(pointNode);

	auto pointNodeAction = MoveBy::create(PIPE_MOVEMENT_SPEED * visibleSize.width, Point(-visibleSize.width * 1.5, 0));
	pointNode->runAction(pointNodeAction);

	auto destroyNode = RemoveSelf::create(topPipe);
	auto seqNode = Sequence::create(delay, destroyNode, NULL);
	pointNode->runAction(seqNode);
}

void Pipe::DestroyPipe(Sprite *sprite, Layer *layer)
{
	layer->removeChild(sprite, true);
}
