#include "gfb.h"

// public fn create_task_bar(fb_t fb)
// {
// 	for(int x = fb->size.y - 5, y = 0; x < fb->size.y; x++)
// 	{
// 		fb->handle[x * fb->size.x] = create_pixel(31, 49, '|');
// 		if(x == fb->size.y - 5 || x == fb->size.y - 1)
// 		{
// 			for(y = 1; y < fb->size.x - 2; y++)
// 			{
// 				fb->handle[x * fb->size.x + y] = create_pixel(31, 49,  '-');
// 			}
// 		}
// 		fb->handle[x * fb->size.x + y] = create_pixel(31, 49, '|');
// 	}
// }