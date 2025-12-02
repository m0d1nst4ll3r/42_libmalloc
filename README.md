# libmalloc

This lib aims to simplify the use of `malloc()`. It provides functions to malloc, free, and most importantly free all allocated memory (usually before an `exit()`).

It only requires adding a `t_libmlc` to your program, which will be used by the lib's functions to track a list of allocated memory.

System calls used are only malloc and free.

### t_libmlc structure

```
typedef struct s_libmlc
{
	void			*tab[LIBMLC_SIZE];
	struct s_libmlc	*next;
}t_libmlc;
```

`LIBMLC_SIZE` is defined by default as `64`.

`tab` contains the list of allocated addresses.

### public functions

`void	*libmlc_malloc(t_libmlc **libmlc, size_t size);`

Allocates `size` bytes using `malloc()` and returns the address.

Returns NULL in case of error (you should probably `libmlc_free_all`).

`void	libmlc_free(t_libmlc **libmlc, void *p);`

Frees allocated address `p` using `free()`.

`void	libmlc_free_all(t_libmlc **libmlc);`

Frees all allocated addresses (sets libmlc to `NULL`).

### usage

Clone this repo in your project and add `libmalloc.a` to your Makefile, along a `$(MAKE) -C libmalloc`.

Add a `t_libmlc *libmlc` in your program structure, init to `NULL`.

Anytime you would normally malloc, use `libmlc_malloc()` instead, anytime you'd free, use `libmlc_free()`. When you wish to free all, use `libmlc_free_all()`.
