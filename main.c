#include "encryption.h"
#include "list.h"

int main(int argc, char *argv[])
{
  int8_t flags = 0;
  char *mode;
  while ((++argv)[0]) {
    if (argv[0][0] == '-') {
      switch (argv[0][1]) {
      default:
        fprintf(stderr, "Unknown option -%c\n\n", argv[0][1]);
        exit(1);
        break;
      case 'q':
        printf("running in quiet mode\n");
        flags = flags | M_QIET;
        break;
      case 'i':
        printf("decoding images\n");
        flags = flags | M_IMAG;
        break;
      case 's':
        printf("decoding strings");
        flags = flags | M_STRN;
        break;
      }
    }
  }
  printf("please enter files for encrytion\n");
  scanf("%s", mode);
  printf("%s\n", mode);
  return 0;
}