
#include "bowser.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

		//~ sprite_t bowser;
#define BOWSER_ANIMATION_COUNT 2
			//~ animation_t bowser_run; // TWO FRAMES
#define 	BOWSER_RUN_FRAME_COUNT 2
				//~ frame_t bowser_run_0; // TWO POLYGONS
#define			BOWSER_RUN_0_POLYGON_COUNT 2
					//~ polygon_t bowser_run_0_head; // TWO VERTICES
#define 				BOWSER_RUN_0_HEAD_VERTICES 2
						int bowser_run_0_head_x[BOWSER_RUN_0_HEAD_VERTICES] = { 1, 2 };
						int bowser_run_0_head_y[BOWSER_RUN_0_HEAD_VERTICES] = { 1, 2 };
					//~ polygon_t bowser_run_0_body;
#define 				BOWSER_RUN_0_BODY_VERTICES 3
						int bowser_run_0_body_x[BOWSER_RUN_0_BODY_VERTICES] = { 1, 2, 3 };
						int bowser_run_0_body_y[BOWSER_RUN_0_BODY_VERTICES] = { 1, 2, 3 };
				//~ frame_t bowser_run_1;
#define			BOWSER_RUN_1_POLYGON_COUNT 3
					//~ polygon_t bowser_run_1_head;
#define 				BOWSER_RUN_1_HEAD_VERTICES 4
						int bowser_run_1_head_x[BOWSER_RUN_1_HEAD_VERTICES] = { 1, 2, 3, 4 };
						int bowser_run_1_head_y[BOWSER_RUN_1_HEAD_VERTICES] = { 1, 2, 3, 4 };
					//~ polygon_t bowser_run_1_body;
#define 				BOWSER_RUN_1_BODY_VERTICES 5
						int bowser_run_1_body_x[BOWSER_RUN_1_BODY_VERTICES] = { 1, 2, 3, 4, 5 };
						int bowser_run_1_body_y[BOWSER_RUN_1_BODY_VERTICES] = { 1, 2, 3, 4, 5 };
					//~ polygon_t bowser_run_1_torso;
#define 				BOWSER_RUN_1_TORSO_VERTICES 6
						int bowser_run_1_torso_x[BOWSER_RUN_1_TORSO_VERTICES] = { 1, 2, 3, 4, 5, 6 };
						int bowser_run_1_torso_y[BOWSER_RUN_1_TORSO_VERTICES] = { 1, 2, 3, 4, 5, 6 };
			//~ animation_t bowser_jump;
#define		BOWSER_JUMP_FRAME_COUNT 1
				//~ frame_t bowser_jump_0;
#define				BOWSER_JUMP_0_POLYGON_COUNT 1
					//~ polygon_t bowser_jump_0_legs;
#define 				BOWSER_JUMP_0_LEGS_VERTICES 7
						int bowser_jump_0_legs_x[BOWSER_JUMP_0_LEGS_VERTICES] = { 1, 2, 3, 4, 5, 6, 7 };
						int bowser_jump_0_legs_y[BOWSER_JUMP_0_LEGS_VERTICES] = { 1, 2, 3, 4, 5, 6, 7 };

int BOWSER_ALLOC[4] = {
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

int * BOWSER_ARRAYS[12] = {
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
	
	size_t sz = (
		sizeof(sprite_t)
		+ sizeof(animation_t) * BOWSER_ALLOC[0]
		+ sizeof(frame_t)     * BOWSER_ALLOC[1]
		+ sizeof(polygon_t)   * BOWSER_ALLOC[2]
		+ sizeof(int)         * BOWSER_ALLOC[3] * 2
	);
	
	printf("sizes:\n\tspri: %lu\n\tanim: %lu\n\tfram: %lu\n\tpoly: %lu\n\tint: %lu\n\n",
		sizeof(sprite_t),
		sizeof(animation_t),
		sizeof(frame_t),
		sizeof(polygon_t),
		sizeof(int)
	);
	
	sprite_t * s = malloc(sz);
	
	void * c = (void *)s + sizeof(sprite_t);
	
	printf("s: %p sz: %x s+sz: %p &s[1]: %p c: %p\n", s, (unsigned int)sz, (void *)s + sz, &s[1], c);
	
	printf("curr: %p targ: %p\n", c, &s->animations);
	
	s->animations = c;
	c += sizeof(animation_t) * BOWSER_ALLOC[0];
	
	int fstride = 0;
	int pstride = 0;
	int vstride = 0;
	int astride = 0;
	
	for(int a = 0; a < BOWSER_ALLOC[0]; a++){
		//~ // just need the anim index
		
		printf("curr: %p targ: %p\n", c, &s->animations[a].frames);
		s->animations[a].frames = c;
		c += sizeof(frame_t) * BOWSER_FRAMES[fstride];
		
		for(int f = 0; f < BOWSER_FRAMES[fstride]; f++){
			printf("curr: %p targ: %p\n", c, &s->animations[a].frames[f].polygons);
			s->animations[a].frames[f].polygons = c;
			c += sizeof(polygon_t) * BOWSER_POLYGONS[pstride];
			
			for(int p = 0; p < BOWSER_POLYGONS[pstride]; p++){
				printf("curr: %p anim: %d  fram: %d poly: %d xory: x\n", c, a, f, p);
				s->animations[a].frames[f].polygons[p].x = c;
				memcpy(c, BOWSER_ARRAYS[astride], sizeof(int) * BOWSER_VERTICES[vstride]);
				c += sizeof(int) * BOWSER_VERTICES[vstride];
				//~ vstride++;
				astride++;
				printf("curr: %p anim: %d  fram: %d poly: %d xory: y\n", c, a, f, p);
				s->animations[a].frames[f].polygons[p].y = c;
				memcpy(c, BOWSER_ARRAYS[astride], sizeof(int) * BOWSER_VERTICES[vstride]);
				c += sizeof(int) * BOWSER_VERTICES[vstride];
				vstride++;
				astride++;
				printf("vs: %d as: %d\n", vstride, astride);
			}
			pstride++;
		}
		fstride++;
	}
	
	printf("curr: %p targ: %p\n", c, NULL);
	
	return s;
	
}

/*
sprite_t * old_clone_bowser(){
	
	int count = 12;
	int *lengths = BOWSER_LENGTHS;
	int **arrays = BOWSER_ARRAYS;
	
	ptrdiff_t sprite_size = sizeof(sprite_t);
	
	for(int a = 0; a < lengths[0]; a++){
		for(int f = 0; f < lengths[a+1])
		sprite_size += sizeof(sprite_t);
	}
	
	
	
	
	 = (
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
		+ sizeof(int) * 2 * BOWSER_JUMP_0_LEGS_VERTICES
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
*/
