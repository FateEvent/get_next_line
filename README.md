# Get Next Line

The get_next_line() function returns the last line read from a file descriptor, or a NULL pointer if there is nothing left to read.
It may be called various times and, if the text has not been entirely read, it returns every time the line that follows.

The get_next_line_bonus() function may take into account various file descriptors and return the last line read from each one of them. 
