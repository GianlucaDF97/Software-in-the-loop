%%%NEW%%%%%%%%%%%%%%%%%%
%VANNO CALCOLATI PRIMA DEL DECOLLO
%%%%%%%%%%%%%%%%%%%%%%%%
% baccxINI_new =-0.007038548201853;%[(m/s^2)^2] 
% baccyINI_new=-0.006720273103400;%[(m/s^2)^2]
% bacczINI_new=-0.032887664485074;%[(m/s^2)^2]

baccxINI_new =-0.003410230057882;%[(m/s^2)^2] NUOVI 
baccyINI_new=-0.005904866911587;%[(m/s^2)^2]
bacczINI_new=-0.034080754589163;%[(m/s^2)^2]

% bpINI_new =-0.1020e-03;
% bqINI_new =-0.0384e-03;
% brINI_new = -0.1250e-03;

bpINI_new =-0.001031278038744;
bqINI_new =0.002593077223300;
brINI_new = -0.001658460292446;
%%%%%%%%%%%%%%%%%%%%%%

T_cal=0.4;

 bias = [baccxINI_new,baccyINI_new,bacczINI_new,bpINI_new,bqINI_new,brINI_new];
 Sensor_Offsets=[0,0,0];
vd_ini=0;

UP=1;
%%%%%%%%%%%%
COV_F1B_VOLO_UP2%
%%%%%%%%%%%%