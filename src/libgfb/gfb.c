#include "gfb.h"

public fb_t init_fb(int width, int height)
{
    fb_t fb = allocate(0, sizeof(_element));

	fb->handle = allocate(0, sizeof(u16) * (width * height));
	fb->max_pixels = width * height;
    fb->size.x = width;
    fb->size.y = height;

	for(int i = 0; i < fb->max_pixels; i++) fb->handle[i] = create_pixel(39, 49, ' ');
    return fb;
}

public u32 create_pixel(u8 fg, u8 bg, u8 pixel)
{ return ((u32)fg << 24) | ((u32)bg << 16) | ((u32)pixel << 8); }

public fn add_pixel(fb_t fb, int x, int y, int fg, int bg, char c)
{
	fb->handle[x * fb->size.x + y] = create_pixel(fg, bg, c);
}

public fn display_fb(fb_t fb)
{
	for(int i = 0; i < fb->max_pixels; i++)
	{
		CHAR16 COLOR[100] = {0};
		str_append(COLOR, L"\x1b[");
		str_append_int(COLOR, (fb->handle[i] >> 24) & 0xFF);
		str_append(COLOR, L"m");
		print(COLOR);

		memzero(COLOR, 99);
		str_append(COLOR, L"\x1b[");
		str_append_int(COLOR, (fb->handle[i] >> 16) & 0xFF);
		str_append(COLOR, L"m");
		print(COLOR);

		printc((fb->handle[i] >> 8) & 0xFF);
	}

	print(L"\x1b[39m\x1b[49m");
}