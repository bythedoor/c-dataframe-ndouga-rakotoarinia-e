
#ifndef C_DATAFRAME_NDOUGA_RAKOTOARINIA_E_COLUMN_H
#define C_DATAFRAME_NDOUGA_RAKOTOARINIA_E_COLUMN_H
#define REALOC_SIZE 256

typedef union {
    unsigned int uint_value;
    signed int int_value;
    char char_value;
    float float_value;
    double double_value;
    char* string_value;
    void* struct_value;
} COL_TYPE;

enum enum_type
{
    NULLVAL = 1 , UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
};
typedef enum enum_type ENUM_TYPE;

typedef struct{
    char *title;
    unsigned int size;
    unsigned int max_size;
    ENUM_TYPE column_type;
    COL_TYPE **data;
    unsigned long long int *index;
}COLUMN;


COLUMN *create_column(ENUM_TYPE type, char* title);

int insert_value(COLUMN* col, void *value);

void print_col(COLUMN* col);

void convert_value(COLUMN *col, unsigned long long int i, char *str, int size);

int nbr_occurences(COLUMN *col, int x);

int get_values(COLUMN *col, int x);

int values_superior(COLUMN *col, int x);

int values_inferior(COLUMN *col, int x);

int values_equal(COLUMN *col, int x);

void delete_column(COLUMN **col);

#endif //C_DATAFRAME_NDOUGA_RAKOTOARINIA_E_COLUMN_H
