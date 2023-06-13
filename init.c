#include "fractol.h"

void    init_bounds(t_fractal *f)
{
    if (f->fractal_type == 1)
    {
        f->max_x = 1;
        f->min_x = -2;
        f->max_y = 1;
        f->min_y = -1;
    }
    else if (f->fractal_type == 2)
    {
        f->max_x = 2;
        f->min_x = -2;
        f->max_y = 1.5;
        f->min_y = -1.5;
        f->c_ju.re = 0.353;
        f->c_ju.im = 0.353;
    }
    else if (f->fractal_type == 3)
    {
        f->max_x = 1;
        f->min_x = -2;
        f->max_y = 2;
        f->min_y = -2;
    }
}

void    init(t_fractal *f)
{
    init_bounds(f);
    f->mlx_ptr = mlx_init();
    if (!f->mlx_ptr)
        exit(EXIT_FAILURE);
    f->win_ptr = mlx_new_window(f->mlx_ptr, WIDTH, HEIGHT, "Fract-ol");
    if (!f->win_ptr)
        exit(EXIT_FAILURE);
    f->img_ptr = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
    if (!f->img_ptr)
        exit(EXIT_FAILURE);
}