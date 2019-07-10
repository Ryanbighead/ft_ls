/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listfunctions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 10:23:08 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/10 14:30:11 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

t_file  *ft_newnode(char *file_name, struct stat stats)
{
    t_file     *new;

	new = malloc(sizeof(t_file));
	new->attributes = ft_convertAtt(stats);
	new->file_name = ft_strdup(file_name);
	new->links = stats.st_nlink;
	new->userID = ft_convertUID(stats);
	new->groupID = ft_convertGID(stats);
	new->size = stats.st_size;
	new->rawtime = stats.st_mtime;
	ft_convertTime(new);
	new->next = NULL;
	new->previous = NULL;
	return (new);
}

t_file    *ft_addnode(t_file *head, char *file_name, struct stat stats)
{
	t_file	*scanner;
	t_file	*tmp;

	if(head == NULL)
		head = ft_newnode(file_name, stats);
	else
	{
		scanner = head;
		while(scanner != NULL)
		{
			tmp = scanner;
			scanner = scanner->next;
		}
		tmp->next = ft_newnode(file_name, stats);
		tmp->next->previous = tmp;
	}
	return (head);
}

void	ft_dellist(t_file *head)
{
	t_file	*scanner = head;
	t_file	*tmp;

	while(scanner != NULL)
	{
		tmp = scanner->next;
		ft_strdel(&scanner->attributes);
		ft_strdel(&scanner->file_name);
		scanner->links = 0;
		ft_strdel(&scanner->userID);
		ft_strdel(&scanner->groupID);
		scanner->time = 0;
		ft_strdel(&scanner->day);
		ft_strdel(&scanner->month);
		ft_strdel(&scanner->year);
		ft_strdel(&scanner->time);
		scanner->previous = NULL;
		scanner->next = NULL;
		scanner = tmp;
	}
}
