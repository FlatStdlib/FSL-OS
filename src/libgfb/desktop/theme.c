/*
    FSL OS Desktop Theme
*/
#include "../../fsl_efi.h"

public fn init_fsl_theme(fb_t fb)
{
	/* Taskbar */
    int end = _FSLEFI_->resolution.y + 10;
    for(int y = 20; y < end; y++)
        for(int x = 50; x < 100; x++)
            draw_pixel(0, 0, y, x, 0x00535f46);

    /* Top Border */
    for(int y = 20; y < end; y++)
        for(int x = 50, at_x = 97; x < 53; x++, at_x++)
            draw_pixel(0, 0, y, x, 0x00ff0000), draw_pixel(0, 0, y, at_x, 0x00ff0000);

    /* Bottom Border */
    // for(int y = 20; y < end; y++)
    //     for(int x = 97; x < 100; x++)
    //         draw_pixel(0, 0, y, x, 0x00ff0000);

    /* Left Border */
    for(int y = 20, at_y = end - 3; y < 23; y++, at_y++)
        for(int x = 50; x < 100; x++)
            draw_pixel(0, 0, y, x, 0x00ff0000), draw_pixel(0, 0, at_y, x, 0x00ff0000);

    /* Right Border */
    // for(int y = end - 3; y < end; y++)
    //     for(int x = 50; x < 100; x++)
    //         draw_pixel(0, 0, y, x, 0x00ff0000);
}