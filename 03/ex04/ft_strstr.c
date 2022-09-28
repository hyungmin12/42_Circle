/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:34:50 by hyyoo             #+#    #+#             */
/*   Updated: 2022/05/25 19:35:11 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] && str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}
/*
int main()
{
printf("======ex04======\n");
char str[20] = "abcabcabcdabc";
char to_find[20] = "abcd";
char str1[20] = "hello hello";
char to_find1[20] = "o h";
printf("%s %s\n", strstr(str, to_find), ft_strstr(str, to_find));
printf("%s %s\n", strstr(str1, to_find1), ft_strstr(str1, to_find1));
}*/
