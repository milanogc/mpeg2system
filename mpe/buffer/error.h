/* macros to deal more easily with errors */

#ifndef ERROR_H

#include <stdio.h>		/* fprintf, perror */
#include <stdlib.h>		/* exit */
#include <errno.h>		/* errno */

#define err_msg(...) fprintf(stderr, __VA_ARGS__)
#define err_quit(...) err_msg(__VA_ARGS__), exit(1)
#define err_sys(estr) perror( (estr) ), exit(errno)

#define print_deb(debug, ...) if (debug) err_msg(__VA_ARGS__)

#endif /* ! ERROR_H */
