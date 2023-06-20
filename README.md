## **Pipex** 
recreates bash's behavior for:
```
< infile cmd1 | cmd2 | cmd3 ... | cmdn > outfile
```
The program can be executed as follows:
```
./pipex infile cmd1 cmd2 cmd3 ... cmdn outfile
```
Arguments must consist of an infile, outfile and n number of commands. 
 
 ## **here_doc**
 recreates bash's behavior for:
 ```
 cmd << LIMITER | cmd1 >> file
 ```
The program can be executed as follows:
 ```
./pipex here_doc LIMITER cmd1 cmd2 cmd3 ... cmdn outfile
```
Arguments must consist of "here_doc", the LIMITER, n number of commands and an outfile.

To add flags to commands, use double quotes e.g. "wc -l".
