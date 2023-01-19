## DONE

1. To avoid pollute source tree, an out-of-source build code style is recommended. "cmake" is a popular build code tool that is capable of fitting aforementioned requirements. Please involve this tool to your project.

2. Put your implements in .c or .cpp file and build a corresponding dynamic library (.so) to separate your job from main system.

3. Use float or double type instead of int in this project.

4. For UI behavior, use a default value to simplify testing procedure. Keep dynamic input matrix dimension in advanced mode.

5. measure execution time of function

6. cmake settings: Root cmake handles all environment setups while subdirectory cmake only takes care of itself. Don't repeatedly set the same variable while it can cause potential error.

## TODO
1. Test script can indicate two things: one is to test the correctness of the program and the other is to demonstrate how to use your program.

2. For the purpose of this project, you need to at least provide a .so file and a header file. Make sure these files are easy to find.

3. srand() with the same seed reproduces everything for debugging.

4. In generate_random_float_matrix, for extremely large number, it can cause stack overflow.

5. #define in .cpp or .h file has different meaning, just make sure you got it.

