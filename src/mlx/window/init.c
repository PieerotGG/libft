/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 23:39:18 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/21 01:58:27 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/window.h"

static int			null_hook()
{
	return (0);
}

static void			add_keyboard_hook(t_window *window, int (*f)(int, void *))
{
	ft_lstadd(&window->keyboard_hooks, ft_lstnew(f, sizeof(f)));
}

static void			add_lkeyboard_hook(t_window *window, int (*f)(int, void *))
{
	ft_lstadd(&window->lkeyboard_hooks, ft_lstnew(f, sizeof(f)));
}

static void			add_mouse_hook(t_window *window, int (*f)(int, int, int, void *))
{
	ft_lstadd(&window->mouse_hooks, ft_lstnew(f, sizeof(f)));
}

t_window			*ft_init_window()
{
	t_window		*win;

	if (!(win = (t_window *)malloc(sizeof(t_window))))
		return (NULL);
	win->render = NULL;
	win->keyboard_hooks = ft_lstnew(null_hook, sizeof(null_hook));;
	win->add_keyboard_hook = add_keyboard_hook;
	win->lkeyboard_hooks = ft_lstnew(null_hook, sizeof(null_hook));
	win->add_lkeyboard_hook = add_lkeyboard_hook;
	win->mouse_hooks = ft_lstnew(null_hook, sizeof(null_hook));;
	win->add_mouse_hook = add_mouse_hook;
	win->width = DEFAULT_WIDTH;
	win->should_render_every_frame = true;
	win->height = DEFAULT_HEIGHT;
	win->ptr = NULL;
	win->next = NULL;
	return (win);
}