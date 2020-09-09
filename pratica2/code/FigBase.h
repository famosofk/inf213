#ifndef FIGBASE_H
#define FIGBASE_H

class FigBase{

    private:
    double x, y;
    int espessura, cor, tipo;

    public:
    FigBase();
    FigBase(double, double, int, int, int);
    const double getX() const;
    const double getY() const;
    void setX(const double);
    void setY(const double);
    int getEspessura() const;
    void setEspessura(const int);
    int getCor() const;
    void setCor(const int);
    int getTipo() const;
    void setTipo(const int);
    void imprime() const;

};



#endif