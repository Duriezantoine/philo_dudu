/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <aduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:15:10 by aduriez           #+#    #+#             */
/*   Updated: 2024/04/02 08:16:24 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 45
# endif

int		ft_putnbr(int n);
int		ft_strlen_to_nl(char *str);
int		find_nl(const char *s);
char	*get_next_line(int fd);
char	*ft_next_line(int fd, char *res);
char	*ft_delete_line(char *res);
char	*free_all(char *s1, char *s2, char *s3);
char	*ft_save_line(char *res);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n_long, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isalnum(int c);
int		ft_isascii(int c);
;
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
int		ft_isalpha(int c);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_tolower(int c);
char	*ft_strrchr(const char *s, int c);
;
int		ft_toupper(int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
char	*ft_delete_line(char *res);
char	*ft_save_line(char *res);
int		ft_strlen_to_nl(char *str);
char	*free_all(char *s1, char *s2, char *s3);
char	*ft_next_line(int fd, char *res);

#endif
