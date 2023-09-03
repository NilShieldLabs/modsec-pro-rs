
#ifndef _MODESECURITY_H_INCLUDED_
#define _MODESECURITY_H_INCLUDED_

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MODSECURITY_VERSION_NUM 30100100

#define MODSECURITY_CHECK_VERSION(a) (MODSECURITY_VERSION_NUM <= a)

#include "rules_set.h"
#include "transaction.h"

struct ModSecurityIntervention {
    int status;
    int pause;
    char* url;
    char* log;
    int disruptive;
};

typedef struct ModSecurityIntervention ModSecurityIntervention;

struct ModSecurity;
typedef struct ModSecurity ModSecurity;

struct Transaction;
typedef struct Transaction Transaction;

typedef void (*ModSecLogCb)(void*, const void*);

ModSecurity* msc_init(void);

void msc_cleanup(ModSecurity* msc);

void msc_set_connector_info(ModSecurity* msc, const char* connector);

void msc_set_log_cb(ModSecurity* msc, ModSecLogCb cb);

int msc_intervention(Transaction* transaction, ModSecurityIntervention* it);

int msc_process_logging(Transaction* transaction);

int msc_update_status_code(Transaction* transaction, int status);

#ifdef __cplusplus
}
#endif

#endif // _MODESECURITY_H_INCLUDED_