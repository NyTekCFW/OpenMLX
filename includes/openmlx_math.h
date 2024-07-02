/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openmlx_math.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:51:42 by lchiva            #+#    #+#             */
/*   Updated: 2024/06/19 15:31:24 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPENMLX_MATH_H
# define OPENMLX_MATH_H

typedef struct vec2_s
{
	int	x;
	int	y;
}	t_vec2;

typedef struct vec2f_s
{
	double	x;
	double	y;
}	t_vec2f;

typedef struct vec3_s
{
	int	x;
	int	y;
	int	z;
}	t_vec3;

typedef struct vec4_s
{
	int	x;
	int	y;
	int	z;
	int	w;
}	t_vec4;

void		set_value(void *adr, __uint32_t val);
__uint32_t	get_value(void *adr);
float		dist(t_vec2f a, t_vec2f b);
#endif