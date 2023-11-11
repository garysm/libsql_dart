#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <ostream>
#include <new>

struct libsql_connection;

struct libsql_database;

struct libsql_row;

struct libsql_rows;

struct libsql_rows_future;

using libsql_database_t = const libsql_database*;

using libsql_connection_t = const libsql_connection*;

using libsql_rows_t = const libsql_rows*;

using libsql_rows_future_t = const libsql_rows_future*;

using libsql_row_t = const libsql_row*;

struct blob {
  const char *ptr;
  int len;
};

extern "C" {

int libsql_sync(libsql_database_t db, const char **out_err_msg);

int libsql_open_sync(const char *db_path,
                     const char *primary_url,
                     const char *auth_token,
                     libsql_database_t *out_db,
                     const char **out_err_msg);

int libsql_open_ext(const char *url, libsql_database_t *out_db, const char **out_err_msg);

void libsql_close(libsql_database_t db);

int libsql_connect(libsql_database_t db, libsql_connection_t *out_conn, const char **out_err_msg);

void libsql_disconnect(libsql_connection_t conn);

int libsql_execute(libsql_connection_t conn,
                   const char *sql,
                   libsql_rows_t *out_rows,
                   const char **out_err_msg);

void libsql_free_rows(libsql_rows_t res);

void libsql_free_rows_future(libsql_rows_future_t res);

void libsql_wait_result(libsql_rows_future_t res);

int libsql_column_count(libsql_rows_t res);

int libsql_column_name(libsql_rows_t res, int col, const char **out_name, const char **out_err_msg);

int libsql_column_type(libsql_rows_t res, int col, int *out_type, const char **out_err_msg);

int libsql_next_row(libsql_rows_t res, libsql_row_t *out_row, const char **out_err_msg);

void libsql_free_row(libsql_row_t res);

int libsql_get_string(libsql_row_t res, int col, const char **out_value, const char **out_err_msg);

void libsql_free_string(const char *ptr);

int libsql_get_int(libsql_row_t res, int col, long long *out_value, const char **out_err_msg);

int libsql_get_float(libsql_row_t res, int col, double *out_value, const char **out_err_msg);

int libsql_get_blob(libsql_row_t res, int col, blob *out_blob, const char **out_err_msg);

void libsql_free_blob(blob b);

} // extern "C"
