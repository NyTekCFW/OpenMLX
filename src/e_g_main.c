/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:05:05 by lchiva            #+#    #+#             */
/*   Updated: 2024/07/17 15:03:27 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/openmlx.h"

void	register_images(void)
{
	t_ml	*lx;

	lx = gmlx(ACT_GET);
	if (lx)
	{
		create_img((t_ui){lx->width, lx->height, 0}, fill_img_color, "framework");
		register_img("./textures/fonts/monospace_ttf.xpm");
		split_image("/monospace_ttf.xpm", "monospace_", 32, 0);
	}
}

//Setup Exemple
int	main(void)
{
	t_ml		*lx;
	t_prim		c;

	lx = gmlx(ACT_INIT);
	if (lx)
	{
		lx->purge_color = 0x7f7f7f;
		if (lx->set_win_size(600, 600) && lx->make_window("OpenMLX Showcase"))
		{
			register_images();
			c = ml_begin(ML_PRIM_TRIANGLES);
			ml_color(&c, 0xff0000);
			ml_setintensity(&c, 0.6);
			ml_setuv(&c, ML_UV_0);
			ml_vertex(&c, (t_vec2){0, 0});
			ml_vertex(&c, (t_vec2){600, 0});
			ml_vertex(&c, (t_vec2){600, 600});
			ml_savemesh(&c, "framework");
			ml_setmode(&c, ML_MODE_LINE);
			ml_overwrite(&c, 0);
			ml_size(&c, 8);
			ml_end(&c);
			typewritter("framework", "OpenMLX ;)", (t_vec2){5, 300});
			print_img((t_vec2){0, 0}, "framework");
			while (1)
				;
			lx->quit_window();
		}
	}
}
