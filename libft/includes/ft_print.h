/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:12:27 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/10/07 12:18:06 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <ctype.h>
# include <stdint.h>
# include <stdarg.h>

void	ft_putchar_fd(char c, int fd);
/**
 * @brief
 * 		Outputs the character c to the file descriptor fd.
 *
 * @param c The character to output
 * @param fd The file descriptor on which to write
 */

void	ft_putendl_fd(char *s, int fd);
/**
 * @brief Outputs the string s to the file descriptor fd, followed by
 * a newline.
 *
 * @param s The string to output
 * @param fd The file descriptor on which to write
 */

void	ft_putnbr_fd(int n, int fd);
/**
 * @brief Outputs the integer n to the file descriptor fd.
 *
 * @param n The integer to output
 * @param fd The file descriptor on which to write
 */

void	ft_putstr_fd(char *s, int fd);
/**
 * @brief Outputs the string s to the file descriptor fd.
 *
 * @param s The string to output
 * @param fd The file descriptor on which to write
 */

int		ft_print_char(int c);
/**
 * @brief Prints a character to the standard output.
 *
 * @param c The character to be printed.
 * @return On success, the number of bytes written is returned (1).
 * On error, -1 is returned.
 */

int		ft_print_decimal(int c);
/**
 * @brief Prints an integer as a decimal number to the standard output.
 *
 * @param c The integer to be printed as a decimal number.
 * @return
 * 		On success, the number of characters written is returned
 * 			(excluding the null terminator).
 *  	On error, -1 is returned.
 */

int		ft_print_hexadecimal(unsigned int c, char casing);
/**
 * @brief Conversion and printing of unsigned integers as hexadecimal numbers.
 *
 * @param c The unsigned integer to be printed as a hexadecimal number.
 * @param casing The casing style for hexadecimal digits ('a' for lowercase,
 * 'A' for uppercase).
 * @return
 * 		On success, the number of characters written (excluding the null 
 * 			terminator) is returned.
 *   	On error, -1 is returned.
 */

int		ft_print_percentage(void);
/**
 * @brief Prints a percentage symbol ('%') to the standard output.
 *
 * @return
 * 		On success, the number of characters written is returned (1).
 * 		On error, -1 is returned.
 */

int		ft_print_pointer(unsigned long c);
/**
 * @brief Prints the hexadecimal representation of an unsigned long 'c'
 * as a pointer.
 *
 * This function prints the hexadecimal representation of 'c' as a pointer,
 * including the "0x" prefix. If 'c' is zero, it prints "(nil)".
 *
 * @param c The unsigned long integer to print as a pointer
 * @return The total number of characters printed, including the "0x" prefix
 * 			or "(nil)"
 */

int		ft_print_string(char *s);
/**
 * @brief Prints a null-terminated string to the standard output.
 *
 * @param s The null-terminated string to print
 * @return The number of characters printed (excluding the null terminator)
 */

int		ft_print_unsigned_decimal(unsigned int c);
/**
 * @brief Prints an unsigned integer 'c' as a decimal number.
 *
 * @param c The unsigned integer to print as a decimal number
 * @return The number of characters printed (excluding the null terminator)
 */

char	*ft_itoa_long(unsigned int n);
/**
 * @brief Converts an unsigned integer 'n' to a string representation.
 *
 * @param n The unsigned integer to convert to a string
 * @return A dynamically allocated string representation of 'n', or NULL
 * on allocation failure
 */

int		ft_printf(const char *str, ...);
/**
 * @brief Prints formatted text to the standard output.
 *
 * This functions accepts a format string and variable arguments,
 * similar to printf, and processes it, printing the formatted text
 * to the standard output.
 * Supported format specifiers:
 * - 'c': Print a character.
 * - 's': Print a string.
 * - 'p': Print a pointer.
 * - 'd' or 'i': Print a signed integer.
 * - 'u': Print an unsigned integer.
 * - 'x': Print an unsigned integer in hexadecimal (lowercase).
 * - 'X': Print an unsigned integer in hexadecimal (uppercase).
 * - '%': Print a '%' character.
 *
 * @param str The format string to process
 * @param ... Variable arguments list
 * @return The number of characters printed
 */

#endif