/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 10:44:13 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/02 10:53:27 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/libft.h"

typedef struct      s_file
{
    char            *file_name;
    struct dirent   *de;
    struct s_file   *next;
    struct s_file   *previous;
}                   t_file;

t_file  *ft_newnode(char *file_name, struct dirent *de);
void    ft_addnode(t_file *node, char *file_name, struct dirent *de);
void    ft_sortlist(t_file *list);

#endif
