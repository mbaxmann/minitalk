/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:38:53 by user42            #+#    #+#             */
/*   Updated: 2021/09/26 16:55:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(ft_strlen((char *)s1) + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen((char *)s1))
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_size(char const *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	result = (char *)malloc((ft_size(s1) + ft_size(s2) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (s1 && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	if (s1)
		free((char *)s1);
	if (s2)
		free((char *)s2);
	return (result);
}
