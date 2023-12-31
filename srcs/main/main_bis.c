/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:42:37 by wfreulon          #+#    #+#             */
/*   Updated: 2023/11/29 17:42:38 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fork_or_not(t_mini *minsh)
{
	if (minsh->nb_cmd == 1)
	{
		if ((minsh->cmds)[0].cmd)
		{
			if ((minsh->cmds)[0].cmd[0])
			{
				if (ft_strncmp((minsh->cmds)[0].cmd[0], "cd", 3) == 0)
					return (1);
				else if (ft_strncmp((minsh->cmds)[0].cmd[0], "export", 7) == 0)
				{
					if (size_double_tab((minsh->cmds)[0].cmd) > 1)
						return (1);
				}
				else if (ft_strncmp((minsh->cmds)[0].cmd[0], "unset", 6) == 0)
					return (1);
				else if (ft_strncmp((minsh->cmds)[0].cmd[0], "exit", 5) == 0)
					return (1);
			}
		}
	}
	return (0);
}

void	ft_start_main(int argc, char **argv, char **envp, t_mini *mini)
{
	signal(SIGINT, handle_ctrlc);
	signal(SIGQUIT, SIG_IGN);
	(void)argv;
	if (argc > 1)
	{
		printf("too many argument");
		exit(1);
	}
	mini->envp = realloc_envp(envp);
	mini->act_fd = -1;
	stat_pointer(mini);
}

int	ft_line_empty(char *line, int todo)
{
	if (!todo)
	{
		if (line[0] == '\0')
		{
			free(line);
			return (1);
		}
		return (0);
	}
	else
	{
		if (line == NULL)
		{
			printf("exit\n");
			return (1);
		}
		return (0);
	}
}
