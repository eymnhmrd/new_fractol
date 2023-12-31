#ifndef FRACTOL_H
#define FRACTOL_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "./mlx_linux/mlx.h"

#define WIDTH 1200
#define HEIGHT 800
#define MAX_ITER 100

#define ESC 65307
#define CLOSE_BTN 17
#define KEY_PLUS 61
#define KEY_MINUS 45
#define KEY_ONE 49
#define KEY_TWO 50
#define KEY_THREE 51
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_UP 65362
#define KEY_DOWN 65364
#define KEY_LEFT 65361
#define KEY_RIGHT 65363
#define KEY_SPACE 32

typedef struct s_complex
{
    double  re;
    double  im;
}t_complex;

typedef struct s_fractal
{
    void       *mlx_ptr;
    void       *win_ptr;
    void       *img_ptr;
    int        *addr;
    int		    bits_per_pixel;
	int		    line_length;
	int		    endian;
    int         fractal_type;
    double      max_x;
    double      min_x;
    double      max_y;
    double      min_y;
    double      mouse_re;
    double      mouse_im;
    t_complex   c_ju;
    int         fix;
}t_fractal;

int     mandelbrot(t_complex c);
void    draw_mandelbrot(t_fractal *f);
int     julia(t_fractal *f, t_complex c);
void    draw_julia(t_fractal *f);
int     burningship(t_complex c);
void    draw_burningship(t_fractal *f);

void    render(t_fractal *f);
void    init(t_fractal *f);
int     fractal_type(char *argv, t_fractal *f);
void    init_bounds(t_fractal *f);
void    help(void);

void    ft_close(t_fractal *f);
int     end(t_fractal *f);
int     key_handle(int key, t_fractal *f);
int     mouse_move(int x, int y, t_fractal *f);
void    move(t_fractal *f, double step, char direction);

int     mouse_press(int button, int x, int y, t_fractal *f);
void    zoom(t_fractal *f, double mouse_re, double mouse_im, double interp);
double  interpolate(double start, double end, double interp);

void    ft_putstr(char *str);
double  ft_abs(double n);
int     ft_strcmp(char *s1, char *s2);

#endif 