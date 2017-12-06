#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */
  VectorXd rmse(4);
  rmse << 0,0,0,0;

  if(estimations.size() == 0){
    cout << "ERROR - CalculateRMSE () - The estimations vector is empty" << endl;
    return rmse;
  }

  if(ground_truth.size() == 0){
    cout << "ERROR - CalculateRMSE () - The ground-truth vector is empty" << endl;
    return rmse;
  }

  if(estimations.size() != ground_truth.size()){
    cout << "ERROR - CalculateRMSE () - The ground-truth and estimations vectors must have the same size." << endl;
    return rmse;
  }

  //accumulate squared residuals
  for(int i = 0; i < estimations.size(); ++i){
	VectorXd residual = estimations[i] - ground_truth[i];
	residual = residual.array() * residual.array();
	rmse += residual;
  }

  //calculate the mean
  rmse /= estimations.size();

  //calculate the squared root
  rmse = rmse.array().sqrt();

  return rmse;
}