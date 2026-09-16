namespace Vec{
    struct Vector2{
        float x,y;
        
        Vector2(float x, float y): x(x), y(y){}
        Vector2(): x(0), y(0){}
        
        Vector2& operator+(Vector2& other);
    
        Vector2& operator*(float other);
    
        Vector2& operator*(Vector2& other);

        Vector2& operator=(Vector2& other);
    };

    struct Vector4{
        float x,y,z,a;

        Vector4(float x ,float y, float z,float a): x(x), y(y), z(z), a(a){}
        Vector4(): x(0), y(0), z(0), a(0) {}
        
        Vector4& operator+(Vector4& other);
    
        Vector4& operator*(float other);
    
        Vector4& operator*(Vector4& other);

        Vector4& operator=(Vector4& other);
    };
}