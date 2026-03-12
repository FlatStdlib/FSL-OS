/*
    FSL OS Desktop Theme
*/
#include "../gfb.h"
#include "../../fsl_efi.h"

/* Create Taskbar and Statistic Gadge */
public fn init_fsl_theme()
{
    clear_screen(0x00000000);
	/* Taskbar */
    int end = _FSLEFI_->resolution.y;
    for(int y = 20; y < end; y++)
        for(int x = 5; x < 55; x++)
            draw_pixel(0, 0, y, x, 0x00535f46);

    /* Top/Bottom Border */
    for(int y = 20; y < end; y++)
        for(int x = 5, at_x = 53; x < 8; x++, at_x++)
            draw_pixel(0, 0, y, x, 0x00ff0000), draw_pixel(0, 0, y, at_x, 0x00ff0000);

    /* Left/Right Border */
    for(int y = 20, at_y = end - 3; y < 23; y++, at_y++)
        for(int x = 5; x < 55; x++)
            draw_pixel(0, 0, y, x, 0x00ff0000), draw_pixel(0, 0, at_y, x, 0x00ff0000);

    int start = _FSLEFI_->resolution.y + 30;
    for(int y = start; y < _FSLEFI_->resolution.y + 100; y++)
        for(int x = 5; x < _FSLEFI_->resolution.x - 30; x++)
            draw_pixel(0, 0, y, x, 0x00ff0000);

    u64 *wlc_msg[] = {
        f_fat_font_bitmap,
        s_fat_font_bitmap,
        l_fat_font_bitmap,
        space_font_bitmap,
        o_fat_font_bitmap,
        s_fat_font_bitmap,
        NULL
    };

    int start_pos = 40;
    for(int i = 0, font_spacing = 0; i < 6; i++, font_spacing += 8) {
        if(wlc_msg[i] == space_font_bitmap)
            output_char(start_pos + font_spacing, 15, 8, 10, 0x00535f46, wlc_msg[i]);
        else
            output_char(start_pos + font_spacing, 15, 8, 10, 0x00000000, wlc_msg[i]);
        
        gBS->Stall(500000); // 50ms
    }
}