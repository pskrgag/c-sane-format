# Sane formatting for C

This is work-in-progress support for sane formatting in C clang front-end. Not intended
to be upstreamed (yet).

Support is added as new builtin, which parses rust-like formatting string and passes
appropriate format specifiers to backing printf-like function.

New builtin has following signature:

```c
void __builtin_print(const char *fmt, int (*printf)(const char *fmt, ...), ...);
```

(For now type of the function is not checked, but it definitely will).

It could be used in following ways:

```c
    // Argument without position
    int a = 10;
    __builtin_print("{}\n", printf, a); // prints "10"
```

```c
    // String interpolation
    int a = 10;
    __builtin_print("{a}\n", printf); // prints "10"
```

```c
    // Positional arguments
    int a = 10 , b = 20;
    __builtin_print("{a} + {b} = {0}\n", printf, a + b); // prints "10 + 20 = 30"
    __builtin_print("{1} + {0} = {2}\n", printf, a, b, a + b); // prints "20 + 10 = 30"
```

```c
    // Hex
    int a = 10 , b = 20;
    __builtin_print("{a:x}\n"); // prints "a"
    __builtin_print("{a:03x}\n"); // prints "00a"
```

See `example.c` for more examples (which I currently use for testing).

Planning to add support for:
    - More %s stuff
    - Rust filling and alignment
    - More sanity checking
    - More testing

Also wondering if there could be some kind of "specifiers database", which could be loaded into
clang. This will be definitely useful for project with custom formatting (like Linux Kernel)
