# libmalloc

This lib aims to simplify the use of `malloc()`. It provides functions to **malloc** (`libmalloc_malloc()`), **free** (`libmalloc_free()`), and most importantly **free all allocated memory** (`libmalloc_free_all()`, usually before an `exit()`).

It only requires adding a `t_libmlc` variable to your program, which will be used by the lib's functions to track a list of pointers.

This improved version uses **exit**, along with **malloc** and **free**. For a version without **exit**, go back to V1.1.

If **libmalloc** catches any malloc failure, it will automatically `libmalloc_free_all()` and `exit()`. You do not have to protect your mallocs if you use `libmalloc_malloc()`, it will do it for you.

### t\_libmlc structure

```
typedef struct s_libmlc
{
	void			*tab[LIBMLC_SIZE];
	int				avail;
	struct s_libmlc	*next;
}t_libmlc;
```

`tab` contains the list of allocated addresses. `avail` is the number of free slots in `tab`.

`LIBMLC_SIZE` is defined by default as `32`.

### Public functions

`void	*libmlc_malloc(t_libmlc **libmlc, size_t size);`

Allocates `size` bytes using `malloc()` and returns the address.

Frees all and exits in case of error (you do not have to protect this call, it will never return `NULL`).

`void	libmlc_free(t_libmlc **libmlc, void *p);`

Frees allocated address `p` using `free()`.

`void	libmlc_free_all(t_libmlc **libmlc);`

Frees all allocated addresses (sets `libmlc` to `NULL`).

### Usage

Clone this repo in your project and add `libmalloc.a` to your **Makefile**, along a `$(MAKE) -C libmalloc`.

Add a `t_libmlc *libmlc` in your program structure, init to `NULL`.

Anytime you would normally malloc, use `libmlc_malloc()` instead, anytime you'd free, use `libmlc_free()`. When you wish to free all, use `libmlc_free_all()`.

### Technicals

**libmalloc** simply adds `malloc()`'ed addresses to `tab` before passing them to the user. It parses `tab`, looking for the first available slot to insert the new address. If there is no available slot, it simply creates a new node in the list. Since nodes are added at the front, newer addresses will be checked first during removal operations.

When it has to remove (free) an address, it has to parse the entire list to find it, which will take more time the longer the list (especially if the address is old). A lower LIBMLC\_SIZE will push newer addresses to the front of the list faster, but it will use a bit more memory. None of these considerations should really matter unless you are looking for extreme optimization.
