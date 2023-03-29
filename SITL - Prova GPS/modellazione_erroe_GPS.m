clear
load('Log_monopattino_13_Mar.mat')
sw=input('inserire numero simulazione');
c=input(" che prova vuoir fare 1 per cost 2 per rampa 3 per log dati");
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

if c==1
    deltat_cost=input('inserire tempo per simulazione a posizione costante');
    time_cost=0:0.02:deltat_cost;
    lat_cost=0.73128*ones(1,length(time_cost));
    long_cost=0.21844*ones(1,length(time_cost));
    lat_smooth=timeseries(lat_cost,time_cost);
    long_smooth=timeseries(long_cost,time_cost);
    out=sim('Prova_SITL_GPS_cost',deltat_cost);
    lat_sim=out.lat_sim;
    long_sim=out.long_sim;
    lat_sim=reshape(lat_sim(1,1,:),[1,length(time_cost)]);  
    long_sim=reshape(long_sim(1,1,:),[1,length(time_cost)]);
elseif c==2
   deltat_rampa=input('inserire tempo per simulazione a posizione con rampa');
    time_rampa=0:0.02:deltat_rampa;
   lat_rampa=2.50*10^-6*time_rampa+0.73128;
    long_rampa=2.50*10^-6*time_rampa+0.21844;
    lat_smooth=timeseries(lat_rampa,time_rampa);
    long_smooth=timeseries(long_rampa,time_rampa);
    out=sim('Prova_SITL_GPS_cost',deltat_rampa);
    lat_sim=out.lat_sim;
    long_sim=out.long_sim;
    lat_sim=reshape(lat_sim(1,1,:),[1,length(time_rampa)]);
    long_sim=reshape(long_sim(1,1,:),[1,length(time_rampa)]);
else 
    T_in=input('inserisci tempo iniziale');
    delta_t=input('inserisci intervallo di tempo');
    index=find(time_tot>T_in-0.02);
    time=0:0.02:delta_t;
    heading=deg2rad((heading_tot(index(1):index(1)+length(time)-1)));
    vel_GPS=vel_GPS_tot(index(1):index(1)+length(time)-1);
    lat=deg2rad(lat_tot(index(1):index(1)+length(time)-1));
    long=deg2rad(long_tot(index(1):index(1)+length(time)-1));

  
    %creazione matrice con tutti i dati di interesse
    Real_meas=[heading; vel_GPS; lat; long];
    %BTach filter
    Real_meas_smooth=smoothdata(Real_meas(:,:),2,'sgolay');

    %creazione timeseries da usare come input nel modello simulink- SIMULATE 
    heading_smooth=timeseries(Real_meas_smooth(1,:),time);
    vel_GPS_smooth=timeseries(Real_meas_smooth(2,:),time);
    lat_smooth=timeseries(Real_meas_smooth(3,:),time);
    long_smooth=timeseries(Real_meas_smooth(4,:),time);
    
%     errore=100;
%     std_lat=2.7348e-7;
%     std_long=1.3733e-6;
%     std_lat1=deg2rad(6.3673e-6);
%     std_long1=deg2rad(5.9309e-6);
%     eps1=0.2544;
%     eps2=0.16;
%    while abs(errore)>0.1
        
    out=sim('Prova_SITL_GPS',delta_t);

    gspeed=out.sim_gspeed;
    gspeed=reshape(gspeed(1,1,:),[1,length(time)]);
    err_gspeed_real=vel_GPS(1,:)-Real_meas_smooth(2,:);
    err_gspeed_sim=gspeed-Real_meas_smooth(2,:);
    
    heading_sim=out.sim_heading;
    heading_sim=heading_sim';
    % heading_sim=reshape(heading_sim(1,1,:),[1,length(time)]);
    err_heading_real=heading-Real_meas_smooth(1,:);
    err_heading_sim=heading_sim-Real_meas_smooth(1,:);

    sigma_vel_real=std(err_gspeed_real);
    sigma_vel_sim=std(err_gspeed_sim);
    
    sigma_heading_real=std(rad2deg(err_heading_real));
    sigma_heading_sim=std(rad2deg(err_heading_sim));
    lat_sim=out.lat_sim;
    long_sim=out.long_sim;
%     lat_sim=reshape(lat_sim(1,1,:),[1,length(time)]);
%     long_sim=reshape(long_sim(1,1,:),[1,length(time)]);

    %stima grandezze misurate
    lat_sim_smooth=smoothdata(lat_sim(:,:),1,'sgolay');
    long_sim_smooth=smoothdata(long_sim(:,:),1,'sgolay');
    
    
    err_dist_sim=[];
    err_dist_real=[];
    for i=1:length(time)
        err_dist_real=[err_dist_real haversine(long(1,i),Real_meas_smooth(4,i),lat(1,i),Real_meas_smooth(3,i))];
        err_dist_sim=[err_dist_sim haversine(long_sim_smooth(i,1),long_sim(i,1),lat_sim_smooth(i,1),lat_sim(i,1))];
    end
    sigma_dist_real=std(err_dist_real);
    sigma_dist_sim=std(err_dist_sim);
    errore=sigma_dist_real-sigma_dist_sim
%     if abs(errore)>0.1
%         eps1=sigma_dist_sim;
%         std_lat_new=(std_lat-std_lat1)/(eps1-eps2)*(0.4041-eps2)+std_lat1;
%         std_long_new=(std_long-std_long1)/(eps1-eps2)*(0.4041-eps2)+std_long1;
%         std_long1=std_long;
%         std_lat1=std_lat;
%         std_lat=std_lat_new;
%         std_long=std_long_new;
%         eps2=eps1;
%         
%     end
     end
% end

% err_lat_sim=out.errore_lat;
% err_long_sim=out.errore_long;
% err_dist_sim=out.err_dist_sim;
% sigma_lat_sim=std(err_lat_sim);
% sigma_long_sim=std(err_long_sim);
% sigma_dist_sim=std(err_dist_sim);



clear index
save(['Dati_simulazione_' num2str(sw) '.mat']);
%% grafici 

close all
sw=input('inserire simulazione richiesta ');
load(['Dati_simulazione_' num2str(sw) '.mat']);
figure(sw)

subplot(2,1,1)
hold on
plot(time,err_gspeed_sim,'b-','LineWidth',1)
plot(time,err_gspeed_real,'r-','LineWidth',1)
yline(sigma_vel_real,'g--','LineWidth',2)
yline(sigma_vel_sim,'m--*','LineWidth',2)
hold off
title(['errore Vel GPS [m/s] simulazione' num2str(sw) ''] )
legend('errore velocità simulata', 'errore velocità misurata dal gps reale', '\sigma_{err }_{vel }_{real }==0.0243','\sigma_{err }_{vel }_{sim }==0.0534','interpeter','latex')

subplot(2,1,2)
hold on
plot(time,vel_GPS(1,:),'r-','LineWidth',1)
plot(time,gspeed,'b-','LineWidth',1)
hold off
title(['confronto tra dati GPS reali e dati simulati simulazione [m/s] ' num2str(sw) ''])
legend(' velocità simulata', ' velocità misurata dal gps reale')

figure(103)
subplot(2,1,1)
hold on
plot(time,err_heading_sim,'b-','LineWidth',1)
plot(time,err_heading_real,'r-','LineWidth',1)
yline(deg2rad(sigma_heading_real),'g--','LineWIdth',2)
yline(deg2rad(sigma_heading_sim),'m--*','LineWIdth',2)
hold off
title(['errore heading [☺ rad] simulazione [rad]' num2str(sw) ''])
legend('errore heading simulato', 'errore heading misurato dal gps reale', '\sigma_{err }_{heading }_{real }=0.5949','\sigma_{err }_{heading }_{sim }==0.5298','interpeter','latex')
subplot(2,1,2)
hold on
plot(time,heading_sim,'b-','LineWidth',1)
plot(time,heading,'r-','LineWidth',1)
hold off
title(['confronto heading [ rad] dati reali e simulati' num2str(sw) ''])
legend('heading simulato', 'heading misurato dal gps reale')


figure(104)
hold on
plot(time,err_dist_sim,'b-','LineWidth',1)
plot(time,err_dist_real,'r-','LineWidth',1)
yline(deg2rad(sigma_dist_real),'g--','LineWIdth',2)
yline(deg2rad(sigma_dist_sim),'m--*','LineWIdth',2)
hold off
title(['errore distanza [m] simulazione' num2str(sw) ''])
legend('errore distanza simulata', 'errore distanza dal gps reale', '\sigma_{err }_{dist }_{real }=','\sigma_{err }_{dist }_{sim }=','interpeter','latex')
%%
close all
sw1=input('inserire simulazione richiesta, per la cost ');
load(['Dati_simulazione_' num2str(sw1) '.mat']);
err_dist_sim_cost=err_dist_sim;
sigma_dist_sim_cost=sigma_dist_sim;
sw2=input('inserire simulazione richiesta,per la rampa ');
load(['Dati_simulazione_' num2str(sw2) '.mat']);
err_dist_sim_rampa=err_dist_sim;
sigma_dist_sim_rampa=sigma_dist_sim;


% subplot(2,1,1)
hold on
plot(time_cost,err_dist_sim_cost,'b-','LineWidth',1)
plot(time_rampa,err_dist_sim_rampa,'r-','LineWidth',1)
yline(sigma_dist_sim_cost,'g-','LineWidth',3)
yline(sigma_dist_sim_rampa,'m-','LineWidth',3)
yline(0.7,'k','LineWidth',3)
hold off
title('errore distanza [m] simulazione')
legend('errore distanza cost', 'errore distanza rampa',['\sigma_{cost}  ' num2str(sigma_dist_sim_cost)],['\sigma_{rampa}  ' num2str(sigma_dist_sim_rampa)],['\sigma_{data}_{sheet}'  num2str(0.7)])

% subplot(2,1,2)
% hold on
% plot(time,vel_GPS(1,:),'r-','LineWidth',1)
% plot(time,gspeed,'b-','LineWidth',1)
% hold off
% title(['confronto tra dati GPS reali e dati simulati simulazione' num2str(sw) ''])





