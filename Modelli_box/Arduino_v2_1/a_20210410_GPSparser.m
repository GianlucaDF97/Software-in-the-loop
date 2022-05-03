function [Lat,Long,hor_speed,Magnetic_declination,fix_mode,n_sat,...
    h_mean_sea,h_WGS85] = GPSparser
%Questa funzione non ha bisogno di input perchè prende in seriale da 
%Arduino Due dalla porta seriale numero 1. Fornisce attraverso qualsiasi 
%formato di messaggio gps le otto grandezze di cui sopra. Questa funzione
%è stata formulata per il GPS 'Ultimate GPS Breakout v3'
persistent a
a = arduino('COM10', 'Due', 'Libraries', 'Serial');
gpsObject = gpsdev( a );

gpsData = gpsObject.read;

Lat              = gpsData.LLA(1);
Long             = gpsData.LLA(2);
h_mean_sea       = gpsData.LLA(3);

hor_speed        = gpsData.GroundSpeed;

gpsInfo = gpsObject.info;

n_sat            = gpsInfo.SatellitesInView;

end

