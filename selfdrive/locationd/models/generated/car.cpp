#include "car.h"

namespace {
#define DIM 8
#define EDIM 8
#define MEDIM 8
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 5.991464547107981;

/******************************************************************************
 *                      Code generated with sympy 1.7.1                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_5216289221370404833) {
   out_5216289221370404833[0] = delta_x[0] + nom_x[0];
   out_5216289221370404833[1] = delta_x[1] + nom_x[1];
   out_5216289221370404833[2] = delta_x[2] + nom_x[2];
   out_5216289221370404833[3] = delta_x[3] + nom_x[3];
   out_5216289221370404833[4] = delta_x[4] + nom_x[4];
   out_5216289221370404833[5] = delta_x[5] + nom_x[5];
   out_5216289221370404833[6] = delta_x[6] + nom_x[6];
   out_5216289221370404833[7] = delta_x[7] + nom_x[7];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3452712874399280815) {
   out_3452712874399280815[0] = -nom_x[0] + true_x[0];
   out_3452712874399280815[1] = -nom_x[1] + true_x[1];
   out_3452712874399280815[2] = -nom_x[2] + true_x[2];
   out_3452712874399280815[3] = -nom_x[3] + true_x[3];
   out_3452712874399280815[4] = -nom_x[4] + true_x[4];
   out_3452712874399280815[5] = -nom_x[5] + true_x[5];
   out_3452712874399280815[6] = -nom_x[6] + true_x[6];
   out_3452712874399280815[7] = -nom_x[7] + true_x[7];
}
void H_mod_fun(double *state, double *out_2157024882082550081) {
   out_2157024882082550081[0] = 1.0;
   out_2157024882082550081[1] = 0.0;
   out_2157024882082550081[2] = 0.0;
   out_2157024882082550081[3] = 0.0;
   out_2157024882082550081[4] = 0.0;
   out_2157024882082550081[5] = 0.0;
   out_2157024882082550081[6] = 0.0;
   out_2157024882082550081[7] = 0.0;
   out_2157024882082550081[8] = 0.0;
   out_2157024882082550081[9] = 1.0;
   out_2157024882082550081[10] = 0.0;
   out_2157024882082550081[11] = 0.0;
   out_2157024882082550081[12] = 0.0;
   out_2157024882082550081[13] = 0.0;
   out_2157024882082550081[14] = 0.0;
   out_2157024882082550081[15] = 0.0;
   out_2157024882082550081[16] = 0.0;
   out_2157024882082550081[17] = 0.0;
   out_2157024882082550081[18] = 1.0;
   out_2157024882082550081[19] = 0.0;
   out_2157024882082550081[20] = 0.0;
   out_2157024882082550081[21] = 0.0;
   out_2157024882082550081[22] = 0.0;
   out_2157024882082550081[23] = 0.0;
   out_2157024882082550081[24] = 0.0;
   out_2157024882082550081[25] = 0.0;
   out_2157024882082550081[26] = 0.0;
   out_2157024882082550081[27] = 1.0;
   out_2157024882082550081[28] = 0.0;
   out_2157024882082550081[29] = 0.0;
   out_2157024882082550081[30] = 0.0;
   out_2157024882082550081[31] = 0.0;
   out_2157024882082550081[32] = 0.0;
   out_2157024882082550081[33] = 0.0;
   out_2157024882082550081[34] = 0.0;
   out_2157024882082550081[35] = 0.0;
   out_2157024882082550081[36] = 1.0;
   out_2157024882082550081[37] = 0.0;
   out_2157024882082550081[38] = 0.0;
   out_2157024882082550081[39] = 0.0;
   out_2157024882082550081[40] = 0.0;
   out_2157024882082550081[41] = 0.0;
   out_2157024882082550081[42] = 0.0;
   out_2157024882082550081[43] = 0.0;
   out_2157024882082550081[44] = 0.0;
   out_2157024882082550081[45] = 1.0;
   out_2157024882082550081[46] = 0.0;
   out_2157024882082550081[47] = 0.0;
   out_2157024882082550081[48] = 0.0;
   out_2157024882082550081[49] = 0.0;
   out_2157024882082550081[50] = 0.0;
   out_2157024882082550081[51] = 0.0;
   out_2157024882082550081[52] = 0.0;
   out_2157024882082550081[53] = 0.0;
   out_2157024882082550081[54] = 1.0;
   out_2157024882082550081[55] = 0.0;
   out_2157024882082550081[56] = 0.0;
   out_2157024882082550081[57] = 0.0;
   out_2157024882082550081[58] = 0.0;
   out_2157024882082550081[59] = 0.0;
   out_2157024882082550081[60] = 0.0;
   out_2157024882082550081[61] = 0.0;
   out_2157024882082550081[62] = 0.0;
   out_2157024882082550081[63] = 1.0;
}
void f_fun(double *state, double dt, double *out_8339224125347936747) {
   out_8339224125347936747[0] = state[0];
   out_8339224125347936747[1] = state[1];
   out_8339224125347936747[2] = state[2];
   out_8339224125347936747[3] = state[3];
   out_8339224125347936747[4] = state[4];
   out_8339224125347936747[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_8339224125347936747[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_8339224125347936747[7] = state[7];
}
void F_fun(double *state, double dt, double *out_6175055055916972345) {
   out_6175055055916972345[0] = 1;
   out_6175055055916972345[1] = 0;
   out_6175055055916972345[2] = 0;
   out_6175055055916972345[3] = 0;
   out_6175055055916972345[4] = 0;
   out_6175055055916972345[5] = 0;
   out_6175055055916972345[6] = 0;
   out_6175055055916972345[7] = 0;
   out_6175055055916972345[8] = 0;
   out_6175055055916972345[9] = 1;
   out_6175055055916972345[10] = 0;
   out_6175055055916972345[11] = 0;
   out_6175055055916972345[12] = 0;
   out_6175055055916972345[13] = 0;
   out_6175055055916972345[14] = 0;
   out_6175055055916972345[15] = 0;
   out_6175055055916972345[16] = 0;
   out_6175055055916972345[17] = 0;
   out_6175055055916972345[18] = 1;
   out_6175055055916972345[19] = 0;
   out_6175055055916972345[20] = 0;
   out_6175055055916972345[21] = 0;
   out_6175055055916972345[22] = 0;
   out_6175055055916972345[23] = 0;
   out_6175055055916972345[24] = 0;
   out_6175055055916972345[25] = 0;
   out_6175055055916972345[26] = 0;
   out_6175055055916972345[27] = 1;
   out_6175055055916972345[28] = 0;
   out_6175055055916972345[29] = 0;
   out_6175055055916972345[30] = 0;
   out_6175055055916972345[31] = 0;
   out_6175055055916972345[32] = 0;
   out_6175055055916972345[33] = 0;
   out_6175055055916972345[34] = 0;
   out_6175055055916972345[35] = 0;
   out_6175055055916972345[36] = 1;
   out_6175055055916972345[37] = 0;
   out_6175055055916972345[38] = 0;
   out_6175055055916972345[39] = 0;
   out_6175055055916972345[40] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_6175055055916972345[41] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_6175055055916972345[42] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_6175055055916972345[43] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_6175055055916972345[44] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_6175055055916972345[45] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_6175055055916972345[46] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_6175055055916972345[47] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_6175055055916972345[48] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_6175055055916972345[49] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_6175055055916972345[50] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_6175055055916972345[51] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_6175055055916972345[52] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_6175055055916972345[53] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_6175055055916972345[54] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_6175055055916972345[55] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_6175055055916972345[56] = 0;
   out_6175055055916972345[57] = 0;
   out_6175055055916972345[58] = 0;
   out_6175055055916972345[59] = 0;
   out_6175055055916972345[60] = 0;
   out_6175055055916972345[61] = 0;
   out_6175055055916972345[62] = 0;
   out_6175055055916972345[63] = 1;
}
void h_25(double *state, double *unused, double *out_6070690362966874654) {
   out_6070690362966874654[0] = state[6];
}
void H_25(double *state, double *unused, double *out_8311707207196836388) {
   out_8311707207196836388[0] = 0;
   out_8311707207196836388[1] = 0;
   out_8311707207196836388[2] = 0;
   out_8311707207196836388[3] = 0;
   out_8311707207196836388[4] = 0;
   out_8311707207196836388[5] = 0;
   out_8311707207196836388[6] = 1;
   out_8311707207196836388[7] = 0;
}
void h_24(double *state, double *unused, double *out_8029682315241074240) {
   out_8029682315241074240[0] = state[4];
   out_8029682315241074240[1] = state[5];
}
void H_24(double *state, double *unused, double *out_1379178555734224167) {
   out_1379178555734224167[0] = 0;
   out_1379178555734224167[1] = 0;
   out_1379178555734224167[2] = 0;
   out_1379178555734224167[3] = 0;
   out_1379178555734224167[4] = 1;
   out_1379178555734224167[5] = 0;
   out_1379178555734224167[6] = 0;
   out_1379178555734224167[7] = 0;
   out_1379178555734224167[8] = 0;
   out_1379178555734224167[9] = 0;
   out_1379178555734224167[10] = 0;
   out_1379178555734224167[11] = 0;
   out_1379178555734224167[12] = 0;
   out_1379178555734224167[13] = 1;
   out_1379178555734224167[14] = 0;
   out_1379178555734224167[15] = 0;
}
void h_30(double *state, double *unused, double *out_517137563509420509) {
   out_517137563509420509[0] = state[4];
}
void H_30(double *state, double *unused, double *out_521137955563531948) {
   out_521137955563531948[0] = 0;
   out_521137955563531948[1] = 0;
   out_521137955563531948[2] = 0;
   out_521137955563531948[3] = 0;
   out_521137955563531948[4] = 1;
   out_521137955563531948[5] = 0;
   out_521137955563531948[6] = 0;
   out_521137955563531948[7] = 0;
}
void h_26(double *state, double *unused, double *out_4708769652325904438) {
   out_4708769652325904438[0] = state[7];
}
void H_26(double *state, double *unused, double *out_4395243349832699548) {
   out_4395243349832699548[0] = 0;
   out_4395243349832699548[1] = 0;
   out_4395243349832699548[2] = 0;
   out_4395243349832699548[3] = 0;
   out_4395243349832699548[4] = 0;
   out_4395243349832699548[5] = 0;
   out_4395243349832699548[6] = 0;
   out_4395243349832699548[7] = 1;
}
void h_27(double *state, double *unused, double *out_6120228988783629708) {
   out_6120228988783629708[0] = state[3];
}
void H_27(double *state, double *unused, double *out_766444032273093364) {
   out_766444032273093364[0] = 0;
   out_766444032273093364[1] = 0;
   out_766444032273093364[2] = 0;
   out_766444032273093364[3] = 1;
   out_766444032273093364[4] = 0;
   out_766444032273093364[5] = 0;
   out_766444032273093364[6] = 0;
   out_766444032273093364[7] = 0;
}
void h_29(double *state, double *unused, double *out_2519648487934912176) {
   out_2519648487934912176[0] = state[1];
}
void H_29(double *state, double *unused, double *out_3302660813565300005) {
   out_3302660813565300005[0] = 0;
   out_3302660813565300005[1] = 1;
   out_3302660813565300005[2] = 0;
   out_3302660813565300005[3] = 0;
   out_3302660813565300005[4] = 0;
   out_3302660813565300005[5] = 0;
   out_3302660813565300005[6] = 0;
   out_3302660813565300005[7] = 0;
}
void h_28(double *state, double *unused, double *out_530688150140586373) {
   out_530688150140586373[0] = state[5];
   out_530688150140586373[1] = state[6];
}
void H_28(double *state, double *unused, double *out_5762060862572424092) {
   out_5762060862572424092[0] = 0;
   out_5762060862572424092[1] = 0;
   out_5762060862572424092[2] = 0;
   out_5762060862572424092[3] = 0;
   out_5762060862572424092[4] = 0;
   out_5762060862572424092[5] = 1;
   out_5762060862572424092[6] = 0;
   out_5762060862572424092[7] = 0;
   out_5762060862572424092[8] = 0;
   out_5762060862572424092[9] = 0;
   out_5762060862572424092[10] = 0;
   out_5762060862572424092[11] = 0;
   out_5762060862572424092[12] = 0;
   out_5762060862572424092[13] = 0;
   out_5762060862572424092[14] = 1;
   out_5762060862572424092[15] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_5216289221370404833) {
  err_fun(nom_x, delta_x, out_5216289221370404833);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3452712874399280815) {
  inv_err_fun(nom_x, true_x, out_3452712874399280815);
}
void car_H_mod_fun(double *state, double *out_2157024882082550081) {
  H_mod_fun(state, out_2157024882082550081);
}
void car_f_fun(double *state, double dt, double *out_8339224125347936747) {
  f_fun(state,  dt, out_8339224125347936747);
}
void car_F_fun(double *state, double dt, double *out_6175055055916972345) {
  F_fun(state,  dt, out_6175055055916972345);
}
void car_h_25(double *state, double *unused, double *out_6070690362966874654) {
  h_25(state, unused, out_6070690362966874654);
}
void car_H_25(double *state, double *unused, double *out_8311707207196836388) {
  H_25(state, unused, out_8311707207196836388);
}
void car_h_24(double *state, double *unused, double *out_8029682315241074240) {
  h_24(state, unused, out_8029682315241074240);
}
void car_H_24(double *state, double *unused, double *out_1379178555734224167) {
  H_24(state, unused, out_1379178555734224167);
}
void car_h_30(double *state, double *unused, double *out_517137563509420509) {
  h_30(state, unused, out_517137563509420509);
}
void car_H_30(double *state, double *unused, double *out_521137955563531948) {
  H_30(state, unused, out_521137955563531948);
}
void car_h_26(double *state, double *unused, double *out_4708769652325904438) {
  h_26(state, unused, out_4708769652325904438);
}
void car_H_26(double *state, double *unused, double *out_4395243349832699548) {
  H_26(state, unused, out_4395243349832699548);
}
void car_h_27(double *state, double *unused, double *out_6120228988783629708) {
  h_27(state, unused, out_6120228988783629708);
}
void car_H_27(double *state, double *unused, double *out_766444032273093364) {
  H_27(state, unused, out_766444032273093364);
}
void car_h_29(double *state, double *unused, double *out_2519648487934912176) {
  h_29(state, unused, out_2519648487934912176);
}
void car_H_29(double *state, double *unused, double *out_3302660813565300005) {
  H_29(state, unused, out_3302660813565300005);
}
void car_h_28(double *state, double *unused, double *out_530688150140586373) {
  h_28(state, unused, out_530688150140586373);
}
void car_H_28(double *state, double *unused, double *out_5762060862572424092) {
  H_28(state, unused, out_5762060862572424092);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_init(car);
