/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:24:29 by leochen           #+#    #+#             */
/*   Updated: 2024/06/04 16:26:28 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	minishell(t_env *minienv)
{
	int		exit_status;
	char	*input;
//	char	**commands;

	exit_status = EXIT_SUCCESS;
	while (1)
	{
		define_main_signals();
		input = do_prompt(minienv);
		//if (has_input_error(input, &exit_status, minienv))
		// 	continue ;
		// handle_expansions(&input, minienv, exit_status);
		// if (!has_pipe(input))
		// 	exit_status = execute_one_command(input, &minienv);
		// else
		// {
		// 	commands = split_commands(input);
		// 	free(input);
		// 	exit_status = execute_multiple_commands(commands, &minienv);
		// 	free_array(commands);
		// }
	}
	return (exit_status);
}