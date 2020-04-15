
#include "mario.h"

#define MARIO_ANIMATION_COUNT 1
#define   MARIO_JUMP_FRAME_COUNT 1
#define     MARIO_JUMP_0_POLYGON_COUNT 1
#define       MARIO_JUMP_0_LEGS_VERTICES 7
                int mario_jump_0_legs_x[MARIO_JUMP_0_LEGS_VERTICES] = { 1, 2, 3, 4, 5, 6, 7 };
                int mario_jump_0_legs_y[MARIO_JUMP_0_LEGS_VERTICES] = { 1, 2, 3, 4, 5, 6, 7 };

int MARIO_ALLOC[] = {
	MARIO_ANIMATION_COUNT,
	MARIO_JUMP_FRAME_COUNT,
	MARIO_JUMP_0_POLYGON_COUNT,
	MARIO_JUMP_0_LEGS_VERTICES,
};

int MARIO_FRAMES[] = {
	MARIO_JUMP_FRAME_COUNT,
};

int MARIO_POLYGONS[] = {
	MARIO_JUMP_0_POLYGON_COUNT,
};

int MARIO_VERTICES[] = {
	MARIO_JUMP_0_LEGS_VERTICES,
};

int * MARIO_ARRAYS[] = {
	mario_jump_0_legs_x,
	mario_jump_0_legs_y,
};

reference_t MARIO = { 
	.alloc = MARIO_ALLOC,
	.frames = MARIO_FRAMES,
	.polygons = MARIO_POLYGONS,
	.vertices = MARIO_VERTICES,
	.arrays = MARIO_ARRAYS 
};
