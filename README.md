<h1 align="center">
	Push_Swap
</h1>

<p align="center">
	:information_source: Because Swap_push isn’t as natural
</p>
<p align="center"><a href="https://www.42porto.com" target="_blank"><img src="https://img.shields.io/static/v1?label=&message=Porto&color=000&style=for-the-badge&logo=42""></a></p>
<p align="center"><img src="https://github.com/Bruno0798/Bruno0798/blob/main/42-project-badges/badges/push_swapn.png?raw=true"> </p>
<p align="center"> <strong>100/100</strong> ✅ </p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/bruno0798/42_push_swap?color=blueviolet" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/bruno0798/42_push_swap?color=blue" />
  <img alt="GitHub top language" src="https://img.shields.io/github/languages/top/bruno0798/42_push_swap?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/bruno0798/42_push_swap?color=brightgreen" />
</p>

---

## Description

The Push_swap project is a sorting algorithm project that challenges you to efficiently sort a set of integers using two stacks and a limited set of instructions. Your goal is to write a C program named `push_swap` that calculates and displays the smallest set of instructions (in the Push swap language) to sort the given integers.

## Objectives

The project emphasizes the importance of sorting algorithms and their complexity. It serves as a practical introduction to algorithmic complexity and prepares you for discussions on these concepts during job interviews.

## Common Instructions

- The project must be written in C.
- Adhere to the Norm.
- Functions should not quit unexpectedly.
- Free allocated memory appropriately; no leaks.
- Submit a Makefile with required flags.
- Makefile rules: `$(NAME)`, `all`, `clean`, `fclean`, `re`.
- If using `libft`, include it in a `libft` folder.

## Rules

- Two stacks named `a` and `b`.
- Stack `a` contains a random set of negative and/or positive numbers (non-duplicated).
- Stack `b` starts empty.
- Goal: Sort numbers in ascending order in stack `a`.
- Available operations:


| Code  | Instruction                         | Action                                                 |
| ----- | ----------------------------------- | ------------------------------------------------------ |
| `sa`  | swap a                              | swaps the 2 top elements of stack a                    |
| `sb`  | swap b                              | swaps the 2 top elements of stack b                    |
| `ss`  | swap a + swap b                     | both `sa` and `sb`                                     |
| `pa`  | push a                              | moves the top element of stack b at the top of stack a |
| `pb`  | push b                              | moves the top element of stack a at the top of stack b |
| `ra`  | rotate a                            | shifts all elements of stack a from bottom to top      |
| `rb`  | rotate b                            | shifts all elements of stack b from bottom to top      |
| `rr`  | rotate a + rotate b                 | both `ra` and `rb`                                     |
| `rra` | reverse rotate a                    | shifts all elements of stack a from top to bottom      |
| `rrb` | reverse rotate b                    | shifts all elements of stack b from top to bottom      |
| `rrr` | reverse rotate a + reverse rotate b | both `rra` and `rrb`                                   |

## Project Requirements

- Makefile must not relink.
- Global variables are forbidden.
- Write a program named `push_swap` that takes stack `a` as an argument.
- Display the smallest list of instructions to sort stack `a`.
- Instructions separated by '\n'.
- Minimize the number of operations for sorting.
- In case of errors, display "Error" on the standard error.

## Usage

**1. Clone the repository:**

```bash
git clone https://github.com/Bruno0798/42_Push_Swap.git
```
**2. Compile the project:**
```bash
make
```
**3. Run the program:**
```bash
./push_swap 4 2 7 1
```
## Notes

- Follow project-specific requirements and guidelines.
- Efficiently implement sorting algorithms.
- Minimize the number of operations.
- Handle errors appropriately.

## License

This project is licensed under the MIT License.

