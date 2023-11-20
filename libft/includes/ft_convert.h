/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:12:20 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/11 22:23:10 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERT_H
#define FT_CONVERT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <ctype.h>

int ft_atoi(const char *str);
/**
 * @brief Converts a string to an integer
 *
 * @param str The pointer of the string to convert
 * @return int The integer converted from the string
 */

char *ft_itoa(int n);
/**
 * @brief Converts an integer to a string
 *
 * @param n The integer to convert
 * @return char* The converted integer
 */

int ft_tolower(int c);
/**
 * @brief Converts an uppercase character to a lowercase character
 *
 * @param c The character to convert
 * @return int The converted character
 */

int ft_toupper(int c);
/**
 * @brief Converts a lowecase character to an uppercase character
 *
 * @param c The character to convert
 * @return int The converted character
 */

#endif