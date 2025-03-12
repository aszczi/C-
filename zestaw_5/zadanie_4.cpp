#include <iostream>

class Drawing {
public:
    Drawing() {}
    virtual ~Drawing(){}
    virtual void drawLine() = 0;
    virtual void drawCircle() = 0;

};

class Shape {
private:
    Drawing *drawing;
protected:
    virtual void drawLine() {
        drawing->drawLine();
    }
    virtual void drawCircle() {
        drawing->drawCircle();
    };
public:

    Shape(Drawing *figure) : drawing{figure}{}
    virtual ~Shape(){}
    virtual void draw() = 0;
    void setLib(Drawing *figure){
        drawing = figure;
    }
};

class Rectangle : public Shape {
public:
    Rectangle(Drawing *rect) : Shape{rect}{ }
    virtual ~Rectangle(){}
    virtual void draw() override final{
        drawLine();
        std::cout<<"|     |"<<std::endl;
        drawLine();
    }
};
class Circle : public Shape {
public:
    Circle(Drawing *circle) : Shape{circle}{ }
    virtual ~Circle(){}
    virtual void draw() override final{
        drawCircle();
    }
};

class DP1 {
public:
    DP1() {};
    ~DP1() {};

    void draw_a_line() {
        std::cout << " _____"<< std::endl;
    }
    void draw_a_circle(){
        std::cout<<"●"<<std::endl;

    }
};

class DP2 {
public:
    void drawline() {
        std::cout << " - - - "<< std::endl;
    }
    void drawcircle() {
        std::cout<<"◯"<<std::endl;
    }
};


class V1Drawing : public Drawing, public DP1 {
private:
    DP1 dp1;
public:
    V1Drawing(DP1 &figure) : dp1(figure){}
    virtual ~V1Drawing() {};
    virtual void drawLine() override final {
        dp1.draw_a_line();
    }

    virtual void drawCircle() override final{
        dp1.draw_a_circle();
    }
};
class V2Drawing : public Drawing, public DP2 {
private:
    DP2 dp2;
public:
    V2Drawing(DP2 &figure) : dp2(figure){}
    virtual ~V2Drawing() {};
    virtual void drawLine() override final {
        dp2.drawline();
    }

    virtual void drawCircle() override final{
        dp2.drawcircle();
    }
};


int main() {
    DP1 library1; // pierwsza biblioteka
    DP2 library2; // druga biblioteka

    Drawing *d1 = new V1Drawing( library1 );
    Drawing *d2 = new V2Drawing( library2 );

    Shape *p1 = new Rectangle( d1 );
    Shape *p2 = new Circle( d2 );

    p1->draw(); // rectangle linia V1
    p2->draw(); // circle okrag V2
    p1->setLib( d2 );
    p2->setLib( d1 );
    p1->draw(); // rectangle linia V2
    p2->draw(); // circle okrag V1

    delete p1;
    delete p2;
    delete d1;
    delete d2;
}