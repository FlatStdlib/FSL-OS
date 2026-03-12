#include "bold_font.h"
#include "default_font.h"

#define TOTAL_BOLD_FONTS 25

static void *bold_fonts[][3] = {
    {(void *)'a', a_font_bitmap, a_fat_font_bitmap},
    {(void *)'b', b_font_bitmap, b_fat_font_bitmap},
    {(void *)'c', c_font_bitmap, c_fat_font_bitmap},
    {(void *)'d', d_font_bitmap, d_fat_font_bitmap},
    {(void *)'e', e_font_bitmap, e_fat_font_bitmap},
    {(void *)'f', f_font_bitmap, f_fat_font_bitmap},
    {(void *)'g', g_font_bitmap, g_fat_font_bitmap},
    {(void *)'h', h_font_bitmap, h_fat_font_bitmap},
    {(void *)'i', i_font_bitmap, i_fat_font_bitmap},
    {(void *)'j', j_font_bitmap, j_fat_font_bitmap},
    {(void *)'k', k_font_bitmap, k_fat_font_bitmap},
    {(void *)'l', l_font_bitmap, l_fat_font_bitmap},
    {(void *)'m', m_font_bitmap, m_fat_font_bitmap},
    {(void *)'n', n_font_bitmap, n_fat_font_bitmap},
    {(void *)'o', o_font_bitmap, o_fat_font_bitmap},
    {(void *)'p', p_font_bitmap, p_fat_font_bitmap},
    {(void *)'q', q_font_bitmap, q_fat_font_bitmap},
    {(void *)'r', r_font_bitmap, r_fat_font_bitmap},
    {(void *)'s', s_font_bitmap, s_fat_font_bitmap},
    {(void *)'t', t_font_bitmap, t_fat_font_bitmap},
    {(void *)'u', u_font_bitmap, u_fat_font_bitmap},
    {(void *)'v', v_font_bitmap, v_fat_font_bitmap},
    {(void *)'w', w_font_bitmap, w_fat_font_bitmap},
    {(void *)'x', x_font_bitmap, x_fat_font_bitmap},
    {(void *)'y', y_font_bitmap, y_fat_font_bitmap},
    {(void *)'z', z_font_bitmap, z_fat_font_bitmap},
    NULL
};

static u64 *get_char_bitmap(char ch)
{
    for(int i = 0; i < TOTAL_BOLD_FONTS; i++)
        if(*(int *)((void **)bold_fonts[i])[0] == ch)    
            return (u64 *)((void **)bold_fonts[i])[1];

    return NULL;
}