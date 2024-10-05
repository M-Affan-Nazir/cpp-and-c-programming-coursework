/*

- ssh: mnazir1@ohaton.cs.ualberta.ca

- file*.txt = all files that contain 'file' and '.txt' [file1.txt, file45.txt, fileblabla.txt]
  '*' expands to 'everthing'.
- head -10 file.txt = first 10 lines of file.txt (dash/hyphen; not minus)

- 'mktemp' = creates a temporary file (in /temp) automatically deleted by OS after some time
- -$() = subshell; adding a sub-command inside the command (that is run and output returned)
  head -$(cat number.txt) alice.txt
  $(cat number.txt) = returns content of number.txt; which is simply number '10'
  now: head -10 alice.txt   -->  [reads 10 lines of alice.txt]

- '|' pipe: connects one command (and redirects output) to the other (like '>')
  run first command, then redirect to next.
  Allows chaining
  head - 10 file.txt | wc 
  cmd1 | cmd2 | cmd3 ....      [  cmd3 has input 'cmd1 | cmd2'  ] 
- $PATH = path for environment variables
- each will have 9 permission bits '---------'
  first dash = if its folder/directory or not.
  d--------- = folder/directory
  ---------- = a file  
  Next 9 = permission bits

  for each of the next 3 dashe: r=read, w=write, x=execute (-rwx---------)
  first 3 = owner itself, next 3 = everyone in group, last 3 = everybody else
  -rwxr-x--x (owner has all 3 permission, users in group can only read and execute, all others can only execute)

- chmod = changes file permission
  chmod u=rwx x.txt (change for owner)
  chmod g=rwx x.txt (change for group)
  chmod o=rwx x.txt (change for others)

  chmod g=e x.txt => (gives only execute permission --e)
  chmod g+e => (gives execute permission ONTOP of all other permissions  rwe)

- Shabang symbol = #!
  #!/usr/bin/python
  when added on-top a file (a.py; it will tell linux to use /usr/bin/python (path to interpreter) to run this file)
  you can simply run 'a.py' rather 'python a.py' now :D
- file extensions are meaningless, all file are simply 1 and 0's. (In only windows) they slightly help to open a file with a default program.
- #!/bin/bash  (bash interpreter)
  if you write this in a file (a.txt); you can write bash/terminal commands to run! Like .bat !
  a.txt:
    #!/bin/bash
    echo whoamI
    echo "Whats up"
  ./a.txt output = affan
                   "Whats up"
- ${1} = first argument provided to file (use bash shabang)
  ${#} = total arguments
  
- if [$x -eq 1]; then:
    echo "x = 1"
  fi

-for x in one,two,three
    eho "Word = ${x}"
 done

- grep = grab somethinng from file
- ${{}}  = used for arthmetic

- sayName(){
    echo whoami
    echo ${1} ${2}
  }

  sayName() Hello Hi  ->  affan, Hello, Hi (augument acting as parameters)

-for windows: .cpp, for linux .cc (C++ extension)

- x = "abc.txt"
  exho {x%txt} = "abc."
  (% = everthing without)

*/




/*
-|,>
-whats group
*/