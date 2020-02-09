#if !defined(_TD_SCHEMA_H_)
#define _TD_SCHEMA_H_

#include <stdint.h>

#include "tstring.h"
#include "type.h"

typedef struct _scolumn {
  td_datatype_t type;
  int32_t bytes;
} SColumn;

typedef struct SSchema {
  int32_t numOfCols;
  SColumn *columns;
} SSchema;

// Column with version
typedef struct {
  td_datatype_t type;
  int32_t colId;
  int32_t bytes;
} SVColumn;

// Schema with version
typedef struct {
  int32_t version;      // Schema with version
  int32_t numOfCols;
  int32_t columnId;
  SVColumn *columns;
} SVSchema;

int32_t tdAddColumnToSchema(tstring_t pSchema, SColumn col);

td_datatype_t tdGetTypeOfCol(SSchema *pSchema, int32_t col);
int32_t tdGetLengthOfCol(SSchema *pSchema, int32_t col);


#endif  // _TD_SCHEMA_H_