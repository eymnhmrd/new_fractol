#include "fractol.h"

double     ft_abs(double n)
{
    if (n < 0)
        return (-n);
    return (n);
}

int     burningship(t_complex c)
{
    int       n;
    t_complex z;
    double    tmp;

    n = 0;
    z.re = 0;
    z.im = 0;
    while ((z.re * z.re + z.im * z.im <= 4) && n < MAX_ITER)
    {
        tmp = z.re;
        z.re = z.re * z.re - z.im * z.im + c.re;
        z.im = 2 * ft_abs(tmp * z.im) + c.im;
        n++;
    }
    if (n == MAX_ITER)
        return (0xFFFF00);
    return (n + 1 - log(log2(sqrt(z.re * z.re + z.im * z.im))));
}

void    draw_burningship(t_fractal *f)
{
    int x;
    int y;
    t_complex c;
    int color;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            c.re = f->min_x + ((double)x / WIDTH) * (f->max_x - f->min_x);
            c.im = f->min_y + ((double)y / HEIGHT) * (f->max_y - f->min_y);
            color = burningship(c);
            f->addr[y * WIDTH + x] = color;
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
}