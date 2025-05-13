#include <math.h>

#include "UNIR2D/Matematicas.hpp"
using namespace unir2d;

float Transforma::aplicaARotacion (float rotacion) const {
    return rotacion + m_rotacion;
};


static Vector multiplica (const float mtrz [4][4], const Vector vect) {
    return Vector {
            mtrz [0][0] * vect.x () + mtrz [0][1] * vect.y () + mtrz [0][3],
            mtrz [1][0] * vect.x () + mtrz [1][1] * vect.y () + mtrz [1][3] };
}


Vector Transforma::aplicaAPosicion (const Vector posicion) const {
    // este es el cálculo:
    float  sen  = std::sin (m_rotacion);
    float  cos  = std::cos (m_rotacion);
    Vector v_a {
            posicion.x () * cos - posicion.y () * sen + m_posicion.x () - m_origen.x (),
            posicion.y () * cos + posicion.x () * sen + m_posicion.y () - m_origen.y () };
    return v_a;
}