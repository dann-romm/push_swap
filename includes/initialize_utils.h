/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_utils.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:44:46 by doalbaco          #+#    #+#             */
/*   Updated: 2022/01/11 17:58:12 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZE_UTILS_H
# define INITIALIZE_UTILS_H

# include <stdlib.h>
# include <unistd.h>
# include "push_swap.h"

int		display_error(int code);
t_state	*free_state(t_state **state);
t_state	*initialize_state(int *args, int len);

#endif
