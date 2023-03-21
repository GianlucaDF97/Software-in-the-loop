%
clear
load('Log_monopattino_13_Mar.mat')
sw=input('inserire numero simulazione');
%per trasformare le timeseries in vettori di double
heading_tot=reshape(dataLog.heading_raw.Data(1,1,:),[1,length(dataLog.heading_raw.Time)]);
heading_tot=cast(heading_tot,'double');
vel_GPS_tot=reshape(dataLog.v_gps_raw.Data(1,1,:),[1,length(dataLog.v_gps_raw.Time)]);
vel_GPS_tot=cast(vel_GPS_tot,'double');
lat_tot=reshape(dataLog.Lat_raw.Data(1,1,:),[1,length(dataLog.Lat_raw.Time)]);
lat_tot=cast(lat_tot,'double');
long_tot=reshape(dataLog.Long_raw.Data(1,1,:),[1,length(dataLog.Long_raw.Time)]);
long_tot=cast(long_tot,'double');

time_tot=dataLog.heading_raw.Time;

T_in=input('inserisci tempo iniziale');
delta_t=input('inserisci intervallo di tempo');
index=find(time_tot>T_in-0.02);
time=0:0.02:delta_t;
heading=heading_tot(index(1):index(1)+length(time)-1);
vel_GPS=vel_GPS_tot(index(1):index(1)+length(time)-1);
lat=lat_tot(index(1):index(1)+length(time)-1);
long=long_tot(index(1):index(1)+length(time)-1);
%creazione matrice con tutti i dati di interesse
Real_meas=[heading; vel_GPS; lat; long];
%BTach filter
Real_meas_smooth=smoothdata(Real_meas(:,:),2,'sgolay');
%creazione timeseries da usare come input nel modello simulink- SIMULATE
heading_smooth=timeseries(Real_meas_smooth(1,:),time);
vel_GPS_smooth=timeseries(Real_meas_smooth(2,:),time);

% simulazione
out=sim('Prova_SITL_GPS',delta_t);
gspeed=out.sim_gspeed;
gspeed=reshape(gspeed(1,1,:),[1,length(time)]);
err_gspeed_real=vel_GPS(1,:)-Real_meas_smooth(2,:);
err_gspeed_sim=gspeed-Real_meas_smooth(2,:);

heading_sim=out.sim_heading;
heading_sim=heading_sim';
err_heading_real=heading-Real_meas_smooth(1,:);
err_heading_sim=heading_sim-Real_meas_smooth(1,:);

sigma_vel_real=std(err_gspeed_real);
sigma_vel_sim=std(err_gspeed_sim);

sigma_heading_real=std(err_heading_real);
sigma_heading_sim=std(err_gspeed_sim);

clear index
save(['Dati_simulazione_' num2str(sw) '.mat']);
%% grafici

sw=input('inserire simulazione richiesta ');
load(['Dati_simulazione_' num2str(sw) '.mat']);
figure(sw)
subplot(2,1,1)
hold on
plot(time,err_gspeed_sim,'b-','LineWidth',1)
plot(time,err_gspeed_real,'r-','LineWidth',1)
hold off
title(['errore Vel GPS [m/s] simulazione' num2str(sw) ''] )

subplot(2,1,2)
hold on
plot(time,vel_GPS(1,:),'r-','LineWidth',1)
plot(time,gspeed,'b-','LineWidth',1)
hold off
title(['confronto tra dati GPS reali e dati simulati simulazione' num2str(sw) ''])

% figure(103)
% plot(time,err_heading_sim,'b-','LineWidth',1)
% plot(time,err_heading_real,'r-','LineWidth',1)
% hold off
% title(['errore heading [m/s] simulazione' num2str(sw) ''])
