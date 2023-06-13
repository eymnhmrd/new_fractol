#include "fractol.h"

void    render(t_fractal *f)
{
    if (f->fractal_type == 1)
        draw_mandelbrot(f);
    else if (f->fractal_type == 2)
        draw_julia(f);
    else if (f->fractal_type == 3)
        draw_burningship(f);
}