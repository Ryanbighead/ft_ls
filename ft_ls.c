/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 09:11:50 by rhutchin          #+#    #+#             */
/*   Updated: 2019/07/02 10:02:43 by rhutchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/ft_ls.h"
#include <dirent.h>     //----------------------------------------------------- Makes the DIR opening, closing and reading magic happen.
#include <sys/stat.h>   //----------------------------------------------------- Makes checking for file stats happen...
#include <sys/types.h>  //----------------------------------------------------- Makes various types available for use...
#include <stdio.h>      //----------------------------------------------------- Delete me mc cheaty

static void ft_ls(char **av)
{
    struct dirent *de;  //----------------------------------------------------- Pointer to the struct which will store the filename.
    struct stat file_info; //-------------------------------------------------- Making a struct which stores the current files stats (user, time, type, permissions etc.)
    
    DIR *dr = opendir(".");  //------------------------------------------------ returns a DIR pointer.
  
    if (dr == NULL) //--------------------------------------------------------- Breaks when nothing 
        printf("The bad has happened -_- you are nowhere\n" ); 

    while ((de = readdir(dr)) != NULL) 
    {
        lstat(de->d_name, &file_info);
        if((de->d_name[0] == '.') && (ft_strcmp("-a", av[2]) != 0)) //--------- Checking for Dir's
             continue;
        if (file_info.st_mode == S_IFDIR)//------------------------------------ Do the stuff
            
        else
            printf("%9s", de->d_name);
    }
    printf("\n");
    closedir(dr);
}

int main (int ac, char **av)
{
    if (ac < 1)
        {
            printf("how?!?!?!?!?\n");
            return (0);
        }
    ft_ls(av);
    return (0);    
}