# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 18:34:29 by mbourgeo          #+#    #+#              #
#    Updated: 2024/04/11 02:13:42 by mbourgeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL	= all

MAND_SRCS	=	main.c \
				display_errors.c display_geometry.c display_material.c \
				display_simple.c display_world.c \
				geom_basic_translate.c geom_basic_rotate.c \
				geom_object_transform.c geom_map_coord_1.c \
				geom_special_build_other.c \
				httbl_create.c httbl_cylinder.c httbl_disc.c \
				httbl_plane.c httbl_point.c httbl_sphere.c \
				mat_create.c mat_diff_light.c \
				mat_lambertian.c mat_scatter.c \
				parsing_env.c \
				parsing_extra.c \
				parsing_file.c parsing_general.c \
				parsing_geom_1.c parsing_transformation.c \
				parsing_types_1.c parsing_types_2.c parsing_types_3.c \
				rt_ray_color.c rt_ray_compute.c rt_lights.c \
				rt_camera.c rt_hit_record.c rt_initialize.c rt_world.c \
				rt_render.c rt_mlx.c rt_image.c \
				utils_array.c utils_convert_1.c utils_convert_2.c \
				utils_interval_1.c utils_interval_2.c utils_math_1.c \
				utils_math_2.c utils_memory.c \
				utils_numbers_1.c utils_numbers_2.c utils_colors_1.c \
				utils_colors_2.c \
				utils_quadratic_solve.c utils_parsing.c \
				utils_random_1.c utils_random_2.c utils_ray.c \
				utils_vec3_1.c utils_vec3_2.c utils_vec3_3.c utils_vec3_4.c \
				utils_debug.c
MAND_SRCDIR	=	miniRT/src
MAND_PATH	=	$(addprefix $(MAND_SRCDIR)/, $(MAND_SRCS))
MAND_OBJDIR	=	miniRT/obj
MAND_OBJS	=	$(patsubst $(MAND_SRCDIR)/%, $(MAND_OBJDIR)/%, $(MAND_PATH:.c=.o))

BONUS_SRCS	=	main_bonus.c \
				display_errors_bonus.c display_geometry_bonus.c \
				display_material_bonus.c display_simple_bonus.c \
				display_world_bonus.c geom_basic_translate_bonus.c \
				geom_basic_rotate_bonus.c geom_object_transform_bonus.c \
				geom_map_coord_1_bonus.c geom_map_coord_2_bonus.c \
				geom_special_build_con_bonus.c \
				geom_special_build_other_bonus.c \
				httbl_box_bonus.c httbl_cone_bonus.c \
				httbl_create_bonus.c httbl_cylinder_bonus.c \
				httbl_dice_bonus.c httbl_disc_bonus.c httbl_plane_bonus.c \
				httbl_point_bonus.c httbl_quad_bonus.c httbl_safe_cone_bonus.c \
				httbl_sphere_bonus.c mat_create_bonus.c mat_txm_bmp_bonus.c \
				mat_diff_light_bonus.c mat_dielectric_bonus.c \
				mat_lambertian_bonus.c mat_metal_bonus.c mat_scatter_bonus.c \
				parsing_env_bonus.c parsing_extra_bonus.c \
				parsing_transformation_bonus.c parsing_material_bonus.c \
				parsing_file_bonus.c parsing_general_bonus.c \
				parsing_geom_1_bonus.c parsing_geom_2_bonus.c \
				parsing_types_1_bonus.c parsing_types_2_bonus.c \
				parsing_types_3_bonus.c parsing_txm_pat_bonus.c \
				rt_ray_color_bonus.c rt_ray_compute_bonus.c rt_lights_bonus.c \
				rt_camera_bonus.c rt_hit_record_bonus.c rt_initialize_bonus.c \
				rt_world_bonus.c rt_render_bonus.c rt_mlx_bonus.c \
				rt_image_bonus.c rt_patterns_1_bonus.c \
				rt_patterns_2_bonus.c rt_bumps_bonus.c \
				utils_array_bonus.c utils_convert_1_bonus.c \
				utils_convert_2_bonus.c utils_interval_1_bonus.c \
				utils_interval_2_bonus.c utils_math_1_bonus.c \
				utils_math_2_bonus.c utils_memory_bonus.c \
				utils_numbers_1_bonus.c utils_numbers_2_bonus.c \
				utils_colors_1_bonus.c utils_colors_2_bonus.c \
				utils_quadratic_solve_bonus.c utils_parsing_bonus.c \
				utils_random_1_bonus.c utils_random_2_bonus.c \
				utils_ray_bonus.c utils_vec3_1_bonus.c utils_vec3_2_bonus.c \
				utils_vec3_3_bonus.c utils_vec3_4_bonus.c \
				utils_debug_bonus.c
BONUS_SRCDIR	=	miniRT_bonus/src
BONUS_PATH		=	$(addprefix $(BONUS_SRCDIR)/, $(BONUS_SRCS))
BONUS_OBJDIR	=	miniRT_bonus/obj
BONUS_OBJS		=	$(patsubst $(BONUS_SRCDIR)/%, $(BONUS_OBJDIR)/%, $(BONUS_PATH:.c=.o))

MD_DEP_DIR		=	miniRT/dep
MAND_DEP		=	$(patsubst $(MAND_OBJDIR)/%.o, $(MD_DEP_DIR)/%.d, $(MAND_OBJS))
BN_DEP_DIR		=	miniRT_bonus/dep
BONUS_DEP		=	$(patsubst $(BONUS_OBJDIR)/%.o, $(BN_DEP_DIR)/%.d, $(BONUS_OBJS))

MD_HD_SRCS	=	mini_rt.h mlx.h
MD_HD_DIR	=	miniRT/inc
MD_HD_PATH	=	$(addprefix $(MD_HD_DIR)/, $(MD_HD_SRCS))
BN_HD_SRCS	=	mini_rt_bonus.h mlx.h
BN_HD_DIR	=	miniRT_bonus/inc
BN_HD_PATH	=	$(addprefix $(BN_HD_DIR)/, $(BN_HD_SRCS))

NAME		=	miniRT/miniRT
NAME_BONUS	=	miniRT_bonus/miniRT_bonus
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

$(NAME):	$(MAND_OBJS) | lib/mlx/libmlx_Linux.a Makefile $(LIB1_NAME) Makefile $(LIB2_NAME) Makefile
				$(CC) $^ -I$(MD_HD_DIR) $(CLIBS) -I$(HDLIB1_DIR) -L$(LIB1_DIR) -lgnl -I$(HDLIB2_DIR) -L$(LIB2_DIR) -lft -o $@ $(COPTIONS)

bonus:		$(BONUS_OBJS) | lib/mlx/libmlx_Linux.a Makefile $(LIB1_NAME) Makefile $(LIB2_NAME) Makefile
				$(CC) $^ -I$(BN_HD_DIR) $(CLIBS) -I$(HDLIB1_DIR) -L$(LIB1_DIR) -lgnl -I$(HDLIB2_DIR) -L$(LIB2_DIR) -lft -o $(NAME_BONUS) $(COPTIONS)

$(LIB1_NAME):
				$(MAKE) -C $(LIB1_DIR) all

$(LIB2_NAME):
				$(MAKE) -C $(LIB2_DIR) all

-include $(MAND_DEP)
$(MAND_OBJDIR)/%.o:		$(MAND_SRCDIR)/%.c | $(LIB1_NAME) $(LIB1_NAME) $(LIB2_NAME) $(LIB2_NAME) $(MAND_OBJDIR) $(MD_DEP_DIR) $(MD_HD_PATH)
							$(CC) $(CFLAGS) $(DEBUG) $(DFLAGS) $(MD_DEP_DIR)/$*.d -I$(HDLIB1_DIR) -I$(HDLIB2_DIR) -c $< -o $@

-include $(BONUS_DEP)
$(BONUS_OBJDIR)/%.o:		$(BONUS_SRCDIR)/%.c | $(LIB1_NAME) $(LIB1_NAME) $(LIB2_NAME) $(LIB2_NAME) $(BONUS_OBJDIR) $(BN_DEP_DIR) $(BN_HD_PATH)
							$(CC) $(CFLAGS) $(DEBUG) $(DFLAGS) $(BN_DEP_DIR)/$*.d -I$(HDLIB1_DIR) -I$(HDLIB2_DIR) -c $< -o $@

lib/mlx/libmlx_Linux.a:
				$(MAKE) -C lib/mlx all

$(MAND_OBJDIR) $(MD_DEP_DIR):		;
				@$(MK) $@

$(BONUS_OBJDIR) $(BN_DEP_DIR):		;
				@$(MK) $@

clean:		;
				@$(MAKE) clean -C lib/mlx
				@$(RM) $(MAND_OBJDIR) $(MD_DEP_DIR)
				@$(RM) $(BONUS_OBJDIR) $(BN_DEP_DIR)
				$(MAKE) -C $(LIB1_DIR) fclean
				$(MAKE) -C $(LIB2_DIR) fclean

fclean:		clean
				@$(RM) $(NAME)
				@$(RM) $(NAME_BONUS)

re:			fclean all

.PHONY:		all clean fclean re bonus
