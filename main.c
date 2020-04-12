#include <stdio.h>
#include <stdlib.h>
#include "bowser.h"

int main(){
	
	sprite_t * first = clone_bowser();
	
	free(first);
	
	return 0;
}
