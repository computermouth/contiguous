
#ifndef _UTIL_H_
#define _UTIL_H_

typedef struct {
	int count;
	int * x;
	int * y;
} polygon_t;

typedef struct {
	int count;
	polygon_t * polygons;
} frame_t;

typedef struct {
	int count;
	frame_t * frames;
} animation_t;

typedef struct {
	int count;
	animation_t * animations;
} sprite_t;

typedef struct {
	int * alloc;
	int * frames;
	int * polygons;
	int * vertices;
	int ** arrays;
} reference_t;

sprite_t * clone_sprite(reference_t);

#endif
