/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:01:00 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/10/07 12:21:22 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
/**
 * @brief Reads the next line from a file descriptor 'fd'.
 *
 * @param fd The file descriptor from which to read the next line
 * @return The next line, or NULL if there are no more lines or an error occurs
 */

char	*ft_read_and_join(int fd, char *temp);
/**
 * @brief Reads data from a file descriptor 'fd' and joins
 * it with the 'temp' buffer.
 *
 * @param fd The file descriptor from which to read data
 * @param temp The current string to which data is appended
 * @return The joined string, or NULL on error or end of file
 */

char	*new_temp(char *temp);
/**
 * @brief Creates a new 'temp' string by removing the first line from 'temp'.
 *
 * @param temp The original string from which to remove the first line
 * @return The new 'temp' string, or NULL if 'temp' is empty or doesn't contain
 *			a newline character
 */

char	*ft_get_line(char *temp);
/**
 * @brief Extracts a line from a string 'temp'.
 *
 * @param temp The string from which to extract a line
 * @return The extracted line as a new string, or NULL on 
 * memory allocation failure
 */

char	*join(char *temp, char *buffer);
/**
 * @brief Joins two strings 'temp' and 'buffer' together.
 *
 * @param temp The first string
 * @param buffer The second string to append to 'temp'
 * @return The concatenated string, or NULL on memory allocation failure
 */

char	*ft_get_char(char *str, char fetch);
/**
 * @brief Searches for a character 'fetch' in a string 'str'.
 *
 * @param str The string in which to search for 'fetch'
 * @param fetch The character to search for
 * @return A pointer to the first occurrence of 'fetch', or NULL
 * if not found or 'str' is NULL
 */

#endif