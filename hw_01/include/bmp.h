#ifndef __BMP_H_
#define __BMP_H_
#pragma pack(push, 1)
#define EXIT_SUCCESS 0
#define INPUT_ERROR 1
#define READ_ERROR 2
#define MEM_ERROR 3
#define ERROR 4
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef int LONG;
typedef struct tagBITMAPFILEHEADER {
    WORD    bfType;
    DWORD   bfSize;
    WORD    bfReserved1;
    WORD    bfReserved2;
    DWORD   bfOffBits;
} BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER {
    DWORD  biSize;
    LONG   biWidth;
    LONG   biHeight;
    WORD   biPlanes;
    WORD   biBitCount;
    DWORD  biCompression;
    DWORD  biSizeImage;
    LONG   biXPelsPerMeter;
    LONG   biYPelsPerMeter;
    DWORD  biClrUsed;
    DWORD  biClrImportant;
} BITMAPINFOHEADER;

typedef struct tagPICTURE {
    BITMAPFILEHEADER bh;
    BITMAPINFOHEADER bi;
    BYTE *pic;
} PICTURE;

int load_bmp(const char *filename, PICTURE *pic);
int save_bmp(const char *filename, PICTURE *pic);
int crop_bmp(PICTURE *pin, PICTURE *cr, int x, int y, int w, int h);
int rotate_bmp(PICTURE *pin);
int insert(PICTURE *pic, char *msg_key, char *msg_text);
int extract(PICTURE *pic, char *msg_key, char *msg_text);
#endif
