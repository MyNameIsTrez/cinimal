- No built-in data structures
- No built-in algorithms
- No usage of enums or imported functions without specifying their source: `animal::dog` and `dog::bark`
- No importing relative to anything but the root directory
- No usage of `..` in `import` statement
- A function starting with a leading _ is private and shouldn't be added to a header
- Let cinimal show variable declarations as being as close as possible to the first assignment
- Exactly 1 newline between every function, struct, and enum
- If there's an instruction before a variable declaration, including `if` and `while`, but excluding another variable declaration, let cinimal add a newline to separate the two
- No trailing comma in import statement
- No splitting of import statement across multiple lines
- Sort all #includes in alphabetical order, and have a trailing comment stating which functions were included from it
- Sort all functions in an import in alphabetical order

# Show errors if
- Show error if a variable is declared and assigned on a single line
- Show error if the user states a function came from cinimal file X, but isn't defined there
- Show error if `else if` is used, instead of `elif`
- Sort all C imports in alphabetical order, and show an error if no function was included from it

# TODO:
- Add "everything" test screenshot to GH readme
- Make placeholder cinimal VS Code extension before someone else grabs it
- Add gif to the extension page showcasing how to use cinimal
- Enums, structs and file namespaces shouldn't have to be capitalized
- Already make all extension settings toggleable

# Tests to add
- Add test showcasing only one instruction per line, so no `while (i += 1)`
- Add test calling a function from a lookup table of functions
- Add test for multidimensional arrays on the heap and stack
- Add test for function forward declaration
- Add test for struct forward declaration
- Add test for passing function as arg
- Add test showcasing union
- Add test showcasing one ptr declaration per line declaration the * of the declaration so it's on both lines
- Add test showcasing const pointers need to be declared and assigned at once
- Add test showcasing printf("%d\n", 42) being turned into print("%d", 42)
- Add test showcasing printf("%d", 42) being turned into printf("%d", 42)
- Add test showcasing redundant usage of `()` gets removed
- Add test showcasing casting
- Add test showcasing no direct nesting of a struct definition inside of another struct definition; you have to define the inner struct before it
- Add test showcasing no tabs anywhere, apart from for indentation, and also show unless it's in a comment
- Add test shocasing no aligning lines using spaces; show minimum number of required spaces only, and also show unless it's inside a comment
- Add test showcasing "i++; j++"

# Questions
- Not sure if there's anything better f64 can be translated to than a hardcoded double?
- Show an error if get_paw_count isn't explicitly listed as coming from dog.cn in the import line?
- Do I want ! or ~ or - or + or casting to also be on the right side of a variable?
- Is it possible to let cinimal use snake_case for everything, including file and folder names in import statements and includes? I think it might cause problems when the C file uses both an uppercase and lowercase variable at once.
- Do I want to keep = {0} being translated to = 0?

# Turn these into settings
- Transpile printf("\n") to print()
