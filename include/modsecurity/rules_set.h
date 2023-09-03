
#ifndef _RULES_SET_H_INCLUDED_
#define _RULES_SET_H_INCLUDED_

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

struct RulesSet;

typedef struct RulesSet RulesSet;

typedef struct ModSecurityIntervention ModSecurityIntervention;

RulesSet* msc_create_rules_set(void);

void msc_rules_dump(RulesSet* rules);

int msc_rules_merge(RulesSet* rules_dst, RulesSet* rules_from, const char** error);

int msc_rules_add_remote(RulesSet* rules, const char* key, const char* uri,
    const char** error);

int msc_rules_add_file(RulesSet* rules, const char* file, const char** error);

int msc_rules_add(RulesSet* rules, const char* plain_rules, const char** error);

int msc_rules_cleanup(RulesSet* rules);

#ifdef __cplusplus
}
#endif

#endif // _RULES_SET_H_INCLUDED_