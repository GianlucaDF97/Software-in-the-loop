%%%NEW%%%%%%%%%%%%%%%%%%
%LOADER HIL
%%%%%%%%%%%%%%%%%%%%%%%%
baccxINI_new = 0.0392;%[(m/s^2)^2]
baccyINI_new = -0.0598;%[(m/s^2)^2]
bacczINI_new = 0.0384;%[(m/s^2)^2]

bpINI_new = 1.5184e-06;%[(rad/s)]
bqINI_new = 2.9671e-05;%[(rad/s)]
brINI_new = 5.4105e-05;%[(rad/s)]

%%%%%%%%%%%%%%%%%%%%%%

T_cal=0.4;

 bias = [baccxINI_new,baccyINI_new,bacczINI_new,bpINI_new,bqINI_new,brINI_new];
 Sensor_Offsets=[0,0,0];
 vd_ini=0;

UP=2;
%%%%%%%%%%%%
COV_F1B%
%%%%%%%%%%%%