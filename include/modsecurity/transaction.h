
#ifndef _TRANSACTION_H_INCLUDED_
#define _TRANSACTION_H_INCLUDED_

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

struct ModSecurity;
typedef struct ModSecurity ModSecurity;

struct Transaction;
typedef struct Transaction Transaction;

Transaction* msc_new_transaction(ModSecurity* ms,
    RulesSet* rules, void* logCbData);

Transaction* msc_new_transaction_with_id(ModSecurity* ms,
    RulesSet* rules, char* id, void* logCbData);

int msc_process_connection(Transaction* transaction,
    const char* client, int cPort, const char* server, int sPort);

int msc_process_request_headers(Transaction* transaction);

int msc_add_request_header(Transaction* transaction, const unsigned char* key,
    const unsigned char* value);

int msc_add_n_request_header(Transaction* transaction,
    const unsigned char* key, size_t len_key, const unsigned char* value,
    size_t len_value);

int msc_process_request_body(Transaction* transaction);

int msc_append_request_body(Transaction* transaction,
    const unsigned char* body, size_t size);

int msc_request_body_from_file(Transaction* transaction, const char* path);

int msc_process_response_headers(Transaction* transaction, int code,
    const char* protocol);

int msc_add_response_header(Transaction* transaction,
    const unsigned char* key, const unsigned char* value);

int msc_add_n_response_header(Transaction* transaction,
    const unsigned char* key, size_t len_key, const unsigned char* value,
    size_t len_value);

int msc_process_response_body(Transaction* transaction);

int msc_append_response_body(Transaction* transaction,
    const unsigned char* body, size_t size);

int msc_process_uri(Transaction* transaction, const char* uri,
    const char* protocol, const char* http_version);

const char* msc_get_response_body(Transaction* transaction);

size_t msc_get_response_body_length(Transaction* transaction);

size_t msc_get_request_body_length(Transaction* transaction);

void msc_transaction_cleanup(Transaction* transaction);

#ifdef __cplusplus
}
#endif

#endif // _TRANSACTION_H_INCLUDED_