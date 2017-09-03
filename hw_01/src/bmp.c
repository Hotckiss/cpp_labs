/***
 * Author: Kirilenko Andery
 * Date: 13.11.2016
***/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "../include/bmp.h"
static int zeros(int width) {
    return (4 - (3 * width % 4)) % 4; 
}
static int read_pic(FILE *f, PICTURE *pic) {
    int i, buf = 0, H = pic->bi.biHeight, W = pic->bi.biWidth, line_width = 3 * W, zero_count = zeros(W);
    BYTE *dest;
    pic->pic = (BYTE *)malloc(sizeof(BYTE) * H * W * 3);
    dest = pic->pic;
    if(!dest)
		return MEM_ERROR;
    for (i = 0; i < H; i++) {
        if(fread(dest, line_width, 1, f) != 1)
	    	return READ_ERROR;
        if(fread(&buf, sizeof(BYTE), zero_count, f) != zero_count)
	    	return READ_ERROR;
        dest = dest + line_width;
    }
    return EXIT_SUCCESS; 
}

int load_bmp(const char *filename, PICTURE *pic) {
    FILE *f = fopen(filename, "rb");
    int res;
    if (!f)
        return READ_ERROR;

    res = fread(&(pic->bh), sizeof(BITMAPFILEHEADER), 1, f);
    if(res != 1) { fclose(f); return ERROR; }

    res = fread(&(pic->bi), sizeof(BITMAPINFOHEADER), 1, f);
    if(res != 1) { fclose(f); return ERROR; }

    res = read_pic(f, pic);
    if(res) { fclose(f); return ERROR; }

    fclose(f);
    return EXIT_SUCCESS;
}

static int write_pic(FILE *f, PICTURE *pic) {
    int i, nil = 0, H = pic->bi.biHeight, W = pic->bi.biWidth, zero_count = zeros(W), line_width = 3 * W;
    for (i = 0; i < H; i++) {
        if(fwrite(pic->pic + i * line_width, sizeof(BYTE), line_width, f) != line_width)
	    	return READ_ERROR;
        if(fwrite(&nil, sizeof(BYTE), zero_count, f) != zero_count)
	    	return READ_ERROR;
    }
    return EXIT_SUCCESS;
}

int save_bmp(const char *filename, PICTURE *pic) {
    FILE *f = fopen(filename, "wb");
    int res;
    if (!f)
        return READ_ERROR;

    res = fwrite(&(pic->bh), sizeof(BITMAPFILEHEADER), 1, f);
    if(res != 1) { fclose(f); return ERROR; }

    res = fwrite(&(pic->bi), sizeof(BITMAPINFOHEADER), 1, f);
    if(res != 1) { fclose(f); return ERROR; }

    res = write_pic(f, pic);
    if(res) { fclose(f); return ERROR; }
    fclose(f);
    return EXIT_SUCCESS;
}
int crop_bmp(PICTURE *pin, PICTURE *cr, int x, int y, int w, int h) {
    int W = pin->bi.biWidth, H = pin->bi.biHeight, new_y = H - h - y, i, line_width = 3 * w, zero_count = h * zeros(w);
    BYTE *dest, *src;
    if (x < 0 || y < 0 || w <= 0 || h <= 0 || x + w > W || new_y + h > H)
        return INPUT_ERROR;
    memcpy(&(cr->bh), &(pin->bh), sizeof(BITMAPFILEHEADER));
    memcpy(&(cr->bi), &(pin->bi), sizeof(BITMAPINFOHEADER));

    cr->bi.biHeight = h;
    cr->bi.biWidth = w;
    cr->bh.bfSize = 3 * w * h + pin->bi.biSize + sizeof(BITMAPFILEHEADER) + zero_count;
    cr->bi.biSizeImage = 3 * w * h + zero_count;
    cr->pic = (BYTE *)malloc(line_width * h);
    if (!cr->pic)
        return MEM_ERROR;

    dest = cr->pic;
    src = pin->pic + 3 * (new_y * W + x);
    for (i = 0; i < h; i++) {
        memcpy(dest, src, line_width);
        dest += line_width;
        src += 3 * W;
    }
    return EXIT_SUCCESS;
}

int rotate_bmp(PICTURE *pin) {
	int W = pin->bi.biWidth, H = pin->bi.biHeight, i, j, zero_old = H * zeros(W), zero_new = W * zeros(H);
    BYTE *buffer = (BYTE *)malloc(3 * H * W), *src = pin->pic;
    if (!buffer)
        return MEM_ERROR;
    pin->bh.bfSize += (zero_new - zero_old);
    pin->bi.biSizeImage += (zero_new - zero_old);
    for (i = 0; i < H; i++)
        for (j = 0; j < W; j++)
            memcpy(buffer + 3 * ((W - j - 1) * H + i), src + 3 * (i * W + j), 3);
    free(pin->pic);
    pin->pic = buffer;
    pin->bi.biHeight = W;
    pin->bi.biWidth = H;
    return EXIT_SUCCESS;
}

static char code_symbol(int c) {
    if (c >= 'A' && c <= 'Z')
        return c - 'A';
    else if (c == ' ')
        return 26;
    else if (c == '.')
        return 27;
    else
        return 28;
}
static int shift(char c) {
	if (c == 'B') return 0;
    else if (c == 'G') return 1;
    else return 2;
}
int insert(PICTURE *pic, char *msg_key, char *msg_text) {
    FILE *fkey = fopen(msg_key, "rt");
    FILE *ftext = fopen(msg_text, "rt");
    int x, y, pos, i, real_y, cur_bit, W = pic->bi.biWidth, H = pic->bi.biHeight, symbol, pixel_pos;
    char comp, code;
    BYTE *dest = pic->pic;
    while ((symbol = fgetc(ftext)) != EOF) {
        code = code_symbol(symbol);
        for (i = 0; i < 5; i++) {
            fscanf(fkey, "%d%d", &x, &y);
            fgetc(fkey);
            comp = fgetc(fkey);
            real_y = H - y - 1;
            pos = shift(comp);
            cur_bit = code & (1 << i);
			pixel_pos = 3 * (real_y * W + x) + pos;
            if (cur_bit == 0) dest[pixel_pos] &= (BYTE)(254);
            else dest[pixel_pos] |= (BYTE)(1);
        }
    }
    fclose(fkey);
    fclose(ftext);
    return EXIT_SUCCESS;
}

static void write(FILE *f, int num) {
    if (num == 26) fprintf(f, " ");
    else if(num == 27) fprintf(f, ".");
    else if (num == 28) fprintf(f, ",");
    else fprintf(f, "%c" , 'A' + num);
}

int extract(PICTURE *pic, char *msg_key, char *msg_text) {
    FILE *fkey = fopen(msg_key, "rt");
    FILE *ftext = fopen(msg_text, "wt");
    BYTE *dest = pic->pic;
    int x, y, det = 0, real_y, pos = 0, num = 0, W = pic->bi.biWidth, H = pic->bi.biHeight, pixel_pos;
    char comp;
    while (fscanf(fkey, "%d%d", &x, &y) > 0) {
        fgetc(fkey);
        comp = fgetc(fkey);
        if (det == 5) {
            det = 0;
            write(ftext, num);
            num = 0;
        }
        real_y = H - y - 1;
        pos = shift(comp);
		pixel_pos = 3 * (real_y * W + x) + pos;
        num += (dest[pixel_pos] & 1) << det;
        det++;
    }
    write(ftext, num);
    fclose(fkey);
    fclose(ftext);
    return EXIT_SUCCESS;
}
