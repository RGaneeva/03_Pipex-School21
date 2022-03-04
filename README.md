# PIPEX

School 21 (Ecole42) 'pipex' project. 
Score 100/100. Passed 2021/08/29

In this project I studied the redirections and the pipes. 
The programm name - pipex, it takes as a parameter 1 file with some information inside, 
reads this information, sends it to the pipe, where, on the other side - 
writes to the new file, sometimes - after after applying some commands to the contents 
of the first file.

# USAGE

clone this repository

git clone https://github.com/RGaneeva/03_Pipex-School21.git

then

| command | result |
|:----|:----|
| make | compile pipex project |
| make clean | clean .o files |
| make fclean | clean .o and .a files |

Examples of using programm:

> ./pipex infile "ls -l" "wc -l" outfile
> ./pipex infile "grep a1" "wc -w" outfile
