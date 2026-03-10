/* 

    [ Single header file font bitmap lib ]

*/
#include "gfb.h"

//10x8
static u64 h_fat_font_bitmap[] = {
    0b01100110,
    0b01100110,
    0b01100110,
    0b01100110,
    0b01111110,
    0b01111110,
    0b01100110,
    0b01100110,
    0b01100110,
    0b00000000
};

static u64 e_fat_font_bitmap[] = {
    0b01111110,
    0b01111110,
    0b01100000,
    0b01100000,
    0b01111100,
    0b01100000,
    0b01100000,
    0b01111110,
    0b01111110,
    0b00000000
};

static u64 l_fat_font_bitmap[] = {
    0b11000000,
    0b11000000,
    0b11000000,
    0b11000000,
    0b11000000,
    0b11000000,
    0b11000000,
    0b11111110,
    0b11111110,
    0b00000000
};

static u64 o_fat_font_bitmap[] = {
    0b01111100,
    0b11111110,
    0b11000110,
    0b11000110,
    0b11000110,
    0b11000110,
    0b11000110,
    0b11111110,
    0b01111100,
    0b00000000
};

#define TOTAL_BOLD_FONTS 4
static void *bold_fonts[][2] = {
    {(void *)'h', h_fat_font_bitmap},
    {(void *)'e', e_fat_font_bitmap},
    {(void *)'l', l_fat_font_bitmap},
    {(void *)'o', o_fat_font_bitmap}
};

static u64 *get_char_bitmap(char ch)
{
    for(int i = 0; i < TOTAL_BOLD_FONTS; i++)
    {
        
        void **n = bold_fonts[i];
        char chr = *(int *)n[0];
        if(chr == ch)    
            return bold_fonts[i][1];
    }

    return NULL;
}