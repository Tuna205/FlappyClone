#ifndef __DEFINITIONS_H__
#define __DEFINITIONS_H__

#define DISPLAY_TIME_SPLASH_SCENE 0.0f
#define TRANSITION_TIME 0.5

#define PIPE_GAP 9
#define PIPE_SPAWN_FREQUENCY 0.008
#define UPPER_SCREEN_PIPE_TRESHOLD 0.9f
#define LOWER_SCREEN_PIPE_TRESHOLD 0.35f

#define PIPE_MOVEMENT_SPEED 0.005//manje je brze

#define BIRD_COLLISION_BITMASK 0x000001
#define OBSTACLE_COLLISION_BITMASK 0x000002
#define POINT_COLLISION_BITMASK 0x000003


#define BIRD_FALLING_SPEED 0.0040
#define BIRD_FLYING_SPEED 0.00575
#define BIRD_FLY_DURATION 0.25

#define SCORE_FONT_SIZE 0.07
#define FONT_TTF "fonts/slkscr.ttf"

#define OBSTACLE_DESTROY_TIME 5

#define PIPE_SPRITE "sprites/pipe-green.png"
#define BIRD_SPRITE "sprites/bluebird-upflap.png"
#define BIRD_SPRITE_FLY "sprites/bluebird-downflap.png"
#define BACKGROUND_SPRITE "sprites/background-night.png"
#define GAMEOVER_SPRITE "sprites/gameover.png"
#define PLAY_SPRITE "sprites/PlayButton.png"
#define PLAY_CLICKED_SPRITE "sprites/PlayButtonPressed.png"
#define RETRY_SPRITE "sprites/RetryButton.png"
#define RETRY_CLICKED_SPRITE "sprites/RetryButtonPressed.png"
#define MENU_SPRITE "sprites/MenuButton.png"
#define MENU_CLICKED_SPRITE "sprites/MenuButtonPressed.png"
#define TITLE_SPRITE "sprites/Title.png"
#define SPLASH_SCREEN_SPRITE "sprites/background-night.png"


#endif // __DEFINITIONS_SCENE_H__
