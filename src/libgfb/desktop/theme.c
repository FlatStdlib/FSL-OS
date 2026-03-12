/*
    FSL OS Desktop Theme
*/
#include "../../fsl_efi.h"

/* Create Taskbar and Statistic Gadge */
public fn init_fsl_theme()
{
	/* Taskbar */
    int end = _FSLEFI_->resolution.y + 10;
    for(int y = 20; y < end; y++)
        for(int x = 50; x < 100; x++)
            draw_pixel(0, 0, y, x, 0x00535f46);

    /* Top/Bottom Border */
    for(int y = 20; y < end; y++)
        for(int x = 50, at_x = 97; x < 53; x++, at_x++)
            draw_pixel(0, 0, y, x, 0x00ff0000), draw_pixel(0, 0, y, at_x, 0x00ff0000);

    /* Left/Right Border */
    for(int y = 20, at_y = end - 3; y < 23; y++, at_y++)
        for(int x = 50; x < 100; x++)
            draw_pixel(0, 0, y, x, 0x00ff0000), draw_pixel(0, 0, at_y, x, 0x00ff0000);

    // int start = _FSLEFI_->resolution.y = 200;
    // for(int y = start; y < _FSLEFI_->resolution.y; y++)
    //     for(int x = 30; x < _FSLEFI_->resolution.x; x++)
    //         draw_pixel(0, 0, y, x, 0x00ff0000);

    clear_screen(_FSLEFI_, 0x00000000);
    init_fsl_theme();
    u64 *wlc_msg[] = {
        f_font_bitmap,
        s_font_bitmap,
        l_font_bitmap,
        space_font_bitmap,
        o_font_bitmap,
        s_font_bitmap,
        NULL
    };

    output_char(200, 60, 8, 10, 0x00000000, h_fat_font_bitmap);
    output_char(208, 60, 8, 10, 0x00000000, e_fat_font_bitmap);
    output_char(216, 60, 8, 10, 0x00000000, l_fat_font_bitmap);
    output_char(225, 60, 8, 10, 0x00000000, l_fat_font_bitmap);
    output_char(233, 60, 8, 10, 0x00000000, o_fat_font_bitmap);
    int start_pos = 40;
    for(int i = 0, font_spacing = 0; i < 6; i++, font_spacing += 8) {
        if(wlc_msg[i] == space_font_bitmap)
            output_char(start_pos + font_spacing, 60, 8, 7, 0x00535f46, wlc_msg[i]);
        else
            output_char(start_pos + font_spacing, 60, 8, 7, 0x00000000, wlc_msg[i]);
    }
}