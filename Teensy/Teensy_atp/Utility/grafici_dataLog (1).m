close all
figure(1)
plot(dataLog.v_gps_raw,'LineWidth',1.3)
hold on
plot(dataLog.groundspeed_filt,'LineWidth',1.3)
hold off
legend('raw','filt')
title('velocità')
grid on
grid minor
ax=gca;
ax.GridAlpha=0.3;
ax.MinorGridAlpha=0.5;
%xlim([270 420])

figure(2)
hold on
plot(dataLog.Lat,'LineWidth',1.3)
plot(dataLog.Lat_raw,'LineWidth',1.3)
legend('filt','raw')
hold off
title('Latitudine')
grid on
grid minor
ax=gca;
ax.GridAlpha=0.3;
ax.MinorGridAlpha=0.5;
ylim([41.879 41.8825])
%xlim([270 420])

figure(3)
hold on
plot(dataLog.Long,'LineWidth',1.3)
plot(dataLog.Long_raw,'LineWidth',1.3)
legend('filt','raw')
hold off
title('Longitudine')
grid on
grid minor
ax=gca;
ax.GridAlpha=0.3;
ax.MinorGridAlpha=0.5;
ylim([12.7 12.705])
%xlim([270 420])

figure(4)
plot(dataLog.h_baro_raw,'LineWidth',1.3)
hold on
plot(dataLog.h_baro_filt,'LineWidth',1.3)
hold off
legend('raw','filt')
title('quota barometrica')
grid on
grid minor
ax=gca;
ax.GridAlpha=0.3;
ax.MinorGridAlpha=0.5;
%xlim([270 420])

% figure(5)
% for i=1:8616
% hold on
% plot(dataLog.Lat.Data(:,:,i),dataLog.Long.Data(:,:,i),'.','LineWidth',1.3)
% end
% title('Mappa')
% grid on
% grid minor
% ax=gca;
% ax.GridAlpha=0.3;
% ax.MinorGridAlpha=0.5;

figure(6)
plot(dataLog.gps_fix,'LineWidth',1.3)
title('Fix GPS')
grid on
grid minor
ax=gca;
ax.GridAlpha=0.3;
ax.MinorGridAlpha=0.5;
%xlim([270 420])

figure(7)
plot(dataLog.phi_raw,'LineWidth',1.3)
title('Rollio')
grid on
grid minor
ax=gca;
ax.GridAlpha=0.3;
ax.MinorGridAlpha=0.5;
%xlim([270 420])

figure(8)
plot(dataLog.psi_raw,'LineWidth',1.3)
title('Imbardata')
grid on
grid minor
ax=gca;
ax.GridAlpha=0.3;
ax.MinorGridAlpha=0.5;
%xlim([270 420])

figure(9)
plot(dataLog.theta_raw,'LineWidth',1.3)
title('Beccheggio')
grid on
grid minor
ax=gca;
ax.GridAlpha=0.3;
ax.MinorGridAlpha=0.5;
%xlim([270 420])

figure(10)
plot(dataLog.ias_filt,'LineWidth',1.3)
title('Velocità Pitot')
grid on
grid minor
ax=gca;
ax.GridAlpha=0.3;
ax.MinorGridAlpha=0.5;
%xlim([270 420])


