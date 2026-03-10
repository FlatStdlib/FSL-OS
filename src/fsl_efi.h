#pragma once

#include "libc/efi_libc.h"
#include "libgfb/gfb.h"
#include "libgfb/fonts.h"
#include "libgfb/bold_font.h"
#include "fs/fs.h"

#include "../third_party_libs/fonts/test.h"
#ifndef _FSL_EFI_H
    #define _FSL_EFI_H
    #define _FSL_EFI_FS_H
#endif

extern EFI_HANDLE gImage;
extern EFI_BOOT_SERVICES *gBS;
extern EFI_SYSTEM_TABLE *gST;
extern EFI_GRAPHICS_OUTPUT_PROTOCOL *Gop;

typedef struct {
    int x, y;
} _cordination;

typedef struct {
    int r, g, b;
} _rgb;

typedef _cordination screen_size;
typedef _cordination position;
typedef _cordination cursor_pos_t;

typedef struct
{
    string  name;
    string  cmd;
    i32     argc;
    string  err;
} _cmd;

typedef _cmd *cmd_t;
typedef _cmd **cmds_t;

typedef struct {
    /* Main HDD/USB FS */
    drive_t         hdd_handle;

    fb_t            fb;
    u32             *framebuffer;
    screen_size     resolution;

    /* CLI Stuff */
    cursor_pos_t    cursor;

    /* System Variables */
    map_t           variables;
    i32             var_len;

    /* Commands */
    cmds_t          commands;
    i32             cmd_len;
} fsl_efi;

extern fsl_efi *_FSLEFI_;
public fn EFIAPI Init_FSL(EFI_SYSTEM_TABLE *SystemTable, EFI_HANDLE ImageHandle);
public fn switch_to_gui_mode();
void uefi_pixel_fn(int x, int y, void *color, void *user_data);
public fn clear_screen(fsl_efi *fsl, uint32_t color);
void draw_char(fsl_efi *fsl, int x, int y, uint8_t *bitmap, uint32_t color);
public fn output_char(int at_x, int at_y, int width, int height, u32 color, u64 *bitmap);
public fn add_font_bitmap(fb_t fb, int at_x, int at_y, int col, int rows, u64 bitmap[restrict rows]);
void draw_pixel(int at_x, int at_y, int x, int y, uint32_t color);
public fn read_usb_drive();
public fn input_strip(const string buff, int *size);
private inline UINT64 rdtsc(void);
public fn blink_cursor();
public string  get_line(const string buffer);
public fn fsl_cli();
public fn create_task_bar(fb_t fb);