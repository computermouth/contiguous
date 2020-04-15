
#include "util.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

sprite_t * clone_sprite(reference_t payload){
	
	size_t sz = (
		sizeof(sprite_t)
		+ sizeof(animation_t) * payload.alloc[0]
		+ sizeof(frame_t)     * payload.alloc[1]
		+ sizeof(polygon_t)   * payload.alloc[2]
		+ sizeof(int)         * payload.alloc[3] * 2
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
	c += sizeof(animation_t) * payload.alloc[0];
	
	int fstride = 0;
	int pstride = 0;
	int vstride = 0;
	int astride = 0;
	
	for(int a = 0; a < payload.alloc[0]; a++){
		//~ // just need the anim index
		
		printf("curr: %p targ: %p\n", c, &s->animations[a].frames);
		s->animations[a].frames = c;
		c += sizeof(frame_t) * payload.frames[fstride];
		
		for(int f = 0; f < payload.frames[fstride]; f++){
			printf("curr: %p targ: %p\n", c, &s->animations[a].frames[f].polygons);
			s->animations[a].frames[f].polygons = c;
			c += sizeof(polygon_t) * payload.polygons[pstride];
			
			for(int p = 0; p < payload.polygons[pstride]; p++){
				printf("curr: %p anim: %d  fram: %d poly: %d xory: x\n", c, a, f, p);
				s->animations[a].frames[f].polygons[p].x = c;
				memcpy(c, payload.arrays[astride], sizeof(int) * payload.vertices[vstride]);
				c += sizeof(int) * payload.vertices[vstride];
				astride++;
				printf("curr: %p anim: %d  fram: %d poly: %d xory: y\n", c, a, f, p);
				s->animations[a].frames[f].polygons[p].y = c;
				memcpy(c, payload.arrays[astride], sizeof(int) * payload.vertices[vstride]);
				c += sizeof(int) * payload.vertices[vstride];
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
