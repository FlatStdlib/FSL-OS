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

/* Fonts */
extern u64 a_font_bitmap[];
extern u64 b_font_bitmap[];
extern u64 c_font_bitmap[];
extern u64 d_font_bitmap[];
extern u64 e_font_bitmap[];
extern u64 f_font_bitmap[];
extern u64 g_font_bitmap[];
extern u64 h_font_bitmap[];
extern u64 i_font_bitmap[];
extern u64 j_font_bitmap[];
extern u64 k_font_bitmap[];
extern u64 l_font_bitmap[];
extern u64 m_font_bitmap[];
extern u64 n_font_bitmap[];
extern u64 o_font_bitmap[];
extern u64 p_font_bitmap[];
extern u64 q_font_bitmap[];
extern u64 r_font_bitmap[];
extern u64 s_font_bitmap[];
extern u64 t_font_bitmap[];
extern u64 u_font_bitmap[];
extern u64 v_font_bitmap[];
extern u64 w_font_bitmap[];
extern u64 x_font_bitmap[];
extern u64 y_font_bitmap[];
extern u64 z_font_bitmap[];

public fb_t init_fb();
public u32 create_pixel(u8 fg, u8 bg, u8 pixel);
public fn add_pixel(fb_t fb, int x, int y, int fg, int bg, char c);
public fn display_fb(fb_t fb);

#endif