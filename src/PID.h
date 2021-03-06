#ifndef PID_H
#define PID_H

class PID {
private:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;

  //state
  unsigned short idx;
  double prev_err;
  double sum_err;
  double curr_err;
  double diff_err;

  double* pK[3];
  double* pdK[3];

  //twiddle 
  double dKi;
  double dKp;
  double dKd;
  int cnt;
  double sum_sqerr;
  double best_err;
  int period;
  bool bNeg;

  bool Twiddle();
public:

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();

  void Restart();
};

#endif /* PID_H */
