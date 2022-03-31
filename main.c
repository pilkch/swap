#define _GNU_SOURCE // Required for renameat2 and RENAME_EXCHANGE

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>

#define PROGRAM_NAME "swap"
#define PROGRAM_VERSION 1.0f

void print_usage()
{
  printf("Usage:\n");
  printf(PROGRAM_NAME " FILE1 FILE2\n");
  printf(PROGRAM_NAME " [-v|--v|--version] [-h|--h|--help]\n");
  printf("Call the renameat2 function to atomically swap two files\n");
  printf("-v|--v|--version:\tPrint the version information\n");
  printf("-h|--h|--help:\tPrint this usage information\n");
}

void print_version()
{
  printf("swap %.2f\n", PROGRAM_VERSION);
}

int main(int argc, char **argv)
{
  for (size_t i = 1; i < (size_t)argc; i++) {
    if (argv[i] == NULL) {
      print_usage();
      return EX_USAGE;
    }

    if ((strcmp(argv[i], "-v") == 0) || (strcmp(argv[i], "-version") == 0) || (strcmp(argv[i], "--version") == 0)) print_version();
    else if ((strcmp(argv[i], "-h") == 0) || (strcmp(argv[i], "-help") == 0) || (strcmp(argv[i], "--help") == 0)) print_usage();
  }

  // Expect "swap FILE1 FILE2"
  if (argc != 3) {
    print_usage();
    return EX_USAGE;
  }

  const char* old_file_path = argv[1];
  const char* new_file_path = argv[2];

  // Swap the two files atomically
  // https://man.archlinux.org/man/renameat2.2.en
  if (renameat2(AT_FDCWD, old_file_path, AT_FDCWD, new_file_path, RENAME_EXCHANGE) != 0) {
    fprintf(stderr, PROGRAM_NAME ": cannot swap %s and %s: %s\n", old_file_path, new_file_path, strerror(errno));
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
