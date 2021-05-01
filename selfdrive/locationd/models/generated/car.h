#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_5216289221370404833);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3452712874399280815);
void car_H_mod_fun(double *state, double *out_2157024882082550081);
void car_f_fun(double *state, double dt, double *out_8339224125347936747);
void car_F_fun(double *state, double dt, double *out_6175055055916972345);
void car_h_25(double *state, double *unused, double *out_6070690362966874654);
void car_H_25(double *state, double *unused, double *out_8311707207196836388);
void car_h_24(double *state, double *unused, double *out_8029682315241074240);
void car_H_24(double *state, double *unused, double *out_1379178555734224167);
void car_h_30(double *state, double *unused, double *out_517137563509420509);
void car_H_30(double *state, double *unused, double *out_521137955563531948);
void car_h_26(double *state, double *unused, double *out_4708769652325904438);
void car_H_26(double *state, double *unused, double *out_4395243349832699548);
void car_h_27(double *state, double *unused, double *out_6120228988783629708);
void car_H_27(double *state, double *unused, double *out_766444032273093364);
void car_h_29(double *state, double *unused, double *out_2519648487934912176);
void car_H_29(double *state, double *unused, double *out_3302660813565300005);
void car_h_28(double *state, double *unused, double *out_530688150140586373);
void car_H_28(double *state, double *unused, double *out_5762060862572424092);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}