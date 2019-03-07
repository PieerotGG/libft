/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawables.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 02:14:46 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/07 03:16:02 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_DRAWABLE_H
# define FT_MLX_DRAWABLE_H
# include "ft_math/point.h"
# include "ft_math/dim.h"
# include "ft_mlx/color.h"

# define OFFSET_NULL ({ 0, 0 })

typedef enum			e_drawable_types
{
						CONTAINER,
						TEXT,
						BUTTON,
						NONE
}						t_drawable_types;

typedef struct			s_image_carry
{
	void				*img_ptr;
	char				**data;
	int					bits_per_pixels;
	int					size_line;
	int					endian;
}						t_image_carry;

t_image_carry			*ft_image_carry_from(void *img_ptr, char **addr, int bpp, int sizel, int endian);

typedef struct			s_drawable
{
	void				*drawable;
	t_drawable_types	type;
}						t_drawable;

t_drawable				*ft_init_drawable(t_drawable_types type, void *value);

typedef struct			s_drawables
{
	t_drawable			*drawable;
	struct s_drawables	*next;
}						t_drawables;

typedef struct			s_text
{
	char				*text;
	t_color				color;
	t_point2d			pos;
}						t_text;

t_text					*ft_init_text(t_point2d pos, char *text, t_color color);

typedef struct			s_button
{
	t_drawable			*child;
	char				*(*image)(struct s_button *, t_point2d, t_image_carry *);
	void				(*onclick)();
	t_color				background_color;
	t_dim2d				dim;
	t_point2d			pos;
}						t_button;

typedef struct			s_container
{
	t_drawables			*childs;
	t_image_carry		*(*render)(struct s_container *, void *, void *, t_image_carry *);
	char				*(*image)(struct s_container *, t_point2d, t_image_carry *);
	void				(*add_child)(struct s_container *, t_drawable *);
	t_color				background_color;
	t_dim2d				dim;
	t_point2d			pos;
}						t_container;

t_container				*ft_init_container(t_point2d pos, t_dim2d dim, t_color color);

t_image_carry			*mlx_container_render(t_container *container, void *mlx_ptr, void *win_ptr, t_image_carry *old);

t_drawable				*mlx_container_to_drawable(t_container *container);

void					mlx_container_background(t_container *c, t_point2d o, t_image_carry *carry);

void					ft_add_drawable_to_drawables(t_drawables *dest, t_drawable *src);

int						ft_drawable_routerender(t_drawable drawable, t_point2d offset, void *);

t_image_carry			*ft_image_merge(t_image_carry *dest, t_point2d offset, t_image_carry *src);

t_image_carry			*ft_image_router(t_drawable *drawable, t_image_carry *dest);

void					ft_put_pixel_to_image(t_image_carry *carry, size_t x, size_t y, unsigned int color);

#endif
