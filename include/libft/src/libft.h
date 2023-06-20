/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: SarahLouise <SarahLouise@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 19:21:06 by smclacke      #+#    #+#                 */
/*   Updated: 2023/06/20 18:24:44 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>

//--------------- libft -----------------------//

int		ft_atoi(const char *str);

char	*ft_itoa(int n);

int		ft_isalnum(int c);

int		ft_isalpha(int c);

int		ft_isascii(int c);

int		ft_isdigit(int c);

int		ft_isprint(int c);

char	*ft_strchr(const char *s, int c);

size_t	ft_strlen(const char *s);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

char	*ft_strrchr(const char *s, int c);

int		ft_tolower(int c);

int		ft_toupper(int c);

void	ft_bzero(void *s, size_t n);

void	*ft_memset(void *b, int c, size_t len);

void	*ft_memcpy(void *dst, const void *src, size_t n);

void	*ft_memmove(void *dst, const void *src, size_t len);

void	*ft_memchr(const void *s, int c, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

void	*ft_calloc(size_t count, size_t size);

char	*ft_strdup(const char *s1);

void	ft_putchar_fd(char c, int fd);

void	ft_putendl_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd);

void	ft_putstr_fd(char *s, int fd);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_substr(char const *s, unsigned int start, size_t len);

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

char	*ft_strtrim(char const *s1, char const *set);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char	**ft_split(char const *s, char c);

//--------------- libft_bonus ------------------//

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);

void	ft_lstadd_front(t_list **lst, t_list *new);

int		ft_lstsize(t_list *lst);

t_list	*ft_lstlast(t_list *lst);

void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstdelone(t_list *lst, void (*del)(void *));

void	ft_lstclear(t_list **lst, void (*del)(void *));

void	ft_lstiter(t_list *lst, void (*f)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//----------- get_next_line --------------//

# ifndef OPEN_MAX
#  define OPEN_MAX 42
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	gnl_strlen(const char *s, int temp);

char	*gnl_strdup(const char *s1);

char	*gnl_strjoin(char const *s1, char const *s2);

char	*gnl_strchr(const char *s, int c);

size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize);

char	*get_next_line(int fd);

//-------------- ft_printf ----------------//
int		ft_printf(const char *str, ...);

int		putchar_lower(int c);

int		putchar_upper(int c);

int		print_nbr(long long n, int base);

int		print_nbr2(unsigned long long n, unsigned int base);

int		print_p(unsigned long long n, unsigned int base);

//--------------- Extra ------------------//

int		ft_strcmp(const char *s1, const char *s2);

int		ft_isspace(int c);

int		ft_ishex(int c);

double	ft_atof(char *str);

char	*ft_lower_str(char *str);

char	*ft_upper_str(char *str);

void	ft_putendl(char *s);

void	ft_putstr(char *str);

void	ft_putchar(char c);

int		ft_arrlen(char **arr);

void	ft_error(char *str);

void	ft_free_arr(char **arr);

int		ft_isquote(char c);

#endif
