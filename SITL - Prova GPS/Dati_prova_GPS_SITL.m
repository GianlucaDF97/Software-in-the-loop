%%
clear
load('Log_monopattino_13_Mar.mat')

%per trasformare le timeseries in vettori di double
heading_tot=reshape(dataLog.heading_raw.Data(1,1,:),[1,length(dataLog.heading_raw.Time)]);
heading_tot=cast(heading_tot,'double');
vel_GPS_tot=reshape(dataLog.v_gps_raw.Data(1,1,:),[1,length(dataLog.v_gps_raw.Time)]);
vel_GPS_tot=cast(vel_GPS_tot,'double');
lat_tot=reshape(dataLog.Lat_raw.Data(1,1,:),[1,length(dataLog.Lat_raw.Time)]);
lat_tot=cast(lat_tot,'double');
long_tot=reshape(dataLog.Long_raw.Data(1,1,:),[1,length(dataLog.Long_raw.Time)]);
long_tot=cast(long_tot,'double');
%creazione vettori con dati che ci interessano
heading=[heading_tot(7000:7500) heading_tot(12000:12500) heading_tot(14000:14500) heading_tot(17000:19000) heading_tot(24500:26000)];
vel_GPS=[vel_GPS_tot(7000:7500)  vel_GPS_tot(12000:12500) vel_GPS_tot(14000:14500) vel_GPS_tot(17000:19000) vel_GPS_tot(24500:26000)];
lat=[lat_tot(7000:7500)  lat_tot(12000:12500) lat_tot(14000:14500) lat_tot(17000:19000) lat_tot(24500:26000)];
long=[long_tot(7000:7500)  long_tot(12000:12500) long_tot(14000:14500) long_tot(17000:19000) long_tot(24500:26000)];
%creazione matrice con tutti i dati di interesse
Real_meas=[heading; vel_GPS; lat; long];
%filtro smooth data
Real_meas_smooth_1=smoothdata(Real_meas(:,1:501),2,'sgolay');
Real_meas_smooth_2=smoothdata(Real_meas(:,502:1002),2,'sgolay');
Real_meas_smooth_3=smoothdata(Real_meas(:,1003:1503),2,'sgolay');
Real_meas_smooth_4=smoothdata(Real_meas(:,1504:3504),2,'sgolay');
Real_meas_smooth_5=smoothdata(Real_meas(:,3505:5005),2,'sgolay');
%vettori dei tempi per creazione timeseries
time=0:0.02:10;
time4=0:0.02:40;
time5=0:0.02:30;


%creazione timeseries da usare come input nel modello simulink- SIMULATE
heading_smooth_1=timeseries(Real_meas_smooth_1(1,:),time1);
vel_GPS_smooth_1=timeseries(Real_meas_smooth_1(2,:),time1);
heading_smooth_2=timeseries(Real_meas_smooth_2(1,:),time2);
vel_GPS_smooth_2=timeseries(Real_meas_smooth_2(2,:),time2);
heading_smooth_3=timeseries(Real_meas_smooth_3(1,:),time3);
vel_GPS_smooth_3=timeseries(Real_meas_smooth_3(2,:),time3);
heading_smooth_4=timeseries(Real_meas_smooth_4(1,:),time4);
vel_GPS_smooth_4=timeseries(Real_meas_smooth_4(2,:),time4);
heading_smooth_5=timeseries(Real_meas_smooth_5(1,:),time5);
vel_GPS_smooth_5=timeseries(Real_meas_smooth_5(2,:),time5);

% figure(100)
% hold on
% plot(vel_GPS(1:251),'k-','LineWidth',1)
% plot(Real_meas_smooth_1(2,:),'b-','LineWidth',1)
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

%% simulazioni
sw=input('inserisci ontervallo scelto');
out=sim('Prova_SITL_GPS',10);
gspeed_1=out.sim_gspeed;
gspeed_1=reshape(gspeed_1(1,1,:),[1,length(time1)]);
i=0;
if (sw==1 || sw=2 || sw==3)
    err_gspeed_real=vel_GPS(1:length(time))-Real_meas_smooth_1(2,:);
    err_gspeed_sim=gspeed_1-Real_meas_smooth_1(2,:);
elseif  sw==4
    
heading_1=out.sim_heading;
heading_1=heading_1';
err_heading_real_1=heading(1:501)-Real_meas_smooth_1(1,:);
err_heading_sim_1=heading_1-Real_meas_smooth_1(1,:);
%% Dopo simulazione simulink n.1
sw=1;
out=sim('Prova_SITL_GPS',10);
% ,'FixedStep','0.02'
% gspeed_1=out.sim_gspeed_1;
gspeed_1=out.sim_gspeed;
gspeed_1=reshape(gspeed_1(1,1,:),[1,length(time1)]);
err_gspeed_real_1=vel_GPS(1:501)-Real_meas_smooth_1(2,:);
err_gspeed_sim_1=gspeed_1-Real_meas_smooth_1(2,:);

% heading_1=out.sim_heading_1;
heading_1=out.sim_heading;
heading_1=heading_1';
err_heading_real_1=heading(1:501)-Real_meas_smooth_1(1,:);
err_heading_sim_1=heading_1-Real_meas_smooth_1(1,:);

sigma_vel_real=std(err_gspeed_real_1);
sigma_vel_sim=std(err_gspeed_sim_1);

sigma_heading_real=std(err_heading_real_1);
sigma_heading_sim=std(err_gspeed_sim_1);
%% Dopo simulazione simulink n.2
sw=2;
out=sim('Prova_SITL_GPS',10);
% gspeed_2=out.sim_gspeed_2;
gspeed_2=out.sim_gspeed;
gspeed_2=reshape(gspeed_2(1,1,:),[1,length(time2)]);
err_gspeed_2=vel_GPS(502:1002)-gspeed_2;
% heading_2=out.sim_heading_2;
heading_2=out.sim_heading;
heading_2=heading_2';
err_heading_2=heading(502:1002)-heading_2;
%% Dopo simulazione simulink n.3
sw=3;
out=sim('Prova_SITL_GPS',10);
% gspeed_3=out.sim_gspeed_3;
gspeed_3=out.sim_gspeed;
gspeed_3=reshape(gspeed_3(1,1,:),[1,length(time3)]);
err_gspeed_3=vel_GPS(1003:1503)-gspeed_3;
% heading_3=out.sim_heading_3;
heading_3=out.sim_heading;
heading_3=heading_3';
err_heading_3=heading(1003:1503)-heading_3;
%% Dopo simulazione simulink n.4
sw=4;
out=sim('Prova_SITL_GPS',40);
% gspeed_4=out.sim_gspeed_4;
gspeed_4=out.sim_gspeed;
gspeed_4=reshape(gspeed_4(1,1,:),[1,length(time4)]);
err_gspeed_4=vel_GPS(1504:3504)-gspeed_4;
% heading_4=out.sim_heading_4;
heading_4=out.sim_heading;
heading_4=heading_4';
err_heading_4=heading(1504:3504)-heading_4;
%% Dopo simulazione simulink n.5
sw=5;
out=sim('Prova_SITL_GPS',30);
% gspeed_5=out.sim_gspeed_5;
gspeed_5=out.sim_gspeed;
gspeed_5=reshape(gspeed_5(1,1,:),[1,length(time5)]);
err_gspeed_5=vel_GPS(3505:5005)-gspeed_5;
% heading_5=out.sim_heading_5;
heading_5=out.sim_heading;
heading_5=heading_5';
err_heading_5=heading(3505:5005)-heading_5;

%% Grafici
figure(101)
hold on
plot(time1,err_gspeed_sim_1,'b-','LineWidth',1)
plot(time1,err_gspeed_real_1,'r-','LineWidth',1)
hold off
figure(102)
hold on
plot(time1,vel_GPS(1,1:251),'b-','LineWidth',1)
plot(time1,gspeed_1,'r-','LineWidth',1)
hold off

title('Errore velocità GPS in t=[140 150] s')
figure(102)
plot(240:0.02:250,err_gspeed_2,'b-','LineWidth',1)
title('Errore velocità GPS in t=[240 250] s')
figure(103)
plot(280:0.02:290,err_gspeed_3,'b-','LineWidth',1)
title('Errore velocità GPS in t=[280 290] s')
figure(104)
plot(340:0.02:380,err_gspeed_4,'b-','LineWidth',1)
title('Errore velocità GPS in t=[340 380] s')
figure(105)
plot(490:0.02:520,err_gspeed_5,'b-','LineWidth',1)
title('Errore velocità GPS in t=[490 520] s')

%% Grafico unico degli errori
figure(106)
hold on
plot(err_gspeed_1,'b-','LineWidth',1)
plot(err_gspeed_2,'k-','LineWidth',1)
plot(err_gspeed_3,'r-','LineWidth',1)
plot(err_gspeed_4,'m-','LineWidth',1)
plot(err_gspeed_5,'g-','LineWidth',1)

