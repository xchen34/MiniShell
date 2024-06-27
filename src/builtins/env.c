/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:03:44 by leochen           #+#    #+#             */
/*   Updated: 2024/06/27 16:03:31 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int env(t_env *minienv)
{
	t_env	*i;

	i = minienv;
	while (i)
	{
		if (ft_strchr(i->key_pair, '='))
			ft_putendl_fd(i->key_pair, STDOUT_FILENO);
		i = i->next;
	}
	return (0);
}