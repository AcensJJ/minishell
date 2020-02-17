/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:55:35 by jacens            #+#    #+#             */
/*   Updated: 2020/02/17 14:08:42 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_change_first_caract(t_list **list)
{
	t_list	*carac;
	t_list	*commande;
	t_list	*space;
	t_list	*file;
	t_list	*tmp;

	carac = *list;
	tmp = carac;
	while (tmp->next->next &&
	(((t_tag *)(tmp->next->next->next->content))->tag == -62
	|| ((t_tag *)(tmp->next->next->next->content))->tag == -63 ||
	((t_tag *)(tmp->next->next->next->content))->tag == -60))
		tmp = tmp->next->next->next;
	if (tmp->next->next != NULL)
	{
		file = tmp->next;
		space = file->next;
		commande = space->next;
		tmp = commande->next;
		file->next = tmp;
		commande->next = space;
		space->next = carac;
		*list = commande;
	}
}

static void	ft_resize_cmd_for_dir(t_list **list, t_list *tmp)
{
	t_list	*back;
	t_list	*prev;

	if ((ft_count_nb_redir(tmp) > 0 || ft_count_nb_redir2(tmp) > 0)
	&& !(((t_tag *)(tmp->content))->tag != -62 &&
	((t_tag *)(tmp->content))->tag != -63 &&
	((t_tag *)(tmp->content))->tag != -60))
		ft_change_first_caract(list);
	back = *list;
	prev = back;
	while (back)
	{
		tmp = prev;
		while (back && ((t_tag *)(back->content))->tag != -59)
			back = back->next;
		ft_remove_all_multi_dir(ft_count_nb_redir(tmp->next), tmp);
		ft_remove_all_multi_dirbis(ft_count_nb_redir(tmp->next), tmp);
		ft_remove_all_multi_dir2(ft_count_nb_redir2(tmp->next), tmp);
		ft_remove_all_multi_dir2bis(ft_count_nb_redir2(tmp->next), tmp);
		prev = back;
		back && ((t_tag *)(back->content))->tag == -59 ? back = back->next : 0;
	}
}

int			ft_verif_redir(t_list *list, t_list **command_list, t_list **env,
						char *com)
{
	t_list	*tmp;
	int		i;

	if (ft_check_redir(command_list))
	{
		ft_printf_fd(2, "\033[1;31mminishell\033[0m: error open file\n");
		return (1);
	}
	ft_resize_cmd_for_dir(command_list, *command_list);
	tmp = *command_list;
	if (((t_tag *)(tmp->content))->tag == -62 ||
		((t_tag *)(tmp->content))->tag == -63 ||
		((t_tag *)(tmp->content))->tag == -60)
		ft_remove_start_dir(command_list);
	ft_change_order_list(*command_list);
	tmp = *command_list;
	com = ((t_tag *)(tmp->content))->str;
	i = -1;
	while (com[++i])
		com[i] = ft_tolower(com[i]);
	list = tmp->next;
	if (command_cmp(list, command_list, env, com))
		return (1);
	return (0);
}
