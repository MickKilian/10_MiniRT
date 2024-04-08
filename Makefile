# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 18:34:29 by mbourgeo          #+#    #+#              #
#    Updated: 2024/04/07 15:17:02 by mbourgeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL	= all

PRIM_SRCS	=	main.c \
				display_errors.c display_geometry.c display_material.c \
				display_simple.c display_world.c \
				geom_basic_translate.c geom_basic_rotate.c \
				geom_object_transform.c \
				geom_special_build_con.c geom_special_build_other.c\
				httbl_box.c httbl_cone.c httbl_create.c httbl_cylinder.c \
				httbl_dice.c httbl_disc.c httbl_pencil.c \
				httbl_plane.c httbl_point.c httbl_quad.c httbl_safe_cone.c \
				httbl_sphere.c \
				mat_create.c mat_diff_light.c mat_dielectric.c \
				mat_lambertian.c mat_metal.c mat_scatter.c \
				parsing_env.c \
				parsing_extra.c parsing_tranformation.c parsing_material.c\
				parsing_file.c parsing_general.c \
				parsing_geom_1.c parsing_geom_2.c parsing_geom_3.c \
				parsing_types_1.c parsing_types_2.c \
				parsing_txm_pat.c \
				rt_ray_color.c rt_ray_compute.c rt_lights.c \
				rt_camera.c rt_hit_record.c rt_initialize.c rt_world.c \
				rt_render.c rt_mlx.c rt_image.c \
				rt_patterns.c rt_bumps.c \
				utils_array.c utils_convert_1.c utils_convert_2.c \
				utils_interval.c utils_math_1.c utils_math_2.c \
				utils_memory.c \
				utils_numbers_1.c utils_numbers_2.c utils_colors.c \
				utils_quadratic_solve.c utils_parsing.c \
				utils_random_1.c utils_random_2.c utils_ray.c \
				utils_vec3_1.c utils_vec3_2.c utils_vec3_3.c utils_vec3_4.c \
				utils_debug.c
PRIM_SRCDIR	=	src
PRIM_PATH	=	$(addprefix $(PRIM_SRCDIR)/, $(PRIM_SRCS))
PRIM_OBJDIR	=	obj
PRIM_OBJS	=	$(patsubst $(PRIM_SRCDIR)/%, $(PRIM_OBJDIR)/%, $(PRIM_PATH:.c=.o))

DEP_DIR		=	dep
PRIM_DEP	=	$(patsubst $(PRIM_OBJDIR)/%.o, $(DEP_DIR)/%.d, $(PRIM_OBJS))

HEADER_SRCS	=	mini_rt.h mlx.h
HEADER_DIR	=	inc
HEADER_PATH	=	$(addprefix $(HEADER_DIR)/, $(HEADER_SRCS))

NAME		=	miniRT
LIB1_DIR	=	lib/gnl
LIB1_NAME	=	lib/gnl/libgnl.a
LIB2_DIR	=	lib/libft
LIB2_NAME	=	lib/libft/libft.a
HDLIB1_DIR	=	$(LIB1_DIR)/inc
HDLIB2_DIR	=	$(LIB2_DIR)/inc
CC			=	gcc
RM			=	rm -rvf
MK			=	mkdir -p
#DEBUG		=	-g3 -fsanitize=address
DEBUG		=	-g3
CFLAGS		=	-Wall -Wextra -Werror
DFLAGS		=	-MMD -MF
COPTIONS	=	-lXext -lX11 -lm
CLIBS		=	-Ilib/mlx -Llib/mlx -lmlx_Linux

#################################

all:		$(NAME)

$(NAME):	$(PRIM_OBJS) | lib/mlx/libmlx_Linux.a Makefile $(LIB1_NAME) Makefile $(LIB2_NAME) Makefile
				$(CC) $^ $(CLIBS) -I$(HDLIB1_DIR) -L$(LIB1_DIR) -lgnl -I$(HDLIB2_DIR) -L$(LIB2_DIR) -lft -o $@ $(COPTIONS)

$(LIB1_NAME):
				$(MAKE) -C $(LIB1_DIR) all

$(LIB2_NAME):
				$(MAKE) -C $(LIB2_DIR) all

-include $(PRIM_DEP)
$(PRIM_OBJDIR)/%.o:		$(PRIM_SRCDIR)/%.c | $(LIB1_NAME) $(LIB1_NAME) $(LIB2_NAME) $(LIB2_NAME) $(PRIM_OBJDIR) $(DEP_DIR) $(HEADER_PATH)
							$(CC) $(CFLAGS) $(DEBUG) $(DFLAGS) $(DEP_DIR)/$*.d -I$(HDLIB1_DIR) -I$(HDLIB2_DIR) -c $< -o $@

lib/mlx/libmlx_Linux.a:
				$(MAKE) -C lib/mlx all

$(PRIM_OBJDIR) $(DEP_DIR):		;
				@$(MK) $@

clean:		;
				@$(MAKE) clean -C lib/mlx
				@$(RM) $(PRIM_OBJDIR) $(DEP_DIR)
				$(MAKE) -C $(LIB1_DIR) fclean
				$(MAKE) -C $(LIB2_DIR) fclean

fclean:		clean
				@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
