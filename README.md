# Minishell
##  Prompt, commandline, shell and terminal. 
![42Projects - Página 10](https://user-images.githubusercontent.com/62228465/142232996-090264fa-a23c-489d-b2b9-842a5d30ebcb.jpeg)

|                     |  Definition         |
| ------------------- | ------------------- |
|  Prompt             | string of characters used in a command-line interface to indicate readiness to accept commands |
|  Commandline        | way of interacting with a computer program                                                     |
|  Shell              | is a program that processes commands and generates output returns, like bash or zsh on Linux   |
|  Terminal           | computer program that emulates a video terminal within another display architecture            |

![42Projects - Minishell](https://user-images.githubusercontent.com/62228465/142232972-b19a1931-d99c-4bdc-ae36-c622106882a0.jpeg)

|  Prompt allowed functions |  Definition   |
| ------------------- | ------------------- |
| readline            | readline will read a line from the terminal and return it, using prompt as a prompt. |
| rl_clear_history    | Clear the history list by deleting all of the entries |
| rl_on_new_line      | Tell the update functions that we have moved onto a new (empty) line, usually after outputting a newline. |
| rl_replace_line     | Replace the contents of rl_line_buffer with text |
| rl_redisplay        | Change what's displayed on the screen to reflect the current contents of rl_line_buffer. |
| add_history         | Place string at the end of the history list |
| getenv              | searches the environment list to find the environment variable name, and returns a pointer to the corresponding value string|

|  System Call allowed functions |  Definition         |
| ------------------- | ------------------- |
| pipe                | ![image](https://user-images.githubusercontent.com/62228465/142508435-ba890987-ad79-4c9e-86ab-7b7153483a0b.png) |
| fork                | ![image](https://user-images.githubusercontent.com/62228465/142500290-f69d80cb-b533-4cce-b080-ec0e710ae013.png)|
| wait                | ![image](https://user-images.githubusercontent.com/62228465/142499932-8ddd127c-6d7f-4cf7-b11e-33325ab7361f.png)|
| waitpid             | The waitpid() system call suspends execution of the calling      process until a child *specified by pid argument* has changed state |
| sigaction           | change the action taken by a process on receipt of a specific signal |
| kill                | send signal to a process |
| ioctl               | ioctl is a system call for device-specific input/output operations and other operations which cannot be expressed by regular system calls.|
| execve              | executes the program referred to by pathname |


| fd allowed functions|  Definition         |
| ------------------- | ------------------- |
| access              | checks whether the calling process can access the file  pathname |
| stat                | get file status |
| unlink              | deletes a name from the file system |
| dup/dup2            | duplicates a file descriptor |
| isatty              | tests whether fd is an open file descriptor referring to a terminal |
| ttyname             | returns a pointer to the null-terminated pathname of the terminal device that is open on the file descriptor fd |
| ttyslot             | find the slot of the current user's terminal in some file |

| dir allowed functions|  Definition         |
| ------------------- | -------------------  |
| getcwd              | get current working directory |
| chdir               | change working directory |
| open/read/close -dir| opens, read and closes a directory stream corresponding to the directory name |

| error allowed functions|  Definition       |
| ------------------- | -------------------  |
| strerror            | returns a pointer to a string that describes the error code passed in the argument errnum|
| perror              | prints a descriptive error message to stderr |

| terminfo[](https://en.wikipedia.org/wiki/Terminfo) allowed functions|  Definition    |
| ------------------- | -------------------  |
| tcsetattr           | set the parameters associated with the terminal |
| tcgetattr           | get the parameters associated with the terminal |
| tgetent             | loads the entry for name |
| tgetflag            | gets the boolean entry for id |
| tgetnum             | gets the numeric entry for id |
| tgetstr             | returns the string entry for id|
| tgoto               | instantiates the parameters into the given capability |
| tputs               | output the returned string |
