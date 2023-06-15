#include "fractol.h"

double  interpolate(double start, double end, double interp)
{
    return (start + (end - start) * interp);
}

void    zoom(t_fractal *f, double mouse_re, double mouse_im, double interp)
{
    double rapport;

    rapport = 1.0 / interp;
    f->max_x = interpolate(mouse_re, f->max_x, rapport);
    f->max_y = interpolate(mouse_im, f->max_y, rapport);
    f->min_x = interpolate(mouse_re, f->min_x, rapport);
    f->max_y = interpolate(mouse_im, f->max_y, rapport);
}

int mouse_press(int button, int x, int y, t_fractal *f)
{
    f->mouse_re = f->min_x + ((double)x / WIDTH) * (f->max_x - f->min_x);
    f->mouse_im = f->min_y + ((double)y / WIDTH) * (f->max_y - f->min_y);
    if (button == 1)
        zoom(f, f->mouse_re, f->mouse_im, 2);
    else if (button == 3)
        zoom(f, f->mouse_re, f->mouse_im, 0.5);
    render(f);
    return (0);
}