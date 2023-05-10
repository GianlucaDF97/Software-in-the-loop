a=input('numero grafico=');
while a<=100
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
        figure(a)
        plot(dataLog.h_baro_raw)
        hold on
        plot(dataLog.h_baro_filt)
        hold off
        legend('raw','filt')
        figure(a+100)
        plot(dataLog.h_baro_filt-dataLog.h_baro_raw)
        title('errore quota')
        
    elseif a==5
        figure(a)
        plot(dataLog.gps_fix)
        
    elseif a==6
        figure(a)
        lat=reshape(dataLog.Lat.Data,[1,length(dataLog.time_frame)]);
        long=reshape(dataLog.Long.Data,[1,length(dataLog.time_frame)]);
        geoplot(lat(3:end),long(3:end))
        geobasemap topographic
        
    elseif a==7
        figure(a)
        hold on
        plot(dataLog.throttleCmd_pwm,'r-','Linewidth',1)
        plot(dataLog.manual_throttleCmd_pwm,'b-','Linewidth',1)
        hold off
        
    elseif a==8
        figure(a)
        hold on
        plot(dataLog.aileronCmd_pwm,'r-','Linewidth',1)
        plot(dataLog.manual_aileronCmd_pwm,'b-','Linewidth',1)
        hold off
        
    elseif a==9
        figure(a)
        hold on
        plot(dataLog.elevatorCmd_pwm,'r-','Linewidth',1)
        plot(dataLog.manual_elevatorCmd_pwm,'b-','Linewidth',1)
        hold off
        
    elseif a==10
        figure(a)
        hold on
        plot(dataLog.rudderCmd_pwm,'r-','Linewidth',1)
        plot(dataLog.manual_rudderCmd_pwm,'b-','Linewidth',1)
        hold off
        
    elseif a==11
        figure(a)
        subplot(4,1,1)
        hold on
        plot(dataLog.throttleCmd_pwm,'r-','Linewidth',1)
        plot(dataLog.manual_throttleCmd_pwm,'b-','Linewidth',1)
        title('Manetta')
        hold off
        subplot(4,1,2)
        hold on
        plot(dataLog.aileronCmd_pwm,'r-','Linewidth',1)
        plot(dataLog.manual_aileronCmd_pwm,'b-','Linewidth',1)
        hold off
        title('Alettoni')
        subplot(4,1,3)
        hold on
        plot(dataLog.elevatorCmd_pwm,'r-','Linewidth',1)
        plot(dataLog.manual_elevatorCmd_pwm,'b-','Linewidth',1)
        hold off
        title('Equilibratore')
        subplot(4,1,4)
        hold on
        plot(dataLog.rudderCmd_pwm,'r-','Linewidth',1)
        plot(dataLog.manual_rudderCmd_pwm,'b-','Linewidth',1)
        hold off
        title('Timone')
        
    elseif a==12
        figure(a)
        plot(dataLog.Base_mode)
        
    elseif a==13
        figure(a)
        subplot(3,1,1)
        plot(dataLog.absA,'b-','Linewidth',1)
        title('absA')
        subplot(3,1,2)
        plot(dataLog.absE,'b-','Linewidth',1)
        title('absE')
        subplot(3,1,3)
        plot(dataLog.absT,'b-','Linewidth',1)
        title('absT')
        
    elseif a==14
        figure(a)
        subplot(3,1,1)
        plot(dataLog.long_home,'b-','LineWidth',1)
        title('Longitudine_home')
        subplot(3,1,2)
        plot(dataLog.lat_home,'b-','LineWidth',1)
        title('Latitudine_home')
        subplot(3,1,3)
        plot(dataLog.modo,'b-','LineWidth',1)
        title('Modo')
    end
    n=input(' altrografico si 1 no 0');
    
    
    if n==1
        a=input('numero grafico=');
    end
    
end
