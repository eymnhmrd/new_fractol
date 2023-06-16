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

void    move(t_fractal *f, double step, char direction)
{
    double  distance_x;
    double  distance_y;

    distance_x = f->max_x - f->min_x;
    distance_y = f->max_y - f->min_y;
    if (direction == 'R')
    {
        f->max_x = f->max_x + distance_x * step;
        f->min_x = f->min_x + distance_x * step;
    }
    else if (direction == 'L')
    {
        f->max_x = f->max_x - distance_x * step;
        f->min_x = f->min_x - distance_x * step;
    }
    else if (direction == 'D')
    {
        f->max_y = f->max_y + distance_y * step;
        f->min_y = f->min_y + distance_y * step;
    }
    else if (direction == 'U')
    {
        f->max_y = f->max_y - distance_y * step;
        f->min_y = f->min_y - distance_y * step; 
    }
}

int     mouse_move(int x, int y, t_fractal *f)
{
    if (f->fractal_type == 2 && f->fix)
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
    else if (key == KEY_UP || key == KEY_W)
        move(f, 0.2, 'U');
    else if (key == KEY_RIGHT || key == KEY_D)
        move(f, 0.2, 'R');
    else if (key == KEY_DOWN || key == KEY_S)
        move(f, 0.2, 'D');
    else if (key == KEY_LEFT || key == KEY_A)
        move(f, 0.2, 'L');
    else if (key == KEY_SPACE)
        f->fix = !f->fix;
    render(f);
    return (0);
}
