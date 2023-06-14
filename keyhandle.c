#include "fractol.h"

int     end(t_fractal *f)
{
    ft_close(f);
    return (0);
}

void    ft_close(t_fractal *f)
{
    mlx_destroy_image(f->mlx_ptr, f->img_ptr);
    mlx_destroy_window(f->mlx_ptr, f->win_ptr);
    exit(EXIT_SUCCESS);
}

int     mouse_move(int x, int y, t_fractal *f)
{
    if (f->fractal_type == 2)
    {
        f->c_ju.re = f->min_x + ((double)x / WIDTH) * (f->max_x - f->min_x);
		f->c_ju.im = f->min_y + ((double)y / HEIGHT) * (f->max_y - f->min_y);
    }
    draw_julia(f);
    return (0);
}

int     key_handle(int key, t_fractal *f)
{
    if (key == ESC)
        ft_close(f);
    extended_key_handle(key, f);
    return (0);
}

void     extended_key_handle(int key, t_fractal *f)
{
    if (key == KEY_ONE && f->fractal_type != 1)
        f->fractal_type = 1;
    else if (key == KEY_TWO && f->fractal_type != 2)
        f->fractal_type = 2;
    else if (key == KEY_THREE && f->fractal_type != 3)
        f->fractal_type = 3;
    init_bounds(f);
    render(f);
}
