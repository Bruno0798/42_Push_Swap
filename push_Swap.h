/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_Swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:04:33 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/10 22:56:58 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft.h"

typedef struct s_stack
{
	long content;
	struct s_stack *next;
} t_stack;

void ft_check_args(char **argv, t_stack *stack);

#endif