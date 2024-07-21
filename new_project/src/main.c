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

// Setup Exemple
int	main(void)
{
	t_ml	*lx;

	lx = gmlx(ACT_INIT);
	if (lx)
	{
		lx->purge_color = 0x7f7f7f;
		if (lx->set_win_size(400, 400) && lx->make_window("OpenMLX Base"))
		{
			register_images();
			start_hook();
			lx->quit_window();
		}
	}
}
