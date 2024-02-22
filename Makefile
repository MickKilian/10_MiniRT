# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 18:34:29 by mbourgeo          #+#    #+#              #
#    Updated: 2024/02/22 05:55:28 by mbourgeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL	= all

PRIM_SRCS	=	main.c mini_rt.c rt_initialize.c mlx.c \
				color_convert.c vec3_operations.c memory.c tests.c \
				color_display.c geom_operations.c camera.c utils_array.c \
				utils_conv.c utils_math.c utils_numbers.c \
				ray_compute.c hit_record.c httbl_create.c interval.c world.c \
				random.c ray_color.c search_poly_root.c httbl_quad.c \
				httbl_box.c httbl_point.c httbl_plane.c httbl_sphere.c \
				httbl_cone.c httbl_cylinder.c httbl_disc.c camera.c \
				material_scatter.c geometries.c materials.c mat_diff_light.c \
				mat_dielectric.c mat_lambertian.c mat_metal.c error.c file.c \
				parsing_general.c parsing_env.c parsing_geom_1.c parsing_geom_2.c \
				parsing_extra.c parsing_types_1.c parsing_types_2.c
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
