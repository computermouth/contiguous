#include <stdio.h>
#include <stdlib.h>
#include "bowser.h"
#include "mario.h"

int main(){
	
	sprite_t * first = clone_sprite(BOWSER);
	sprite_t * second = clone_sprite(BOWSER);
	sprite_t * third = clone_sprite(MARIO);
	sprite_t * fourth = clone_sprite(MARIO);
	
	free(first);
	free(second);
	free(third);
	free(fourth);
	
	return 0;
}
