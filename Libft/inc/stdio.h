/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdio.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 22:13:45 by dmontema          #+#    #+#             */
/*   Updated: 2022/01/28 18:31:00 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDIO_H
# define	STDIO_H

# include "ft_printf.h"
# include "get_next_line.h"

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#	endif
