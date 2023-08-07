/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:33:26 by wfreulon          #+#    #+#             */
/*   Updated: 2023/07/29 19:46:09 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_mini	mini;
	
	(void)argc;
	(void)argv;
	mini.paths = findpath(envp);
	mini.exit = 0;
	while (mini.exit == 0)
	{
		mini.input = readline("minishell ➤ ");
		if (mini.input != NULL && *mini.input != '\0')
		{
			add_history(mini.input);
		}
		if (!ft_strncmp(mini.input, "exit", 4))
			mini.exit = 1;
		printf("%s\n", spaceit(mini.input));
	}
}
