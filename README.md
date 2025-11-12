# libmalloc

Functions to use malloc, add malloc'd adresses to a struct, free those mallocs one by one (removing addresses), and free all (usually before your program exits, or on error). This version does not use exit since it is forbidden in early 42 projects.
System calls are malloc and free.

### structure

`LIBMLC_SIZE` is defined by default as `64`

tab contains malloc'd adresses

the list is chained

```
typedef struct s_libmlc
{
	void			*tab[LIBMLC_SIZE];
	struct s_libmlc	*next;
}t_libmlc;
```

### public functions

`void	*libmlc_malloc(t_libmlc **libmlc, size_t size);`

Allocates size bytes using malloc and returns the address.

Returns NULL in case of error (you should `libmlc_free_all`).

`void	libmlc_free(t_libmlc **libmlc, void *p);`

Frees p using free.

`void	libmlc_free_all(t_libmlc **libmlc);`

Frees all malloc'd addresses and empties the list (sets libmlc to `NULL`).

### usage

Clone this repo in your project and add `libmalloc.a` to your Makefile, along a `make -C libmalloc`.

Add a `t_libmlc *libmlc` in your program structure, init to `NULL`.

Anytime you would normally malloc, use `libmlc_malloc` instead, anytime you'd free, use `libmlc_free`. When you wish to free all, use `libmlc_free_all`.
