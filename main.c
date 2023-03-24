/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:48:28 by nrossel           #+#    #+#             */
/*   Updated: 2023/03/24 13:27:24 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_data	data;
	(void) ac;
	(void) envp;

	// data.args = ("ls", "-l", NULL);
	// data.cmd = "ls";
	//data.envp = /Users/nrossel/.brew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki:/Library/Apple/usr/bin;
	pipe(data.fd1);
	if (!(access("infile", F_OK | R_OK) == 0 || access("outfile", F_OK | W_OK) == 0))
	{
		perror("Access infile | outfile: denied");
		exit(1);
	}
	data.infile = open(av[1], O_RDONLY);
	data.outfile = open(av[2], O_WRONLY);
	if (data.infile == 0 || data.infile < 0
		|| data.outfile == 0 || data.outfile < 0)
		{
			perror("infile | outifile not open");
			exit(2);
		}
	data.pid1 = fork();
	if (data.pid1 < 0)
	{
		perror("fork pid1: ");
		exit(3);
	}
	if (!data.pid1)//Child_process();
	{
		pipe(data.fd2);
		data.pid2 = fork();
		if (data.pid2 < 0)
		{
			perror("fork pid2: ")
			exit(4);
		}
		if (!data.pid2) // Child1 / 1er args (ls -l)
		{
			close(data.fd2[0]); // close read side of pipe2
			dup2(data.infile, 0); // infile is new stdin
			dup2(2, data.fd2[1]); // write side of pipe2 is new stdout
			close(data.infile); // close unused file
			close(data.outfile); // close unused file
			read(0, &data.buffer, sizeof(data.buffer)); // read from infile
			ft_printf("Child1 process : %s", data.buffer);
			execve("/bin/ls", NULL, NULL);

		}
		else // child2 - main / 2ème args (cw -l)
		{
			close(data.infile); // close unused file
			close(data.outfile); // close unused file
			close(data.fd2[1]); // close write side of pipe2
			dup2(0, data.fd2[0]); // read side of pipe2 is new stdin
			dup2(1, data.fd1[1]); // write side of pipe1 is new stdout
			read(0, &data.buffer, sizeof(data.buffer));
			ft_printf("child2 - main process : %s", data.buffer);
			exeve("/usr/bin/wc", NULL, NULL);
		}
	}
	else (data.pid1) //Main_process();
	{
		close(data.fd1[1]); // close write side
		dup2(data.outfile, 1); // outfile is new stdout
		close(data.infile); // close unused file
		close(data.outfile); // close unused file
		wait(&data.pid1); // wait until child process finish
		while (read(data.fd1[0], data.buffer, sizeof(data.buffer)) != 0) // read from child process by pipe fd[0]
		{
			printf("Main process : %s", data.buffer);
			write(1, &data.buffer, sizeof(data.buffer)); // write to outfile
		}
		close(data.fd1[0]);
	}
	//execve(data.cmd, data.args, data.envp);
}
