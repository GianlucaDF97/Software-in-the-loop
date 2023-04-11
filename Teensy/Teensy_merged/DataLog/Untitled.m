a=input('numero grafico=');
n=1;
while a<=5 && n==1
if a==1
figure(a)
plot(dataLog.v_gps_raw)
hold on
plot(dataLog.groundspeed_filt)
hold off
legend('raw','filt')

elseif a==2
figure(a)
hold on
plot(dataLog.Lat)
plot(dataLog.Lat_raw)
legend('filt','raw')
hold off

elseif a==3
figure(a)
hold on
plot(dataLog.Lon)
plot(dataLog.Lon_raw)
legend('filt','raw')
hold off

elseif a==4
figure(2)
plot(dataLog.h_baro_raw)
hold on
plot(dataLog.h_baro_filt,'--r')
hold off
legend('raw','filt') 

elseif a==5
for i=1:8616
hold on
plot(dataLog.Lat.Data(:,:,i),dataLog.Long.Data(:,:,i),'.')
end

elseif a==1
figure(a)
plot(dataLog.v_gps_raw)
hold on
plot(dataLog.groundspeed_filt)
hold off
legend('raw','filt')
end 
n=input(' altrografico si 1 no 0');

if n==1
   a=input('numero grafico=');
end
    
end

