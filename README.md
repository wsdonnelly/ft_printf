# Hive Helsinki project to recode libc's printf
-All of the functions used have also been recoded with the exception of write, malloc, free and functions of stdarg.h
# Bonus functionality
- ‘*’ find either the field width and/or the precision as an int in the argument list depending on the placement
-%b to print an unsigned int in binary (similar behaviour as x)
- %C print color. Write the macro for  (RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN) in the argument list preceding the conversion argument.
- %B banner mode. Enter a lower case string with no punctuation and spaces to separate words as an argument to print a banner for purely no reason. Letters are encoded bitwise as uint8_t’s of my own design. 
- For example ‘A’ is encoded:
0110
1001
1111
1001
where the top left if the least significant digit and the bottom right is the most siginificant digit.
## notes
For me the ultimate take away from this project was a deepening of my program design understanding.
In general I like to think that I attempt to write concise, short code, with a minimum of repetitions. 
However I decided (after a 2 rewrites) that a better approach for this project was to conceptualise it as a suite of individual programs that are called by a central dispatcher. This approach has the pros of having less computation and logic; thus gaining increased speed and legibility as well as being easier to expand the basic functionality of my printf at a latter date.