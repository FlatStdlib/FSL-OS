/*
    FSL OS Desktop Theme
*/
#include "gfb.h"
#include "../fsl_efi.h"

/* Create Taskbar and Statistic Gadge */
public fn init_fsl_theme()
{
    clear_screen(0x00000000);
    
	/* Taskbar */
    int end = _FSLEFI_->resolution.x - 20;
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

    display_os_name();  
    create_info_box();
    get_cpu_info();
}

public fn display_os_name()
{
    u64 *boot_msg[] = {
        f_pretty_font,
        s_pretty_font,
        l_pretty_font,
        space_font_bitmap,
        space_font_bitmap,
        o_pretty_font,
        s_pretty_font,
        NULL
    };

    int start_pos = 100;
    for (int i = 0, font_spacing = 0; i < 8; i++, font_spacing += 30)
    {
        if (boot_msg[i] == space_font_bitmap)
        {
            output_large_char(start_pos + font_spacing, 25, 24, 11, 0x00535f46, boot_msg[i]);
            continue;
        }
        else
        {
            output_large_char(start_pos + font_spacing, 25, 24, 11, 0xFFFFFFFF, boot_msg[i]);
        }

        gBS->Stall(500000);
    }
}

public fn create_info_box()
{
    int start_x = 100;
    int end_x = _FSLEFI_->resolution.y - 20;

    int start_y = 20;
    int end_y = 200;

    for(int y = start_y; y < end_y; y++)
        for(int x = start_x; x < end_x; x++)
            draw_pixel(0, 0, y, x, 0x00535f46);

    place_text(25, 120, 8, 8, 0x00000000, 0x00535f46, L"[ info and settings ]");
}

public fn get_cpu_info()
{
    place_text(25, 180, 8, 8, 0x00ff0000, 0x00535f46, L"cpu ");
    register u32 r asm("eax") = 0;
    asm("cpuid");
    register u32 eax asm("ebx");
    register u32 ebx asm("edx");
    register u32 ecx asm("ecx");

    i8 vendor[13];
    ((u32 *)vendor)[0] = eax;
    ((u32 *)vendor)[1] = ebx;
    ((u32 *)vendor)[2] = ecx;

    CHAR16 vendor16[13];
    for (int i = 0; i < 12; i++)
        vendor16[i] = (CHAR16)vendor[i];

    vendor16[12] = L'\0';
    place_text(50, 180, 8, 8, 0x00ff0000, 0x00535f46, vendor16);
}