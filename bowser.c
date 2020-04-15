
#include "bowser.h"

#define BOWSER_ANIMATION_COUNT 2
#define   BOWSER_RUN_FRAME_COUNT 2
#define     BOWSER_RUN_0_POLYGON_COUNT 2
#define       BOWSER_RUN_0_HEAD_VERTICES 2
                int bowser_run_0_head_x[BOWSER_RUN_0_HEAD_VERTICES] = { 1, 2 };
                int bowser_run_0_head_y[BOWSER_RUN_0_HEAD_VERTICES] = { 1, 2 };
#define       BOWSER_RUN_0_BODY_VERTICES 3
                int bowser_run_0_body_x[BOWSER_RUN_0_BODY_VERTICES] = { 1, 2, 3 };
                int bowser_run_0_body_y[BOWSER_RUN_0_BODY_VERTICES] = { 1, 2, 3 };
#define     BOWSER_RUN_1_POLYGON_COUNT 3
#define       BOWSER_RUN_1_HEAD_VERTICES 4
                int bowser_run_1_head_x[BOWSER_RUN_1_HEAD_VERTICES] = { 1, 2, 3, 4 };
                int bowser_run_1_head_y[BOWSER_RUN_1_HEAD_VERTICES] = { 1, 2, 3, 4 };
#define       BOWSER_RUN_1_BODY_VERTICES 5
                int bowser_run_1_body_x[BOWSER_RUN_1_BODY_VERTICES] = { 1, 2, 3, 4, 5 };
                int bowser_run_1_body_y[BOWSER_RUN_1_BODY_VERTICES] = { 1, 2, 3, 4, 5 };
#define       BOWSER_RUN_1_TORSO_VERTICES 6
                int bowser_run_1_torso_x[BOWSER_RUN_1_TORSO_VERTICES] = { 1, 2, 3, 4, 5, 6 };
                int bowser_run_1_torso_y[BOWSER_RUN_1_TORSO_VERTICES] = { 1, 2, 3, 4, 5, 6 };
#define   BOWSER_JUMP_FRAME_COUNT 1
#define     BOWSER_JUMP_0_POLYGON_COUNT 1
#define       BOWSER_JUMP_0_LEGS_VERTICES 7
                int bowser_jump_0_legs_x[BOWSER_JUMP_0_LEGS_VERTICES] = { 1, 2, 3, 4, 5, 6, 7 };
                int bowser_jump_0_legs_y[BOWSER_JUMP_0_LEGS_VERTICES] = { 1, 2, 3, 4, 5, 6, 7 };

int BOWSER_ALLOC[] = {
	BOWSER_ANIMATION_COUNT,
	BOWSER_RUN_FRAME_COUNT + BOWSER_JUMP_FRAME_COUNT,
	BOWSER_RUN_0_POLYGON_COUNT + BOWSER_RUN_1_POLYGON_COUNT + BOWSER_JUMP_0_POLYGON_COUNT,
	BOWSER_RUN_0_HEAD_VERTICES + BOWSER_RUN_0_BODY_VERTICES + BOWSER_RUN_1_HEAD_VERTICES + BOWSER_RUN_1_BODY_VERTICES + BOWSER_RUN_1_TORSO_VERTICES + BOWSER_JUMP_0_LEGS_VERTICES,
};

int BOWSER_FRAMES[] = {
	BOWSER_RUN_FRAME_COUNT, BOWSER_JUMP_FRAME_COUNT
};

int BOWSER_POLYGONS[] = {
	BOWSER_RUN_0_POLYGON_COUNT, BOWSER_RUN_1_POLYGON_COUNT, BOWSER_JUMP_0_POLYGON_COUNT,
};

int BOWSER_VERTICES[] = {
	BOWSER_RUN_0_HEAD_VERTICES,
	BOWSER_RUN_0_BODY_VERTICES,
	BOWSER_RUN_1_HEAD_VERTICES,
	BOWSER_RUN_1_BODY_VERTICES,
	BOWSER_RUN_1_TORSO_VERTICES,
	BOWSER_JUMP_0_LEGS_VERTICES,
};

int * BOWSER_ARRAYS[] = {
	bowser_run_0_head_x,
	bowser_run_0_head_y,
	bowser_run_0_body_x,
	bowser_run_0_body_y,
	bowser_run_1_head_x,
	bowser_run_1_head_y,
	bowser_run_1_body_x,
	bowser_run_1_body_y,
	bowser_run_1_torso_x,
	bowser_run_1_torso_y,
	bowser_jump_0_legs_x,
	bowser_jump_0_legs_y,
};

reference_t BOWSER = { 
	.alloc = BOWSER_ALLOC,
	.frames = BOWSER_FRAMES,
	.polygons = BOWSER_POLYGONS,
	.vertices = BOWSER_VERTICES,
	.arrays = BOWSER_ARRAYS 
};
