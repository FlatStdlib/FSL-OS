#pragma once

#include "fs/fs.h"
#include "libc/efi_libc.h"
#include "libgfb/gfb.h"
#include "libgfb/bitmaps/fonts.h"

#ifndef _FSL_EFI_H
    #define _FSL_EFI_H
    #define _FSL_EFI_FS_H
#endif

extern EFI_HANDLE gImage;
extern EFI_BOOT_SERVICES *gBS;
extern EFI_SYSTEM_TABLE *gST;
extern EFI_GRAPHICS_OUTPUT_PROTOCOL *Gop;
extern EFI_GRAPHICS_OUTPUT_PROTOCOL *vGop;

#define CPU_HZ 3000000000ULL
#define BLINK_INTERVAL (CPU_HZ)

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

// init.c
public fn EFIAPI Init_EFI(EFI_SYSTEM_TABLE *SystemTable, EFI_HANDLE ImageHandle);
public fn Init_FSL();

/* Temporary CLI SHIT */
public fn read_usb_drive();
public fn input_strip(const string buff, int *size);
public string get_line(const string buffer);
public fn fsl_cli();

/*
    [ libgfb/fb_api.c ]
*/
public void init_gfb(fsl_efi *fsl);

/*
    [ libgfb/desktop/theme.c ]
*/
public fn init_fsl_theme();