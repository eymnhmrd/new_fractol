#include "fractol.h"

int     julia(t_fractal *f, t_complex c)
{
    int         n;
    t_complex   z;
    double      tmp;

    n = 0;
    z.re = c.re;
    z.im = c.im;
    while ((z.re * z.re + z.im * z.im <= 4) && n < MAX_ITER)
    {
        tmp = z.re;
        z.re = z.re * z.re - z.im * z.im + f->c_ju.re;
        z.im = 2 * tmp * z.im + f->c_ju.im;
        n++;
    }
    if (n == MAX_ITER)
        return (0xFF0000);
    return (n + 1 - log(log(sqrt(z.re * z.re + z.im * z.im))));
}

void    draw_julia(t_fractal *f)
{
    int x;
    int y;
    t_complex   c;
    int color;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            c.re = f->min_x + ((double)x / WIDTH) * (f->max_x - f->min_x);
            c.im = f->min_y + ((double)y / HEIGHT) * (f->max_y - f->min_y);
            color = julia(f, c);
            f->addr[y * WIDTH + x] = color;
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
}