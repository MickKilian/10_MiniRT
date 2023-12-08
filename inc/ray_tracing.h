/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:08:04 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/08 10:55:26 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_TRACING_H
# define RAY_TRACING_H

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

# define ERR_NO_AMBIENT_PARAMS	"Missing ambient parameters in scene file"
# define ERR_NO_LIGHT_PARAMS	"Missing light parameters in scene file"
# define ERR_NO_CAMERA_PARAMS	"Missing camera parameters in scene file"
# define ERR_OPEN_FILE			"File could not be open"
# define ERR_IS_NOT_RT_FILE		"File is not an .rt file"
# define ERR_BAD_NB_ARGUMENTS	"Program requires 1 argument, the scene info as an .rt file"

# define	PI	3.1415926535897932385
// Aspect ratio : 16/9
# define	ASPECT_RATIO 1.777777778
# define	EPSILON 1e-8
# define	IMAGE_WIDTH 400

typedef struct s_httbl	t_httbl;

typedef enum	e_geom_types {
	PLANE,
	QUAD,
	DISC,
	BOX,
	SPHERE,
	CYLINDER,
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

typedef struct	s_plane
{
	t_vec3	q;
	t_vec3	u;
	t_vec3	v;
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

typedef struct	s_lamber
{
	t_vec3	albedo;
}	t_lamber;

typedef struct	s_metal
{
	t_vec3	albedo;
	double	fuzz;
}	t_metal;

typedef struct	s_dielec
{
	t_vec3	albedo;
	double	idx_refract;
}	t_dielec;

typedef struct	s_diff_light
{
	t_vec3	color;
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
	t_vec3			offset;
	t_vec3			theta;
	union
	{
		t_plane		pln;
		t_quad		qud;
		t_disc		dsc;
		t_box		box;
		t_sphere	sph;
		t_cylinder	cyl;
	};
} t_geometry;

typedef struct	s_httbl {
	t_geometry	geom;
	t_material	mat;
	t_httbl		*next;
}	t_httbl;

typedef struct	s_hit_rec {
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
	//double	focal_length;
	double	vfov;
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
	t_vec3	background;
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
	t_vec3	color;
}	t_ambient;

typedef struct	s_light
{
	bool	set;
	t_vec3	color;
}	t_light;

typedef struct	s_rt
{
	t_ambient	ambient;
	t_light		light;
	double		aspect_ratio;
	int			img_width;
	int			img_height;
	t_mlx		mlx;
	t_camera	cam;
	t_world		world;
}	t_rt;

//All functions prototypes
//src/parsing/
//file.c
bool		is_rt_file(char *file_path);
int			read_file(t_rt *rt, int fd);
char		*clean_line(char *line);
bool		is_incomplete_file(t_rt *rt);
int			open_and_read_file(t_rt *rt, char *file_path);

//parsing.c
int			parse_line(t_rt *rt, char *line);
int			parse_httbl_params(t_rt *rt, char *line, t_geom_types geom_type);

//parsing_geom.c
int		parse_sphere(t_rt *rt, char **params);
int		parse_plane(t_rt *rt, char **params);
int		parse_cylinder(t_rt *rt, char **params);

//parsing_env.c
int			parse_ambient_params(t_rt *rt, char *line);
int			parse_light_params(t_rt *rt, char *line);
int			parse_camera_params(t_rt *rt, char *line);

//ray_tracing.c
int			ray_tracing(t_rt *rt);

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

//httbl_plane.c
t_plane		plane(const t_vec3 point, const t_vec3 vec1, const t_vec3 vec2);
bool		hit_plane(const t_rt *rt, const t_ray r, const t_interval tray, t_hit_rec *rec);
//bool		is_interior(double a, double b, t_hit_rec *rec);

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
bool		hit_cylinder(const t_rt *rt, const t_ray r, const t_interval tray, t_hit_rec *rec);
bool		hit_cylinder_finite(const t_rt *rt, const t_ray r, const t_interval tray, t_hit_rec *rec);

//httbl_quad.c
//bool	hit_quad(const t_rt *rt, const t_ray r, const t_interval tray, t_hit_rec *rec);
//bool	is_interior(double a, double b, t_hit_rec *rec);

//utils.c
double		ft_min(const double n1, const double n2);
double		deg2rad(double deg);
double		lin2gam_double(double linear);

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
t_diff_light	diff_light(t_vec3 color);

//geometries.c
t_geometry	geom_plane(t_plane pln);
t_geometry	geom_quad(t_quad qud);
t_geometry	geom_disc(t_disc dsc);
t_geometry	geom_box(t_box box);
t_geometry	geom_sphere(t_sphere sph);
t_geometry	geom_cylinder(t_cylinder cyl);

//material.c
t_material	mat_lamber(t_lamber lamber);
t_material	mat_metal(t_metal metal);
t_material	mat_dielec(t_dielec dielec);
t_material	mat_diff_light(t_diff_light diff_light);

//lights.c
bool		diffuse_light(t_vec3 *attenuation, t_ray *scattered);

//geom_operations.c
void		add_box_quads(t_world *world, t_box *box, t_material mat);
void		add_cyl_discs(t_world *world, t_cylinder *cyl, t_material mat);
t_ray		offset_r(t_ray r, t_vec3 offset);
t_vec3		offset_p(t_vec3 v, t_vec3 offset);
t_vec3		rotate_x(t_vec3 vec, double cos_theta, double sin_theta);
t_ray		rotate_rx(t_ray r, double cos_theta, double sin_theta);
t_vec3		rotate_y(t_vec3 vec, double cos_theta, double sin_theta);
t_ray		rotate_ry(t_ray r, double cos_theta, double sin_theta);
t_vec3		rotate_z(t_vec3 vec, double cos_theta, double sin_theta);
t_ray		rotate_rz(t_ray r, double cos_theta, double sin_theta);

//error.c
bool		display_error(char *error);

#endif // RAY_TRACING
