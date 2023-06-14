#include "fractol.h"

void    help(void)
{
    ft_putstr("------      Fract-ol      ------\n");
    ft_putstr("Usage : ./fractol [fractal_name]\n");
    ft_putstr("      1 - Mandelbrot            \n");
    ft_putstr("      2 - Julia                 \n");
    ft_putstr("      3 - Burningship           \n");
    exit(EXIT_SUCCESS);
}

int    fractal_type(char *argv, t_fractal *f)
{
    if (ft_strcmp(argv, "Mandelbrot") == 0)
        f->fractal_type = 1;
    else if (ft_strcmp(argv, "Julia") == 0)
        f->fractal_type = 2;
    else if (ft_strcmp(argv, "Burningship") == 0)
        f->fractal_type = 3;
    else
        return (0);
    return (1);
}

int	main(int argc, char **argv)
{
	t_fractal   f;

    if (argc == 2)
    {
        if (fractal_type(argv[1], &f))
        {
            init(&f);
            f.addr = (int *)mlx_get_data_addr(f.img_ptr, &f.bits_per_pixel, &f.line_length, &f.endian);
            render(&f);
            mlx_hook(f.win_ptr, CLOSE_BTN, 0, end, &f);
            mlx_key_hook(f.win_ptr, key_handle, &f);
            if (f.fractal_type == 2)
                mlx_hook(f.win_ptr, 6, 1L<<6, mouse_move, &f);
            mlx_loop(f.mlx_ptr);
        }
        else
            help();
    }
    else
        help();
}