/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:08:04 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/22 06:06:28 by mbourgeo         ###   ########.fr       */
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
# include "../lib/libft/inc/libft.h"
# include "../lib/gnl/inc/get_next_line.h"

# define	NB_PARAMS_RESOLUTION		3
# define	NB_PARAMS_AMBIENT_LIGHT		3
# define	NB_PARAMS_LIGHT				4
# define	NB_PARAMS_CAMERA			4
# define	NB_PARAMS_POINT				3
# define	NB_PARAMS_PLANE				4
# define	NB_PARAMS_SPHERE			4
# define	NB_PARAMS_QUAD				5
# define	NB_PARAMS_DISC				5
# define	NB_PARAMS_BOX				4
# define	NB_PARAMS_CYLINDER			6
# define	NB_PARAMS_CONE				7
# define	NB_PARAMS_DIE				4
# define	NB_PARAMS_SAF_CONE		4
# define	ERR_INFO_TYPE				"Invalid information type"
# define	ERR_NB_COMPS_VEC			"Vector should have 3 components"
# define	ERR_NB_COMPS_COLOR			"Color should have 3 components"
# define	ERR_INVALID_COLOR_COMP		"Color component should be an integer in range [0-255]"
# define	ERR_NUM						"Not a valid number"
# define	ERR_DEC						"Not a valid decimal number"
# define	ERR_OUT_OF_INT				"Input is out of range"
# define	ERR_OUT_OF_RATIO			"Ratio should be in range [0.0-1.0]"
# define	ERR_OUT_OF_VIEW_ANGLE		"Horizontral view angle should be in range [0-180]"
# define	ERR_NB_PARAMS_RESOLUTION	"Wrong number of resolution parameters in scene file"
# define	ERR_AT_LEAST_A_OR_L			"Missing a light source (ambient or punctual) in scene file"
# define	ERR_NO_PARAMS_AMBIENT		"Missing ambient light parameters in scene file"
# define	ERR_NB_PARAMS_AMBIENT		"Wrong number of ambient light parameters in scene file"
# define	ERR_NO_PARAMS_LIGHT			"Missing light parameters in scene file"
# define	ERR_NB_PARAMS_LIGHT			"Wrong number light parameters in scene file"
# define	ERR_NO_PARAMS_CAMERA		"Missing camera parameters in scene file"
# define	ERR_NB_PARAMS_CAMERA		"Wrong number of camera parameters in scene file"
# define	ERR_NB_PARAMS_GEOM			"Wrong number of parameters for geometry element in scene file"
# define	ERR_OPEN_FILE				"File could not be open"
# define	ERR_IS_NOT_RT_FILE			"File is not an .rt file"
# define	ERR_NB_ARGUMENTS			"Program requires 1 argument: the scene info as an .rt file"

# define	PI	3.1415926535897932385
// Aspect ratio : 16/9
# define	ASPECT_RATIO 1.777777778
# define	EPSILON 1e-8
# define	IMAGE_WIDTH 500
# define	MAX_DEPTH 40

typedef struct s_httbl	t_httbl;

typedef enum	e_geom_types {
	POINT,
	PLANE,
	QUAD,
	DISC,
	BOX,
	DIE,
	SPHERE,
	CYLINDER,
	CONE,
	SAF_CONE,
	LEN_GEOM_TYPES
}	t_geom_types;

typedef enum	e_mat_types {
	LAMBERTIAN,
	METAL,
	DIELECTRIC,
	DIFF_LIGHT,
	LEN_MAT_TYPES
}	t_mat_types;

typedef struct	s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct	s_interval
{
	double	min;
	double	max;
}	t_interval;

typedef struct	s_half_poly
{
	double	a;
	double	half_b;
	double	c;
	double	root_1;
	double	root_2;
}	t_half_poly;

typedef struct	s_ray
{
	t_vec3	orig;
	t_vec3	dir;
}	t_ray;

//typedef struct	s_color
//{
//	double	val;
//	t_vec3	vec;
//	double	rgb[4];
//	double	thsv[4];
//}	t_color;

//typedef struct	s_rgb
//{
//	double	t;
//	double	r;
//	double	g;
//	double	b;
//}	t_rgb;

typedef struct	s_point
{
	t_vec3	q;
}	t_point;

typedef struct	s_plane
{
	t_vec3	q;
	t_vec3	d;
	//t_vec3	u;
	//t_vec3	v;
}	t_plane;

typedef struct	s_quad
{
	t_vec3	q;
	t_vec3	u;
	t_vec3	v;
}	t_quad;

typedef struct	s_box
{
	t_vec3	a;
	t_vec3	b;
}	t_box;

typedef struct	s_disc
{
	t_vec3	center;
	t_vec3	normal;
	double	radius;
}	t_disc;

typedef struct	s_sphere
{
	t_vec3	center;
	double	radius;
}	t_sphere;

typedef struct	s_cylinder
{
	t_vec3		base_center;
	t_vec3		generator;
	double		radius;
	double		height;
	t_interval	interval_z;
}	t_cylinder;

typedef struct	s_cone
{
	t_vec3		base_center;
	t_vec3		tip;
	t_vec3		generator;
	double		radius_min;
	double		radius_max;
	double		height;
	t_interval	interval_z;
}	t_cone;

typedef struct	s_lamber
{
	t_vec3	color;
}	t_lamber;

typedef struct	s_metal
{
	t_vec3	color;
	double	fuzz;
}	t_metal;

typedef struct	s_dielec
{
	t_vec3	color;
	double	idx_refract;
}	t_dielec;

typedef struct	s_diff_light
{
	t_vec3	color;
	double	ratio;
}	t_diff_light;

typedef struct	s_material
{
	t_mat_types			type;
	union
	{
		t_lamber		lamber;
		t_metal			metal;
		t_dielec		dielec;
		t_diff_light	diff_light;
	};
} t_material;

typedef struct	s_geometry
{
	t_geom_types	type;
	t_vec3			trans;
	t_vec3			theta;
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
	};
} t_geometry;

typedef struct	s_httbl {
	t_geometry	geom;
	t_material	mat;
	t_httbl		*next;
}	t_httbl;

typedef struct	s_hit_rec {
	t_geom_types		geom_type;
	t_vec3				p;
	t_vec3				normal;
	double				t;
	bool				front_face;
	t_mat_types			mat;
	union
	{
		t_lamber		lamber;
		t_metal			metal;
		t_dielec		dielec;
		t_diff_light	diff_light;
	};
}	t_hit_rec;

typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_image;

typedef struct	s_camera {
	bool	set;
	t_vec3	center;
	t_vec3	dir;
	//double	focal_length;
	double	vfov;
	double	hfov;
	t_vec3	u;
	t_vec3	v;
	t_vec3	w;
	double	defocus_angle;
	double	focus_dist;
	t_vec3	defocus_disk_u;
	t_vec3	defocus_disk_v;
	t_vec3	pixel00_loc;
	t_vec3	pixel_delta_u;
	t_vec3	pixel_delta_v;
	double	max_depth;
	int		samples_per_pixel;
	t_vec3	offset;
}	t_camera;

typedef struct	s_world
{
	t_httbl		*httbl_head;
	t_httbl		*httbl;
	size_t		size;
}	t_world;

typedef struct	s_mlx
{
	void	*ptr;
	void	*win_ptr;
	t_image	image;
}	t_mlx;

typedef struct	s_ambient
{
	bool	set;
	double	ratio;
	t_vec3	color;
}	t_ambient;

typedef struct	s_light
{
	bool	set;
	t_vec3	pos;
	double	ratio;
	t_vec3	color;
}	t_light;

typedef struct	s_rt
{
	t_ambient	ambient;
	t_light		light;
	double		aspect_ratio;
	bool		set_resolution;
	int			img_width;
	int			img_height;
	t_mlx		mlx;
	t_camera	cam;
	t_world		world;
	int			p_expected;
	int			p_count;
	int			p_avail;
	t_geometry	temp_geom;
	t_material	temp_mat;
	t_vec3		temp_color;
	int			temp_ret;
	char		**temp_params;
}	t_rt;

//All functions prototypes
//file.c
bool		is_rt_file(char *file_path);
int			read_file(t_rt *rt, int fd);
char		*clean_line(char *line);
bool		is_incomplete_file(t_rt *rt);
int			open_and_read_file(t_rt *rt, char *file_path);

//parsing.c
int	parse_line(t_rt *rt, char *line);
int	parse_line_cont(t_rt *rt);
int	parse_httbl(t_rt *rt, t_geom_types geom_type, int nb_params);
int	parse_httbl_cont(t_rt *rt, t_geom_types geom_type);

//parsing_types_1.c
int	parse_dbl(char* str, double *num);
int	parse_dbl_01(char* str, double *num);
int	parse_dbl_0180(char* str, double *num);

//parsing_types_2.c
int	parse_dbl_vec3(char* str, t_vec3 *vec);
int	parse_color(char* str, t_vec3 *color);
//char	*get_info_type(char *line);

//parsing_geom.c
int		parse_sphere(t_rt *rt);
int		parse_plane(t_rt *rt);
int		parse_cylinder(t_rt *rt);
int		parse_cone(t_rt *rt);
int		parse_quad(t_rt *rt);
int		parse_disc(t_rt *rt);
int		parse_box(t_rt *rt);
int		parse_die(t_rt *rt);
int		parse_saf_cone(t_rt *rt);
int		create_light_point(t_rt *rt);

//parsing_env.c
int			parse_resolution_params(t_rt *rt);
int			parse_ambient_params(t_rt *rt);
int			parse_light_params(t_rt *rt);
int			parse_camera_params(t_rt *rt);

//parsing_extra.c
int	parse_extra(t_rt *rt);
int	parse_transform(t_rt *rt);
int	parse_dielectric(t_rt *rt);
int	parse_metal(t_rt *rt);
int	parse_diff_light(t_rt *rt);

//mini_rt.c
int			mini_rt(t_rt *rt);

//rt_initialize.c
void		rt_initialize(t_rt *rt);

//camera.c
int			render(t_rt *rt);
void		cam_initialize(t_camera *cam, int img_width, int img_height);

//mlx.c
int			mlx_initialize(t_mlx *mlx, int img_width, int img_height);
int			image_create(t_mlx *mlx, int img_width, int img_height);
int			image_update(t_mlx *mlx);
int			my_mlx_pixel_put(t_image img, int x, int y, int color);

//color_convert.c
t_vec3		vec2rgb(const t_vec3 color);
t_vec3		rgb2vec(const t_vec3 color);
t_vec3		lin2gam_vec(const t_vec3 lin);
double		rgb2val(const t_vec3 color);

//vec3_operations.c
t_vec3		new_vec3(double x, double y, double z);
//int			edit_vec3(t_vec3 *v, double x, double y, double z);
t_vec3		vec3_add2(const t_vec3 v1, const t_vec3 v2);
t_vec3		vec3_add3(const t_vec3 v1, const t_vec3 v2, const t_vec3 v3);
//int			vec_add_in(t_vec3 *v3, const t_vec3 *v1, const t_vec3 *v2);
t_vec3		vec3_substract2(const t_vec3 v1, const t_vec3 v2);
//int			vec_substract_in(t_vec3 *v3, const t_vec3 *v1, const t_vec3 *v2);
t_vec3		vec3_prod_comp_by_comp(const t_vec3 v1, const t_vec3 v2);
int			vec3_update(t_vec3 *vec, double x, double y, double z);
//int			vec_prod_2vec_comp_by_comp_in(t_vec3 *v3, const t_vec3 *v1, const t_vec3 *v2);
t_vec3		vec3_identity_number(double t);
//int			vec_identity_number_in(t_vec3 *v, double t);
//t_vec3		vec_prod_number(const t_vec3 *v, double t);
//nt			vec_prod_number_in(t_vec3 *v, double t);
t_vec3		vec3_scale(double t, t_vec3 v);
//int			vec_number_prod_in(double t, t_vec3 *v);
double		vec3_dot(const t_vec3 v1, const t_vec3 v2);
t_vec3		vec3_cross(const t_vec3 v1, const t_vec3 v2);
//int			vec_cross_in(t_vec3 *v3, const t_vec3 *v1, const t_vec3 *v2);
t_vec3		vec3_unit(const t_vec3 v);
//int			vec_unit_in(t_vec3 *v);
double		vec3_length(const t_vec3 v);
double		vec3_length_squared(const t_vec3 v);
double		vec3_index(const t_vec3 v, int i);
int			display_vec3(const t_vec3 v);
//t_vec3		vec3_2points(const t_vec3 orig, const t_vec3 end);
bool		near_zero(const t_vec3 vec);
t_vec3		vec3_cos(t_vec3 theta);
t_vec3		vec3_sin(t_vec3 theta);

//memory.c
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_bzero(void *ptr, const size_t size);
void		free_httbls(t_httbl *httbl);

//test.c
int			test_vec3_operations(void);

//color_display.c
void		write_color(t_vec3 pixel_color);

//ray_color.c
t_vec3		ray_color(t_rt *rt, int depth, const t_ray r);
t_vec3		ray_color_grad_blue(const t_ray r);
t_vec3		ray_color_grad_red(const t_ray r);
t_vec3		ray_color_grad_violet(const t_ray r);
t_vec3		ray_color_grad_yellow(const t_ray r);
t_vec3		ray_color_grad_sunset(const t_ray r);
t_vec3		ray_color_red();

//ray_compute.c
t_vec3		hit_point(const t_ray r, double t);
t_ray		new_ray(const t_vec3 orig, const t_vec3 dir);
t_vec3		reflect(const t_vec3 v, const t_vec3 n);
t_vec3		refract(const t_vec3 r_in, const t_vec3 n, double eta_in_over_out);
double		reflectance(double cosine, double ref_idx);
t_ray		get_ray(const t_camera *cam, int i, int j);
t_vec3		pixel_sample_square(const t_camera *cam);
t_vec3		defocus_disk_sample(const t_camera *cam);

//random.c
t_vec3		get_random_dev(const t_camera *cam);
double		random_double();
double		random_double_interval(double min, double max);
t_vec3		random_vec3_interval(double min, double max);
t_vec3		random_in_unit_sphere(void);
t_vec3		random_unit_vector(void);
t_vec3		random_in_same_hemisphere(const t_vec3 normal);
t_vec3		random_in_unit_disk(void);

//world.c
int			world_initialize(t_world *world);
void		create_saf_cone(t_world *world, t_vec3 pos, t_vec3 gen, double height);
void		create_cylinder_box(t_world *world, double height, double width, double thickness, double factor, double spacing, double y_offset, double z_offsset);
bool		world_hit(t_rt *rt, const t_ray r, t_interval tray, t_hit_rec *rec);
void		httbl_addback(t_world *world, t_httbl *new_httbl);
void		httbl_record(t_world *world, t_httbl *new_httbl);

//httbl_create.c
t_httbl		*new_httbl(const t_geometry geom, const t_material mat);
//t_httbl		*new_httbl_plane(t_plane pln);
//t_httbl		*new_httbl_sphere(t_sphere sph);
//t_httbl		*new_httbl_cylinder(t_cylinder cyl);
//void		assign_geom(t_httbl *httbl, t_httbl_types geom_type, void(*p1));
//void		assign_mat(t_httbl *httbl, t_mat_types mat_type, void(*p2));

//httbl_point.c
t_point		point(const t_vec3 point);
bool		hit_point_geom(const t_rt *rt, const t_ray r, const t_interval tray, t_hit_rec *rec); //bool		is_interior(double a, double b, t_hit_rec *rec);

//httbl_plane.c
t_plane		plane(const t_vec3 point, const t_vec3 dir);
bool		hit_plane(const t_rt *rt, const t_ray r, const t_interval tray, t_hit_rec *rec); //bool		is_interior(double a, double b, t_hit_rec *rec);

//httbl_quad.c
t_quad		quad(const t_vec3 point, const t_vec3 vec1, const t_vec3 vec2);
bool		hit_quad(const t_rt *rt, const t_ray r, const t_interval tray, t_hit_rec *rec);
bool		is_interior(double a, double b, t_hit_rec *rec);

//httbl_box.c
t_box		box(const t_vec3 a, const t_vec3 b);

//httbl_disc.c
t_disc		disc(const t_vec3 center, const t_vec3 normal, double radius);
bool		hit_disc(const t_rt *rt, const t_ray r, const t_interval tray, t_hit_rec *rec);

//httbl_sphere.c
t_sphere	sphere(const t_vec3 center, double r);
bool		hit_sphere(const t_rt *rt, const t_ray r, const t_interval tray, t_hit_rec *rec);

//httbl_cylinder.c
t_cylinder	cylinder(const t_vec3 base_center, t_vec3 generator, double radius, double height);
bool		hit_cylinder_finite(const t_rt *rt, const t_ray r, const t_interval tray, t_hit_rec *rec);

//httbl_cone.c
t_cone		cone(const t_vec3 base_center, t_vec3 generator, double radius_min, double radius_max, double height);
bool		hit_cone_finite(const t_rt *rt, const t_ray r, const t_interval tray, t_hit_rec *rec);

//httbl_quad.c
//bool	hit_quad(const t_rt *rt, const t_ray r, const t_interval tray, t_hit_rec *rec);
//bool	is_interior(double a, double b, t_hit_rec *rec);

//utils_math.c
double		ft_min(const double n1, const double n2);
double		ft_max(const double n1, const double n2);

//utils_convert.c
double		deg2rad(double deg);
t_vec3		deg2rad_vec3(t_vec3 vec);
double		lin2gam_double(double linear);
double		str2dbl(char *str);

//utils_numbers.c
int	is_digit(char c);
int	is_dec(char *str);
int	is_ulong(char *str);
int	is_long(char *str);
int	is_valid_color_comp(char *str);
int	is_in_int_range(char *str);
int	is_in_range01 (double num);
int	is_in_range0180 (double num);

//utils_array.c
double	array_size(char **params);

//interval.c
t_interval	interval(double min, double max);
bool		contains(t_interval intrvl, double x);
bool		surrounds(t_interval intrvl, double x);
double		clamp(t_interval intrvl, double x);

//search_poly_root.c
bool		search_poly_root(t_half_poly *half_poly, const t_interval tray, double *root);
bool		solve_half_poly(t_half_poly *half_poly);

//hit_record.c
void		set_face_normal(const t_ray r, const t_vec3 outward_normal, t_hit_rec *rec);

//material_scatter.c
bool		lambertian_scatter(const t_ray r_in, const t_hit_rec rec, t_vec3 *attenuation, t_ray *scattered);
bool		metal_scatter(const t_ray r_in, const t_hit_rec rec, t_vec3 *attenuation, t_ray *scattered);
bool		dielectric_scatter(const t_ray r_in, const t_hit_rec rec, t_vec3 *attenuation, t_ray *scattered);

//mat_lambertian.c
t_lamber	lamber(t_vec3 color);

//mat_metal.c
t_metal		metal(t_vec3 color, double fuzz);

//mat_dielectric.c
t_dielec	dielec(t_vec3 color, double ir);

//mat_diff_light.c
t_diff_light	diff_light(double ratio, t_vec3 color);

//geometries.c
t_geometry	geom_point(t_point pnt);
t_geometry	geom_plane(t_plane pln);
t_geometry	geom_quad(t_quad qud);
t_geometry	geom_disc(t_disc dsc);
t_geometry	geom_box(t_box box);
t_geometry	geom_die(t_box box);
t_geometry	geom_sphere(t_sphere sph);
t_geometry	geom_cylinder(t_cylinder cyl);
t_geometry	geom_cone(t_cone con);

//material.c
t_material	mat_lamber(t_lamber lamber);
t_material	mat_metal(t_metal metal);
t_material	mat_dielec(t_dielec dielec);
t_material	mat_diff_light(t_diff_light diff_light);

//lights.c
bool		diffuse_light(t_vec3 *attenuation, t_ray *scattered);

//geom_operations.c
void		add_box_quads(t_world *world, t_box *box, t_material mat);
void		add_die_dots(t_world *world, t_box *box, t_material mat);
void		add_cyl_discs(t_world *world, t_geometry *geom, t_material mat);
void		add_con_discs(t_world *world, t_geometry *geom, t_material mat);
t_ray		translate_r(t_ray r, t_vec3 trans);
t_vec3		translate_p(t_vec3 v, t_vec3 trans);
t_vec3		rotate_x(t_vec3 vec, double cos_theta, double sin_theta);
t_ray		rotate_rx(t_ray r, double cos_theta, double sin_theta);
t_vec3		rotate_y(t_vec3 vec, double cos_theta, double sin_theta);
t_ray		rotate_ry(t_ray r, double cos_theta, double sin_theta);
t_vec3		rotate_z(t_vec3 vec, double cos_theta, double sin_theta);
t_ray		rotate_rz(t_ray r, double cos_theta, double sin_theta);
t_vec3		rotate(t_vec3 vec, t_vec3 cos_theta, t_vec3 sin_theta);

//error.c
bool		display_error(char *error);
bool		display_error_plus(char *error, char *msg);
bool		display_warning(char *warning);
bool		display_warning_plus(char *warning, char *msg);

#endif // MINI_RT_H
