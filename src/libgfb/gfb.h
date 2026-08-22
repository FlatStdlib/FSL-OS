/* Public SDK - Globals Only */
#pragma once

#include "../libc/efi_libc.h"

#ifndef _FSL_FRAMEBUFFER_H
#define _FSL_FRAMEBUFFER_H

typedef struct 
{
    u32 x, y;
} _pdata;

typedef _pdata location_t;
typedef _pdata e_size_t;

/* BG << 24 | FG << 16 | PIXEL << 8 */
typedef u64		pixel_t;
typedef pixel_t *frame_t;

typedef struct
{
    location_t      location;   // Location Of the Element On Parent (X,Y)
    e_size_t        size;       // Size of the element (X,Y)
    frame_t			handle;     // Framebuffer
    u32	 			max_pixels; // Total Max Pixels
} _element;

/* Shape */
typedef _element *shape_t;

/* Framebuffer */
typedef _element *fb_t;

/* theme.c */
public fn create_box(int x, int y, int w, int h, u64 bg);
public fn place_bold_text(int x, int y, int BM_height, int BM_width, i64 fg, i64 bg, string text);
public fn place_text(int x, int y, int BM_height, int BM_width, i64 fg, i64 bg, string text);
public fn place_char_bitmap(int x, int y, int BM_height, int BM_width, i64 fg, i64 bg, u64 **text, i32 sz);
public fn clear_screen(uint32_t color);
public fn output_char(int at_x, int at_y, int width, int height, u32 color, u64 *bitmap);
public fn output_large_char(int at_x, int at_y, int width, int height, u32 color, u64 *bitmap);
public fn draw_pixel(int at_x, int at_y, int x, int y, uint32_t color);

/*
    [ libgfb/desktop/theme.c ]
*/
public fn init_fsl_theme();
public fn display_os_name();
public fn create_info_box();
public fn get_cpu_info();
public fn create_terminal();
#endif
