class Vector
{
private:
    float x;
    float y;
    float z;
    float w;

public:
    Vector();
    ~Vector();
    Vector(const Vector &);
    Vector(float, float);
    Vector(float, float, float);
    Vector(float, float, float, float);
    void operator=(const Vector &);
    float operator[](int);
    Vector operator+(Vector);
    Vector operator-(Vector);
    Vector operator*(float);
    Vector operator/(float);
    float Norm();
    void Normalized();
    float Dot(Vector);
};
