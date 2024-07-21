/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:05:05 by lchiva            #+#    #+#             */
/*   Updated: 2024/07/21 20:19:51 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../OpenMLX/includes/openmlx.h"

void	register_images(void)
{
	t_ml	*lx;

	lx = gmlx(ACT_GET);
	if (lx)
	{
		create_img((t_ui){lx->width, lx->height, 0},
			fill_img_color, "framework");
		register_img("./textures/fonts/monospace_ttf.xpm");
		split_image("/monospace_ttf.xpm", "monospace_", 32, 0);
	}
}

static void	rendering(t_ml *lx)
{
	if (lx)
	{
		fill_shader_color("clear_window", lx->purge_color);
		cpicker_edit(&lx->purge_color);
		if (lx->cpicker.is_open)
		{
			cpicker_show(lx, "clear_window");
			print_img((t_vec2){0}, "clear_window");
		}
		else
			lx->purge_window();
	}
}

void	mouse_pressed(int ks, int x, int y, t_ml *lx)
{
	if (lx)
	{
		if (lx->cpicker.is_open && ks == XK_MOUSE_LEFT_CLICK)
		{
			set_keycode_status(ks, 0);
			cpicker_check_cursor(lx, (t_vec2){x, y});
			return ;
		}
	}
}

// Setup Exemple
int	main(void)
{
	t_ml	*lx;

	lx = gmlx(ACT_INIT);
	if (lx)
	{
		lx->purge_color = 0x7f7f7f;
		if (lx->set_win_size(400, 400) && lx->make_window("OpenMLX Showcase"))
		{
			lx->render_callback = rendering;
			lx->mouse_p_callback = mouse_pressed;
			add_keycode(XK_MOUSE_LEFT_CLICK, NULL);
			add_keycode(XK_p, cpicker_open);
			register_images();
			cpicker_init(lx);
			cpicker_edit(&lx->purge_color);
			start_hook();
			lx->quit_window();
		}
	}
}
