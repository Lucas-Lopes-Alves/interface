#include "vectors.hpp"
using namespace Vec;

// ===========================
// Vector2 implementations
// ===========================

Vector2& Vector2::operator*(float other){
    this->x *= other;
    this->y *= other;
    
    return *this;
}

Vector2& Vector2::operator+(Vector2& other){
    this->x += other.x;
    this->y += other.y;
    
    return *this;
}

Vector2& Vector2::operator*(Vector2& other){
    this->x *= other.x;
    this->y *= other.y;
    
    return *this;
}

Vector2& Vector2::operator=(Vector2& other){
    x = other.x;
    y = other.y;

    return *this;
}

// ============================
// Vector3 implementations
// ============================

Vector3& Vector3::operator+(Vector3& other){
    x += other.x;
    y += other.y;
    z += other.z;

    return *this;
}

Vector3& Vector3::operator*(float other){
    x *= other;
    y *= other;
    z *= other;

    return *this;
}

Vector3& Vector3::operator*(Vector3& other){
    x *= other.x;
    y *= other.y;
    z *= other.z;

    return *this;
}

Vector3& Vector3::operator=(Vector3& other){
    x = other.x;
    y = other.y;
    z = other.z;

    return *this;
}

// =============================
// Vector 4 Implementations
// =============================

Vector4& Vector4::operator+(Vector4& other){
    x += other.x;
    y += other.y;
    z += other.z;
    a += other.a;

    return *this;
}

Vector4& Vector4::operator*(float other){
    x *= other;
    y *= other;
    z *= other;
    a *= other;

    return *this;
}

Vector4& Vector4::operator*(Vector4& other){
    x *= other.x;
    y *= other.y;
    z *= other.z;
    a *= other.a;

    return *this;
}

Vector4& Vector4::operator=(Vector4& other){
    x = other.x;
    y = other.y;
    z = other.z;
    a = other.a;

    return *this;
}