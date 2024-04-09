/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:08:04 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/09 17:01:56 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <stdbool.h>
# include <time.h>
# include <sys/time.h>
# include "../lib/libft/inc/libft.h"
# include "../lib/gnl/inc/get_next_line.h"

# define ERR_MLX_INIT				"Mlx could not be initialized"
# define ERR_IMG_CREATE				"Image could not be created"
# define NB_PARAMS_RESOLUTION		1
# define ERR_PARAMS_RESOLUTION\
	"Resolution WIDTH(int[>0]) (OPT)HEIGHT(int[>0])"
# define NB_PARAMS_ALGO				2
# define ERR_PARAMS_ALGO\
	"Algorithm SAMPLES_PER_PIXEL(int[>0]) DEPTH(int[>0])"
# define NB_PARAMS_AMBIENT			2
# define ERR_PARAMS_AMBIENT\
	"Ambient light FACTOR(double[0-1]) COLOR(vector[3X0-255])"
# define NB_PARAMS_POINT_LIGHT		3
# define ERR_PARAMS_POINT_LIGHT\
	"Point light LOCATION(vector[3Xdouble]) FACTOR(double[0-1]) \
	COLOR(vector[3Xint0-255])"
# define NB_PARAMS_CAMERA			3
# define ERR_PARAMS_CAMERA\
	"Camera LOCATION(vector[3Xdouble]) DIRECTION(3Xvector[double]) \
	HFOV(double[0-180])"
# define NB_PARAMS_POINT			2
# define NB_PARAMS_PLANE			3
# define ERR_PARAMS_PLANE\
	"Plane POINT(vector[3Xdouble]) DIR_1(vector[3Xdouble]) \
	DIR_2(vector[3Xdouble])"
# define NB_PARAMS_SPHERE			3
# define ERR_PARAMS_SPHERE\
	"Sphere CENTER(vector[3Xdouble]) DIAMETER(double[>=0]) \
	COLOR(vector[3Xint0-255])"
# define NB_PARAMS_QUAD				4
# define ERR_PARAMS_QUAD\
	"Quad CENTER(vector[3Xdouble]) VEC_1(vector[3Xdouble]) \
VEC_2(vector[3Xdouble]) COLOR(vector[3Xint0-255])"
# define NB_PARAMS_DISC				4
# define ERR_PARAMS_DISC\
	"Disc CENTER(vector[3Xdouble]) NORMAL(vector[3Xdouble]) \
DIAMETER(double[>=0]) COLOR(vector[3Xint0-255])"
# define NB_PARAMS_BOX				5
# define ERR_PARAMS_BOX\
	"Box CENTER(vector[3Xdouble]) VEC_1(vector[3Xdouble]) \
VEC_2(vector[3Xdouble]) VEC_3(vector[3Xdouble]) COLOR(vector[3Xint0-255])"
# define NB_PARAMS_CYLINDER			5
# define ERR_PARAMS_CYLINDER\
	"Cylinder CENTER(vector[3Xdouble]) GENERATOR(vector[3Xdouble]) \
DIAMETER(double[>=0]) HEIGHT(double[>=0]) COLOR(vector[3Xint0-255])"
# define NB_PARAMS_CONE				6
# define ERR_DIAS_CONE "Cone min and max diameters cannot be equal"
# define ERR_DIAS_ORDER_CONE "Cone diameters should be max followed min"
# define ERR_PARAMS_CONE\
	"Cone BASE_CENTER(vector[3Xdouble]) GENERATOR(vector[3Xdouble]) \
MAX_DIAMETER(double[>=0]) MIN_DIAMETER(double[>=0]) HEIGHT(double[>=0]) \
COLOR(vector[3Xint0-255])"
# define NB_PARAMS_DICE				5
# define ERR_PARAMS_DICE\
	"Dice BASE_CENTER(vector[3Xdouble]) DIR_FACE_1(vector[3Xdouble]) \
DIR_FACE_2(vector[3Xdouble]) SIZE(double[>=0]) COLOR(vector[3Xint0-255])"
# define NB_PARAMS_SAFE_CONE		3
# define ERR_PARAMS_SAFE_CONE\
	"Safety cone BASE_CENTER(vector[3Xdouble]) \
GENERATOR(vector[3Xdouble]) HEIGHT(double[>=0])"
# define NB_PARAMS_PENCIL			3
# define ERR_PARAMS_PENCIL\
	"Pencil BASE_CENTER(vector[3Xdouble]) GENERATOR(vector[3Xdouble]) \
HEIGHT(double[>=0])"
# define NB_PARAMS_TRANSLATION		1
# define ERR_PARAMS_TRANSLATION\
	"Translation TRANSLATION_VECTOR(vector[3Xdouble])"
# define NB_PARAMS_ROTATION			2
# define ERR_PARAMS_ROTATION\
	"Rotation ROTATION_AXIS(vector[3Xdouble]) ROTATION_ANGLE[double[DEG]]"
# define NB_PARAMS_METAL			2
# define ERR_PARAMS_METAL			"Material type Metal FUZZ(double[0-1]) \
RATIO(double[0-1])"
# define NB_PARAMS_DIELECTRIC		1
# define ERR_PARAMS_DIELECTRIC\
	"Material type Dielectric INDEX_REFRACT(double[>=0])"
# define NB_PARAMS_DIFF_LIGHT		1
# define ERR_PARAMS_DIFF_LIGHT\
	"Material type Diffuse Light FACTOR(double[0-1])"
# define NB_PARAMS_TXM				2
# define ERR_PARAMS_TXM				".xpm texture file FILENAME(string[.xpm]) \
ROTATION_ANGLE(double[DEG])"
# define NB_PARAMS_BUMP				2
# define ERR_PARAMS_BUMP				".xpm bump file FILENAME(string[.xpm]) \
ROTATION_ANGLE(double[DEG])"
# define NB_PARAMS_PAT				3
# define ERR_PARAMS_PAT\
	"Pattern TYPE(int[0: chk, 1: lines_long, 2: lines_lat, 3: sprl_2_col, \
4: sprl_grad]) RATIO([int[>0]]) ROTATION_ANGLE(double[DEG])"
# define ERR_INFO_TYPE				"Invalid information type"
# define ERR_GEOM_TYPE				"Geometry type not implemented"
# define ERR_NB_COMPS_VEC			"Vector should have 3 components"
# define ERR_NORMALIZED				"Vector should be normalized"
# define ERR_NB_COMPS_COLOR			"Color should have 3 components"
# define ERR_INVALID_COLOR_COMP\
	"Color component should be an integer in range [0-255]"
# define ERR_NUM					"Not a valid number"
# define ERR_INT					"Not a valid int number"
# define ERR_DEC					"Not a valid decimal number"
# define ERR_PAT					"Not a valid pattern number"
# define ERR_NEGATIVE_NUM			"Input should be a positive number"
# define ERR_OUT_OF_INT				"Input is out of range"
# define ERR_OUT_OF_01				"Input should be in range [0,1]"
# define ERR_OUT_OF_N1_1\
	"Vector must have its components in the range [-1,1]"
# define ERR_OUT_OF_VIEW_ANGLE\
	"Horizontal view angle should be in range [0-180]"
# define ERR_NB_PARAMS				"Wrong number of parameters for"
# define ERR_TL_PARAMS				"Less parameters than expected for"
# define ERR_TM_PARAMS				"More parameters than expected for"
# define ERR_EXTRA_INFO				"Object cannot take extra information"
# define ERR_DUPLICATE_RESOLUTION	"Resolution parameters were already set"
# define ERR_DUPLICATE_ALGO			"Algorithm parameters were already set"
# define ERR_AT_LEAST_A_OR_L		"Missing a light source (ambient or point)"
# define ERR_NO_PARAMS_AMBIENT		"Missing ambient light parameters"
# define ERR_DUPLICATE_AMBIENT		"Ambient light was already set"
# define ERR_NO_PARAMS_PT_LIGHT		"Missing point light parameters"
# define ERR_DUPLICATE_PT_LIGHT		"Point light was already set"
# define ERR_NO_PARAMS_CAMERA		"Missing camera parameters"
# define ERR_DUPLICATE_CAMERA		"Camera parameters were already set"
# define ERR_OPEN_RT_FILE			".rt file could not be open"
# define ERR_OPEN_XPM_FILE			".xpm file could not be open"
# define ERR_IS_NOT_RT_FILE			"File is not an .rt file"
# define ERR_IS_NOT_XPM_FILE		"Not a valid specification for .xpm file"
# define ERR_LOADING_XPM_TEXT		".xpm texture image could not be loaded"
# define ERR_LOADING_XPM_BUMP		".xpm bump image could not be loaded"
# define ERR_NB_ARGUMENTS\
	"Program requires 1 argument: the scene info as an .rt file"

# define PI	3.1415926535897932385
# define EPSILON 1e-8
# define IMAGE_WIDTH 500
# define ASPECT_RATIO 1.777777778
# define MAX_DEPTH 50
# define SAMPLES_PER_PIXEL 20
# define REFRESH_FREQ 20
# define NORMAL_MODE 0
# define SHADOW_BIAS 0.01
# define CLOSE_VOLUMES 1
# define MULTI_LIGHTS 1

typedef struct s_httbl	t_httbl;

typedef enum e_geom_types
{
	POINT,
	PLANE,
	QUAD,
	DISC,
	BOX,
	DICE,
	SPHERE,
	CYLINDER,
	CONE,
	SAFE_CONE,
	PENCIL,
	LEN_GEOM_TYPES
}	t_geom_types;

typedef enum e_mat_types
{
	LAMBERTIAN,
	METAL,
	DIELECTRIC,
	DIFF_LIGHT,
	LEN_MAT_TYPES
}	t_mat_types;

typedef enum e_pat_types
{
	CHECKBOARD,
	LINES_LONG,
	LINES_LAT,
	SPIRAL_2_COLORS,
	SPIRAL_GRADIENT,
	LEN_PAT_TYPES
}	t_pat_types;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_itv
{
	double	min;
	double	max;
}	t_itv;

typedef struct s_h_pol
{
	t_vec3	oc;
	double	r_sq;
	double	h_sq;
	double	a;
	double	h_b;
	double	c;
	double	root_1;
	double	root_2;
}	t_h_pol;

typedef struct s_ray
{
	t_vec3	orig;
	t_vec3	dir;
}	t_ray;

typedef struct s_point
{
	t_vec3	q;
}	t_point;

typedef struct s_plane
{
	t_vec3	q;
	t_vec3	d;
}	t_plane;

typedef struct s_quad
{
	t_vec3	ctr;
	t_vec3	u;
	t_vec3	v;
	t_vec3	nrm;
	t_vec3	q;
	t_vec3	w;
	double	d;
}	t_quad;

typedef struct s_box
{
	t_vec3	ctr;
	t_vec3	u;
	t_vec3	v;
	t_vec3	w;
}	t_box;

typedef struct s_disc
{
	t_vec3	ctr;
	t_vec3	nrm;
	double	rd;
}	t_disc;

typedef struct s_sphere
{
	t_vec3	ctr;
	double	rd;
	t_vec3	ax;
}	t_sphere;

typedef struct s_cylinder
{
	t_vec3		ctr;
	t_vec3		gen;
	double		rd;
	double		h;
	t_itv		itv_z;
}	t_cylinder;

typedef struct s_cone
{
	t_vec3		b_ctr;
	t_vec3		tip;
	t_vec3		gen;
	double		r_max;
	double		r_min;
	double		h;
	t_itv		itv_z;
}	t_cone;

typedef struct s_safe_cone
{
	t_vec3	b_ctr;
	t_vec3	gen;
	double	h;
	double	r_max;
	double	r_min;
	double	r_step;
}	t_safe_cone;

typedef struct s_dice
{
	t_vec3		ctr;
	t_vec3		u;
	t_vec3		v;
	t_vec3		w;
	double		h;
}	t_dice;

typedef struct s_dice_dots
{
	int		code;
	t_vec3	u;
	t_vec3	v;
}	t_dice_dots;

typedef struct s_pencil
{
	t_vec3	b_ctr;
	t_vec3	gen;
	double	l;
	double	w;
}	t_pencil;

typedef struct s_lamber
{
	t_vec3	color;
}	t_lamber;

typedef struct s_metal
{
	t_vec3	color;
	double	fuzz;
	double	ratio;
}	t_metal;

typedef struct s_dielec
{
	t_vec3	color;
	double	idx_refract;
}	t_dielec;

typedef struct s_diff_light
{
	t_vec3	color;
	double	ratio;
}	t_diff_light;

typedef struct s_image
{
	void	*ptr;
	char	*addr;
	int		w;
	int		h;
	int		bpp;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_texture
{
	bool	is_present;
	char	*path;
	t_image	img;
	double	rot_an;
}	t_texture;

typedef struct s_pattern
{
	bool		is_present;
	t_pat_types	type;
	int			ratio;
	double		rot_an;
}	t_pattern;

typedef struct s_bump
{
	bool	is_present;
	char	*path;
	t_image	img;
	double	rot_an;
}	t_bump;

typedef struct s_material
{
	t_mat_types			type;
	t_vec3				color;
	double				light_conc;
	double				k_d;
	double				k_s;
	t_texture			txm;
	t_bump				bmp;
	t_pattern			pat;
	double				rot_an;
	union
	{
		t_lamber			lamber;
		t_metal				metal;
		t_dielec			dielec;
		t_diff_light		diff_light;
	};
}	t_material;

typedef struct s_trsf
{
	t_vec3	tra;
	t_vec3	rot_ax;
	double	rot_an;
}	t_trsf;

typedef struct s_geometry
{
	t_geom_types	type;
	t_trsf			trsf;
	t_trsf			trsf_i;
	union
	{
		t_point		pnt;
		t_plane		pln;
		t_quad		qud;
		t_disc		dsc;
		t_box		box;
		t_sphere	sph;
		t_cylinder	cyl;
		t_cone		con;
		t_safe_cone	sfc;
		t_dice		dce;
		t_pencil	pnc;
	};
}	t_geometry;

typedef struct s_httbl
{
	t_geometry	*geom;
	t_material	*mat;
	t_httbl		*next;
}	t_httbl;

typedef struct s_hit_rec
{
	t_httbl			*httbl;
	t_vec3			p;
	t_vec3			uv;
	t_vec3			uv_cyl;
	t_vec3			nrm;
	double			t;
	bool			front_face;
	t_geom_types	geom_type;
	t_mat_types		mat_type;
	double			mat_rot_an;
	t_vec3			att;
	t_ray			sctt;
	t_vec3			col;
	union
	{
		t_lamber		lamber;
		t_metal			metal;
		t_dielec		dielec;
		t_diff_light	diff_light;
	};
}	t_hit_rec;

typedef struct s_camera
{
	bool	set;
	t_vec3	ctr;
	t_vec3	dir;
	double	vfov;
	double	hfov;
	t_vec3	u;
	t_vec3	v;
	t_vec3	w;
	t_vec3	look_from;
	t_vec3	look_at;
	t_vec3	vup;
	double	defocus_angle;
	double	focus_dist;
	t_vec3	defocus_disk_u;
	t_vec3	defocus_disk_v;
	t_vec3	pixel00_loc;
	t_vec3	pixel_delta_u;
	t_vec3	pixel_delta_v;
	t_vec3	offset;
	double	viewport_h;
	double	viewport_w;
	t_vec3	viewport_u;
	t_vec3	viewport_v;
	t_vec3	viewport_upper_left;
	double	defocus_radius;
	bool	sampling;
}	t_camera;

typedef struct s_world
{
	t_httbl		*httbl_head;
	t_httbl		*httbl;
	size_t		size;
}	t_world;

typedef struct s_mlx
{
	void	*ptr;
	void	*win_ptr;
}	t_mlx;

typedef struct s_ambient
{
	bool	set;
	double	ratio;
	t_vec3	color;
}	t_ambient;

typedef struct s_light
{
	t_vec3	pos;
	double	ratio;
	t_vec3	color;
}	t_light;

typedef struct s_temp
{
	int				expect;
	int				count;
	int				avail;
	int				end;
	int				option;
	bool			extra;
	char			**params;
	t_geometry		*geom;
	t_material		*mat;
	t_ray			ray;
	int				type;
	t_vec3			color;
	t_light			light;
	int				ret;
	t_trsf			trsf;
	bool			has_txm;
	char			*txm_path;
	double			txm_rot_an;
	bool			has_bmp;
	char			*bmp_path;
	double			bmp_rot_an;
	bool			has_pat;
	int				pat;
	int				pat_ratio;
	double			pat_rot_an;
	bool			shadow_comp;

}	t_temp;

typedef struct s_rt
{
	t_ambient		ambient;
	double			aspect_ratio;
	bool			set_resolution;
	bool			set_algo;
	bool			set_point_light;
	t_image			img;
	t_mlx			mlx;
	t_camera		cam;
	t_world			world;
	int				spp;
	int				max_depth;
	int				estim_sec;
	struct timeval	begin_time;
	t_httbl			*cur_httbl;
	t_temp			tp;
}	t_rt;

//parsing_file.c
bool			is_rt_file(char *file_path);
bool			is_xpm_file(char *file_path);
int				read_file(t_rt *rt, int fd);
char			*clean_line(char *line);
bool			is_incomplete_file(t_rt *rt);
int				open_and_read_file(t_rt *rt, char *file_path);

//parsing_general.c
int				parse_line(t_rt *rt, char *line);
void			parse_line_cont(t_rt *rt);
int				parse_httbl(t_rt *rt, t_geom_types geom_type, int nb_params);
void			parse_httbl_cont(t_rt *rt, t_geom_types geom_type);

//parsing_types_1.c
int				parse_dbl(char *str, double *num);
int				parse_dbl_pos(char *str, double *num);
int				parse_int_pos(char *str, double *num);
int				parse_dbl_01(char *str, double *num);
int				parse_dbl_n1_1(char *str, double *num);
int				parse_dbl_vec3_n1_1(char *str, t_vec3 *vec);
int				parse_dbl_vec3_n1_1_norm(char *str, t_vec3 *vec);
int				parse_dbl_0180(char	*str, double *num);

//parsing_types_2.c
int				parse_dbl_vec3(char *str, t_vec3 *vec);
int				check_range_vec_n1_1(t_vec3 *vec);
int				parse_color(char *str, t_vec3 *color);
int				parse_pat(char *str, int *num);
//char	*get_info_type(char *line);

//parsing_geom.c
int				parse_sphere(t_rt *rt);
int				parse_plane(t_rt *rt);
int				parse_cylinder(t_rt *rt);
int				parse_cone(t_rt *rt);
int				parse_quad(t_rt *rt);
int				parse_disc(t_rt *rt);
int				parse_box(t_rt *rt);
int				parse_dce(t_rt *rt);
int				parse_safe_cone(t_rt *rt);
int				parse_pencil(t_rt *rt);

//parsing_env.c
int				parse_resolution_params(t_rt *rt);
int				parse_algo_params(t_rt *rt);
int				parse_ambient_params(t_rt *rt);
int				parse_light_params(t_rt *rt);
int				parse_camera_params(t_rt *rt);

//parsing_extra.c
int				parse_extra(t_rt *rt);

//parsing_transformation.c
int				parse_translation(t_rt *rt);
int				parse_rotation(t_rt *rt);

//parsing_material.c
int				parse_dielectric(t_rt *rt);
int				parse_metal(t_rt *rt);
int				parse_diff_light(t_rt *rt);

//parsing_txm_pat.c
int				parse_texture(t_rt *rt);
int				parse_bump(t_rt *rt);
int				parse_pattern(t_rt *rt);

//main.c
int				mini_rt(t_rt *rt);
int				ft_exit(t_rt *rt);

//test.c
int				test_vec3_operations(void);

//rt_mlx.c
int				on_key_press(int keycode, t_mlx *mlx_data);
int				mlx_initialize(t_mlx *mlx);

//rt_image.c
int				image_create(t_mlx *mlx, t_image *img, int w, int h);
int				image_update(t_mlx *mlx, t_image img);
int				my_mlx_pixel_put(t_image img, int x, int y, int color);
t_vec3			get_pixel_color(t_image *img, t_vec3 uv);
double			get_bump_gradient(t_image *img, t_vec3 uv, int dir, \
	double coeff);

//rt_bumps.c
void			modify_bump_normal(t_vec3 *nrm, t_vec3 ref, double grad_u, \
	double grad_v);
void			alter_normal_with_bump(t_rt *rt, t_hit_rec *rec);

//rt_ray_color.c
t_vec3			ray_color(t_rt *rt, int depth, t_ray r);

//rt_lights.c
t_vec3			point_lights(t_rt *rt, t_hit_rec *rec);

//rt_ray_compute.c
t_vec3			reflect(t_vec3 v, t_vec3 n);
t_vec3			refract(t_vec3 r_in, t_vec3 n, double eta_in_over_out);
double			reflectance(double cosine, double ref_idx);
t_ray			get_ray(t_camera *cam, int i, int j);

//rt_camera.c
void			cam_initialize(t_rt *rt);
void			cam_viewport_compute(t_rt *rt);

//rt_render.cj
int				render(t_rt *rt);
int				render_innerloop(t_rt *rt, int j);
void			time_estimation(t_rt *rt);
void			progress_compute(t_rt *rt, int j);

//rt_hit_record.c
void			set_face_nrm(t_ray r, t_vec3 out_nrm, t_hit_rec *rec);
void			set_rec_mat(t_rt *rt, t_hit_rec *rec);
void			set_rec_color(t_rt *rt, t_hit_rec *rec);
void			set_rec_mat_color(t_hit_rec *rec);

//rt_initialize.c
int				rt_initialize(t_rt *rt);

//rt_world.c
int				world_populate(t_world *world);
bool			check_hit_httbl(t_rt *rt, t_ray *r, t_itv *tray, \
	t_hit_rec *rec);
bool			world_hit(t_rt *rt, t_ray r, t_itv tray, t_hit_rec *rec);

//geom_special_build.c
void			add_box_quads(t_world *world, t_box *box, t_material *mat);
void			add_dice_dots(t_world *world, t_box *box);
void			add_dice_face(t_world *world, t_box *box, \
	t_dice_dots dice_dots);
void			add_cyl_discs(t_world *world, t_geometry *geom, \
	t_material *mat);
void			add_con_discs(t_world *world, t_geometry *geom, \
	t_material *mat);
void			create_safe_cone(t_world *world, t_safe_cone *sfc);
void			create_safe_cone_base(t_world *world, t_safe_cone *sfc, \
	t_vec3 rot_ax, double rot_an);

//geom_object_transform.c
void			geom_translate(t_rt *rt);
void			geom_rotate(t_rt *rt);
void			cylinder_rotate(t_rt *rt);
void			cone_rotate(t_rt *rt);
void			sphere_rotate(t_rt *rt);

//httbl_create.c
t_httbl			*new_httbl(t_geometry *geom, t_material *mat);
void			httbl_addback(t_world *world, t_httbl *new_httbl);
void			httbl_record(t_world *world, t_geometry *geom, t_material *mat);
void			httbl_create(t_rt *rt);

//httbl_point.c
t_point			point(t_vec3 point);
t_geometry		*geom_point(t_point pnt);
bool			hit_pt_geom(t_rt *rt, t_ray r, t_itv tray, t_hit_rec *rec);

//httbl_plane.c
t_plane			plane(t_vec3 point, t_vec3 dir);
t_geometry		*geom_plane(t_plane pln);
bool			hit_plane(t_rt *rt, t_ray r, t_itv tray, t_hit_rec *rec);

//httbl_quad.c
t_quad			quad(t_vec3 point, t_vec3 vec1, t_vec3 vec2);
t_geometry		*geom_quad(t_quad qud);
bool			hit_quad(t_rt *rt, t_ray r, t_itv tray, t_hit_rec *rec);
bool			is_interior(double a, double b);

//httbl_box.c
t_box			box(t_vec3 ctr, t_vec3 u, t_vec3 v, t_vec3 w);
t_geometry		*geom_box(t_box box);

//httbl_disc.c
t_disc			disc(t_vec3 ctr, t_vec3 nrm, double rd);
t_geometry		*geom_disc(t_disc dsc);
bool			hit_disc(t_rt *rt, t_ray r, t_itv tray, t_hit_rec *rec);

//httbl_sphere.c
t_sphere		sphere(t_vec3 ctr, double r);
t_geometry		*geom_sphere(t_sphere sph);
void			reverse_geom_sphere(t_geometry *geom);
bool			hit_sphere(t_rt *rt, t_ray r, t_itv tray, t_hit_rec *rec);

//httbl_cylinder.c
t_cylinder		cylinder(t_vec3 b_ctr, t_vec3 gen, double rd, double h);
t_geometry		*geom_cylinder(t_cylinder cyl);
void			reverse_geom_cylinder(t_geometry *geom);
bool			hit_cylinder_finite(t_rt *rt, t_ray r, t_itv tray, \
	t_hit_rec *rec);
void			set_poly_cylinder(t_rt *rt, t_ray r, t_h_pol *h_pol);

//httbl_cone.c
t_cone			cone(t_vec3 b_ctr, t_vec3 gen, double r_min, double r_max);
t_geometry		*geom_cone(t_cone con);
void			reverse_geom_cone(t_geometry *geom);
bool			hit_cone_finite(t_rt *rt, t_ray r, t_itv tray, t_hit_rec *rec);
void			set_poly_cone(t_rt *rt, t_ray r, t_h_pol *h_pol);

//httbl_dice.c
t_dice			dice(t_vec3 ctr, t_vec3 dir_1, t_vec3 dir_2, double size);
t_dice_dots		dice_dots(t_vec3 u, t_vec3 v, int code);
t_geometry		*geom_dce(t_box box);

//httbl_safe_cone.c
t_safe_cone		safe_cone(t_vec3 b_ctr, t_vec3 gen, double h);
t_geometry		*geom_safe_cone(t_safe_cone safe_cone);

//httbl_pencil.c
t_pencil		pencil(t_vec3 b_ctr, t_vec3 gen, double l);
t_geometry		*geom_pencil(t_pencil pnc);

//utils_math_1.c
double			ft_min(double n1, double n2);
double			ft_max(double n1, double n2);
double			ft_min3(double n1, double n2, double n3);
double			ft_max3(double n1, double n2, double n3);

//utils_math_2.c
double			ft_abs(double a);
double			ft_modulo(double x, double y);
int				next_modulo(int x, int mod);

//utils_convert_1.c
double			deg2rad(double deg);
double			rad2deg(double rad);
t_vec3			deg2rad_vec3(t_vec3 vec);
double			lin2gam_double(double linear);

//utils_convert_2.c
double			str2dbl(char *str);
int				dec2bin(int dec, int bin, int pos);

//utils_numbers_1.c
int				is_dec(char *str);
int				is_ulong(char *str);
int				is_long(char *str);
int				is_valid_color_comp(char *str);

//utils_numbers_2.c
int				is_in_int_range(char *str);
int				is_in_range01(double num);
int				is_in_range_n1_1(double num);
int				is_in_range0180(double num);

//utils_array.c
double			array_size(char **params);

//utils_random_1.c
t_vec3			get_rdm_dev(t_camera *cam);
double			rdm_dbl(void);
double			rdm_dbl_itv(double min, double max);
t_vec3			rdm_vec3_itv(double min, double max);
t_vec3			rdm_in_unit_sphere(void);

//utils_random_2.c
t_vec3			rdm_unit_vector(void);
t_vec3			rdm_in_same_hemisphere(t_vec3 nrm);
t_vec3			rdm_in_unit_disk(void);
t_vec3			pixel_sample_square(t_camera *cam);
t_vec3			defocus_disk_sample(t_camera *cam);

//utils_vec3_1.c
t_vec3			new_vec3(double x, double y, double z);
t_vec3			vec3_add2(t_vec3 v1, t_vec3 v2);
t_vec3			vec3_add3(t_vec3 v1, t_vec3 v2, t_vec3 v3);
t_vec3			vec3_sub2(t_vec3 v1, t_vec3 v2);
t_vec3			vec3_prd(t_vec3 v1, t_vec3 v2);

//utils_vec3_2.c
int				vec3_update(t_vec3 *vec, double x, double y, double z);
t_vec3			vec3_id(double t);
t_vec3			vec3_scale(double t, t_vec3 v);
double			vec3_dot(t_vec3 v1, t_vec3 v2);
t_vec3			vec3_cross(t_vec3 v1, t_vec3 v2);

//utils_vec3_3.c
t_vec3			vec3_unit(t_vec3 v);
double			vec3_len(t_vec3 v);
double			vec3_len_sq(t_vec3 v);
double			vec3_index(t_vec3 v, int i);
bool			vec3_is_nz(t_vec3 vec);

//utils_vec3_4.c
t_vec3			vec3_cos(t_vec3 theta);
t_vec3			vec3_sin(t_vec3 theta);
t_vec3			vec3_cpy(t_vec3 vec);

//utils_quadratic_solve.c
bool			search_poly_root(t_h_pol *h_pol, t_itv tray, double *root);
bool			search_poly_root_2(t_h_pol *h_pol, t_itv tray, double *root_1, \
	double *root_2);
bool			solve_h_pol(t_h_pol *h_pol);

//utils_memory.c
void			free_httbls(t_rt *rt, t_world *world);
void			free_split_vec(char **vec);
void			free_tp(t_temp tp);

//utils_parsing.c
int				check_nb_params(t_rt *rt, int expect, char *err_msg);
void			get_end_idx(t_rt *rt);

//utils_ray.c
t_vec3			hit_pt(t_ray r, double t);
t_ray			new_ray(t_vec3 orig, t_vec3 dir);

//utils_colors.c
t_vec3			vec2rgb(t_vec3 col);
t_vec3			vec2hsv(t_vec3 col);
t_vec3			rgb2vec(t_vec3 col);
t_vec3			lin2gam_vec(t_vec3 lin);
double			rgb2val(t_vec3 col);
t_vec3			val2rgb(int rgb);
t_vec3			compl_color(t_vec3 col);
t_vec3			hsv2rgb(t_vec3 hsv);
t_vec3			mix_colors(t_vec3 col_1, t_vec3 col_2, double a);
t_vec3			limit_color_vec(t_vec3 col);

//utils_debug.c
void			debug(char *msg);

//utils_interval.c
t_itv			itv(double min, double max);
t_itv			itv_span(double min, double max, double span);
bool			cts(t_itv itv, double x);
bool			srs(t_itv itv, double x);
int				sts(t_itv itv, double x);
double			clamp(t_itv itv, double x);

//mat_lambertian.c
t_lamber		lamber(t_vec3 color);
t_material		*mat_lamber(t_lamber lamber);

//mat_metal.c
t_metal			metal(t_vec3 color, double fuzz, double ratio);
t_material		*mat_metal(t_metal metal);

//mat_dielectric.c
t_dielec		dielec(t_vec3 color, double ir);
t_material		*mat_dielec(t_dielec dielec);

//mat_diff_light.c
t_diff_light	diff_light(double ratio, t_vec3 color);
t_material		*mat_diff_light(t_diff_light diff_light);

//mat_create.c
void			mat_finalize(t_rt *rt);
void 			mat_rot_choice(t_rt *rt);
t_material		*duplicate_mat(t_material *src);
int				handle_textures(t_rt *rt);
int				handle_bumps(t_rt *rt);

//mat_scatter.c
bool			lambertian_scatter(t_hit_rec *rec);
bool			metal_scatter(t_ray r_in, t_hit_rec *rec);
bool			dielectric_scatter(t_ray r_in, t_hit_rec *rec);

//lights.c
bool			diffuse_light(t_vec3 *attenuation, t_ray *scattered);

//geom_basic_translate.c
t_vec3			tra_v(t_vec3 v, t_vec3 tra);
t_ray			tra_r(t_ray r, t_vec3 tra);

//geom_basic_rotate.c
t_vec3			rot_v(t_vec3 u, t_vec3 v, double a);
void			rot_1v(t_trsf trsf, t_vec3 *u1);
void			rot_2v(t_trsf trsf, t_vec3 *u1, t_vec3 *u2);
void			rot_3v(t_trsf trsf, t_vec3 *u1, t_vec3 *u2, t_vec3 *u3);
t_ray			rot_r(t_ray r, t_vec3 v, double a);

//geom_map_coord_1.c
void			set_map_coord_pln(t_hit_rec *rec);
void			set_map_coord_qud(t_hit_rec *rec);
void			set_map_coord_dsc(t_hit_rec *rec);
void			set_map_coord_sph(t_hit_rec *rec, t_vec3 ctr);
void			set_map_coord_cyl(t_hit_rec *rec, t_vec3 ctr, double h);

//geom_map_coord_2.c
void			set_map_coord_con(t_hit_rec *rec, t_vec3 ctr, double h);

//display_errors.c
bool			display_error(char *error);
bool			display_error_plus(char *error, char *msg);
bool			display_warning(char *warning);
bool			display_warning_plus(char *warning, char *msg);
char			*get_error_message(char *geom);

//display_geometry.c
void			display_geometry(t_geometry *geom);
void			display_sphere(t_sphere *sph);
void			display_cylinder(t_cylinder *cyl);
void			display_disc(t_disc *dsc);
void			display_quad(t_quad *qud);

//display_material.c
void			display_material(t_material *mat);
void			display_lamber(t_lamber *lamber);
void			display_metal(t_metal *metal);

//display_simple.c
void			display_vec3(t_vec3 v);
void			display_color(t_vec3 pixel_color);

//display_world.c
void			display_world(t_world *world);
void			display_httbl(t_httbl *httbl, int id);

//scene_random_logo42_create.c
bool			is_inside(double x, double r, double min, double max);
bool			is_in_logo42(t_sphere sph, t_vec3 p, double h);
void			rdm_logo42_sphere(t_world *world, double h, int nb_spheres);
bool			is_overlaying(t_httbl *httbl, t_sphere sph);
bool			is_overlaying_xz(t_httbl *httbl, t_sphere sph);

//rt_patterns.c
bool			checkboard_zone(t_vec3 uv, double scale);
bool			long_zone(t_vec3 uv, double scale);
bool			lat_zone(t_vec3 uv, double scale);
bool			spiral_zone(t_vec3 uv, double scale);
t_vec3			pattern_color(bool zone_pattern, t_vec3 color_even, \
	t_vec3 color_odd);
t_vec3			checkboard_pattern(t_vec3 uv, double scale, t_vec3 color_even, \
	t_vec3 color_odd);
t_vec3			spiral_pattern(t_vec3 uv, double scale, t_vec3 color_even, \
	t_vec3 color_odd);
t_vec3			spiral_colors(t_vec3 uv, double scale);
t_vec3			gradient_color_spiral(t_vec3 uv, double scale, t_vec3 col);

#endif // MINI_RT_H
