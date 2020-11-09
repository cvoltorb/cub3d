/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvoltorb <cvoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:29:54 by cvoltorb          #+#    #+#             */
/*   Updated: 2020/11/09 19:57:57 by cvoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define FLG_NONE	0b00000000
# define FLG_RES	0b00000001
# define FLG_NORTH	0b00000010
# define FLG_SOUTH	0b00000100
# define FLG_WEST	0b00001000
# define FLG_EAST	0b00010000
# define FLG_SPR	0b00100000
# define FLG_FLOOR	0b01000000
# define FLG_CEIL	0b10000000

# define BLOCK_SIZE 64
# define FOV (M_PI / 3)

# define NONE 0xFF000000
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define MAGENTA 0x00FF00FF
# define YELLOW 0x00FFFF00
# define CYAN 0x0000FFFF

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define SPEED 15
# define TURN 0.05

typedef struct	s_texture
{
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	char		*sprite_texture;
}				t_texture;

typedef struct	s_params
{
	int			resolution[2];
	int			flr_color;
	int			ceil_color;
	char		**map;
	int			len_x;
	int			len_y;
}				t_params;

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			img_width;
	int			img_height;
}				t_data;

typedef struct	s_images
{
	t_data		no_img;
	t_data		so_img;
	t_data		we_img;
	t_data		ea_img;
	t_data		sprite_img;
}				t_images;

typedef struct	s_sprite
{
	double		sprite_x;
	double		sprite_y;
	double		sprite_dist;
	t_data		img_sprite;
}				t_sprite;

typedef struct	s_vars
{
	t_images	texture;
	void		*mlx;
	void		*win_mlx;
	t_data		img;
	int			px;
	int			py;
	double		pov;
	double		current_ray;
	double		xa;
	double		ya;
	int			s_width;
	int			s_height;
	int			len_x;
	int			len_y;
	char		**map;
	double		offset_x_hor;
	double		offset_y_vert;
	t_sprite	*sprites;
	int			flr_color;
	int			ceil_color;
	int			sprites_amount;
	double		*ray_length;
}				t_vars;

int				get_next_line(int fd, char **line);
int				ft_close(t_vars *vars);
int				events(int keycode, t_vars *vars);
int				get_amount_line(char **lines);
int				parser(t_params *params, t_texture *data_cub, int fd);
int				parse_resolution(t_params *params, char **parsed_line, \
													unsigned char *flags);
int				parse_textures(t_texture *textures, char **parsed_line, \
													unsigned char *flags);
int				parse_params(t_params *params, char **parsed_line, \
												unsigned char *flags);
char			**get_map(int fd, t_params *params);
void			ft_free_array(char ***ar);
int				ft_pos(char **map);
int				ft_choice_mass(char **map, char *set);
int				ft_full_map(char **map);
void			get_sprite_coord(t_vars *vars);
void			ft_count_sprites(t_vars *vars);
void			ft_error(int flag);
int				ft_look_up(double f);
int				ft_look_right(double f);
double			make_angle(double ray);
int				get_len_ray(t_vars *vars, double ray);
double			horizontal_ray(t_vars *vars, double ray);
double			vertical_ray(t_vars *vars, double ray);
void			paint_ceil(t_vars *vars, int top_pos_of_wall, int num_wall);
void			paint_floor(t_vars *vars, int bot_pos_of_wall, int num_wall);
void			get_hor_texture(t_vars *vars, t_data *current_texture);
void			get_vert_texture(t_vars *vars, t_data *current_texture);
int				start(t_params *params, t_texture *textures, int screen);
void			print_ray(t_data *img, int x, int y, double start, double len);
void			t_draw_map(t_data *img, char **map);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			my_mlx_draw_square(t_data *data, int x1, int y1, int color);
int				get_coordinates(t_vars *vars);
int				cast_ray(t_vars *vars);
int				my_mlx_pixel_get_color(t_data *data, int x, int y);
void			create_bmp(t_vars *vars);
void			get_sprite(t_vars *vars, int num_sprite);
void			sort_sprites(t_vars *vars);
int				get_cur_color(t_vars *vars, t_data *current_texture, \
															int y_pixel);
void			free_textures(t_texture *textures);
void			check_texture_correct(t_vars *vars);

#endif
