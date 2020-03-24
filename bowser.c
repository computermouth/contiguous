
#include "bowser.h"
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

		sprite_t bowser;
#define BOWSER_ANIMATION_COUNT 2
			animation_t bowser_run; // TWO FRAMES
#define 	BOWSER_RUN_FRAME_COUNT 2
				frame_t bowser_run_0; // TWO POLYGONS
#define			BOWSER_RUN_0_POLYGON_COUNT 2
					polygon_t bowser_run_0_head; // TWO VERTICES
#define 				BOWSER_RUN_0_HEAD_VERTICES 2
						int bowser_run_0_head_x[BOWSER_RUN_0_HEAD_VERTICES] = { 1, 2 };
						int bowser_run_0_head_y[BOWSER_RUN_0_HEAD_VERTICES] = { 1, 2 };
					polygon_t bowser_run_0_body;
#define 				BOWSER_RUN_0_BODY_VERTICES 3
						int bowser_run_0_body_x[BOWSER_RUN_0_BODY_VERTICES] = { 1, 2, 3 };
						int bowser_run_0_body_y[BOWSER_RUN_0_BODY_VERTICES] = { 1, 2, 3 };
				frame_t bowser_run_1;
#define			BOWSER_RUN_1_POLYGON_COUNT 3
					polygon_t bowser_run_1_head;
#define 				BOWSER_RUN_1_HEAD_VERTICES 4
						int bowser_run_1_head_x[BOWSER_RUN_1_HEAD_VERTICES] = { 1, 2, 3, 4 };
						int bowser_run_1_head_y[BOWSER_RUN_1_HEAD_VERTICES] = { 1, 2, 3, 4 };
					polygon_t bowser_run_1_body;
#define 				BOWSER_RUN_1_BODY_VERTICES 5
						int bowser_run_2_body_x[BOWSER_RUN_1_BODY_VERTICES] = { 1, 2, 3, 4, 5 };
						int bowser_run_2_body_y[BOWSER_RUN_1_BODY_VERTICES] = { 1, 2, 3, 4, 5 };
					polygon_t bowser_run_1_torso;
#define 				BOWSER_RUN_1_TORSO_VERTICES 6
						int bowser_run_2_torso_x[BOWSER_RUN_1_TORSO_VERTICES] = { 1, 2, 3, 4, 5, 6 };
						int bowser_run_2_torso_y[BOWSER_RUN_1_TORSO_VERTICES] = { 1, 2, 3, 4, 5, 6 };
			animation_t bowser_jump;
#define		BOWSER_JUMP_FRAME_COUNT 1
				frame_t bowser_jump_0;
#define				BOWSER_JUMP_0_POLYGON_COUNT 1
					polygon_t bowser_jump_0_legs;
#define 				BOWSER_RUN_0_LEGS_VERTICES 7
						int bowser_jump_0_legs_x[BOWSER_RUN_0_LEGS_VERTICES] = { 1, 2, 3, 4, 5, 6, 7 };
						int bowser_jump_0_legs_y[BOWSER_RUN_0_LEGS_VERTICES] = { 1, 2, 3, 4, 5, 6, 7 };
/*
sprite_t bowser;
	animation_t run;
		frame_t run_0;
			polygon_t head;
			polygon_t body;
		frame_t run_1;
			polygon_t head;
			polygon_t body;
			polygon_t torso;
	animation_t jump;
		frame_t jump_0;
			polygon_t legs;
			polygon_t shell;
		frame_t jump_1;
			polygon_t legs;
*/

sprite_t * clone_bowser(){
	
	ptrdiff_t struct_pad = (
		sizeof(sprite_t)
		+ 	sizeof(animation_t) * BOWSER_ANIMATION_COUNT
		+ 		sizeof(frame_t) * BOWSER_RUN_FRAME_COUNT
		+ 			sizeof(polygon_t) * BOWSER_RUN_0_POLYGON_COUNT
		+ 			sizeof(polygon_t) * BOWSER_RUN_1_POLYGON_COUNT
		+ 		sizeof(frame_t) * BOWSER_JUMP_FRAME_COUNT
		+ 			sizeof(polygon_t) * BOWSER_JUMP_0_POLYGON_COUNT
	);
	
	ptrdiff_t vertex_pad = (
		  sizeof(int) * 2 * BOWSER_RUN_0_HEAD_VERTICES
		+ sizeof(int) * 2 * BOWSER_RUN_0_BODY_VERTICES
		+ sizeof(int) * 2 * BOWSER_RUN_1_HEAD_VERTICES
		+ sizeof(int) * 2 * BOWSER_RUN_1_BODY_VERTICES
		+ sizeof(int) * 2 * BOWSER_RUN_1_TORSO_VERTICES
		+ sizeof(int) * 2 * BOWSER_RUN_0_LEGS_VERTICES
	);
	
	sprite_t * bowser = malloc( struct_pad + vertex_pad );
	
	void * current = bowser + sizeof(sprite_t);
	
	for(int i = 0; i < BOWSER_ANIMATION_COUNT; i++)
	
		bowser->animations[i] = current;
		current += sizeof(animation_t) * i;
		
		for()
	
	bowser->animations[0].frames = current;
	current += sizeof(frame_t) * BOWSER_RUN_FRAME_COUNT;
	
	bowser->animations[0].frames[0] = current;
	current += sizeof(frame_t) * BOWSER_RUN_FRAME_COUNT;
	
	bowser->animations[0].frames = current;
	current += sizeof(frame_t) * BOWSER_RUN_FRAME_COUNT;
	
	
	
	bowser->animations[0].frames[0].polygons[0].x = current;
	memcpy(bowser->animations[0].frames[0].polygons[0].x, bowser_run_0_head_x, BOWSER_RUN_0_HEAD_VERTICES);
	current += sizeof(bowser_run_0_head_x)/sizeof(bowser_run_0_head_x[0]);
	
	bowser->animations[0].frames[0].polygons[0].y = current;
	memcpy(bowser->animations[0].frames[0].polygons[0].x, bowser_run_0_head_x, BOWSER_RUN_0_HEAD_VERTICES);
	current += sizeof(bowser_run_0_head_x)/sizeof(bowser_run_0_head_x[0]);
	
	
	return bowser;
	
}
