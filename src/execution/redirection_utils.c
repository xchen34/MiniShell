/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:20:55 by leochen           #+#    #+#             */
/*   Updated: 2024/07/01 17:04:04 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*char	get_redir_symbol(char *s)  //返回的是具体的定向符号 或者返回-1(<<)
{
		int	i;

	i = 0;
	while (s[i])
		{
			if (s[i] == '\'' || s[i] == '\"')
			skip_quotes(s, i, s[i]);
		else if (s[i] == '<' && s[i+1] == '<') // check for '<<'
			return (-1); // return -1 for '<<'
		else if (s[i] == '<' || s[i] == '>')
				return (s[i]);
		i++;
		}
		return (0);
 }*/
char	get_redir_symbol(char *s)
{
	while (*s)
	{
		if (*s == '\'')
		{
			s++;
			while (*s != '\'')
				s++;
		}
		if (*s == '"')
		{
			s++;
			while (*s != '"')
				s++;
		}
		if (*s == '<' || *s == '>' || *s < 0)
			return (*s);
		s++;
	}
	return (0);
}

void	redirect_fd(int fd_to_redirect, int fd_location)
{
	dup2(fd_to_redirect, fd_location);
	close(fd_to_redirect);
}
int if_append(char c)
{
	if (c == '>')
		return (1);
	return (0);
	
}


void initialize_original_fds(int original_fds[2])
{
    original_fds[0] = -1;
    original_fds[1] = -1;
}

int process_redirects(char *cmd, int original_fds[2])
{
    char redir_symbol;
    int result;

    redir_symbol = get_redir_symbol(cmd);
    while (redir_symbol != 0)
    {
        result = process_single_redirect(cmd, redir_symbol, original_fds);
        if (result == 0)
            return result;
        redir_symbol = get_redir_symbol(cmd);
    }
    return 1;
}