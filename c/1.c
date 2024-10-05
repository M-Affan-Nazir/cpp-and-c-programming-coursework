/*

- 'cat' = lists the content of the file
- '~?'  =  root/home directory 
- 'ctrl + D'  =  End of file signal / end-OfFile/Input signal
- standard input = user's input through keyboard
  standard output = connection to the cmd/shell's output (slow)
  standard error  = special connection to cmd/sell; it outputs immediately (fast)
- '>' or '<'  redirect output from one file/program, as an input to another  file/program
  python x.py > ./a.txt (output from x.py saved in a.txt)
- 'wc' = returns num-lines, num-words, num-characters
-  stanrd-error is different; so it can not be redirected using '>' or '<'
   If you want to redirect, you use '<2' 
-  you can assign a variable in bash; x = 10
   you can read it:  'echo ${x}' or 'echo $x'
- To see the exit status of a program: '$?'
  when using 'diff' to compare 2 files, it exits with a status of 2 when there is an error,
  '$?' gives exit-status of command/program run imneduately before it
- 

*/