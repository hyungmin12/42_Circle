/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shane <shane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:03:41 by youngjpa          #+#    #+#             */
/*   Updated: 2023/04/17 18:42:31 by shane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_main_init(int argc, char **argv)
{
	struct termios	term_sig;

	ft_pica_shell();
	if (argc != 1)
		exit_errno("argument input error", NULL, 126);
	tcgetattr(STDIN_FILENO, &term_sig);
	term_sig.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term_sig);
	set_signal(SHE, SHE);
	g_exit_signal_code = 0;
	(void)argc;
	(void)argv;
}

void	ft_pica_shell(void)
{
	printf("⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛🟨🟨🟨🟨⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜\n");
	printf("⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛🟨🟨🟨⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛\n");
	printf("⬛⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛🟨🟨⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛\n");
	printf("⬛⬛⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛🟫🟫⬛⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛\n");
	printf("⬛⬛⬛⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛🟫🟫⬛⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬛\n");
	printf("⬛⬛⬛⬛🟨🟨⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛🟫⬛⬜⬜⬜⬜⬜⬜⬛🟨🟨⬛⬛⬛\n");
	printf("⬜⬛⬛🟨🟨🟨🟨⬛⬜⬜⬜⬜⬛⬛⬛⬛⬛⬛⬛⬛⬜⬜⬜⬜⬛🟨🟨🟨🟨⬛⬛\n");
	printf("⬜⬛⬛🟨🟨🟨🟨🟨⬛⬜⬛⬛🟨🟨🟨🟨🟨🟨🟨🟨⬛⬛⬜⬛🟨🟨🟨🟨🟨⬛⬛\n");
	printf("⬜⬜⬛🟨🟨🟨🟨🟨🟨⬛⬛⬛⬛🟨🟨🟨🟨🟨🟨⬛⬛⬛⬛🟨🟨🟨🟨🟨🟨⬛⬜\n");
	printf("⬜⬜⬜⬛🟨🟨🟨🟨⬛⬛🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨⬛⬛🟨🟨🟨🟨⬛⬜⬜\n");
	printf("⬜⬜⬜⬛⬛🟨⬛🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨⬛🟨⬛⬛⬜⬜\n");
	printf("⬜⬜⬜⬛🟨⬛🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨⬛🟨⬛⬜⬜\n");
	printf("⬜⬜⬛⬛⬛🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨⬛⬛⬛⬜\n");
	printf("⬜⬛⬛🟨⬛🟨🟨🟨🟨⬛⬛🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨⬛⬛🟨🟨🟨🟨⬛🟨⬛⬛\n");
	printf("⬛🟨⬛🟨⬛🟨🟨🟨⬛⬜⬛⬛🟨🟨🟨🟨🟨🟨🟨🟨⬛⬛⬜⬛🟨🟨🟨⬛🟨⬛🟨\n");
	printf("⬛🟨🟨🟨⬛🟨🟨🟨⬛⬛⬛⬛🟨🟨🟨🟨🟨🟨🟨🟨⬛⬛⬛⬛🟨🟨🟨⬛🟨🟨🟨\n");
	printf("⬜⬛🟨⬛🟨🟨🟨🟨🟨⬛⬛🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨⬛⬛🟨🟨🟨🟨🟨⬛🟨⬛\n");
	printf("⬜⬛🟨⬛🟨🟨🟥🟥🟨🟨🟨🟨🟨🟨🟨⬛⬛🟨🟨🟨🟨🟨🟨🟨🟥🟥🟨🟨⬛🟨⬛\n");
	printf("⬜⬜⬛⬛🟨🟥🟥🟥🟥🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟥🟥🟥🟥🟨⬛⬛⬜\n");
	printf("⬜⬜⬜⬜⬛🟥🟥🟥🟥🟨🟨🟨⬛🟨🟨⬛⬛🟨🟨⬛🟨🟨🟨🟥🟥🟥🟥⬛⬜⬜⬜\n");
	printf("⬜⬜⬜⬜⬛🟨🟥🟥🟨🟨🟨🟨🟨⬛⬛🟨🟨⬛⬛🟨🟨🟨🟨🟨🟥🟥🟨⬛⬜⬜⬜\n");
	printf("⬜⬜⬜⬜⬜⬛🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨⬛⬜⬜⬜⬜ created\n");
	printf("⬜⬜⬜⬜⬜⬛⬛⬛🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨⬛⬛⬛⬜⬜⬜⬜ by\n");
	printf("⬜⬜⬜⬜⬜⬜⬛🟨⬛⬛⬛🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨⬛⬛⬛🟨⬛⬜⬜⬜⬜⬜ hyyoo\n");
	printf("⬜⬜⬜⬜⬜⬜⬛🟨🟨🟨🟨🟨⬛⬛⬛⬛⬛⬛⬛⬛🟨🟨🟨🟨🟨⬛⬜⬜⬜⬜⬜ youngjpa\n\n");
}

void	ft_minishell(char *input, t_cmd_info *cmd, t_env_info info_env)
{
	while (42)
	{
		input = readline("\033[33mminishell $ \033[0m");
		if (!input)
			break ;
		if (*input != '\0')
			add_history(input);
		if (*input != '\0' && !ft_str_isspace(input))
		{
			cmd = ft_cmd_init();
			ft_parse(input, cmd);
			ft_tokenize(cmd, &info_env);
			ft_arg_check(&cmd);
			execute(cmd, &info_env);
			ft_free_list(cmd);
		}
		free(input);
	}
}

int	main(int argc, char **argv, char **envp)
{
	struct termios		term_sig;
	char				*input;
	t_cmd_info			*cmd;
	t_env_info			info_env;

	input = NULL;
	cmd = NULL;
	tcgetattr(STDIN_FILENO, &term_sig);
	ft_main_init(argc, argv);
	ft_env_init(&info_env, envp);
	ft_minishell(input, cmd, info_env);
	tcsetattr(STDIN_FILENO, TCSANOW, &term_sig);
}
