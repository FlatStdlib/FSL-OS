#include <fsl.h>

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

static void *bold_fonts[][2] = {
    {(void *)'h', o_fat_font_bitmap},
    {(void *)'o', o_fat_font_bitmap}
};

int entry()
{
    for(int i = 0; i < 2; i++)
    {
        void **n = (char **)bold_fonts[i];
        char ch = (char)(up_t)bold_fonts[i][0];
        printc(ch);
    }
}