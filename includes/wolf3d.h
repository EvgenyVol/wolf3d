/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <jhoppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:48:25 by jhoppe            #+#    #+#             */
/*   Updated: 2019/09/06 17:49:57 by jhoppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include "../frameworks/SDL2.framework/Headers/SDL.h"
# include "../frameworks/SDL2_mixer.framework/Headers/SDL_mixer.h"
# include "../utils/gnl/get_next_line.h"
# include "../utils/libft/libft.h"
# define WIDTH 1200
# define HEIGHT 768
# define FPS 60
# define TEXTURECOUNT 8
# define AMMO_X -25
# define HEALTH_X WIDTH * 5 / 32
# define DELTA_X 50
# define FRAGS_X WIDTH * 9 / 32
# define ARMOR_X WIDTH * 35 / 64
# define UI_Y		w->height + ((HEIGHT - w->height) / 5)
# define TGA			t_tga
# define IMAGE			t_image

typedef unsigned int	t_u32;
typedef unsigned char	t_u8;

typedef struct			s_rgba
{
	int				red;
	int				green;
	int				blue;
	int				alpha;
}						t_rgba;

typedef struct			s_sound
{
	Mix_Music		*bgmusic;
	Mix_Chunk		*shoot;
	Mix_Chunk		**reload;
	int				m_volume;
	int				s_volume;
}						t_sound;

typedef struct			s_image
{
	Uint32			width;
	Uint32			height;
	Uint32			length;
	Uint32			*pixels;
}						t_image;

typedef struct			s_ui_node
{
	t_image			*img;
	SDL_Rect		rect;
}						t_ui_node;

typedef struct			s_ui
{
	t_ui_node		bar;
	t_ui_node		**face;
	t_ui_node		health;
	t_ui_node		ammo;
	t_ui_node		**digit;
	t_ui_node		**letter;
	t_ui_node		menu_background;
	t_ui_node		menu_quit;
	t_ui_node		menu_pause;
	t_ui_node		menu_music;
	t_ui_node		menu_sounds;
	t_ui_node		menu_logo;
	int				position;
	bool			clicked;
}						t_ui;

typedef struct			s_tga
{
	t_u32			size;
	t_u8			data_type;
	t_u8			*data;
	t_u8			*ptr;
	IMAGE			*image;
}						t_tga;

typedef struct			s_texture
{
	t_ui_node		*img_c;
	Uint32			*ptr;
	Uint32			tex_x;
	Uint32			tex_y;
	Uint8			type;
	short			draw_start;
	short			draw_end;
	short			col_height;
}						t_texture;

typedef struct			s_ixy
{
	int				x;
	int				y;
}						t_ixy;

typedef struct			s_dxy
{
	double			x;
	double			y;
}						t_dxy;

typedef struct			s_mouse
{
	struct s_ixy	last;
	struct s_ixy	curr;
}						t_mouse;

typedef struct			s_frametime
{
	double			old;
	double			new;
	double			delta;
	int				framerate;
}						t_frametime;

typedef struct			s_riffle
{
	t_ui_node		**fraps;
	SDL_Rect		rect;
	unsigned int	ammo;
	double			start;
	double			end;
	bool			active;
	int				shoot;
	int				sound_mix;
	bool			busy_anim;
	int				tr;
	struct s_ixy	pos;
}						t_riffle;

typedef struct			s_map
{
	Uint32			**block;
	Uint32			width;
	Uint32			height;
	Uint32			x;
	Uint32			y;
}						t_map;

typedef struct			s_ray
{
	struct s_dxy	dir;
	struct s_dxy	pos;
	double			dist;
	struct s_dxy	delta;
	struct s_dxy	side;
	struct s_dxy	step;
	struct s_ixy	map;
	double			camera;
	double			wallx;
	double			wall_dist;
	int				hit;
	int				hit_side;
	double			floor_x_wall;
	double			floor_y_wall;
	short			draw_start;
	short			draw_end;
}						t_ray;

typedef struct			s_player
{
	struct s_dxy	pos;
	struct s_dxy	dir;
	struct s_dxy	plane;
	double			speed;
	double			rotation;
	double			cx;
	double			cy;
	bool			go;
}						t_player;

typedef struct			s_controls
{
	bool			w;
	bool			a;
	bool			s;
	bool			d;
	bool			q;
	bool			e;
	bool			p;
}						t_controls;

typedef struct			s_window
{
	SDL_Window		*window;
	SDL_Surface		*screen;
	t_image			*screen_img;
	int				width;
	int				height;
	bool			power;
	bool			pause;
	t_u32			*ptr;
	t_ray			ray;
	t_player		player;
	t_riffle		riffle;
	t_map			map;
	t_mouse			mouse;
	t_frametime		ftime;
	t_texture		**textures;
	t_texture		**text_sky;
	t_sound			*music;
	t_ui			ui;
	t_ui_node		sky;
	SDL_Event		e;
	t_controls		controls;
	char			**raw_paths;
}						t_window;

int						global_init(t_window *w);
void					init_riffle(t_window *w);
void					fill_ui(t_window *w);
void					re_init_riffle(t_window *w, int key);
void					load_assets(t_window *w);
int						load_sounds(t_window *w);

void					count_delta_time(t_window *w);
void					sounds_animation(t_window *w);

int						clear_image(t_window *window);
void					draw_cycle(t_window *w);
int						read_map(t_window *wolf, char *path);
void					render_walls(t_window *w);
void					raycasting(t_window *w, int x);
void					move_controls(t_window *w);
void					draw_background(t_window *w);

int						volume_control(t_window *w);
t_image					*scale_bilin(SDL_Rect *rect, t_image *image);
t_image					*scale_img(t_image *img, SDL_Rect r);
void					render_image(t_window *w, t_ui_node *img_c);
void					render_scale(t_window *w, t_ui_node *img_c);
void					render_scale_r(t_window *w,
						t_ui_node *img_c, SDL_Rect rect);
t_ui_node				*scale(t_ui_node *img_c, int percent);

void					cast_floor(t_window *w);
void					set_pixel(SDL_Surface *surf, const int x, const int y,
							const int color);
void					ui_bar(t_window *w);
void					show_menu(t_window *w);

void					make_shot(t_window *w);
void					weapon_animation(t_window *w);
void					weapon_shoot(t_window *w, int key);
void					weapon_fraps(t_window *w, int key);

void					move_forward(t_window *w, double dist);
void					move_backward(t_window *w, double dist);
void					move_left(t_window *w, double dist);
void					move_right(t_window *w, double dist);
void					rotate_move(t_window *w, double rotate);

bool					open_error(char *path);
bool					mem_error(TGA *tga);
bool					unsupported_error(TGA *tga);
bool					get_tga_info(char *path);
t_image					*read_tga(char *path);
void					load_paths_raw(t_window *w, char *path);

void					ft_setinrange(int *num, int min, int max);
void					print_arr(t_map *map);
void					face_animation(t_window *w);
Uint32					set_color(t_rgba rgb);
Uint32					form_color(int red, int green, int blue, int alpha);
t_rgba					inter_color(Uint32 *pixels,
						float x_diff, float y_diff, int w);
SDL_Rect				set_rect(int w, int h, int x, int y);
int						shade_color(int color, double percent);
void					draw_mask_backround(t_window *w);
void					draw_skill(t_window *w, int index);
void					draw_menu_background(t_window *w);
void					face_animation(t_window *w);
void					get_menu_offset_by_index(int index,
						int *offset_x, int *offset_y);
void					fill_ui(t_window *w);
void					re_init_riffle(t_window *w, int key);

int						get_world_side(t_window *w);
void					calc_c_height(t_window *w, int tex_num);

bool					key_action(SDL_Event *ev, int32_t
						key_code, Uint32 press);
bool					switch_key(t_window *w, char key, bool *key_tr);
bool					handle_key(t_window *w, char key, bool *key_tr);

void					scale_rect_digits(t_window *w, float scale_k);
int						get_text_height(char *path);
void					load_paths_raw(t_window *w, char *path);
t_image					*not_found_img();

#endif
