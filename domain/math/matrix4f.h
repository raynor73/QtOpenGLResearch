#ifndef MATRIX4F_H
#define MATRIX4F_H

class Matrix4f
{
public:
    Matrix4f();
    //Matrix4f(const Matrix4f &);
    ~Matrix4f();

    /*float **getM() { return m_data; }
    void setM(float **);
    float get(int, int) const;
    void set(int, int, float);
    Matrix4f& identity();
    Matrix4f& operator*(const Matrix4f &);
    Matrix4f& mul(const Matrix4f&, Matrix4f&) const;*/

private:
    static const int SIZE = 4;

    float **m_data;
};

#endif // MATRIX4F_H
