/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:12:39 by mbatteux          #+#    #+#             */
/*   Updated: 2023/09/20 18:12:41 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define RDM "/dev/urandom"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_cmd
{
	int		num;
	char	**argv;
	char	*true_path;
}			t_cmd;

typedef struct s_data
{
	char	**all_path;
	int		nbr;
	pid_t	*pid;
}		t_data;


void	find_path(t_data *pip);
char	*get_access(t_data *pip, char *argv);
// void	proc_1(t_data *pip, char **env, char **argv, int *pipe_fd);
// void	proc_2(t_data *pip, char **env, char **argv, int *pipe_fd);

#endif
