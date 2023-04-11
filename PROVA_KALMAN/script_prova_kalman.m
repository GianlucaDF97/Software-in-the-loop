load('FlightData_09_Mar_2023_13_33_04.mat')
time=dataLog.time_frame;
Lat_raw=reshape(dataLog.Lat_raw.Data(1,1,:),[1,length(time)]);
Lat=timeseries(Lat_raw,time);
Long_raw=reshape(dataLog.Long_raw.Data(1,1,:),[1,length(time)]);
Long=timeseries(Long_raw,time);
V_gps_raw=reshape(dataLog.v_gps_raw.Data(1,1,:),[1,length(time)]);
V_gps=timeseries(V_gps_raw,time);
quota_GPS_raw=reshape(dataLog.h_gps_raw.Data(1,1,:),[1,length(time)]);
quota_GPS=timeseries(quota_GPS_raw,time);
heading_raw=reshape(dataLog.heading_raw.Data(1,1,:),[1,length(time)]);
heading=timeseries(heading_raw,time);
fix_raw=reshape(dataLog.gps_fix.Data(1,1,:),[1,length(time)]);
fix=timeseries(fix_raw,time);
acc_x_raw=reshape(dataLog.acc_x_raw.Data(1,1,:),[1,length(time)]);
acc_x=timeseries(acc_x_raw,time);
acc_y_raw=reshape(dataLog.acc_y_raw.Data(1,1,:),[1,length(time)]);
acc_y=timeseries(acc_y_raw,time);
acc_z_raw=reshape(dataLog.acc_z_raw.Data(1,1,:),[1,length(time)]);
acc_z=timeseries(acc_z_raw,time);
p_raw=reshape(dataLog.p_raw.Data(1,1,:),[1,length(time)]);
p=timeseries(p_raw,time);
q_raw=reshape(dataLog.q_raw.Data(1,1,:),[1,length(time)]);
q=timeseries(q_raw,time);
r_raw=reshape(dataLog.r_raw.Data(1,1,:),[1,length(time)]);
r=timeseries(r_raw,time);
phi_raw=reshape(dataLog.phi_raw.Data(1,1,:),[1,length(time)]);
phi=timeseries(phi_raw,time);
theta_raw=reshape(dataLog.theta_raw.Data(1,1,:),[1,length(time)]);
theta=timeseries(theta_raw,time);
psi_raw=reshape(dataLog.psi_raw.Data(1,1,:),[1,length(time)]);
psi=timeseries(psi_raw,time);
quota_baro_raw=reshape(dataLog.h_baro_raw.Data(1,1,:),[1,length(time)]);
quota_baro=timeseries(quota_baro_raw,time);
press_raw=reshape(dataLog.press_raw.Data(1,1,:),[1,length(time)]);
press=timeseries(press_raw,time);
temperatura_raw=reshape(dataLog.temp_raw.Data(1,1,:),[1,length(time)]);
temperatura=timeseries(temperatura_raw,time);
mario_raw=reshape(zeros(1,length(time)),[1,length(time)]);
mario=timeseries(mario_raw,time);
v_pitot_raw=reshape(dataLog.v_pitot_raw.Data(1,1,:),[1,length(time)]);
v_pitot=timeseries(v_pitot_raw,time);
dist_lidar_raw=reshape(dataLog.dist_lidar_raw.Data(1,1,:),[1,length(time)]);
dist_lidar=timeseries(dist_lidar_raw,time);
dpdiff_raw=reshape(zeros(1,length(time)),[1,length(time)]);
dpdiff=timeseries(dpdiff_raw,time);
% input=[Lat, Long, V_gps, quota_GPS, heading,fix,acc_x,acc_y,acc_z,p,q,r,phi,theta,psi,quota_baro,press,temperatura,mario,v_pitot,dist_lidar,dpdiff];
t_AP=0.02;

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

%%
figure(1)
plot(dataLog.h_baro_raw)
plot(out.h_baro_filt,'*g')
plot(dataLog.h_baro_filt,'-r')
legend('raw','filt_prova','filt_real') 











