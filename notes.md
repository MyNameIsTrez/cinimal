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
- No `void *`
- No `malloc()`, nor anything else heap related. Use globals for persistent storage.

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
- No splitting of import statement across multiple lines?
- Not sure if there's anything better f64 can be translated to than a hardcoded double?



- ref keyword must always come first in declarations. There can't be more than one.
- Don't compile if get_paw_count isn't explicitly listed as coming from dog.cn in the import line
- Don't compile if a function is listed as coming from a cinimal file, but isn't defined there
- Don't compile if a function/struct forward declaration is attempted
- No functions in variables
- No function passing as arguments
- The {} in the import line aren't optional
- Let all inserted C includes be in alphabetical order, and have a trailing comment stating which function was included from it?
- How to do lookup tables?
- Do I want stack arrays? How would they be declared?
- Include printf, assert, calloc, free, strdup, NULL
- Let transpilation throw an error if a #include is present in the cinimal file
- Add includes.cn test, that is there so one can try to remove inserted includes without breaking backwards compatibility
- No union?
- Wrap calloc() in code checking NULL?: https://stackoverflow.com/a/26844703/13279557
- Let variables and pointers *always* be automatically initialized to 0. cinimal code is expected to use this, in order to not need to initialize values to 0 manually.
- No pointer arithmetic?
- No letting pointers change which memory block they point to?
- No negative indexing
- No indexing past calloc() block bounds
- No using i[arr] syntax. Is this even possible with refs?
- Prepend enum name to enum values in the .c files, so `country_ukraine`
- Change ptr to ref, and change .c files to .cpp. Update readme, .gitignore, .cpp file contents, .cn file contents
- Give ref a different syntax highlighting color than the rest of the types
- Let AST generator throw an error if an unknown keyword is encountered, such as C++'s `throw`
- Remove redundant ref demonstration in main.cn
- Automatic freeing
- Is the heap *that* useful to have?

Refs vs (const) pointers:
- Refs mean there's no need for & nor -> nor *
- Pointer needs to be created to store calloc() result and to free it
- Refs/const pointers need to be declared and assigned at once
- Pointer arithmetic is still possible on refs to memory
- index[mem_ptr_ref] is still possible with refs to memory. Could be detected during transpilation by checking if the thing on the left of the [ is a pointer/reference
- Can't use const * instead of c++, unless I let transpile.py add &, -> and * appropriately
