# C keywords that deliberately aren't in cinimal
- No `const` / `static`
- No `typedef` / `define`
- No `for`
- No `switch()`
- No `++` / `--`
- No `#include`
- No `;`
- No `sizeof()`
- No unsigned numbers, including `size_t`
- No `void *`, nor replacements

# C concepts that deliberately aren't in cinimal
- No multiline comments
- No recursion
- No direct nesting of a struct definition inside of another struct definition; you have to instead define the inner struct before it
- No comments outside of functions
- No tabs anywhere, apart from for indentation
- No casting
- No aligning lines using spaces; minimum number of required spaces only
- No declaring and assigning a variable on a single line
- No redundant usage of `()`

# TODO: ??
- No built-in data structures
- No built-in algorithms
- No `else if`, only `elif`
- No `using` C++ keyword
- No usage of enums or imported functions without specifying their source: `animal::dog` and `dog::bark`
- No importing relative to anything but the root directory
- No usage of `..` in `import` statement

# Rules
- Only one variable declaration per line
- Only one instruction per line, so no `while (i += 1)`

# Misc
- Only number types are signed ints and floating point numbers, so for example i32 and f16
- Indentation scoping, rather than { }
- `str` type
- # for comments. A single space must always follow the #
- Comments must be on their own line
- `&&` and `||` should both only return booleans, so not the last/first value like in Python/JS, in order to retain C compatibility
- Imports must be alphabetical
- Functions imported in a single line must be alphabetical
- `malloc()` uses `calloc()` under the hood
- `free()` sets the pointer to NULL

# Opinionated compiler:
- snake_case for everything, including file and folder names
- Functions have to be in the order in which they get called, with the main() always at the top, and the rest below it in the order in which they get called
- All variable declarations must be as close as possible to the first assignment
- Exactly 1 newline between every function, struct, and enum, with a required trailing newline
- If there's an instruction before a variable declaration, including `if` and `while`, but excluding another variable declaration, then there must be a newline to separate it
- If there's an instruction after an `if` or `while`, there must be a newline separating them
- No trailing comma in import statement

# Questions
- How badly do I want refs? Do I want them to never be NULL? If I don't mind the programmer needing to use * and &, then I should use pointers instead
- No splitting of import statement across multiple lines?
