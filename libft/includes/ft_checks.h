/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:12:16 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/10/07 12:13:19 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKS_H
# define FT_CHECKS_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <ctype.h>

int	ft_isalnum(int c);
/*
 * @brief Checks if a character is alphanumeric
 *
 * @param c The character to check
 * @return int 1 if the character is alphanumeric, 0 otherwise
 */

int	ft_isalpha(int c);
/*
 * @brief Checks if a character is alphabetic
 *
 * @param c The character to check
 * @return int 1 if the character is alphabetic, 0 otherwise
 */

int	ft_isascii(int c);
/*
 * @brief Checks if a character is on the ASCII table
 *
 * @param c The character to check
 * @return int 1 if the character is on the ASCII, 0 otherwise
 */

int	ft_isdigit(int c);
/*
 * @brief Checks if a character is a digit
 *
 * @param c The character to check
 * @return int 1 if the character is a digit, 0 otherwise
 */

int	ft_isprint(int c);
/*
 * @brief Checks if a character is printable
 *
 * @param c The character to check
 * @return int 1 if the character is printable, 0 otherwise
 */

#endif