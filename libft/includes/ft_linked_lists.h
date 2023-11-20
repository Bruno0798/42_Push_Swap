/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_lists.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:59:39 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/11 16:46:57 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LINKED_LISTS_H
#define FT_LINKED_LISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <ctype.h>
#include <stddef.h>

typedef struct s_list
{
	void *content;
	struct s_list *next;
} t_list;
/**
 * @brief A linked list node.
 *
 * @param content The content of the node
 * @param next The next node in the list
 */

void ft_lstadd_back(t_list **lst, t_list *new);
/**
 * @brief Adds a new element to the end of a linked list.
 *
 * @param lst A pointer to a pointer to the linked list
 * @param new The new element to add to the end of the list
 */

void ft_lstadd_front(t_list **lst, t_list *new);
/**
 * @brief Adds a new element to the front of a linked list.
 *
 * @param lst A pointer to a pointer to the linked list
 * @param new The new element to add to the front of the list
 */

void ft_lstclear(t_list **lst, void (*del)(void *));
/**
 * @brief Deletes all the nodes of the list.
 *
 * @param lst A pointer to the first node of the list
 * @param del The function pointer to apply to each node
 */

void ft_lstdelone(t_list *lst, void (*del)(void *));
/**
 * @brief Deletes a single element from a linked list and frees
 * its content using the provided 'del' function.
 *
 * @param lst The element to be deleted
 * @param del The function pointer to apply to each node
 */

void ft_lstiter(t_list *lst, void (*f)(void *));
/**
 * @brief Iterates over a linked list and applies a
 * function 'f' to each element.
 *
 * @param lst The linked list to iterate over
 * @param f The function pointer to apply to each node
 */

t_list *ft_lstlast(t_list *lst);
/**
 * @brief Returns a pointer to the last element of a linked list.
 *
 * @param lst The linked list to find the last element in
 * @return A pointer to the last element, or NULL if 'lst' is empty
 */

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
/**
 * @brief Applies a function 'f' to each element in a linked list
 * and creates a new list with the results.
 *
 * @param lst The linked list to map
 * @param f A function to apply to the content of each element
 * @param del A function to free the content of an element in case of failure
 * @return A new linked list with elements transformed by 'f',
 * 		or NULL on failure
 */

t_list *ft_lstnew(void *content);
/**
 * @brief Creates a new linked list element with the provided content.
 *
 * @param content The content to be stored in the new element
 * @return A pointer to the new linked list element, or NULL on memory
 * 		allocation failure
 */

int ft_lstsize(t_list *lst);
/**
 * @brief Returns the number of elements in a linked list.
 *
 * @param lst The linked list for which to count the elements
 * @return The number of elements in the linked list,
 * 		or 0 if 'lst' is empty
 */
#endif