#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/bmp.h"

int main(int argc, char *argv[]) {
    PICTURE pin;
    PICTURE cr;
    int x, y, w, h;
    if (!strcmp(argv[1], "crop-rotate")) {
        x = atoi(argv[4]);
        y = atoi(argv[5]);
        w = atoi(argv[6]);
        h = atoi(argv[7]);
		if(load_bmp(argv[2], &pin))
            return 1;

        if (crop_bmp(&pin, &cr, x, y, w, h))
            return 1;

        if (rotate_bmp(&cr))
            return 1;

        if(save_bmp(argv[3], &cr))
	    	return 1;

        free(cr.pic);
    }
    else if (!strcmp(argv[1], "insert")) {
        if(load_bmp(argv[2], &pin))
            return 1;
        if(insert(&pin, argv[4], argv[5]))
	    return 1;
        if(save_bmp(argv[3], &pin))
	    return 1;
    }
    else {
        if(load_bmp(argv[2], &pin))
            return 1;
        if(extract(&pin, argv[3], argv[4]))
	    	return 1;
    }
    free(pin.pic);
    return EXIT_SUCCESS;
}
