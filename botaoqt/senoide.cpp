#include "senoide.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QColor>
#include <cmath>

Senoide::Senoide(QWidget *parent) : QWidget(parent){
  startTimer(100);
  teta=0;
}

void Senoide::timerEvent(QTimerEvent *e){
  teta+=0.03;
  repaint();
}

void Senoide::paintEvent(QPaintEvent *e){
  // cria o pintor que vai modificar a tela
  QPainter p(this);
  QPen pen;
  QBrush brush;

  // habilita ANTIALIASING
  p.setRenderHint(QPainter::Antialiasing);

  // desenha um retangulo com o fundo da tela
  pen.setWidth(0);
  pen.setStyle(Qt::NoPen);
  brush.setColor(QColor(230,230,130));
  brush.setStyle(Qt::SolidPattern);
  p.setPen(pen);
  p.setBrush(brush);
  p.drawRect(0,0,width(),height());
  // desenha uma reta vermelha diagonal
  pen.setStyle(Qt::SolidLine);
  pen.setColor(Qt::red);
  p.setPen(pen);
  // reta horizontal
  p.drawLine(0,height()/2,width(),height()/2);

  // desenha uma senoide em cor azul
  float w=1;
  float t;
  int x0, y0, x1, y1;

  pen.setColor(Qt::blue);
  p.setPen(pen);
  x0=0;
  y0=height()/2 - height()/2* sin(teta);
  for(int i=0; i<width(); i=i+5){
    t = (float) i / width() * 2*3.14;
    x1 = i;
    y1 = height()/2 - height()/2 * sin(w*t+teta);
    p.drawLine(x0,y0,x1,y1);
    x0 = x1; y0 = y1;
  }
}








