#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void live_update_3(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_19(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_6794182699788045524);
void live_err_fun(double *nom_x, double *delta_x, double *out_2083680679542908203);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_3694715790776780070);
void live_H_mod_fun(double *state, double *out_8113539636200269585);
void live_f_fun(double *state, double dt, double *out_7865903952507096390);
void live_F_fun(double *state, double dt, double *out_3120221082551971936);
void live_h_3(double *state, double *unused, double *out_2945031730277704093);
void live_H_3(double *state, double *unused, double *out_6444261605705101960);
void live_h_4(double *state, double *unused, double *out_1738158655202000054);
void live_H_4(double *state, double *unused, double *out_6948699031232825544);
void live_h_9(double *state, double *unused, double *out_1444913281554593646);
void live_H_9(double *state, double *unused, double *out_2419835801272887251);
void live_h_10(double *state, double *unused, double *out_8315307708455960571);
void live_H_10(double *state, double *unused, double *out_6305239117786072402);
void live_h_12(double *state, double *unused, double *out_708046058748378235);
void live_H_12(double *state, double *unused, double *out_4842143519493615975);
void live_h_31(double *state, double *unused, double *out_2638610533163085972);
void live_H_31(double *state, double *unused, double *out_7517233294637035796);
void live_h_32(double *state, double *unused, double *out_6513328226278578461);
void live_H_32(double *state, double *unused, double *out_8979009057424764173);
void live_h_13(double *state, double *unused, double *out_6044833227898883470);
void live_H_13(double *state, double *unused, double *out_927386995965160381);
void live_h_14(double *state, double *unused, double *out_1444913281554593646);
void live_H_14(double *state, double *unused, double *out_2419835801272887251);
void live_h_19(double *state, double *unused, double *out_5312116878356367122);
void live_H_19(double *state, double *unused, double *out_6852515652375318432);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}