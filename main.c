/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmalope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 15:22:56 by pmalope           #+#    #+#             */
/*   Updated: 2019/08/27 14:19:49 by pmalope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_check_arg(char *str)
{
	if (str && str[0] == '-' && str[1])
		return (1);
	return (0);
}

void	ft_init_arg(t_option *opt, char *str)
{
	int		i;

	i = 0;
	while (str[++i])
	{
		if (ft_check_opt(str[i], "lRrat") || (str[1] == '-' && !str[2]))
		{
			opt->l = (str[i] == 'l' ? ON : opt->l);
			opt->upper_r = (str[i] == 'R' ? ON : opt->upper_r);
			opt->a = (str[i] == 'a' ? ON : opt->a);
			opt->r = (str[i] == 'r' ? ON : opt->r);
			opt->t = (str[i] == 't' ? ON : opt->t);
		}
		else
			ft_error_opt(str[i]);
	}
}

void	ft_parse_param(int nb, char **arg, t_option *opt, t_list **path)
{
	int		i;
	int		flag;

	i = -1;
	flag = 1;
	while (++i < nb)
	{
		if (ft_check_arg(arg[i + 1]) == 0)
			flag = 0;
		if (flag == 1)
			ft_init_arg(opt, arg[i + 1]);
		else if (flag == 0)
			ft_lstpushback(path, arg[i + 1], ft_strlen(arg[i + 1]));
	}
}

int		main(int argc, char **argv)
{
	t_option	opt;
	t_list		*path;

	opt = (t_option){OFF, OFF, OFF, OFF, OFF};
	path = NULL;
	if (argc > 1)
		ft_parse_param(argc - 1, argv, &opt, &path);
	if (path == NULL)
		path = ft_lstnew(".", ft_strlen("."));
	ft_open_dir(opt, path, path->next != NULL ? 1 : 0);
	free_lists(path);
	sleep(100);
	return (0);
}
