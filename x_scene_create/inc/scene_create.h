/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_create.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:08:04 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/17 04:59:55 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_CREATE_H
# define SCENE_CREATE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <stdbool.h>
# include <time.h>
# include <sys/time.h>

# define	ERR_OPEN_FILE				"File could not be open"
# define	ERR_IS_NOT_RT_FILE			"File is not an .rt file"
# define	ERR_NB_ARGUMENTS			"Program requires 1 argument: the scene info as an .rt file"

# define	PI	3.1415926535897932385
# define	EPSILON 1e-8

typedef struct s_list_obj	t_list_obj;

typedef enum	e_geom_types {
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

typedef struct	s_resol {
	bool	set;
	int		img_width;
	int		img_height;
}	t_resol;

typedef struct	s_algo {
	bool	set;
	int		samples_per_pixel;
	int		depth;
}	t_algo;

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

typedef struct	s_camera {
	bool	set;
	t_vec3	center;
	t_vec3	dir;
	double	hfov;
}	t_camera;

typedef struct	s_point
{
	t_vec3	q;
}	t_point;

typedef struct	s_plane
{
	t_vec3	q;
	t_vec3	d;
}	t_plane;

typedef struct	s_quad
{
	t_vec3	center;
	t_vec3	u;
	t_vec3	v;
}	t_quad;

typedef struct	s_box
{
	t_vec3	center;
	t_vec3	u;
	t_vec3	v;
	t_vec3	w;
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
	t_vec3		center;
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
	double		radius_max;
	double		radius_min;
	double		height;
	t_interval	interval_z;
}	t_cone;

typedef struct	s_safe_cone
{
	t_vec3		base_center;
	t_vec3		generator;
	double		height;
}	t_safe_cone;

typedef struct	s_dice
{
	t_vec3		center;
	t_vec3		u;
	t_vec3		v;
	t_vec3		w;
	double		size;

}	t_dice;

typedef struct	s_pencil
{
	t_vec3	base_center;
	t_vec3	generator;
	double	length;
	double	width;
}	t_pencil;

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

typedef struct	s_obj
{
	t_vec3	center;
	double	radius;
}	t_obj;

typedef struct	s_geometry
{
	t_geom_types	type;
	t_vec3			trans;
	t_vec3			rot_axis;
	t_vec3			rot_inv_axis;
	double			rot_angle;
	double			rot_inv_angle;
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
} t_geometry;

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

typedef struct	s_list_obj
{
	t_obj		obj;
	t_list_obj	*next;
}	t_list_obj;

typedef struct	s_rt
{
	int			fd;
	t_resol		resol;
	t_algo		algo;
	t_ambient	ambient;
	t_light		light;
	t_camera	cam;
	t_geometry	*geometry;
	t_material	*material;
	t_vec3		trans;
	t_vec3		rot_axis;
	double		rot_angle;
	t_list_obj	*list_obj;
	t_list_obj	*list_obj_head;
	int			list_obj_size;
}	t_rt;

//All function prototypes
//scene_create.c
int		scene_create(t_rt *rt);

//random_dice.c
void	n_random_dice(t_rt *rt);
t_obj	new_obj(t_vec3 point, double radius);
void	place_dice(t_rt *rt, int nb_dice);
bool	try_location(t_rt *rt, t_vec3 p, double size);

//utils_random.c
double	random_double(void);
double	random_double_interval(double min, double max);
t_vec3	random_vec3_interval(double min, double max);
t_vec3	random_in_unit_sphere(void);
t_vec3	random_unit_vector(void);
t_vec3	random_in_same_hemisphere(const t_vec3 normal);
t_vec3	random_in_unit_disk(void);
void	random_dice(t_rt *rt, t_vec3 center, double size, t_vec3 color);

//utils_vec3.c
t_vec3	new_vec3(double x, double y, double z);
t_vec3	vec3_add2(const t_vec3 v1, const t_vec3 v2);
t_vec3	vec3_add3(const t_vec3 v1, const t_vec3 v2, const t_vec3 v3);
t_vec3	vec3_substract2(const t_vec3 v1, const t_vec3 v2);
t_vec3	vec3_prod_comp_by_comp(const t_vec3 v1, const t_vec3 v2);
int		vec3_update(t_vec3 *vec, double x, double y, double z);
t_vec3	vec3_identity_number(double t);
t_vec3	vec3_scale(double t, t_vec3 v);
double	vec3_dot(const t_vec3 v1, const t_vec3 v2);
t_vec3	vec3_cross(const t_vec3 v1, const t_vec3 v2);
t_vec3	vec3_unit(const t_vec3 v);
double	vec3_length(const t_vec3 v);
double	vec3_length_squared(const t_vec3 v);
double	vec3_index(t_vec3 v, int i);
bool	vec3_is_nearzero(const t_vec3 vec);
t_vec3	vec3_cos(t_vec3 theta);
t_vec3	vec3_sin(t_vec3 theta);

//utils_file.c
bool	is_rt_file(char *file_path);
int		open_and_write_file(t_rt *rt, char *file_path);

//utils_general.c
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*ft_itoa(int n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
char	*ft_dbl2str(double num);

//utils_display.c
bool	display_error(char *error);
bool	display_error_plus(char *error, char *msg);

//utils_chained_list.c
t_list_obj	*new_list_obj(t_obj obj);
void		list_obj_addback(t_rt *rt, t_list_obj *new_list_obj);
void		free_list_obj(t_list_obj *list_obj);

//write_simple.c
void	write_str(t_rt *rt, char *str);
void	write_dbl(t_rt *rt, double x);
void	write_code(t_rt *rt, char *str);
void	write_number(t_rt *rt, double x);
void	write_vec3(t_rt *rt, t_vec3 v);

//write_objects.c
void	write_resol(t_rt *rt);
void	write_algo(t_rt *rt);
void	write_ambient(t_rt *rt);
void	write_cam(t_rt *rt);
void	write_point(t_rt *rt);
void	write_plane(t_rt *rt);
void	write_quad(t_rt *rt);
void	write_sphere(t_rt *rt);
void	write_disc(t_rt *rt);
void	write_cylinder(t_rt *rt);
void	write_cone(t_rt *rt);
void	write_safe_cone(t_rt *rt);
void	write_dice(t_rt *rt);
void	write_lamber(t_rt *rt);
void	write_dielec(t_rt *rt);
void	write_metal(t_rt *rt);
void	write_diff_light(t_rt *rt);
void	write_tra(t_rt *rt);
void	write_rot(t_rt *rt);

//set_objects.c
void	set_resol(t_rt *rt, double img_width);
void	set_algo(t_rt *rt, int samples_per_pixel, int depth);
void	set_ambient(t_rt *rt, double ratio, t_vec3 color);
void	set_cam(t_rt *rt, t_vec3 center, t_vec3 dir, double hfov);
void	set_plane(t_rt *rt, t_vec3 q, t_vec3 d);
void	set_quad(t_rt *rt, t_vec3 center, t_vec3 u, t_vec3 v);
void	set_sphere(t_rt *rt, t_vec3 center, double radius);
void	set_disc(t_rt *rt, t_vec3 center, t_vec3 normal, double radius);
void	set_cylinder(t_rt *rt, t_vec3 center, t_vec3 generator, double radius, double height, t_interval interval_z);
void	set_cone(t_rt *rt, t_vec3 base_center, t_vec3 generator, double radius_max, double radius_min, double height);
void	set_safe_cone(t_rt *rt, t_vec3 base_center, t_vec3 generator, double height);
void	set_dice(t_rt *rt, t_vec3 center, t_vec3 u, t_vec3 v, double height);
void	set_lamber(t_rt *rt, t_vec3 color);
void	set_dielec(t_rt *rt, t_vec3 color, double idx_refract);
void	set_metal(t_rt *rt, t_vec3 color, double fuzz);
void	set_diff_light(t_rt *rt, t_vec3 color, double ratio);
void	set_tra(t_rt *rt, t_vec3 trans);
void	set_rot(t_rt *rt, t_vec3 rot_axis, double rot_angle);

#endif // SCENE_CREATE_H
