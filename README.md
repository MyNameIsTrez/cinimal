# cinimal

Minimalistic C and Python-like language.

## How it works

`transpile.py` transpiles a cinimal `.cn` file to a `.c` file.

The user is responsible for compiling the generated `.c` file.

Transpiling to C just means turning this:
```cn
i32 main()
	return 0
```
into this:
```c
int32_t main() {
	return 0;
}
```
