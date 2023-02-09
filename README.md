
## Usage
[USAGE] for hello world:
```
./app
```

[USAGE] for both matrix in same size:
```
./app [size] [random_seed]
```

[USAGE] for 2 matrix in diffrence size:
```
./app [m1_size] [m2_size] [random_seed]
```

[USAGE] for 2 matrix in diffrence row and col:
```
./app  [m1_row] [m1_col] [m2_row] [m2_col] [random_seed]
```

## DONE

1. To avoid pollute source tree, an out-of-source build code style is recommended. "cmake" is a popular build code tool that is capable of fitting aforementioned requirements. Please involve this tool to your project.

2. Put your implements in .c or .cpp file and build a corresponding dynamic library (.so) to separate your job from main system.

3. Use float or double type instead of int in this project.

4. For UI behavior, use a default value to simplify testing procedure. Keep dynamic input matrix dimension in advanced mode.

5. measure execution time of function

6. cmake settings: Root cmake handles all environment setups while subdirectory cmake only takes care of itself. Don't repeatedly set the same variable while it can cause potential error.

7. For the purpose of this project, you need to at least provide a .so file and a header file. Make sure these files are easy to find.

8. change type vector to pointer:In generate_random_float_matrix, for extremely large number, it can cause stack overflow.

## Notes
1. Test script can indicate two things: one is to test the correctness of the program and the other is to demonstrate how to use your program.

2. srand() with the same seed reproduces everything for debugging.

3. #define in .cpp or .h file has different meaning, just make sure you got it.

