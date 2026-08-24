#include "matrix.h"




void Matrix_Init(matrix_t* martix, int rows, int cols)
{
    ASSERT(rows > 0 && cols > 0);
    martix->rows = rows;
    martix->cols = cols;
    memset(martix->d, 0, sizeof(martix->d));
}



void Matrix_Identity(matrix_t* matrix, int size)
{
    int i;
    ASSERT(size > 0);
    matrix->rows = size;
    matrix->cols = size;
    memset(matrix->d, 0, sizeof(matrix->d));
    for(i = 0; i < size; i++)
    {
        matrix->d[MAT_IDX(i, i)] = 1.0f;
    }
}



void Matrix_From_Array(matrix_t* mat, const matrix_type* array,const int rows,const int cols)
{
    int i, j;
    ASSERT(NULL != array);
    Matrix_Init(mat, rows, cols);
    for(i = 0; i < rows; ++i)
    {
        for(j = 0; j < cols; ++j)
        {
            mat->d[MAT_IDX(i, j)] = array[i * cols + j];
        }
    }
}




matrix_t Matrix_Transpose(const matrix_t* src)
{
    int i, j;
    matrix_t dest;
    Matrix_Init(&dest, src->cols, src->rows);
    for(i = 0; i < src->rows; i++)
    {
        for(j = 0; j < src->cols; j++)
        {
            dest.d[MAT_IDX(j, i)] = src->d[MAT_IDX(i, j)];
        }
    }
    return dest;
}




matrix_t multiply_matrices(const matrix_t* A, const matrix_t* B)
{
    int i, j, k;
    matrix_t dest;
    ASSERT(A->cols == B->rows);

    Matrix_Init(&dest, A->rows, B->cols);

    for(i = 0; i < A->rows; i++)
    {
        for(j = 0; j < B->cols; j++)
        {
            for(k = 0; k < A->cols; k++)
            {
                dest.d[MAT_IDX(i, j)] += A->d[MAT_IDX(i, k)] * B->d[MAT_IDX(k, j)];
            }
        }
    }

    return dest;
}



matrix_t add_matrices(const matrix_t* A, const matrix_t* B)
{
    int i, j;
    matrix_t result;
    ASSERT(A->rows == B->rows && A->cols == B->cols);

    Matrix_Init(&result, A->rows, A->cols);

    for(i = 0; i < A->rows; i++)
    {
        for(j = 0; j < A->cols; j++)
        {
            result.d[MAT_IDX(i, j)] = A->d[MAT_IDX(i, j)] + B->d[MAT_IDX(i, j)];
        }
    }

    return result;
}




matrix_t subtract_matrices(const matrix_t* A, const matrix_t* B)
{
    int i, j;
    matrix_t result;
    ASSERT(A->rows == B->rows && A->cols == B->cols);

    Matrix_Init(&result, A->rows, A->cols);

    for(i = 0; i < A->rows; i++)
    {
        for(j = 0; j < A->cols; j++)
        {
            result.d[MAT_IDX(i, j)] = A->d[MAT_IDX(i, j)] - B->d[MAT_IDX(i, j)];
        }
    }

    return result;
}




int inverse_matrix(matrix_t* A, matrix_t* invA)
{
    int i, j, k;
    int n;
    int max_row;
    matrix_type pivot, factor, temp;

    #define AUG_COLS (2 * MAX_SIZE)
    #define AUG_IDX(ii, jj) ((ii) * AUG_COLS + (jj))
    matrix_type augmented[MAX_SIZE * AUG_COLS];

    ASSERT(A->rows == A->cols);

    Matrix_Init(invA, A->rows, A->cols);

    n = A->rows;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            augmented[AUG_IDX(i, j)] = A->d[MAT_IDX(i, j)];
            augmented[AUG_IDX(i, j + n)] = (float)((i == j) ? 1 : 0);
        }
    }

    for(i = 0; i < n; i++)
    {
        max_row = i;
        for(j = i + 1; j < n; j++)
        {
            if(fabs(augmented[AUG_IDX(j, i)]) > fabs(augmented[AUG_IDX(max_row, i)]))
            {
                max_row = j;
            }
        }

        if(fabs(augmented[AUG_IDX(max_row, i)]) < 1e-6f)
        {
            return 1;
        }

        if(max_row != i)
        {
            for(j = 0; j < 2 * n; j++)
            {
                temp = augmented[AUG_IDX(i, j)];
                augmented[AUG_IDX(i, j)] = augmented[AUG_IDX(max_row, j)];
                augmented[AUG_IDX(max_row, j)] = temp;
            }
        }

        pivot = augmented[AUG_IDX(i, i)];
        for(j = 0; j < 2 * n; j++)
        {
            augmented[AUG_IDX(i, j)] /= pivot;
        }

        for(j = 0; j < n; j++)
        {
            if(j != i)
            {
                factor = augmented[AUG_IDX(j, i)];
                for(k = 0; k < 2 * n; k++)
                {
                    augmented[AUG_IDX(j, k)] -= factor * augmented[AUG_IDX(i, k)];
                }
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            invA->d[MAT_IDX(i, j)] = augmented[AUG_IDX(i, j + n)];
        }
    }
    #undef AUG_COLS
    #undef AUG_IDX

    return 0;
}





static float invSqrt(float x)
{
    /* C251 int is 16-bit, cannot type-pun with 32-bit float.
       Use standard math library instead. */
    return (float)(1.0 / sqrt((double)x));
}




void normalize_vector(matrix_t *v)
{
    int i;
    matrix_type norm = 0;

    ASSERT(1 == v->cols || 1 == v->rows);

    if(1 == v->rows)
    {
        for(i = 0; i < v->cols; ++i)
        {
            norm += (v->d[MAT_IDX(0, i)] * v->d[MAT_IDX(0, i)]);
        }
    }
    else if(1 == v->cols)
    {
        for(i = 0; i < v->rows; ++i)
        {
            norm += (v->d[MAT_IDX(i, 0)] * v->d[MAT_IDX(i, 0)]);
        }
    }

    norm = invSqrt((float)norm);
    if(1 == v->rows)
    {
        for(i = 0; i < v->cols; ++i)
        {
            v->d[MAT_IDX(0, i)] *= norm;
        }
    }
    else if(1 == v->cols)
    {
        for(i = 0; i < v->rows; ++i)
        {
            v->d[MAT_IDX(i, 0)] *= norm;
        }
    }
}





void print_matrix(const matrix_t* matrix)
{
    int i, j;
    for(i = 0; i < matrix->rows; i++)
    {
        for(j = 0; j < matrix->cols; j++)
        {
            printf("%2f ", matrix->d[MAT_IDX(i, j)]);
        }
        printf("\n");
    }
    printf("\n");
}



