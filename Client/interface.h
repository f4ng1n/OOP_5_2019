#ifndef TINTERFACE_H
#define TINTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QLayout>
#include "complex.h"
#include <QUdpSocket>
#include <QMessageBox>

namespace Ui {
class TInterface;
}
class TInterface : public QWidget
{
    Q_OBJECT
private :

public:
    TInterface(QWidget *parent = nullptr);
    void update_roots_val(TComplex, TComplex);
    QUdpSocket *socketClient;
    QUdpSocket *socketClientRecive;
    double root1_r, root1_i, root2_r, root2_i, value_r, value_i;
private:
    QLabel *p_lbl_root1, *p_lbl_root2,
           *p_lbl_calculated_value, *p_lbl_polinome,
            *p_lbl_i1,*p_lbl_i2,*p_lbl_i3,*p_lbl_i;
    QLineEdit *p_led_a,*p_led_ai, *p_led_b, *p_led_bi, *p_led_c,*p_led_ci, *p_led_x, *p_led_xi;
   private slots:
    void sockReady();
    void calculate_button_pressed();
    void update_polinom();
};

#endif // TINTERFACE_H
