## About

This is a very simple wrapper around the Linux renameat2 function to swap two files or directories atomically.  
It is mainly useful for scripts to call.

## Requirements

- Linux kernel 3.15 and higher

## Building

Build:
```bash
make
```

## Tests

Run the tests:
```bash
cd tests
./test-files.sh
./test-directories.sh
```

## Usage

Create two files and swap them
```bash
$ echo "Hello" > a
$ echo "Goodbye" > b
$ ./swap a b
$ cat a
Goodbye
$ cat b
Hello
```

It works for directories too:
```bash
$ mkdir c
$ mkdir d
$ echo "Good Evening" > c/first
$ echo "Good Night" > d/second
$ ./swap c d
$ find c d
c
c/second
d
d/first
$ cat c/second
Good Night
$ cat b
Good Evening
```
