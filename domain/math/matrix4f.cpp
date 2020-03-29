#include <algorithm>
#include "matrix4f.h"

Matrix4f::Matrix4f()
{
    m_data = new float*[SIZE];
    for (int i = 0; i < SIZE; i++)
        m_data[i] = new float[SIZE];
}

/*Matrix4f::Matrix4f(const Matrix4f &other)
{
    for (int i = 0; i < SIZE; i++)
        std::copy(&other.m_data[i][0], &other.m_data[i][SIZE], &m_data[i][0]);
}*/

Matrix4f::~Matrix4f()
{
    for (int i = 0; i < SIZE; i++)
       delete m_data[i];

    delete m_data;
}

/*void Matrix4f::setM(float **data)
{
    for (int i = 0; i < SIZE; i++)
        std::copy(&data[i][0], &data[i][SIZE], &m_data[i][0]);
}

float  Matrix4f::get(int row, int column) const
{
    return m_data[row][column];
}

void Matrix4f::set(int row, int column, float value)
{
    m_data[row][column] = value;
}

Matrix4f& Matrix4f::identity()
{
    for (int i = 0; i < SIZE; i++) {
        std::fill_n(&m_data[i][0], SIZE, 0);
        m_data[i][i] = 1;
    }

    return *this;
}

Matrix4f& Matrix4f::operator *(const Matrix4f &other)
{
    Matrix4f m;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            m.set(i, j, m_data[i][0] * other.m_data[0][j] +
                        m_data[i][1] * other.m_data[1][j] +
                        m_data[i][2] * other.m_data[2][j] +
                        m_data[i][3] * other.m_data[3][j]);
        }
    }

    setM(m.getM());

    return *this;
}

Matrix4f& Matrix4f::mul(const Matrix4f &other, Matrix4f &dest) const
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            dest.set(i, j, m_data[i][0] * other.m_data[0][j] +
                           m_data[i][1] * other.m_data[1][j] +
                           m_data[i][2] * other.m_data[2][j] +
                           m_data[i][3] * other.m_data[3][j]);
        }
    }

    return dest;
}*/
