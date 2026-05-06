/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:46:30 by driemers          #+#    #+#             */
/*   Updated: 2025/05/05 13:18:50 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H

# define MINIRT_H

# include <stdbool.h>

# define READ_SIZE 10

# define KEY_ESC 65307
# define WIN_EXIT 17
# define ELEMENTS 6
# define M_PI 3.1415927f
# define ELEMENT_IDS "ACLspc"
# define COLOUR_MAX 255
# define COLOUR_MAX_F 255.0f
# define EPSILON 1e-6f

# define CYLINDER 1
# define PLANE 2
# define SPHERE 3
# define CY_CAP 1
# define CY_SIDE 2

# define ERR_INCORRECT_ARG "Minirt needs a .rt file as argument!\n"
# define ERR_NO_SUCH_FILE "Input file not found!\n"
# define ERR_MEM_FAIL "Failed to allocate enoug memory!\n"
# define ERR_INVALID_CHAR "Invalid character was found in input file!\n"
# define ERR_FLOAT_OUTSIDE_BOUNDS "Float is outside of 32 bit range!\n"
# define ERR_FLOAT_N_OUTSIDE_BOUNDS "Float is outside of normilized range!\n"
# define ERR_CHAR_OUT_OF_BOUNDS "Int is out of bounds for eightbit interger!\n"
# define ERR_VALUE_NEGATIVE "This value can not be nagtive!\n"
# define ERR_SETUP_CANNED "Something went wrong, setup canceled!\n"

//settings
# define PRINT_DATA false
# define PRINT_PROGRESS false
# define DEBUG false
# define MUTIBLE_LIGHTS false
# define BRIGHTNESS 150.0f
# define ALLOW_BLACK false
# define LINEAR_COLOUR false
# define SCREEN_X 6
# define SCREEN_Y 4
# define SCREEN_SCALE 400

typedef struct s_colour
{
	int	r;
	int	g;
	int	b;
}	t_colour;

typedef struct s_colour_f
{
	float	r;
	float	g;
	float	b;
}	t_colour_f;

typedef struct s_uv
{
	float	u;
	float	v;
}	t_uv;

typedef struct s_float_three
{
	float	x;
	float	y;
	float	z;
}	t_float_three;

typedef struct s_ambient_light
{
	float		intensity;
	t_colour	col;
}	t_ambient_light;

typedef struct s_camera
{
	t_float_three	pos;
	t_float_three	rot;
	float			fov;
}	t_camera;

typedef struct s_base_camera
{
	t_float_three	forward;
	t_float_three	right;
	t_float_three	up;
}	t_base_camera;

typedef struct s_ray
{
	t_float_three	origin;
	t_float_three	direction;
}	t_ray;

typedef struct s_light
{
	t_float_three	pos;
	float			intensity;
	t_colour		col;
	struct s_light	*next;
}	t_light;

typedef struct s_sphere
{
	t_float_three	pos;
	float			diameter;
	t_colour		col;
	struct s_sphere	*next;
}	t_sphere;

typedef struct s_plane
{
	t_float_three	pos;
	t_float_three	normal;
	t_colour		col;
	struct s_plane	*next;
}	t_plane;

typedef struct s_cylinder
{
	t_float_three		pos;
	t_float_three		rot;
	float				diameter;
	float				height;
	t_colour			col;
	struct s_cylinder	*next;
}	t_cylinder;

// lights, spheres, planes and cylinders are setup as linked lists
typedef struct s_scene
{
	t_ambient_light	ambient_lighting;
	t_camera		camera;
	t_light			*lights;
	t_sphere		*spheres;
	t_plane			*planes;
	t_cylinder		*cylinders;
}	t_scene;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_win
{
	void		*mlx;
	void		*win;
	t_img		img;
	int			res_x;
	int			res_y;
	t_scene		*scene;
}				t_win;

typedef struct s_obj_intersection
{
	t_float_three	point;
	t_float_three	normal_to_object;
	t_colour		color;
	float			dist;
	float			min;
	bool			hit;
	int				object_type;
	int				cy_hit_type;
}	t_obj_intersection;

typedef struct s_obj_in_shadow
{
	t_float_three	light_source;
	t_ray			ray_shadow;
	t_sphere		*sp;
	t_plane			*pl;
	t_cylinder		*cy;
	float			a;
	int				x;
}	t_obj_in_shadow;

typedef struct s_cy_intersection
{
	t_float_three	c;
	t_float_three	p;
	float			dist_cap;
	float			dist_min;
	bool			intersection;
}	t_cy_intersection;

//render stuff
void			put_pixel(t_img *data, int x, int y, int colour);
void			push_frame(t_win *win);
void			init_frame(t_win *win);
//

//file stuff
char			*read_file(int fd);
//

//parce_utils
t_colour		parce_colour(char **str, int *fail);
t_float_three	parce_float_three(char **str, int *fail, int normalize);
float			parce_float(char **str, int *fail, int normalize);
int				find_str(char **str, int *fail, char *find_str);
int				myenum(char c, char *my_enum);
char			*add_char(char c, char *str);
void			clear_str(char *str, int size);
//

//parce_objects
t_ambient_light	parce_ambient_light(char **str, int *fail);
t_camera		parce_cam(char **str, int *fail);
t_light			*parce_light(char **str, int *fail);
t_sphere		*parce_sphere(char **str, int *fail);
t_plane			*parce_plane(char **str, int *fail);
t_cylinder		*parce_cylinder(char **str, int *fail);
//

//atof
float			rt_atof(char *str, int n, int *fail);
//

//mem_ctrl
int				proper_free(void *ptr);
void			free_scene(t_scene *scene);
//

//error handeling
int				print_warn(char *str);
int				print_err(char *str);
int				print_err_fail(char *str, int *fail);
void			*print_err_null(char *str);
void			*print_err_fail_null(char *str, int *fail);
//

//Vector maths
t_float_three	vec_store(float x, float y, float z);
t_float_three	vec_mul(t_float_three a, float t);
t_float_three	vec_add(t_float_three a, t_float_three b);
t_float_three	vec_sub(t_float_three a, t_float_three b);
float			vec_dot(t_float_three a, t_float_three b);
t_float_three	vec_cross(t_float_three a, t_float_three b);
t_float_three	vec_normalize(t_float_three a);
t_float_three	vec_rotate(t_float_three v, t_float_three k, float angle);
float			vec_length(t_float_three a);
//

//Color_maths
t_colour		col_store(int x, int y, int z);
t_colour		col_add(t_colour a, t_colour b);
t_colour		col_sub(t_colour a, t_colour b);
t_colour		col_mul(t_colour a, float t);
float			col_dot(t_colour a, t_colour b);
t_colour		col_cross(t_colour a, t_colour b);
t_colour		col_normalize(t_colour a);
t_colour		col_clamp(t_colour col, float min, float max);
t_colour_f		colf_store(float x, float y, float z);
t_colour_f		colf_add(t_colour_f a, t_colour_f b);
t_colour_f		colf_sub(t_colour_f a, t_colour_f b);
t_colour_f		colf_mul(t_colour_f a, float t);
t_colour		colf_to_col(t_colour_f col);
t_colour_f		col_to_colf(t_colour col);
t_colour_f		colf_pretty(t_colour_f col);
//

//Object_interaction
bool			cylinder_intersection(t_ray ray, float *dist, \
					t_cylinder *cy, int *cy_hit_type);
t_colour		get_object_intersection(t_ray ray, t_win *win);
void			get_plane_intersection(t_obj_intersection *obj, t_ray ray, \
					t_win *win, t_plane *pl_head);
void			get_cylinder_intersection(t_obj_intersection *o, t_ray ray, \
					t_win *win, t_cylinder *cy);
void			get_sphere_intersection(t_obj_intersection *obj, t_ray ray, \
					t_win *win, t_sphere *sp_head);
t_colour		compute_color(	t_float_three point, t_colour color, \
					t_win *win, t_float_three normal_to_object);
t_colour_f		get_diffused_colour(t_float_three point, t_win *win, \
					t_float_three normal_to_object);
t_colour_f		add_light(t_float_three point, t_win *win, \
					t_float_three normal_to_object, t_light *light);
bool			object_in_shadow(t_float_three point, t_win *win, float dist, \
					t_light *light);
void			init_obj_in_shadow_struct(t_obj_in_shadow *s, \
					t_float_three point, t_win *win, t_light *light);
bool			plane_intersection(t_ray ray, float *dist, t_plane *plane);
bool			sphere_intersection(t_ray ray, float *dist, t_sphere *sp, \
					float d1);
bool			object_in_shadow(t_float_three point, t_win *win,
					float dist_to_light, t_light *light);
t_colour		get_object_intersection(t_ray ray, t_win *win);
t_colour		compute_color(t_float_three point, t_colour color, t_win *win, \
					t_float_three normal_to_object);
float			get_cap_dist(bool intersection, float dist_min);
t_float_three	perpendicular_vector(t_float_three v);
void			get_cap_cy_dist(t_ray ray, t_cy_intersection *c, \
					t_cylinder *cy);
float			solve_quad(float a, float b, float c);
void			normalize_vectors(t_win	*win);

//

//Render
t_base_camera	build_base_camera(t_win *win, t_scene *scene);
t_uv			get_uv(int x, int y, t_win *win, float fov);
unsigned int	get_color(t_base_camera base, t_win *win, int x, int y);
int				render(t_win *win);
//

#endif
