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
typedef u32		pixel_t;
typedef pixel_t *frame_t;

struct winsize {
    u16 			ws_row;
   	u16 			ws_col;
    u16 			ws_xpixel;
    u16 			ws_ypixel;
};

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


public fn clear_screen(uint32_t color);
public fn output_char(int at_x, int at_y, int width, int height, u32 color, u64 *bitmap);
void draw_pixel(int at_x, int at_y, int x, int y, uint32_t color);

#endif