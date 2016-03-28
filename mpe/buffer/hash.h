#ifndef HASH_H
#define HASH_H

#include <glib.h>

typedef GHashTable mac_table_t;

mac_table_t *mac_table_new(void);
int mac_table_insert(mac_table_t *t, char *ip, char *mac);
int mac_table_delete(mac_table_t *t, char *ip);
char *mac_table_lookup(mac_table_t *t, char *ip);
void mac_table_free(mac_table_t *t);
int mac_table_read_file(mac_table_t *t, char *filename);

#endif /* ! HASH_H */
