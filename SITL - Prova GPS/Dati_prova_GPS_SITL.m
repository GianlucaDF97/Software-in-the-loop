load('C:\Users\User\Desktop\DataLog\Log_monopattino_13_Mar.mat')

heading_tot=reshape(dataLog.heading_raw.Data(1,1,:),[1,length(dataLog.heading_raw.Time)]);
heading_tot=cast(heading_tot,'double');
vel_GPS_tot=reshape(dataLog.v_gps_raw.Data(1,1,:),[1,length(dataLog.v_gps_raw.Time)]);
vel_GPS_tot=cast(vel_GPS_tot,'double');
lat_tot=reshape(dataLog.Lat_raw.Data(1,1,:),[1,length(dataLog.Lat_raw.Time)]);
lat_tot=cast(lat_tot,'double');
long_tot=reshape(dataLog.Long_raw.Data(1,1,:),[1,length(dataLog.Long_raw.Time)]);
long_tot=cast(long_tot,'double');
heading=[heading_tot(7000:7500) heading_tot(12000:12500) heading_tot(14000:14500) heading_tot(17000:19000) heading_tot(24500:26000)];
vel_GPS=[vel_GPS_tot(7000:7500) vel_GPS_tot(12000:12500) vel_GPS_tot(14000:14500) vel_GPS_tot(17000:19000) vel_GPS_tot(24500:26000)];
lat=[lat_tot(7000:7500) lat_tot(12000:12500) lat_tot(14000:14500) lat_tot(17000:19000) lat_tot(24500:26000)];
long=[long_tot(7000:7500) long_tot(12000:12500) long_tot(14000:14500) long_tot(17000:19000) long_tot(24500:26000)];
Real_meas=[heading; vel_GPS; lat; long];
Real_meas_smooth_1=smoothdata(Real_meas(:,1:501),2,'sgolay');
Real_meas_smooth_2=smoothdata(Real_meas(:,502:1002),2,'sgolay');
Real_meas_smooth_3=smoothdata(Real_meas(:,1003:1503),2,'sgolay');
Real_meas_smooth_4=smoothdata(Real_meas(:,1504:3504),2,'sgolay');
Real_meas_smooth_5=smoothdata(Real_meas(:,3505:5005),2,'sgolay');

% figure(100)
% hold on
% plot(heading(1:501),'k-','LineWidth',1)
% plot(Real_meas_smooth_1(1,:),'b-','LineWidth',1)
% plot(501,heading(501),'k.','MarkerSize',15)
% plot(502:1002,heading(502:1002),'k-','LineWidth',1)
% plot(502:1002,Real_meas_smooth_2(1,:),'b-','LineWidth',1)
% plot(1002,heading(1002),'k.','MarkerSize',15)
% plot(1003:1503,heading(1003:1503),'k-','LineWidth',1)
% plot(1003:1503,Real_meas_smooth_3(1,:),'b-','LineWidth',1)
% plot(1503,heading(1503),'k.','MarkerSize',15)
% plot(1504:3504,heading(1504:3504),'k-','LineWidth',1)
% plot(1504:3504,Real_meas_smooth_4(1,:),'b-','LineWidth',1)
% plot(3504,heading(3504),'k.','MarkerSize',15)
% plot(3505:5005,heading(3505:5005),'k-','LineWidth',1)
% plot(3505:5005,Real_meas_smooth_5(1,:),'b-','LineWidth',1)
% plot(5005,heading(5005),'k.','MarkerSize',15)
% hold off

%% Dopo simulazione simulink
gspeed=out.sim_gspeed_1;
i=1;
figure(101)
hold on
while i<502
plot(gspeed(i,:))
i=i+5;
end
plot(vel_GPS(1:501),'b-','LineWidth',1.5)








