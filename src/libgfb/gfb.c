
#include "gfb.h"            // Public
#include "../fsl_efi.h"     // Private

public fn output_char(int at_x, int at_y, int width, int height, u32 color, u64 *bitmap)
{
    int bitcount = 0;
    for(int y = at_y; y < at_y + height; y++, bitcount++)
	{
		for(int x = at_x, bit = width; x < at_x + width; x++, bit--)
			if((bitmap[bitcount] >> bit) & 0xFF != 0)
				draw_pixel(0, 0, x, y, color);
	}
}

public fn clear_screen(uint32_t color)
{
    UINTN pixels = _FSLEFI_->resolution.x * _FSLEFI_->resolution.y;
    for(UINTN i = 0; i < pixels; i++)
        _FSLEFI_->framebuffer[i] = color;
}

public fn draw_pixel(int at_x, int at_y, int x, int y, uint32_t color) {
    UINTN stride = vGop->Mode->Info->PixelsPerScanLine;
    _FSLEFI_->framebuffer[(at_y + y) * stride + (at_x + x)] = color;
}